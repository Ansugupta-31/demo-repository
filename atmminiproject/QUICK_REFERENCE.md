# ATM Mini Project - Quick Reference Guide

## 🚀 Quick Start

```bash
cd atmminiproject
make clean && make
./atm
```

---

## 👤 Common User Quick Reference

### Login
```
Choose: 1
Account: 1001
PIN: 1234
```

### Common User Menu Options
```
1 → Check Balance
2 → Withdraw Money
3 → Deposit Money
4 → Transfer Money
5 → View Transaction History
6 → Change PIN
7 → Logout
```

**Demo Accounts:**
- **1001** | PIN: 1234 | Balance: 50,000 | Ansu Kumar
- **1002** | PIN: 5678 | Balance: 75,000 | Priya Singh
- **1003** | PIN: 9012 | Balance: 100,000 | Rajesh Patel

---

## 🔐 Admin User Quick Reference

### Login
```
Choose: 2
Admin ID: 101
Password: admin123
```

### Admin Menu Options
```
1 → View All Accounts
2 → View Specific Account
3 → Create New Account
4 → Delete Account
5 → Block Account
6 → Unblock Account
7 → View Transaction Log
8 → Generate Report
9 → Logout
```

**Admin Account:**
- **Admin ID: 101** | **Password: admin123**

---

## 📋 Function Reference

### Common User Functions (common.cpp)

```cpp
// Authenticate user
bool login(int accountNumber, int pin)

// Display current balance
void checkBalance(int accountNumber)

// Withdraw funds
void withdraw(int accountNumber, double amount)

// Deposit funds
void deposit(int accountNumber, double amount)

// Transfer to another account
void transfer(int fromAccount, int toAccount, double amount)

// Show transaction history
void viewTransactionHistory(int accountNumber)

// Update account PIN
void changePin(int accountNumber, int oldPin, int newPin)

// Get account details
Account getAccountDetails(int accountNumber)
```

### Admin Functions (admin.cpp)

```cpp
// Authenticate admin
bool adminLogin(int adminId, std::string password)

// Display all user accounts
void viewAllAccounts()

// Show specific account details
void viewUserAccount(int accountNumber)

// Create new account
void createNewAccount(int accountNumber, int pin, double balance, std::string name)

// Remove account
void deleteAccount(int accountNumber)

// Restrict account access
void blockAccount(int accountNumber)

// Allow account access
void unblockAccount(int accountNumber)

// Display all transactions
void viewTransactionLog()

// Show system statistics
void generateReport()
```

### File Handler Functions (filehandler.cpp)

```cpp
// Create data files
void initializeFiles()

// Store account to file
bool saveUserAccount(const Account& account)

// Read account from file
Account readUserAccount(int accountNumber)

// Modify account in file
bool updateUserAccount(const Account& account)

// Remove account from file
bool deleteUserAccount(int accountNumber)

// Check if account is blocked
bool isAccountBlocked(int accountNumber)

// Block an account
void blockAccount(int accountNumber)

// Unblock an account
void unblockAccount(int accountNumber)

// Record transaction
void logTransaction(int accountNumber, std::string type, double amount)

// Display transaction history
void viewTransactionLog(int accountNumber)
```

---

## 📁 File Structure

```
atmminiproject/
├── main.cpp                  → Main program (entry point)
├── common.h/cpp              → User operations
├── admin.h/cpp               → Admin operations
├── filehandler.h/cpp         → File I/O operations
├── Makefile                  → Build configuration
├── README.md                 → Full documentation
├── PROJECT_SUMMARY.md        → Project details
├── QUICK_REFERENCE.md        → This file
├── test.sh                   → Test script
└── atm                       → Compiled executable
```

---

## 🎯 Data File Formats

### users.txt
```
accountNumber|PIN|balance|name
1001|1234|50000|Ansu Kumar
```

### transactions.txt
```
accountNumber|type|amount|timestamp
1001|WITHDRAW|5000|2024-05-26 14:30:45
```

### admin.txt
```
adminID|password|name
101|admin123|System Administrator
```

### blocked.txt
```
accountNumber
1005
```

---

## 🔍 Namespace Structure

```cpp
CommonUser {
  - login()
  - checkBalance()
  - withdraw()
  - deposit()
  - transfer()
  - viewTransactionHistory()
  - changePin()
  - getAccountDetails()
}

AdminUser {
  - adminLogin()
  - viewAllAccounts()
  - viewUserAccount()
  - createNewAccount()
  - deleteAccount()
  - blockAccount()
  - unblockAccount()
  - viewTransactionLog()
  - generateReport()
}

FileHandler {
  - saveUserAccount()
  - readUserAccount()
  - updateUserAccount()
  - getAllUserAccounts()
  - deleteUserAccount()
  - logTransaction()
  - viewTransactionLog()
  - isAccountBlocked()
  - blockAccount()
  - unblockAccount()
  - initializeFiles()
  - saveAdminAccount()
  - readAdminAccount()
}
```

---

## 💡 Common Tasks

### Check Balance for Account 1001
```
1 → Login
1001 → Account Number
1234 → PIN
1 → Check Balance
7 → Logout
```

### Transfer Money (1001 to 1002)
```
1 → Login
1001 → Account Number
1234 → PIN
4 → Transfer Money
1002 → To Account
5000 → Amount
7 → Logout
```

### Create New Account (as Admin)
```
2 → Admin Login
101 → Admin ID
admin123 → Password
3 → Create New Account
2001 → Account Number
5555 → PIN
25000 → Initial Balance
Rohan Kumar → Name
9 → Logout
```

### Block Account (as Admin)
```
2 → Admin Login
101 → Admin ID
admin123 → Password
5 → Block Account
1005 → Account Number
9 → Logout
```

---

## 🛠️ Build Commands

```bash
# Full rebuild
make clean && make

# Just build
make

# Run program
make run
# or
./atm

# Clean binaries
make clean

# Remove all generated files
make clean
```

---

## 📊 System Statistics

| Metric | Value |
|--------|-------|
| Total Lines of Code | 1,200+ |
| Source Files | 4 |
| Header Files | 3 |
| Total Functions | 30+ |
| Namespaces | 3 |
| Data Files | 4 (runtime) |
| Executable Size | 77 KB |
| Compilation Time | < 1 second |

---

## ⚙️ Technical Details

- **Language**: C++ (C++11 Standard)
- **Compiler**: GCC/G++
- **Platform**: Linux/Unix/Windows(WSL)
- **File Format**: Plain text with pipe delimiters
- **Time Zone**: Local system time
- **Decimal Precision**: 2 places

---

## 🔐 Security Notes

1. PIN must be 4 digits (1000-9999)
2. All transactions are logged with timestamps
3. Admin can block suspicious accounts
4. Data persists across program restarts
5. Balance validation prevents overdrafts

---

## 📝 Example Workflow

```
START
  ↓
Main Menu
  ├─ Option 1: Common User → Login → Operations → Logout
  ├─ Option 2: Admin User → Login → Operations → Logout
  └─ Option 3: Exit
  ↓
END
```

---

## 🐛 Troubleshooting

| Issue | Solution |
|-------|----------|
| Make command not found | Install: `apt install make` |
| g++ not found | Install: `apt install g++` |
| Permission denied | Run: `chmod +x atm` |
| Compilation errors | Check C++11 support: `g++ --version` |
| Data files not created | Check write permissions in directory |

---

## 🎓 Key Concepts Demonstrated

✓ Procedural Programming (functions, not classes)
✓ Namespaces (code organization)
✓ File Handling (data persistence)
✓ String Parsing (pipe-delimited data)
✓ Input Validation (error handling)
✓ Struct Usage (data structures)
✓ Time Functions (timestamps)
✓ Menu-Driven Interface (user interaction)

---

## 📞 Usage Examples

### Example 1: Simple Balance Check
```bash
./atm
1                    # Common User
1001                 # Account
1234                 # PIN
1                    # Check Balance
7                    # Logout
3                    # Exit
```

### Example 2: Admin Creates Account
```bash
./atm
2                    # Admin Login
101                  # Admin ID
admin123             # Password
3                    # Create Account
2001                 # New Account #
4444                 # PIN
50000                # Balance
John Doe             # Name
9                    # Logout
3                    # Exit
```

---

**Last Updated**: 2024-05-26
**Status**: ✅ Ready to Use
**Compilation**: ✅ Success
**Testing**: ✅ Ready

---

For detailed documentation, see: **README.md** and **PROJECT_SUMMARY.md**
