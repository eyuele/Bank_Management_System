#include <iostream>
using namespace std;



// Function: CreateAccount
// -----------------------------
bool CreateAccount(long long int InitAccNum, long long int AccountNumber[], int &count, int  Age[],
    long long int AccDeposit[], string FirstName[], string MiddleName[], 
    string LastName[])
{
    bool IsRunning, Run;
    IsRunning = true;
    Run = true;
    int choice;

    int TempAge;
    int TempInitialDeposit;
    string TempFirstName, TempMiddleName, TempLastName;
    cout << "-------------------------------------------------------------------------------"<< endl;
    cout << endl;
    
    
    
    return IsRunning;
     
    
}
//

// Function: Deposit
// -----------------------------
bool Deposit(long long int AccountNumber[],int count, int  Age[],
    long long int AccDeposit[], string FirstName[], string MiddleName[], 
    string LastName[])
{
    int arrnum, choice;
    long long int InputAccount, DepositAmount;
    bool Run = true, IsRunning = true;
    




    return IsRunning;
}

//

// Function: Transfer
// -----------------------------
bool Transfer(long long int AccountNumber[1000],int count,
    long long int AccDeposit[1000], string FirstName[1000], string MiddleName[1000], 
    string LastName[1000])
{
    int ArrRecNum, arrnum, choice;
    long long int InputAccount, InputResAccount, TransferAmount;
    bool Run = true, IsRunning = true;
    


    return IsRunning;
}
//


// Function: Withdraw
// -----------------------------
bool Withdraw(long long int AccountNumber[],int count,
    long long int AccDeposit[], string FirstName[], string MiddleName[], 
    string LastName[])
{

    int arrnum, choice;
    long long int InputAccount, WithdrawAmount;
    bool Run = true, IsRunning = true;
    string InputName;
    

    return IsRunning;
}

//

// Function: BalanceInquiry
// -----------------------------
bool BalanceInquiry(long long int AccountNumber[],int count,
    long long int AccDeposit[], string FirstName[], string MiddleName[], 
    string LastName[])
{
    int choice;
    long long int InputAccount;
    bool Run = true, IsRunning = true;
    string InputName;
    


    return IsRunning;
}




// Function: ShowAllAccounts
// -----------------------------
bool ShowAllAccounts(long long int AccountNumber[], int count,
    long long int AccDeposit[], string FirstName[], string MiddleName[], 
    string LastName[])
{
    int choice;
    bool Run = true, IsRunning = true;
    

    return IsRunning;
}

int main (){
    const int ArrSize = 1000;
    long long int InitAccNum = 1000, AccountNumber[ArrSize];
    int  Age[ArrSize], count = 0;
    long long int AccDeposit[ArrSize];
    string FirstName[ArrSize], MiddleName[ArrSize], LastName[ArrSize]; 

    bool IsRunning = true;
    int menu;
    while (IsRunning == true){
// Display information or prompt to user
        cout << "-------------------------------------------------------------------------------"<< endl;
        cout << endl;
        cout << "-----------------------------BANK MANAGEMENT SYSTEM----------------------------" << endl;
        cout << endl;
        cout << "-------------------------------------------------------------------------------"<< endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Transfer" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Balance Inquiry" << endl;
        cout << "6. Show All Accounts" << endl;
        cout << "7. Exit" << endl;
        cout << endl;
        cout << "-------------------------------------------------------------------------------"<< endl;
        
        cout << "Choose the service you want (1-7): ";
        cin >> menu;
        if (menu == 1){
            IsRunning = CreateAccount(InitAccNum, AccountNumber, count, Age,
            AccDeposit, FirstName, MiddleName, LastName);
        }
        else if (menu == 2){
            IsRunning = Deposit(AccountNumber, count, Age,
            AccDeposit, FirstName, MiddleName, LastName);

        }
        else if (menu == 3){
            IsRunning = Transfer(AccountNumber, count,
            AccDeposit, FirstName, MiddleName, LastName);
        }
        else if (menu == 4){
            IsRunning = Withdraw(AccountNumber, count,
            AccDeposit, FirstName, MiddleName, LastName);
        }
        else if (menu == 5){
            IsRunning = BalanceInquiry(AccountNumber, count,
            AccDeposit, FirstName, MiddleName, LastName);
        }
        else if (menu == 6){
            IsRunning = ShowAllAccounts(AccountNumber, count,
            AccDeposit, FirstName, MiddleName, LastName);
        }
        // Exit and return to main menu system 

        else if (menu == 7){
             
            cout << "Enter 1 to exit, Enter 2 to go back." << endl;
            int choice;
            cin >> choice;
            switch (choice)
            {
                case 1:{
                    cout << "Exiting..." << endl;
                    IsRunning = false;
                    break;
                }
                case 2:{
                    cout << "Going Back..." << endl;
                    break;
                }
                default:{
                    cout << "Please try again." << endl;
                }
                
            }
        }
        else{
            cout << "Please Enter a Valid Input(1-7)." << endl;
        }
        cout << endl;
    }
    return 0;
}