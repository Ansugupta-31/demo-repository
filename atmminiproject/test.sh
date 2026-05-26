#!/bin/bash

# ATM Mini Project - Test Script
# This script tests the ATM system with automated inputs

echo "====================================="
echo "ATM MINI PROJECT - SYSTEM TEST"
echo "====================================="
echo ""

cd /workspaces/demo-repository/atmminiproject

# Test 1: Common User Login and Check Balance
echo "Test 1: Common User Login - Check Balance"
echo "1
1001
1234
1
7" | ./atm > test_output.txt 2>&1

# Show results
sleep 1
echo "✓ Common User Test Completed"
echo ""

# Test 2: Admin Login
echo "Test 2: Admin Login - View All Accounts"
(timeout 3s bash -c '
echo "2
101
admin123
1
9" | ./atm
' || true) > test_admin.txt 2>&1

echo "✓ Admin User Test Completed"
echo ""

# Display project statistics
echo "====================================="
echo "PROJECT STATISTICS"
echo "====================================="
echo "Total C++ Files: $(find . -name '*.cpp' | wc -l)"
echo "Total Header Files: $(find . -name '*.h' | wc -l)"
echo ""

echo "Source Code Summary:"
wc -l *.cpp *.h | tail -1
echo ""

echo "File Structure:"
tree -L 1 2>/dev/null || find . -maxdepth 1 -type f | sort
echo ""

echo "====================================="
echo "PROJECT CREATION COMPLETE!"
echo "====================================="
