#include <iostream>
using namespace std;

// Function: CreateAccount
bool CreateAccount(long long int InitAccNum, long long int AccountNumber[], int &count, int  Age[],
    long long int AccDeposit[], string AccountName[][3])
{
    bool IsRunning, Run;
    IsRunning = true;
    Run = true;
    char choice;
    int TempAge;
    long long int TempInitialDeposit;
    string TempFirstName, TempMiddleName, TempLastName;
    cout << "----------------------------------------------------------------------"<< endl;
    cout << endl;
    
    
    while(Run){
        int AgeNdDepoVar = 0;
        bool Duplicate = false, IsValidAge = false, IsValidDeposit = false;
        cout << endl;
        cout << "------ Enter Your Legal Name ------ "<<endl;
        cout << endl;
        cout << "First name: ";
        cin >> TempFirstName;
        cout << "Middle name: ";
        cin >> TempMiddleName;
        cout << "Last name: ";
        cin >> TempLastName;
        
        // This part checks if an account already exists under the same name 
        for(int i = 0; i < count; i++ ){
            if (AccountName[i][0] == TempFirstName && AccountName[i][1] == TempMiddleName && AccountName[i][2] == TempLastName){
                cout << "An account already exists under this name." << endl;
                Duplicate = true;
            }
        }

        // This part validates customer age and initial deposit amount
        while (Duplicate == false && AgeNdDepoVar == 0){
            // Age validation
            while (IsValidAge == false){
                cout << endl;
                cout << "Enter your age (must be 18-120): ";
                cin >> TempAge;
                if(TempAge >= 18 && TempAge <= 120){
                    AgeNdDepoVar++;
                    IsValidAge = true;
                }
                else {
                    cout << "Invalid age. Please enter a value between 18 and 120." << endl;
                }
            }

            // Deposit validation
            while(IsValidDeposit == false){
                cout << endl;
                cout << "Enter initial deposit (minimum 50 Birr): ";
                cin >> TempInitialDeposit;
                if (TempInitialDeposit < 50){
                    cout << TempInitialDeposit << " Birr is below the required minimum.\nMinimum deposit to create an account is 50 Birr.\nPlease try again.\n";
                }
                else if(TempInitialDeposit >= 50){
                    AgeNdDepoVar++;
                    IsValidDeposit = true;
                }
                else {
                    cout << "Invalid input. Please try again." << endl;
                }
            }
        }

        // Save the entered information to arrays
        if (Duplicate == false && IsValidAge == true && IsValidDeposit == true){
            AccountName[count][0] = TempFirstName;
            AccountName[count][1] = TempMiddleName;
            AccountName[count][2] = TempLastName;
            Age[count] = TempAge;
            AccountNumber[count] = InitAccNum + count;
            AccDeposit[count] = TempInitialDeposit;
            cout << "Account created successfully!" << endl;
        }

        // Display the newly created account information
        if (Duplicate == false){
            cout << endl;
            cout << "----------------------------------------------------------------------"<< endl;
            cout << "Account Number: " << AccountNumber[count] << endl;
            cout << "----------------------------------------------------------------------"<< endl;
            cout << "Full Name: " << AccountName[count][0] << " " << AccountName[count][1] << " " << AccountName[count][2] << endl;
            cout << "----------------------------------------------------------------------"<< endl;
            cout << "Age: " << Age[count] << endl;
            cout << "----------------------------------------------------------------------"<< endl;
            cout << "Initial Deposit: " << AccDeposit[count] << " Birr" << endl;
            cout << "----------------------------------------------------------------------"<< endl;
            cout << endl;
            count++;
        }

        // Menu navigation options
        cout << "Options:" << endl;
        cout << "  1) Quit the program" << endl;
        cout << "  2) Return to main menu" << endl;
        cout << "  3) Create another account" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case '1': {
                cout << "Exiting program..." << endl;
                Run = false;
                IsRunning = false; 
                break;
            }
            case '2': {
                cout << "Returning to main menu..." << endl;
                Run = false;
                break;
            }
            case '3': {
                cout << "Preparing to create another account..." << endl;
                break;
            }
            default:{
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    return IsRunning;
}

// Function: Deposit
bool Deposit(long long int AccountNumber[],int count, int  Age[],
    long long int AccDeposit[], string AccountName[][3], string TransactionHistory[][100], int Log[])
{
    int arrnum;
    char choice;
    long long int InputAccount, DepositAmount;
    bool Run = true, IsRunning = true;
    
    while (Run){
        bool ValidDepo = false, IsValid = false;
        arrnum = 0;
        cout << "Enter Account Number: ";
        cin >> InputAccount;

        for (int i = 0; i < count; i++){
            if (AccountNumber[i] == InputAccount){
                cout << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Account Number: " << AccountNumber[i] << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Full Name: " << AccountName[i][0] << " " << AccountName[i][1] << " " << AccountName[i][2] << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Age: " << Age[i] << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Current Balance: " << AccDeposit[i] << " Birr" << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                arrnum = i;
                IsValid = true;
                break;
            }
        }
        cout << endl;

        if (IsValid == false){
            cout << "No account found with that account number."<< endl;
        }
        while (ValidDepo == false && IsValid == true){
            cout << "Enter deposit amount (minimum 50 Birr): ";
            cin >> DepositAmount;
            if (DepositAmount < 50){
                cout << "Minimum deposit amount is 50 Birr. Please enter a larger amount." << endl;
            }
            else if (DepositAmount >= 50){
                cout << "Deposit successful!"<<endl;
                TransactionHistory[arrnum][Log[arrnum]] = "Deposit: +" + to_string(DepositAmount) + " Birr";
                cout << "Deposited: " << DepositAmount << " Birr" << endl;
                AccDeposit[arrnum] = AccDeposit[arrnum] + DepositAmount;
                cout << "Updated balance: " << AccDeposit[arrnum] << " Birr" << endl;
                ValidDepo = true;
                Log[arrnum] += 1;
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << endl;
            }
        }

        // Menu navigation options
        cout << "Options:" << endl;
        cout << "  1) Quit the program" << endl;
        cout << "  2) Return to main menu" << endl;
        cout << "  3) Make another deposit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case '1': {
                cout << "Exiting program..." << endl;
                Run = false;
                IsRunning = false; 
                break;
            }
            case '2': {
                cout << "Returning to main menu..." << endl;
                Run = false;
                break;
            }
            case '3': {
                cout << "Preparing for another deposit..." << endl;
                break;
            }
            default:{
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    return IsRunning;
}

// Function: Transfer
bool Transfer(long long int AccountNumber[],int count,
    long long int AccDeposit[], string AccountName[][3], string TransactionHistory[][100], int Log[])
{
    int ArrRecNum, arrnum;
    char choice;
    long long int InputAccount, InputResAccount, TransferAmount;
    bool Run = true, IsRunning = true;
    
    while (Run){
        bool ValidRecipant = false, ValidTransfer = false, IsValid = false;
        arrnum = 0;
        ArrRecNum = 0;
        
        cout << "Enter Your Account Number: ";
        cin >> InputAccount;
        
        for (int i = 0; i < count; i++){
            if (AccountNumber[i] == InputAccount){
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Account Number: " << AccountNumber[i] << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Full Name: " << AccountName[i][0] << " " << AccountName[i][1] << " " << AccountName[i][2] << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Current Balance: " << AccDeposit[i] << " Birr" << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                arrnum = i;
                IsValid = true;
                break;
            }
            cout << endl;
        }
        
        if (IsValid == false){
            cout << "No account found with that account number."<< endl;
            continue;
        }
        
        cout << "Enter Recipient's Account Number: ";
        cin >> InputResAccount;
        
        for (int i = 0; i < count; i++){
            if (AccountNumber[i] == InputResAccount && AccountNumber[i] != InputAccount){
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Recipient Account Number: " << AccountNumber[i] << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Recipient Name: " << AccountName[i][0] << " " << AccountName[i][1] << " " << AccountName[i][2] << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                ArrRecNum = i;
                ValidRecipant = true;
                break;
            }
            else if (AccountNumber[i] == InputAccount){
                cout << "Cannot transfer to the same account." << endl;
            }
            cout << endl;
        }
        
        if (ValidRecipant == false){
            cout << "No recipient account found with that account number."<< endl;
            continue;
        }
        
        while (ValidTransfer == false && IsValid == true && ValidRecipant == true){
            cout << "Enter transfer amount: ";
            cin >> TransferAmount;
            if (AccDeposit[arrnum]-TransferAmount < 50){
                cout << "Transfer failed. Insufficient balance.\nMaximum transferable amount: " << AccDeposit[arrnum] - 50 << " Birr" << endl;
                cout << "----------------------------------------------------------------------"<< endl;
            }
            else if (AccDeposit[arrnum]-TransferAmount >= 50){
                cout << "-------Transfer successful!-------"<<endl;
                TransactionHistory[arrnum][Log[arrnum]] = "Transfer to " + AccountName[ArrRecNum][0] + ": -" + to_string(TransferAmount) + " Birr";
                TransactionHistory[ArrRecNum][Log[ArrRecNum]] = "Transfer from " + AccountName[arrnum][0] + ": +" + to_string(TransferAmount) + " Birr";
                cout << "Transferred: " << TransferAmount << " Birr" << endl;
                //updates the transfer amount 
                AccDeposit[arrnum] = AccDeposit[arrnum] - TransferAmount;
                AccDeposit[ArrRecNum] = AccDeposit[ArrRecNum] + TransferAmount;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Your updated balance: " << AccDeposit[arrnum] << " Birr" << endl;
                ValidTransfer = true;
                Log[arrnum] += 1;
                Log[ArrRecNum] += 1;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << endl;
            }
        }

        // Menu navigation options
        cout << "Options:" << endl;
        cout << "  1) Quit the program" << endl;
        cout << "  2) Return to main menu" << endl;
        cout << "  3) Make another transfer" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case '1': {
                cout << "Exiting program..." << endl;
                Run = false;
                IsRunning = false; 
                break;
            }
            case '2': {
                cout << "Returning to main menu..." << endl;
                Run = false;
                break;
            }
            case '3': {
                cout << "Preparing for another transfer..." << endl;
                break;
            }
            default:{
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        cout << endl;
    }
    return IsRunning;
}

// Function: Withdraw
bool Withdraw(long long int AccountNumber[],int count,
    long long int AccDeposit[], string AccountName[][3],string TransactionHistory[][100], int Log[])
{
    int arrnum;
    char choice;
    long long int InputAccount, WithdrawAmount;
    bool Run = true, IsRunning = true;
    string TempMessage, InputName;
    
    while (IsRunning == true && Run == true){
        bool ValidWithdraw = false, IsValid = false;
        arrnum = 0;
        cout << "Enter Account Number: ";
        cin >> InputAccount;
        cout << "Enter Account Holder's First Name: ";
        cin >> InputName;
        
        for (int i = 0; i < count; i++){
            if (AccountNumber[i] == InputAccount && AccountName[i][0] == InputName){
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Account Number: " << AccountNumber[i] << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Full Name: " << AccountName[i][0] << " " << AccountName[i][1] << " " << AccountName[i][2] << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Current Balance: " << AccDeposit[i] << " Birr" << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                arrnum = i;
                IsValid = true;
                break;
            }
        }
        
        if (IsValid == false){
            cout << "No account found with those details."<< endl;
        }
        
        while (ValidWithdraw == false && IsValid == true){
            cout << "Enter withdrawal amount: ";
            cin >> WithdrawAmount;
            if (AccDeposit[arrnum] - WithdrawAmount < 50){
                cout << "Withdrawal declined. Insufficient balance.\nMaximum withdrawable amount: " << AccDeposit[arrnum] - 50 << " Birr" << endl;
            }
            else if (AccDeposit[arrnum]-WithdrawAmount >= 50){
                cout << "Withdrawal successful!"<<endl;
                TransactionHistory[arrnum][Log[arrnum]] = "Withdrawal: -" + to_string(WithdrawAmount) + " Birr";
                cout << "Withdrawn: " << WithdrawAmount << " Birr" << endl;
                AccDeposit[arrnum] = AccDeposit[arrnum] - WithdrawAmount;
                cout << "Updated balance: " << AccDeposit[arrnum] << " Birr" << endl;
                ValidWithdraw = true;
                Log[arrnum] += 1;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << endl;
            }
        }

        // Menu navigation options
        cout << "Options:" << endl;
        cout << "  1) Quit the program" << endl;
        cout << "  2) Return to main menu" << endl;
        cout << "  3) Make another withdrawal" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case '1': {
                cout << "Exiting program..." << endl;
                Run = false;
                IsRunning = false; 
                break;
            }
            case '2': {
                cout << "Returning to main menu..." << endl;
                Run = false;
                break;
            }
            case '3': {
                cout << "Preparing for another withdrawal..." << endl;
                break;
            }
            default:{
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        cout << endl;
    }
    return IsRunning;
}

// Function: AccountDetails
bool AccountDetails(long long int AccountNumber[],int count,
    long long int AccDeposit[], string AccountName[][3], string TransactionHistory[][100], int Log[])
{
    char choice;
    long long int InputAccount;
    bool Run = true, IsRunning = true;
    string InputName;
    
    while (Run){
        bool IsValid = false;
        cout << "Enter Account Number: ";
        cin >> InputAccount;
        cout << "Enter Account Holder's First Name: ";
        cin >> InputName;
        
        for (int i = 0; i < count; i++){
            if (AccountNumber[i] == InputAccount && AccountName[i][0]== InputName){
                cout << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Account Number: " << AccountNumber[i] << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Full Name: " << AccountName[i][0] << " " << AccountName[i][1] << " " << AccountName[i][2] << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                cout << "Current Balance: " << AccDeposit[i] << " Birr" << endl;
                cout << "----------------------------------------------------------------------"<< endl;
                IsValid = true;
                
                // Display transaction history
                cout << "Transaction History:" << endl;
                if (Log[i] == 0) {
                    cout << "  No transactions yet." << endl;
                } else {
                    for (int j = 0; j < Log[i]; j++) {
                        cout << "  " << j + 1 << ") " << TransactionHistory[i][j] << endl;
                    }
                }
                break;
            }
        }
        
        cout << endl;
        
        if (IsValid == false){
            cout << "No account found with those details."<< endl;
            continue;
        }

        // Menu navigation options
        cout << "Options:" << endl;
        cout << "  1) Quit the program" << endl;
        cout << "  2) Return to main menu" << endl;
        cout << "  3) Check another account" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case '1': {
                cout << "Exiting program..." << endl;
                Run = false;
                IsRunning = false; 
                break;
            }
            case '2': {
                cout << "Returning to main menu..." << endl;
                Run = false;
                break;
            }
            case '3': {
                cout << "Preparing to check another account..." << endl;
                break;
            }
            default:{
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        cout << endl;
    }
    return IsRunning;
}

// Function: ShowAllAccounts
bool ShowAllAccounts(long long int AccountNumber[], int count,
    long long int AccDeposit[], string AccountName[][3]){
    char choice;
    bool Run = true, IsRunning = true;
    
    while (Run){
        cout << "====== ALL ACCOUNTS ======" << endl;
        for(int i = 0; i < count; i++){
            cout << endl;
            cout << "----------------------------------------------------------------------"<< endl;
            cout << "Account Number: " << AccountNumber[i] << endl;
            cout << "----------------------------------------------------------------------"<< endl;
            cout << "Full Name: " << AccountName[i][0] << " " << AccountName[i][1] << " " << AccountName[i][2] << endl;
            cout << "----------------------------------------------------------------------"<< endl;
            cout << "Current Balance: " << AccDeposit[i] << " Birr" << endl;
            cout << "----------------------------------------------------------------------"<< endl;
        }
        
        cout << endl;
        
        // Menu navigation options
        cout << "Options:" << endl;
        cout << "  1) Quit the program" << endl;
        cout << "  2) Return to main menu" << endl;
        cout << "  3) Refresh account list" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case '1': {
                cout << "Exiting program..." << endl;
                Run = false;
                IsRunning = false; 
                break;
            }
            case '2': {
                cout << "Returning to main menu..." << endl;
                Run = false;
                break;
            }
            case '3': {
                cout << "Refreshing account list..." << endl;
                break;
            }
            default:{
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        cout << endl;
    }
    return IsRunning;
}

int main (){
    const int ArrSize = 100;
    bool IsRunning = true;
    char menu;
    
    //Transaction Data
    int Log[ArrSize] = {0};
    string TransactionHistory[ArrSize][100]; 

    //Created Account Data
    int count = 0;
    int Age[ArrSize] = {0};
    long long int InitAccNum = 1000;
    long long int AccountNumber[ArrSize];
    long long int AccDeposit[ArrSize];
    string AccountName[ArrSize][3];
    
    

    while (IsRunning){
        // Main menu display
        cout << "====================================================================="<< endl;
        cout << endl;
        cout << "   =================== BANK MANAGEMENT SYSTEM ===================    " << endl;
        cout << endl;
        cout << "====================================================================="<< endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Transfer Money" << endl;
        cout << "4. Withdraw Money" << endl;
        cout << "5. Account Details" << endl;
        cout << "6. View All Accounts" << endl;
        cout << "7. Exit Program" << endl;
        cout << endl;
        cout << "====================================================================="<< endl;
        
        cout << "Select an option (1-7): ";
        cin >> menu;
        switch (menu){
            case '1':{
                IsRunning = CreateAccount(InitAccNum, AccountNumber, count, Age,AccDeposit, AccountName);
                break;
            }
            case '2':{
                IsRunning = Deposit(AccountNumber, count, Age,AccDeposit, AccountName, TransactionHistory, Log);
                break;
            }
            case '3':{
                IsRunning = Transfer(AccountNumber, count,AccDeposit, AccountName, TransactionHistory, Log);
                break;
            }
            case '4':{
                IsRunning = Withdraw(AccountNumber, count,AccDeposit, AccountName, TransactionHistory, Log);
                break;
            }
            case '5':{
                IsRunning = AccountDetails(AccountNumber, count, AccDeposit, AccountName, TransactionHistory, Log);
                break;
            }
            case '6':{
                IsRunning = ShowAllAccounts(AccountNumber, count, AccDeposit, AccountName);
                break;
            }
            case '7':{
                cout << "Options:" << endl;
                cout << "  1) Confirm Exit" << endl;
                cout << "  2) Return to Main Menu" << endl;
                cout << "Enter your choice: ";
                char choice;
                cin >> choice;
                switch (choice)
                {
                    case '1':{
                        cout << "Exiting program..." << endl;
                        IsRunning = false;
                        break;
                    }
                    case '2':{
                        cout << "Returning to main menu..." << endl;
                        break;
                    }
                    default:{
                        cout << "Invalid choice. Returning to main menu..." << endl;
                        break;
                    }
                }
                break;
            }
            default:{
                cout << "Invalid option. Please enter a number between 1 and 7." << endl;
                break;
            }
        }
        cout << endl;
    }
    return 0;
}