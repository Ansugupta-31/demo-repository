#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
#include "common.h"
#include "admin.h"

namespace FileHandler {
    
    // User data file operations
    bool saveUserAccount(const CommonUser::Account& account);
    bool updateUserAccount(const CommonUser::Account& account);
    CommonUser::Account readUserAccount(int accountNumber);
    bool userAccountExists(int accountNumber);
    std::vector<CommonUser::Account> getAllUserAccounts();
    bool deleteUserAccount(int accountNumber);
    
    // Transaction logging
    void logTransaction(int accountNumber, std::string transactionType, double amount);
    void viewTransactionLog(int accountNumber);
    
    // Admin data operations
    bool saveAdminAccount(const AdminUser::AdminAccount& admin);
    AdminUser::AdminAccount readAdminAccount(int adminId);
    
    // Utility functions
    void initializeFiles();
    bool isAccountBlocked(int accountNumber);
    void blockAccount(int accountNumber);
    void unblockAccount(int accountNumber);
    
}

#endif
