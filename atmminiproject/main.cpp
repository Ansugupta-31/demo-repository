#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "common.h"
#include "admin.h"
#include "filehandler.h"

// Main menu display
void displayMainMenu() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║          ATM MINI PROJECT SYSTEM           ║" << std::endl;
    std::cout << "║                                            ║" << std::endl;
    std::cout << "║  1. Common User Login                      ║" << std::endl;
    std::cout << "║  2. Admin Login                            ║" << std::endl;
    std::cout << "║  3. Exit                                   ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    std::cout << "Enter your choice: ";
}

// Common user menu
void displayCommonUserMenu() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║         COMMON USER MENU                   ║" << std::endl;
    std::cout << "║                                            ║" << std::endl;
    std::cout << "║  1. Check Balance                          ║" << std::endl;
    std::cout << "║  2. Withdraw Money                         ║" << std::endl;
    std::cout << "║  3. Deposit Money                          ║" << std::endl;
    std::cout << "║  4. Transfer Money                         ║" << std::endl;
    std::cout << "║  5. View Transaction History               ║" << std::endl;
    std::cout << "║  6. Change PIN                             ║" << std::endl;
    std::cout << "║  7. Logout                                 ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    std::cout << "Enter your choice: ";
}

// Admin menu
void displayAdminMenu() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║           ADMIN USER MENU                  ║" << std::endl;
    std::cout << "║                                            ║" << std::endl;
    std::cout << "║  1. View All Accounts                      ║" << std::endl;
    std::cout << "║  2. View Specific Account                  ║" << std::endl;
    std::cout << "║  3. Create New Account                     ║" << std::endl;
    std::cout << "║  4. Delete Account                         ║" << std::endl;
    std::cout << "║  5. Block Account                          ║" << std::endl;
    std::cout << "║  6. Unblock Account                        ║" << std::endl;
    std::cout << "║  7. View Transaction Log                   ║" << std::endl;
    std::cout << "║  8. Generate Report                        ║" << std::endl;
    std::cout << "║  9. Logout                                 ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    std::cout << "Enter your choice: ";
}

// Common user workflow
void commonUserWorkflow(int accountNumber) {
    int choice;
    bool logout = false;
    
    while (!logout) {
        displayCommonUserMenu();
        std::cin >> choice;
        std::cin.ignore();
        
        switch (choice) {
            case 1: {
                // Check balance
                CommonUser::checkBalance(accountNumber);
                break;
            }
            case 2: {
                // Withdraw money
                double amount;
                std::cout << "\nEnter amount to withdraw: Rs. ";
                std::cin >> amount;
                std::cin.ignore();
                CommonUser::withdraw(accountNumber, amount);
                break;
            }
            case 3: {
                // Deposit money
                double amount;
                std::cout << "\nEnter amount to deposit: Rs. ";
                std::cin >> amount;
                std::cin.ignore();
                CommonUser::deposit(accountNumber, amount);
                break;
            }
            case 4: {
                // Transfer money
                int toAccount;
                double amount;
                std::cout << "\nEnter recipient account number: ";
                std::cin >> toAccount;
                std::cout << "Enter amount to transfer: Rs. ";
                std::cin >> amount;
                std::cin.ignore();
                CommonUser::transfer(accountNumber, toAccount, amount);
                break;
            }
            case 5: {
                // View transaction history
                CommonUser::viewTransactionHistory(accountNumber);
                break;
            }
            case 6: {
                // Change PIN
                int oldPin, newPin;
                std::cout << "\nEnter old PIN: ";
                std::cin >> oldPin;
                std::cout << "Enter new PIN (4 digits): ";
                std::cin >> newPin;
                std::cin.ignore();
                CommonUser::changePin(accountNumber, oldPin, newPin);
                break;
            }
            case 7: {
                // Logout
                std::cout << "\nThank you for using ATM. Goodbye!" << std::endl;
                logout = true;
                break;
            }
            default: {
                std::cout << "\nInvalid choice! Please try again." << std::endl;
                break;
            }
        }
    }
}

// Admin user workflow
void adminUserWorkflow() {
    int choice;
    bool logout = false;
    
    while (!logout) {
        displayAdminMenu();
        std::cin >> choice;
        std::cin.ignore();
        
        switch (choice) {
            case 1: {
                // View all accounts
                AdminUser::viewAllAccounts();
                break;
            }
            case 2: {
                // View specific account
                int accountNumber;
                std::cout << "\nEnter account number: ";
                std::cin >> accountNumber;
                std::cin.ignore();
                AdminUser::viewUserAccount(accountNumber);
                break;
            }
            case 3: {
                // Create new account
                int accountNumber, pin;
                double initialBalance;
                std::string name;
                
                std::cout << "\nEnter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter PIN (4 digits): ";
                std::cin >> pin;
                std::cout << "Enter initial balance: Rs. ";
                std::cin >> initialBalance;
                std::cin.ignore();
                std::cout << "Enter account holder name: ";
                std::getline(std::cin, name);
                
                AdminUser::createNewAccount(accountNumber, pin, initialBalance, name);
                break;
            }
            case 4: {
                // Delete account
                int accountNumber;
                std::cout << "\nEnter account number to delete: ";
                std::cin >> accountNumber;
                std::cin.ignore();
                AdminUser::deleteAccount(accountNumber);
                break;
            }
            case 5: {
                // Block account
                int accountNumber;
                std::cout << "\nEnter account number to block: ";
                std::cin >> accountNumber;
                std::cin.ignore();
                AdminUser::blockAccount(accountNumber);
                break;
            }
            case 6: {
                // Unblock account
                int accountNumber;
                std::cout << "\nEnter account number to unblock: ";
                std::cin >> accountNumber;
                std::cin.ignore();
                AdminUser::unblockAccount(accountNumber);
                break;
            }
            case 7: {
                // View transaction log
                AdminUser::viewTransactionLog();
                break;
            }
            case 8: {
                // Generate report
                AdminUser::generateReport();
                break;
            }
            case 9: {
                // Logout
                std::cout << "\nAdmin logged out. Goodbye!" << std::endl;
                logout = true;
                break;
            }
            default: {
                std::cout << "\nInvalid choice! Please try again." << std::endl;
                break;
            }
        }
    }
}

// Initialize demo data
void initializeDemoData() {
    // Create sample user accounts if they don't exist
    if (!FileHandler::userAccountExists(1001)) {
        CommonUser::Account acc1;
        acc1.accountNumber = 1001;
        acc1.pin = 1234;
        acc1.balance = 50000.0;
        acc1.name = "Ansu Kumar";
        FileHandler::saveUserAccount(acc1);
    }
    
    if (!FileHandler::userAccountExists(1002)) {
        CommonUser::Account acc2;
        acc2.accountNumber = 1002;
        acc2.pin = 5678;
        acc2.balance = 75000.0;
        acc2.name = "Priya Singh";
        FileHandler::saveUserAccount(acc2);
    }
    
    if (!FileHandler::userAccountExists(1003)) {
        CommonUser::Account acc3;
        acc3.accountNumber = 1003;
        acc3.pin = 9012;
        acc3.balance = 100000.0;
        acc3.name = "Rajesh Patel";
        FileHandler::saveUserAccount(acc3);
    }
    
    // Create sample admin account if it doesn't exist
    std::ifstream adminCheck("admin.txt");
    if (!adminCheck.good() || adminCheck.peek() == std::ifstream::traits_type::eof()) {
        AdminUser::AdminAccount admin;
        admin.adminId = 101;
        admin.adminPassword = "admin123";
        admin.adminName = "System Administrator";
        FileHandler::saveAdminAccount(admin);
    }
    adminCheck.close();
}

// Main function
int main() {
    // Initialize files
    FileHandler::initializeFiles();
    
    // Initialize demo data
    initializeDemoData();
    
    int mainChoice;
    bool exit_program = false;
    
    std::cout << "\n╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║      WELCOME TO ATM MINI PROJECT           ║" << std::endl;
    std::cout << "║                                            ║" << std::endl;
    std::cout << "║  Demo Accounts:                            ║" << std::endl;
    std::cout << "║  Account 1001 | PIN: 1234                  ║" << std::endl;
    std::cout << "║  Account 1002 | PIN: 5678                  ║" << std::endl;
    std::cout << "║  Account 1003 | PIN: 9012                  ║" << std::endl;
    std::cout << "║                                            ║" << std::endl;
    std::cout << "║  Admin Account:                            ║" << std::endl;
    std::cout << "║  Admin ID: 101 | Password: admin123        ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    
    while (!exit_program) {
        displayMainMenu();
        std::cin >> mainChoice;
        std::cin.ignore();
        
        switch (mainChoice) {
            case 1: {
                // Common User Login
                int accountNumber, pin;
                std::cout << "\n========== COMMON USER LOGIN ==========" << std::endl;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter PIN: ";
                std::cin >> pin;
                std::cin.ignore();
                
                if (CommonUser::login(accountNumber, pin)) {
                    commonUserWorkflow(accountNumber);
                }
                break;
            }
            case 2: {
                // Admin Login
                int adminId;
                std::string password;
                std::cout << "\n========== ADMIN LOGIN ==========" << std::endl;
                std::cout << "Enter admin ID: ";
                std::cin >> adminId;
                std::cin.ignore();
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
                
                if (AdminUser::adminLogin(adminId, password)) {
                    adminUserWorkflow();
                }
                break;
            }
            case 3: {
                // Exit
                std::cout << "\nThank you for using ATM Mini Project System!" << std::endl;
                std::cout << "Please take your card. Goodbye!" << std::endl;
                exit_program = true;
                break;
            }
            default: {
                std::cout << "\nInvalid choice! Please try again." << std::endl;
                break;
            }
        }
    }
    
    return 0;
}
