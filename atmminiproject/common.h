#ifndef COMMON_H
#define COMMON_H

#include <string>

namespace CommonUser {
    
    struct Account {
        int accountNumber;
        int pin;
        double balance;
        std::string name;
    };
    
    // Function declarations for common user operations
    bool login(int accountNumber, int pin);
    void checkBalance(int accountNumber);
    void withdraw(int accountNumber, double amount);
    void deposit(int accountNumber, double amount);
    void transfer(int fromAccount, int toAccount, double amount);
    void viewTransactionHistory(int accountNumber);
    void changePin(int accountNumber, int oldPin, int newPin);
    Account getAccountDetails(int accountNumber);
    
}

#endif
