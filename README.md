# Bank Management System
---
**St. Mary's University**

*Programming Fundamentals Course - C++ Project*

![Console Interface Demo](https://via.placeholder.com/800x400?text=Bank+Management+System+Console+Demo)

---

## 👥 Team Members
| Name | ID | GitHub |
|------|----|--------|
| Eyuel Esubalew | RCD/1690/2017 | [@eyuele](https://github.com/eyuele) |
| Birhanemedin Mulat | RCD/0242/2017 | [@BMACode](https://github.com/BMACode) |
| Kidus Anteneh | RCD/0264/2017 | [@kidusantenehalemu](https://github.com/kidusantenehalemu) |
| Akbari Girma | RCD/0235/2017 | [@Akbari-Girma](https://github.com/Akbari-Girma) |
| Amanuel Asefa | RCD/0236/2017 | [@amanueA](https://github.com/amanueA) |
| Abenezer Getachew | RCD/0230/2017 | [@Abeniw](https://github.com/Abeniw) |
| Isayas Tefera | RCD/1832/2017 | [@IsayasT](https://github.com/IsayasT) |
| Alemtsehay Gormas | RCD/1827/2017 | [@alemg01](https://github.com/alemg01) |
| Ermiyas Teklemuz | RCD/2549/2016 | [@ErmiyasT](https://github.com/ErmiyasT) |

---

## 📝 Project Overview
A console-based banking simulation system implementing core financial operations using fundamental C++ concepts. Designed specifically to demonstrate array manipulation and structured programming principles.

---

## 🎯 Features

✅ Account Creation (with:
- Unique name validation  
- Age verification (18–120)  
- Initial deposit validation (min. 50 Birr)

✅ Deposit Function  
✅ Withdraw Function  
✅ Transfer Between Accounts (with minimum balance rule)  
✅ View Account Details (with full transaction history)  
✅ Show All Accounts  
✅ Basic Menu Navigation System  
✅ All transactions logged using `string TransactionHistory[100][100]`

---

## 📐 System Design

- Data is stored in **arrays** only (no vectors or classes).
- User input is validated using `if-else` and loops.
- Every function uses **pure C++ iostream**, no external libraries.
- Easy-to-navigate menu interface.

---

## 🔢 Variables and Data Structures

| Name | Type | Purpose |
|------|------|---------|
| `AccountName[100][3]` | `string` | Stores full names (First, Middle, Last) |
| `AccountNumber[100]` | `long long` | Unique account numbers |
| `Age[100]` | `int` | Stores ages of users |
| `AccDeposit[100]` | `long long` | Tracks current balance |
| `TransactionHistory[100][100]` | `string` | Logs deposits, withdrawals, and transfers |
| `Log[100]` | `int` | Index counter for transaction history per user |
| `count` | `int` | Tracks number of created accounts |

---

## 🛠️ Functions Overview

| Function | Description |
|----------|-------------|
| `CreateAccount()` | Creates a new bank account with age and deposit validations |
| `Deposit()` | Adds money to an account and logs the transaction |
| `Transfer()` | Transfers money between valid accounts and logs both sides |
| `Withdraw()` | Allows withdrawals while maintaining minimum 50 Birr |
| `AccountDetails()` | Shows details + transaction history for one account |
| `ShowAllAccounts()` | Displays all registered accounts in the system |
| `main()` | Displays menu and connects all the functions |

---

## ❗ Limitations (by academic design)

- ❌ No use of `cin.fail()` for input type checking  
- ❌ No `file handling` or saving data after exit  
- ❌ No use of `STL` (e.g., vectors, maps)  

---

## 🧪 Sample Run

```bash
=====================================================================
   =================== BANK MANAGEMENT SYSTEM ===================    
=====================================================================
1. Create New Account
2. Deposit Money
3. Transfer Money
4. Withdraw Money
5. Account Details
6. View All Accounts
7. Exit Program
=====================================================================
Select an option (1-7): 1
```

---

## 🔄 Sample Transaction Log

```
Transaction History:
  1) Deposit: +100 Birr
  2) Transfer to John: -50 Birr
  3) Withdrawal: -30 Birr
```

---
