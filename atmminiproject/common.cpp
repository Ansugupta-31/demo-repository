#include "common.h"
#include "filehandler.h"
#include <iostream>
#include <iomanip>

namespace CommonUser {
    
    // Login function
    bool login(int accountNumber, int pin) {
        if (FileHandler::isAccountBlocked(accountNumber)) {
            std::cout << "\nError: This account is blocked!" << std::endl;
            return false;
        }
        
        Account account = FileHandler::readUserAccount(accountNumber);
        
        if (account.accountNumber == -1) {
            std::cout << "\nError: Account not found!" << std::endl;
            return false;
        }
        
        if (account.pin == pin) {
            std::cout << "\nLogin successful! Welcome, " << account.name << std::endl;
            return true;
        } else {
            std::cout << "\nError: Incorrect PIN!" << std::endl;
            return false;
        }
    }
    
    // Check balance
    void checkBalance(int accountNumber) {
        Account account = FileHandler::readUserAccount(accountNumber);
        
        if (account.accountNumber == -1) {
            std::cout << "\nError: Account not found!" << std::endl;
            return;
        }
        
        std::cout << "\n========== Account Balance ==========" << std::endl;
        std::cout << "Account Number: " << account.accountNumber << std::endl;
        std::cout << "Account Holder: " << account.name << std::endl;
        std::cout << "Current Balance: Rs. " << std::fixed << std::setprecision(2) 
                  << account.balance << std::endl;
        std::cout << "=====================================" << std::endl;
    }
    
    // Withdraw money
    void withdraw(int accountNumber, double amount) {
        if (amount <= 0) {
            std::cout << "\nError: Invalid amount!" << std::endl;
            return;
        }
        
        Account account = FileHandler::readUserAccount(accountNumber);
        
        if (account.accountNumber == -1) {
            std::cout << "\nError: Account not found!" << std::endl;
            return;
        }
        
        if (amount > account.balance) {
            std::cout << "\nError: Insufficient balance!" << std::endl;
            std::cout << "Available Balance: Rs. " << std::fixed << std::setprecision(2) 
                      << account.balance << std::endl;
            return;
        }
        
        account.balance -= amount;
        FileHandler::updateUserAccount(account);
        FileHandler::logTransaction(accountNumber, "WITHDRAW", amount);
        
        std::cout << "\n========== Withdrawal Successful ==========" << std::endl;
        std::cout << "Amount Withdrawn: Rs. " << std::fixed << std::setprecision(2) 
                  << amount << std::endl;
        std::cout << "Remaining Balance: Rs. " << account.balance << std::endl;
        std::cout << "===========================================" << std::endl;
    }
    
    // Deposit money
    void deposit(int accountNumber, double amount) {
        if (amount <= 0) {
            std::cout << "\nError: Invalid amount!" << std::endl;
            return;
        }
        
        Account account = FileHandler::readUserAccount(accountNumber);
        
        if (account.accountNumber == -1) {
            std::cout << "\nError: Account not found!" << std::endl;
            return;
        }
        
        account.balance += amount;
        FileHandler::updateUserAccount(account);
        FileHandler::logTransaction(accountNumber, "DEPOSIT", amount);
        
        std::cout << "\n========== Deposit Successful ==========" << std::endl;
        std::cout << "Amount Deposited: Rs. " << std::fixed << std::setprecision(2) 
                  << amount << std::endl;
        std::cout << "New Balance: Rs. " << account.balance << std::endl;
        std::cout << "========================================" << std::endl;
    }
    
    // Transfer money to another account
    void transfer(int fromAccount, int toAccount, double amount) {
        if (amount <= 0) {
            std::cout << "\nError: Invalid amount!" << std::endl;
            return;
        }
        
        if (fromAccount == toAccount) {
            std::cout << "\nError: Cannot transfer to the same account!" << std::endl;
            return;
        }
        
        Account sender = FileHandler::readUserAccount(fromAccount);
        Account receiver = FileHandler::readUserAccount(toAccount);
        
        if (sender.accountNumber == -1) {
            std::cout << "\nError: Sender account not found!" << std::endl;
            return;
        }
        
        if (receiver.accountNumber == -1) {
            std::cout << "\nError: Receiver account not found!" << std::endl;
            return;
        }
        
        if (amount > sender.balance) {
            std::cout << "\nError: Insufficient balance!" << std::endl;
            return;
        }
        
        sender.balance -= amount;
        receiver.balance += amount;
        
        FileHandler::updateUserAccount(sender);
        FileHandler::updateUserAccount(receiver);
        
        FileHandler::logTransaction(fromAccount, "TRANSFER_OUT", amount);
        FileHandler::logTransaction(toAccount, "TRANSFER_IN", amount);
        
        std::cout << "\n========== Transfer Successful ==========" << std::endl;
        std::cout << "Amount Transferred: Rs. " << std::fixed << std::setprecision(2) 
                  << amount << std::endl;
        std::cout << "To Account: " << toAccount << std::endl;
        std::cout << "Your New Balance: Rs. " << sender.balance << std::endl;
        std::cout << "==========================================" << std::endl;
    }
    
    // View transaction history
    void viewTransactionHistory(int accountNumber) {
        FileHandler::viewTransactionLog(accountNumber);
    }
    
    // Change PIN
    void changePin(int accountNumber, int oldPin, int newPin) {
        Account account = FileHandler::readUserAccount(accountNumber);
        
        if (account.accountNumber == -1) {
            std::cout << "\nError: Account not found!" << std::endl;
            return;
        }
        
        if (account.pin != oldPin) {
            std::cout << "\nError: Incorrect old PIN!" << std::endl;
            return;
        }
        
        if (newPin <= 999 || newPin > 9999) {
            std::cout << "\nError: PIN should be 4 digits!" << std::endl;
            return;
        }
        
        account.pin = newPin;
        FileHandler::updateUserAccount(account);
        
        std::cout << "\n========== PIN Changed Successfully ==========" << std::endl;
        std::cout << "Your new PIN has been set." << std::endl;
        std::cout << "=============================================" << std::endl;
    }
    
    // Get account details
    Account getAccountDetails(int accountNumber) {
        return FileHandler::readUserAccount(accountNumber);
    }
}
