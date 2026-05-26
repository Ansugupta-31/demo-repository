#include "filehandler.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>

namespace FileHandler {
    
    const char* USER_FILE = "users.txt";
    const char* TRANSACTION_FILE = "transactions.txt";
    const char* ADMIN_FILE = "admin.txt";
    const char* BLOCKED_FILE = "blocked.txt";
    
    // Initialize files if they don't exist
    void initializeFiles() {
        std::ofstream file;
        
        // Check and create users.txt
        std::ifstream check(USER_FILE);
        if (!check.good()) {
            file.open(USER_FILE, std::ios::app);
            file.close();
        }
        check.close();
        
        // Check and create transactions.txt
        check.open(TRANSACTION_FILE);
        if (!check.good()) {
            file.open(TRANSACTION_FILE, std::ios::app);
            file.close();
        }
        check.close();
        
        // Check and create blocked.txt
        check.open(BLOCKED_FILE);
        if (!check.good()) {
            file.open(BLOCKED_FILE, std::ios::app);
            file.close();
        }
        check.close();
    }
    
    // Save user account to file
    bool saveUserAccount(const CommonUser::Account& account) {
        std::ofstream file(USER_FILE, std::ios::app);
        if (!file.is_open()) {
            std::cout << "Error opening user file!" << std::endl;
            return false;
        }
        
        file << account.accountNumber << "|" 
             << account.pin << "|" 
             << account.balance << "|" 
             << account.name << std::endl;
        
        file.close();
        return true;
    }
    
    // Read user account from file
    CommonUser::Account readUserAccount(int accountNumber) {
        CommonUser::Account account;
        account.accountNumber = -1; // Invalid by default
        
        std::ifstream file(USER_FILE);
        if (!file.is_open()) {
            std::cout << "Error opening user file!" << std::endl;
            return account;
        }
        
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int accNum, pin;
            double balance;
            std::string name;
            char delimiter;
            
            iss >> accNum >> delimiter >> pin >> delimiter >> balance >> delimiter;
            std::getline(iss, name);
            
            if (accNum == accountNumber) {
                account.accountNumber = accNum;
                account.pin = pin;
                account.balance = balance;
                account.name = name;
                break;
            }
        }
        
        file.close();
        return account;
    }
    
    // Check if user account exists
    bool userAccountExists(int accountNumber) {
        CommonUser::Account account = readUserAccount(accountNumber);
        return account.accountNumber != -1;
    }
    
    // Update user account in file
    bool updateUserAccount(const CommonUser::Account& account) {
        std::ifstream inputFile(USER_FILE);
        std::ofstream tempFile("temp_users.txt");
        
        if (!inputFile.is_open() || !tempFile.is_open()) {
            std::cout << "Error opening files!" << std::endl;
            return false;
        }
        
        std::string line;
        bool found = false;
        
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            int accNum;
            iss >> accNum;
            
            if (accNum == account.accountNumber) {
                tempFile << account.accountNumber << "|" 
                        << account.pin << "|" 
                        << account.balance << "|" 
                        << account.name << std::endl;
                found = true;
            } else {
                tempFile << line << std::endl;
            }
        }
        
        inputFile.close();
        tempFile.close();
        
        if (found) {
            remove(USER_FILE);
            rename("temp_users.txt", USER_FILE);
            return true;
        }
        
        remove("temp_users.txt");
        return false;
    }
    
    // Get all user accounts
    std::vector<CommonUser::Account> getAllUserAccounts() {
        std::vector<CommonUser::Account> accounts;
        std::ifstream file(USER_FILE);
        
        if (!file.is_open()) {
            std::cout << "Error opening user file!" << std::endl;
            return accounts;
        }
        
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;
            
            std::istringstream iss(line);
            int accNum, pin;
            double balance;
            std::string name;
            char delimiter;
            
            iss >> accNum >> delimiter >> pin >> delimiter >> balance >> delimiter;
            std::getline(iss, name);
            
            CommonUser::Account account;
            account.accountNumber = accNum;
            account.pin = pin;
            account.balance = balance;
            account.name = name;
            
            accounts.push_back(account);
        }
        
        file.close();
        return accounts;
    }
    
    // Delete user account
    bool deleteUserAccount(int accountNumber) {
        std::ifstream inputFile(USER_FILE);
        std::ofstream tempFile("temp_users.txt");
        
        if (!inputFile.is_open() || !tempFile.is_open()) {
            std::cout << "Error opening files!" << std::endl;
            return false;
        }
        
        std::string line;
        bool found = false;
        
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            int accNum;
            iss >> accNum;
            
            if (accNum == accountNumber) {
                found = true;
            } else {
                tempFile << line << std::endl;
            }
        }
        
        inputFile.close();
        tempFile.close();
        
        if (found) {
            remove(USER_FILE);
            rename("temp_users.txt", USER_FILE);
            return true;
        }
        
        remove("temp_users.txt");
        return false;
    }
    
    // Log transaction to file
    void logTransaction(int accountNumber, std::string transactionType, double amount) {
        std::ofstream file(TRANSACTION_FILE, std::ios::app);
        if (!file.is_open()) {
            std::cout << "Error opening transaction file!" << std::endl;
            return;
        }
        
        time_t now = time(0);
        struct tm* timeinfo = localtime(&now);
        char timeStr[100];
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", timeinfo);
        
        file << accountNumber << "|" 
             << transactionType << "|" 
             << amount << "|" 
             << timeStr << std::endl;
        
        file.close();
    }
    
    // View transaction log for account
    void viewTransactionLog(int accountNumber) {
        std::ifstream file(TRANSACTION_FILE);
        if (!file.is_open()) {
            std::cout << "Error opening transaction file!" << std::endl;
            return;
        }
        
        std::cout << "\n========== Transaction History ==========" << std::endl;
        std::string line;
        bool found = false;
        
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int accNum;
            iss >> accNum;
            
            if (accNum == accountNumber) {
                std::cout << line << std::endl;
                found = true;
            }
        }
        
        if (!found) {
            std::cout << "No transactions found." << std::endl;
        }
        
        std::cout << "========================================" << std::endl;
        file.close();
    }
    
    // Save admin account
    bool saveAdminAccount(const AdminUser::AdminAccount& admin) {
        std::ofstream file(ADMIN_FILE, std::ios::app);
        if (!file.is_open()) {
            std::cout << "Error opening admin file!" << std::endl;
            return false;
        }
        
        file << admin.adminId << "|" 
             << admin.adminPassword << "|" 
             << admin.adminName << std::endl;
        
        file.close();
        return true;
    }
    
    // Read admin account
    AdminUser::AdminAccount readAdminAccount(int adminId) {
        AdminUser::AdminAccount admin;
        admin.adminId = -1; // Invalid by default
        
        std::ifstream file(ADMIN_FILE);
        if (!file.is_open()) {
            std::cout << "Error opening admin file!" << std::endl;
            return admin;
        }
        
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int id;
            std::string password, name;
            char delimiter;
            
            iss >> id >> delimiter;
            std::getline(iss, password, '|');
            std::getline(iss, name);
            
            if (id == adminId) {
                admin.adminId = id;
                admin.adminPassword = password;
                admin.adminName = name;
                break;
            }
        }
        
        file.close();
        return admin;
    }
    
    // Check if account is blocked
    bool isAccountBlocked(int accountNumber) {
        std::ifstream file(BLOCKED_FILE);
        if (!file.is_open()) {
            return false;
        }
        
        std::string line;
        while (std::getline(file, line)) {
            if (std::stoi(line) == accountNumber) {
                file.close();
                return true;
            }
        }
        
        file.close();
        return false;
    }
    
    // Block account
    void blockAccount(int accountNumber) {
        std::ofstream file(BLOCKED_FILE, std::ios::app);
        if (!file.is_open()) {
            std::cout << "Error opening blocked accounts file!" << std::endl;
            return;
        }
        
        file << accountNumber << std::endl;
        file.close();
        std::cout << "Account " << accountNumber << " has been blocked." << std::endl;
    }
    
    // Unblock account
    void unblockAccount(int accountNumber) {
        std::ifstream inputFile(BLOCKED_FILE);
        std::ofstream tempFile("temp_blocked.txt");
        
        if (!inputFile.is_open() || !tempFile.is_open()) {
            std::cout << "Error opening files!" << std::endl;
            return;
        }
        
        std::string line;
        bool found = false;
        
        while (std::getline(inputFile, line)) {
            if (std::stoi(line) != accountNumber) {
                tempFile << line << std::endl;
            } else {
                found = true;
            }
        }
        
        inputFile.close();
        tempFile.close();
        
        if (found) {
            remove(BLOCKED_FILE);
            rename("temp_blocked.txt", BLOCKED_FILE);
            std::cout << "Account " << accountNumber << " has been unblocked." << std::endl;
        } else {
            remove("temp_blocked.txt");
        }
    }
}
