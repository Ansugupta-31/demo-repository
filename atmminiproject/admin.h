#ifndef ADMIN_H
#define ADMIN_H

#include <string>

namespace AdminUser {
    
    struct AdminAccount {
        int adminId;
        std::string adminPassword;
        std::string adminName;
    };
    
    // Function declarations for admin operations
    bool adminLogin(int adminId, std::string password);
    void viewAllAccounts();
    void viewUserAccount(int accountNumber);
    void createNewAccount(int accountNumber, int pin, double initialBalance, std::string name);
    void deleteAccount(int accountNumber);
    void blockAccount(int accountNumber);
    void unblockAccount(int accountNumber);
    void viewTransactionLog();
    void generateReport();
    
}

#endif
