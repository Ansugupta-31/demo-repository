# ATM Mini Project

A complete ATM system simulation built in C++ using procedural programming, namespaces, and file handling.

## Project Overview

This project implements a realistic ATM workflow with two types of users:
- **Common Users**: Can perform banking operations like withdrawal, deposit, transfer, etc.
- **Admin Users**: Can manage user accounts, view transaction logs, and generate reports.

## Features

### Common User Features
- ✅ Account Login with PIN authentication
- ✅ Check Balance
- ✅ Withdraw Money
- ✅ Deposit Money
- ✅ Transfer Money to Another Account
- ✅ View Transaction History
- ✅ Change PIN

### Admin User Features
- ✅ Admin Login with credentials
- ✅ View All User Accounts
- ✅ View Specific Account Details
- ✅ Create New Account
- ✅ Delete Account
- ✅ Block/Unblock Account
- ✅ View Transaction Log
- ✅ Generate System Report

## File Structure

```
atmminiproject/
├── main.cpp           # Main program with ATM workflow menu
├── common.h          # Header file for common user operations
├── common.cpp        # Implementation of common user functions
├── admin.h           # Header file for admin operations
├── admin.cpp         # Implementation of admin functions
├── filehandler.h     # Header file for file operations
├── filehandler.cpp   # Implementation of file handling
├── Makefile          # Build configuration
├── README.md         # This file
└── Data Files (created at runtime):
    ├── users.txt              # Stores user account data
    ├── admin.txt              # Stores admin account data
    ├── transactions.txt       # Stores transaction logs
    └── blocked.txt            # Stores blocked accounts
```

## Programming Concepts Used

### 1. **Procedural Programming**
   - All code organized as functions within namespaces
   - No object-oriented design (no classes or objects)
   - Direct procedural function calls

### 2. **Namespaces**
   - `CommonUser`: Contains all common user operations
   - `AdminUser`: Contains all admin operations
   - `FileHandler`: Contains all file I/O operations
   - Prevents naming conflicts and organizes code logically

### 3. **File Handling**
   - User account data persisted in `users.txt`
   - Admin credentials stored in `admin.txt`
   - Transaction history in `transactions.txt`
   - Blocked accounts tracked in `blocked.txt`
   - Data format: pipe-delimited (`|`) for easy parsing

### 4. **Data Structures**
   - `CommonUser::Account`: Stores account information (account number, PIN, balance, name)
   - `AdminUser::AdminAccount`: Stores admin information (admin ID, password, name)

## Compilation & Execution

### Prerequisites
- C++ compiler (g++ or clang++)
- Make utility
- Linux/Unix environment (or Windows with WSL/MinGW)

### Build Instructions

```bash
# Navigate to project directory
cd atmminiproject

# Clean any previous builds
make clean

# Build the project
make

# Run the application
make run

# Or run directly
./atm
```

### Manual Compilation
```bash
g++ -std=c++11 -o atm main.cpp common.cpp admin.cpp filehandler.cpp
./atm
```

## Demo Accounts

The system comes pre-populated with demo accounts:

### Common User Accounts:
| Account Number | PIN  | Initial Balance | Name          |
|---------------|------|-----------------|---------------|
| 1001          | 1234 | Rs. 50,000      | Ansu Kumar    |
| 1002          | 5678 | Rs. 75,000      | Priya Singh   |
| 1003          | 9012 | Rs. 100,000     | Rajesh Patel  |

### Admin Account:
| Admin ID | Password  | Name                |
|----------|-----------|---------------------|
| 101      | admin123  | System Administrator|

## Usage Examples

### Common User Workflow
```
1. Launch the program: ./atm
2. Select "1. Common User Login"
3. Enter Account Number: 1001
4. Enter PIN: 1234
5. Choose operations from the menu
```

### Admin Workflow
```
1. Launch the program: ./atm
2. Select "2. Admin Login"
3. Enter Admin ID: 101
4. Enter Password: admin123
5. Manage accounts and view reports
```

## Data Persistence

All user data is automatically saved to files:

### users.txt Format
```
accountNumber|PIN|balance|accountHolderName
1001|1234|50000|Ansu Kumar
1002|5678|75000|Priya Singh
```

### transactions.txt Format
```
accountNumber|transactionType|amount|timestamp
1001|WITHDRAW|5000|2024-05-26 14:30:45
1002|DEPOSIT|10000|2024-05-26 14:35:22
```

### admin.txt Format
```
adminID|password|adminName
101|admin123|System Administrator
```

## Code Organization

### Common User Namespace (`common.h/cpp`)
- `login()`: Authenticate user with PIN
- `checkBalance()`: Display account balance
- `withdraw()`: Remove money from account
- `deposit()`: Add money to account
- `transfer()`: Transfer money between accounts
- `viewTransactionHistory()`: Display transaction records
- `changePin()`: Update account PIN
- `getAccountDetails()`: Retrieve account information

### Admin Namespace (`admin.h/cpp`)
- `adminLogin()`: Authenticate admin
- `viewAllAccounts()`: Display all user accounts
- `viewUserAccount()`: Display specific account details
- `createNewAccount()`: Create new user account
- `deleteAccount()`: Remove user account
- `blockAccount()`: Restrict account access
- `unblockAccount()`: Restore account access
- `viewTransactionLog()`: Display all transactions
- `generateReport()`: Generate system statistics

### FileHandler Namespace (`filehandler.h/cpp`)
- `saveUserAccount()`: Store user account to file
- `readUserAccount()`: Retrieve user account from file
- `updateUserAccount()`: Modify existing account record
- `getAllUserAccounts()`: Fetch all accounts
- `deleteUserAccount()`: Remove account from file
- `logTransaction()`: Record transaction with timestamp
- `viewTransactionLog()`: Display transaction history
- `isAccountBlocked()`: Check blocked status
- `blockAccount()`: Add account to blocked list
- `unblockAccount()`: Remove from blocked list

## Security Features

1. **PIN Authentication**: 4-digit PIN required for common users
2. **Account Blocking**: Admin can block suspicious accounts
3. **Transaction Logging**: All transactions are recorded with timestamps
4. **Data Validation**: 
   - Amount validation (must be positive)
   - Balance verification before transactions
   - Account existence checks

## Error Handling

The system handles various error conditions:
- Invalid account numbers
- Incorrect PIN/Password
- Insufficient balance for withdrawal
- Blocked accounts
- Duplicate account creation
- Invalid amount values

## Future Enhancements

Potential improvements to the system:
- [ ] Database integration (SQLite/MySQL)
- [ ] Encryption for stored credentials
- [ ] Multi-threaded support for concurrent users
- [ ] Mobile check deposit feature
- [ ] Loan management system
- [ ] Investment portfolio management
- [ ] Email notifications for transactions
- [ ] Dashboard with charts and analytics

## Technical Details

- **Language**: C++ (C++11 standard)
- **Paradigm**: Procedural Programming
- **File Format**: Plain text with pipe delimiters
- **Compilation**: Standard g++ compiler
- **Platform**: Cross-platform (Linux/Unix/Windows with WSL)

## Notes

- Data files are created automatically in the project directory
- To reset the system, delete the `.txt` files and rebuild
- The system uses local time for transaction timestamps
- All monetary amounts are treated as floating-point numbers

## License

This is a mini project for educational purposes.

## Author

Created as an ATM Mini Project demonstration

---

**For any issues or suggestions, please feel free to modify and extend the project!**
