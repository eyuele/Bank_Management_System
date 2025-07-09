
# 💼 Bank Management System

### 📚 Basic C++ Console Project  
**Author:** Ethiel (Eyuel)  
**University:** St. Mary’s University  
**Course:** Programming Fundamentals / C++ (Beginner Level)

---

## 📌 Description

This project is a **Bank Management System** built entirely using **basic C++ and `iostream`**—no advanced libraries, no file handling, and no `cin.fail()` validation. It is structured to simulate real-world banking operations in a simple, educational context.

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
- ❌ No classes or OOP  
- ❌ Not designed for security (no password check per account)

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

## 🚧 Future Improvements (for advanced versions)

- Add file saving and loading with `fstream`
- Add password authentication per account
- Replace arrays with `vector` or `struct`
- Add error-proof input handling using `cin.fail()` and `getline()`
- Build GUI version using libraries like **Kivy (Python)** or **Qt (C++)**

---

## 🧾 License

This is a student project made for educational purposes only.  
Feel free to reuse and learn from it in **basic C++ programming courses**.
