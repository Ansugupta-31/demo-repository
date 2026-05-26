#include "admin.h"
#include "filehandler.h"
#include "common.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

namespace AdminUser {
    
    // Admin login
    bool adminLogin(int adminId, std::string password) {
        AdminAccount admin = FileHandler::readAdminAccount(adminId);
        
        if (admin.adminId == -1) {
            std::cout << "\nError: Admin account not found!" << std::endl;
            return false;
        }
        
        if (admin.adminPassword == password) {
            std::cout << "\nAdmin login successful! Welcome, " << admin.adminName << std::endl;
            return true;
        } else {
            std::cout << "\nError: Incorrect password!" << std::endl;
            return false;
        }
    }
    
    // View all user accounts
    void viewAllAccounts() {
        std::vector<CommonUser::Account> accounts = FileHandler::getAllUserAccounts();
        
        if (accounts.empty()) {
            std::cout << "\nNo user accounts found." << std::endl;
            return;
        }
        
        std::cout << "\n========== All User Accounts ==========" << std::endl;
        std::cout << std::left << std::setw(12) << "Account No" 
                  << std::setw(20) << "Name" 
                  << std::setw(15) << "Balance" << std::endl;
        std::cout << "=======================================" << std::endl;
        
        for (const auto& account : accounts) {
            std::cout << std::left << std::setw(12) << account.accountNumber 
                      << std::setw(20) << account.name 
                      << "Rs. " << std::fixed << std::setprecision(2) << account.balance << std::endl;
        }
        
        std::cout << "=======================================" << std::endl;
    }
    
    // View specific user account details
    void viewUserAccount(int accountNumber) {
        CommonUser::Account account = FileHandler::readUserAccount(accountNumber);
        
        if (account.accountNumber == -1) {
            std::cout << "\nError: Account not found!" << std::endl;
            return;
        }
        
        std::cout << "\n========== User Account Details ==========" << std::endl;
        std::cout << "Account Number: " << account.accountNumber << std::endl;
        std::cout << "Account Holder: " << account.name << std::endl;
        std::cout << "PIN: " << account.pin << std::endl;
        std::cout << "Balance: Rs. " << std::fixed << std::setprecision(2) 
                  << account.balance << std::endl;
        
        if (FileHandler::isAccountBlocked(accountNumber)) {
            std::cout << "Status: BLOCKED" << std::endl;
        } else {
            std::cout << "Status: ACTIVE" << std::endl;
        }
        
        std::cout << "==========================================" << std::endl;
    }
    
    // Create new account
    void createNewAccount(int accountNumber, int pin, double initialBalance, std::string name) {
        if (FileHandler::userAccountExists(accountNumber)) {
            std::cout << "\nError: Account already exists!" << std::endl;
            return;
        }
        
        if (pin <= 999 || pin > 9999) {
            std::cout << "\nError: PIN should be 4 digits!" << std::endl;
            return;
        }
        
        if (initialBalance < 0) {
            std::cout << "\nError: Initial balance cannot be negative!" << std::endl;
            return;
        }
        
        CommonUser::Account newAccount;
        newAccount.accountNumber = accountNumber;
        newAccount.pin = pin;
        newAccount.balance = initialBalance;
        newAccount.name = name;
        
        if (FileHandler::saveUserAccount(newAccount)) {
            std::cout << "\n========== Account Created Successfully ==========" << std::endl;
            std::cout << "Account Number: " << accountNumber << std::endl;
            std::cout << "Account Holder: " << name << std::endl;
            std::cout << "Initial Balance: Rs. " << std::fixed << std::setprecision(2) 
                      << initialBalance << std::endl;
            std::cout << "===================================================" << std::endl;
        } else {
            std::cout << "\nError: Could not create account!" << std::endl;
        }
    }
    
    // Delete account
    void deleteAccount(int accountNumber) {
        if (!FileHandler::userAccountExists(accountNumber)) {
            std::cout << "\nError: Account not found!" << std::endl;
            return;
        }
        
        if (FileHandler::deleteUserAccount(accountNumber)) {
            std::cout << "\n========== Account Deleted Successfully ==========" << std::endl;
            std::cout << "Account Number: " << accountNumber << " has been deleted." << std::endl;
            std::cout << "==================================================" << std::endl;
        } else {
            std::cout << "\nError: Could not delete account!" << std::endl;
        }
    }
    
    // Block account
    void blockAccount(int accountNumber) {
        if (!FileHandler::userAccountExists(accountNumber)) {
            std::cout << "\nError: Account not found!" << std::endl;
            return;
        }
        
        if (FileHandler::isAccountBlocked(accountNumber)) {
            std::cout << "\nError: Account is already blocked!" << std::endl;
            return;
        }
        
        FileHandler::blockAccount(accountNumber);
    }
    
    // Unblock account
    void unblockAccount(int accountNumber) {
        if (!FileHandler::userAccountExists(accountNumber)) {
            std::cout << "\nError: Account not found!" << std::endl;
            return;
        }
        
        if (!FileHandler::isAccountBlocked(accountNumber)) {
            std::cout << "\nError: Account is not blocked!" << std::endl;
            return;
        }
        
        FileHandler::unblockAccount(accountNumber);
    }
    
    // View transaction log
    void viewTransactionLog() {
        std::ifstream file("transactions.txt");
        if (!file.is_open()) {
            std::cout << "\nNo transactions found." << std::endl;
            return;
        }
        
        std::cout << "\n========== Complete Transaction Log ==========" << std::endl;
        std::string line;
        bool found = false;
        
        while (std::getline(file, line)) {
            if (!line.empty()) {
                std::cout << line << std::endl;
                found = true;
            }
        }
        
        if (!found) {
            std::cout << "No transactions recorded." << std::endl;
        }
        
        std::cout << "=============================================" << std::endl;
        file.close();
    }
    
    // Generate report
    void generateReport() {
        std::vector<CommonUser::Account> accounts = FileHandler::getAllUserAccounts();
        
        if (accounts.empty()) {
            std::cout << "\nNo accounts found for report." << std::endl;
            return;
        }
        
        double totalBalance = 0;
        int totalAccounts = 0;
        
        for (const auto& account : accounts) {
            totalBalance += account.balance;
            totalAccounts++;
        }
        
        std::cout << "\n========== ATM System Report ==========" << std::endl;
        std::cout << "Total Active Accounts: " << totalAccounts << std::endl;
        std::cout << "Total Balance in System: Rs. " << std::fixed << std::setprecision(2) 
                  << totalBalance << std::endl;
        std::cout << "Average Balance per Account: Rs. " << (totalBalance / totalAccounts) << std::endl;
        std::cout << "======================================" << std::endl;
    }
}
