#include <iostream>
using namespace std;



// Function: CreateAccount

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
    
    while(IsRunning == true && Run == true){
        int AgeNdDepoVar = 0;
        bool Duplicate = false, IsValidAge = false, IsValidDeposit = false;
        cout << endl;
        cout << "------Enter your legal name------ "<<endl;
        cout << endl;
        cout<< "First name: ";
        cin >> TempFirstName;
        cout<< "Middle name: ";
        cin >> TempMiddleName;
        cout<< "Last name: ";
        
        getline(cin, TempLastName);
        cin.ignore();
        // This part of the code checks if an account is already registered under the same name 
        for(int i = 0; i < count; i++ ){
            
// Conditional check
            if (FirstName[i] == TempFirstName && MiddleName[i] == TempMiddleName && LastName[i] == TempLastName){
                cout << "There exists an account under this name " << endl;
                Duplicate = true;
            }
            
        }

        
        // This part of the program checks if a correct customer age is provided 
        // and if the minimum amount of money is deposited 
        while (Duplicate == false && AgeNdDepoVar == 0){

            // This part of the program checks if a correct customer age is provided 
            while (IsValidAge == false){
                cout << "Enter legal Age: ";
                cin >> TempAge;
                if(TempAge >= 18 && TempAge <= 120){
                    AgeNdDepoVar++;
                    IsValidAge = true;
                }
                
                else {
                    cout << "Enter a valid input." << endl;
                    
                }
            }

            // Checks if the minimum amount of money is deposited 
            

            while(IsValidDeposit == false){
                cout << "Enter legal Initial Deposit: ";
                cin >> TempInitialDeposit;
                if (TempInitialDeposit < 50){
                    cout << TempInitialDeposit << " is below the required minimum.\nThe minimum amount needed to create a new account is 50 Birr.\nPlease enter again.\n";
                }
                else if(TempInitialDeposit >= 50){
                    AgeNdDepoVar++;
                    IsValidDeposit = true;
                }
                else {
                    cout << "Enter a valid input." << endl;
                }
            }
            
        }

        
        // This part of the program saves the entered info to the arrays
        if (Duplicate == false && IsValidAge == true && IsValidDeposit == true){
            FirstName[count] = TempFirstName;
            MiddleName[count] = TempMiddleName;
            LastName[count] = TempLastName;
            Age[count] = TempAge;
            AccountNumber[count] = InitAccNum + count;
            AccDeposit[count] = TempInitialDeposit;
            cout << "The Account Has Been Successfully Created." << endl;
            
        }

        //This part of the program displays the newly created account info.
        if ( Duplicate == false ){
            cout << "-------------------------------------------------------------------------------"<< endl;
            cout << "Account Number | " << AccountNumber[count] << endl;
            cout << "-------------------------------------------------------------------------------"<< endl;
            cout << "Full Name | " << FirstName[count] << " " << MiddleName[count] << " " << LastName[count] << endl;
            cout << "-------------------------------------------------------------------------------"<< endl;
            cout << "Age | " << Age[count] << endl;
            cout << "-------------------------------------------------------------------------------"<< endl;
            cout << "Deposit | " << AccDeposit[count] << endl;
            cout << "-------------------------------------------------------------------------------"<< endl;
            cout << endl;
            count++;
        }
        

        

        // This part of the program handles exiting, going back to the main menu, or creating another account
        cout << "Enter 1 to quit the program." << endl;
        cout << "Enter 2 to go back to the main menu" << endl;
        cout << "Enter 3 to go back again and create another account." << endl;
        cin >> choice;

        switch (choice){
            case 1: {
                cout << "Quitting" << endl;
                Run = false;
                IsRunning = false; 
                break;
            }
            case 2: {
                cout << "Going back to main menu" << endl;
                Run = false;
                break;
            }
            case 3: {
                cout << endl;
                break;
            }
            default:{
                cout << "Enter a valid input." << endl;
            }
        }
        
    }
    
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
    
    while (IsRunning == true && Run == true ){
        bool ValidDepo = false, IsValid = false;
        arrnum = 0;
        cout << "Enter Account Number: ";
        cin >> InputAccount;
        for (int i = 0; i < count; i++){
// Conditional check
            if (AccountNumber[i] == InputAccount){
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Account Number | " << AccountNumber[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Full Name | " << FirstName[i] << " " << MiddleName[i] << " " << LastName[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Age | " << Age[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Deposit | " << AccDeposit[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                arrnum = i;
                IsValid = true;
                break;
            }
        }
// Conditional check
        if (IsValid == false){
            cout << "There Is No Account Under That Account Number."<< endl;
        }
        while ( ValidDepo == false && IsValid == true){
            cout << "Enter Enter deposit amount: ";
            cin >> DepositAmount;
            if (DepositAmount < 50){
                cout << "The Minimum Amount You Can Deposit Is 50 Birr, Please Deposit A Larger Amount" << endl;
            }
            else if (DepositAmount >= 50){
                cout << "The Deposit Was Successfull."<<endl;
                cout << "You Have Deposited " << DepositAmount << " Birr." << endl;
                AccDeposit[arrnum] = AccDeposit[arrnum] + DepositAmount;
                cout << "Your Updated Balance Is " << AccDeposit[arrnum] << " Birr." << endl;
                ValidDepo = true;
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << endl;
            }
        }
    // This part of the program handles exiting, going back to the main menu, or creating another account
        cout << "Enter 1 to quit the program." << endl;
        cout << "Enter 2 to go back to the main menu" << endl;
        cout << "Enter 3 to go back again and create another account." << endl;
        cin >> choice;

        switch (choice){
            case 1: {
                cout << "Quitting" << endl;
                Run = false;
                IsRunning = false; 
                break;
            }
            case 2: {
                cout << "Going back to main menu" << endl;
                Run = false;
                break;
            }
            case 3: {
                cout << endl;
                break;
            }
            default:{
                cout << "Enter a valid input." << endl;
            }
        }

    }



    return IsRunning;
}



// Function: Transfer
// -----------------------------
bool Transfer(long long int AccountNumber[1000],int count,
    long long int AccDeposit[1000], string FirstName[1000], string MiddleName[1000], 
    string LastName[1000])
{
    int ArrRecNum, arrnum, choice;
    long long int InputAccount, InputResAccount, TransferAmount;
    bool Run = true, IsRunning = true;
    
    while (IsRunning == true && Run == true ){
        bool ValidRecipant = false, ValidTransfer = false, IsValid = false;
        arrnum = 0;
        ArrRecNum = 0;
// Display information or prompt to user
        cout << "Enter Account Number: ";
// Take user input
        cin >> InputAccount;
        for (int i = 0; i < count; i++){
            
// Conditional check
            if (AccountNumber[i] == InputAccount){
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Account Number | " << AccountNumber[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Full Name | " << FirstName[i] << " " << MiddleName[i] << " " << LastName[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Deposit | " << AccDeposit[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                arrnum = i;
                IsValid = true;
                break;
            }
            cout << endl;
        }
        if (IsValid == false ){
            cout << "There Is No Account Under That Account Number."<< endl;
            continue;
        }
        cout << "Enter Recipant Account Number: ";
        cin >> InputResAccount;
        for (int i = 0; i < count; i++){
            
// Conditional check
            if (AccountNumber[i] == InputResAccount && AccountNumber[i] != InputAccount){
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Account Number | " << AccountNumber[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Full Name | " << FirstName[i] << " " << MiddleName[i] << " " << LastName[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                ArrRecNum = i;
                ValidRecipant = true;
                break;
            }
            
// Conditional check
            else if (AccountNumber[i] == InputAccount){
                cout << "you cant transfer to same account." << endl;
            }
            cout << endl;
        }
        if (ValidRecipant == false ){
            cout << "There Is No Account Under That Account Number."<< endl;
            continue;
        }
        while ( ValidTransfer == false && IsValid == true && ValidRecipant == true){
            cout << "Enter Enter transfer amount: ";
            cin >> TransferAmount;
            if (AccDeposit[arrnum]-TransferAmount < 50){
                cout << "Transfer faild, You have insufficient balance.\ncurrently you can only transfer " << AccDeposit[arrnum] - 50 << endl;
            }
            else if (AccDeposit[arrnum]-TransferAmount >= 50){
                cout << "The Transfer Was Successfull."<<endl;
                cout << "You Have Transfered " << TransferAmount << " Birr." << endl;
                AccDeposit[arrnum] = AccDeposit[arrnum] - TransferAmount;
                AccDeposit[ArrRecNum] = AccDeposit[ArrRecNum] + TransferAmount;
                cout << "Your Updated Balance Is " << AccDeposit[arrnum] << " Birr." << endl;
                ValidTransfer = true;
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << endl;
            }
        }
    // This part of the program handles exiting, going back to the main menu, or creating another account
        cout << "Enter 1 to quit the program." << endl;
        cout << "Enter 2 to go back to the main menu" << endl;
        cout << "Enter 3 to go back again and create another account." << endl;
        cin >> choice;

        switch (choice){
            case 1: {
                cout << "Quitting" << endl;
                Run = false;
                IsRunning = false; 
                break;
            }
            case 2: {
                cout << "Going back to main menu" << endl;
                Run = false;
                break;
            }
            case 3: {
                cout << endl;
                break;
            }
            default:{
                cout << "Enter a valid input." << endl;
            }
        }
        cout << endl;
    }

    return IsRunning;
}


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
    while (IsRunning == true && Run == true ){
        bool ValidWithdraw = false, IsValid = false;
        arrnum = 0;
        cout << "Enter Account Number: ";
        cin >> InputAccount;
        cout << "Enter Account Name: ";
        cin >> InputName;
        for (int i = 0; i < count; i++){
// Conditional check
            if (AccountNumber[i] == InputAccount && FirstName[i] == InputName){
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Account Number | " << AccountNumber[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Full Name | " << FirstName[i] << " " << MiddleName[i] << " " << LastName[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Deposit | " << AccDeposit[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                arrnum = i;
                IsValid = true;
                
                break;
                
            }
        }
// Conditional check
        if (IsValid == false){
            cout << "There Is No Account Under That Account Number."<< endl;
        }
        while ( ValidWithdraw == false && IsValid == true ){
            cout << "Enter Enter transfer amount: ";
            cin >> WithdrawAmount;
            if (AccDeposit[arrnum] - WithdrawAmount < 50){
                cout << "Withdraw Declined, You have insufficient balance.\ncurrently you can only withdraw " << AccDeposit[arrnum] - 50 << endl;
            }
            else if (AccDeposit[arrnum]-WithdrawAmount >= 50){
                cout << "The withdraw Was Successfull."<<endl;
                cout << "You Have Withdrawed " << WithdrawAmount << " Birr." << endl;
                AccDeposit[arrnum] = AccDeposit[arrnum] - WithdrawAmount;
                cout << "Your Updated Balance Is " << AccDeposit[arrnum] << " Birr." << endl;
                ValidWithdraw = true;
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << endl;
            }
        }
        

    // This part of the program handles exiting, going back to the main menu, or creating another account
        cout << "Enter 1 to quit the program." << endl;
        cout << "Enter 2 to go back to the main menu" << endl;
        cout << "Enter 3 to go back again and create another account." << endl;
        cin >> choice;

        switch (choice){
            case 1: {
                cout << "Quitting" << endl;
                Run = false;
                IsRunning = false; 
                break;
            }
            case 2: {
                cout << "Going back to main menu" << endl;
                Run = false;
                break;
            }
            case 3: {
                cout << endl;
                break;
            }
            default:{
                cout << "Enter a valid input." << endl;
            }
        }
        cout << endl;
    }

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
    while (Run == true && IsRunning == true){
        bool IsValid = false;
        cout << "Enter Account Number: ";
        cin >> InputAccount;
        cout << "Enter Account Name: ";
        cin >> InputName;
        for (int i = 0; i < count; i++){
            
// Conditional check
            if (AccountNumber[i] == InputAccount && FirstName[i] == InputName){
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Account Number | " << AccountNumber[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Full Name | " << FirstName[i] << " " << MiddleName[i] << " " << LastName[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                cout << "Deposit | " << AccDeposit[i] << endl;
                cout << "-------------------------------------------------------------------------------"<< endl;
                IsValid = true;
                break;
            }
            cout << endl;
        }
// Conditional check
        if (IsValid == false ){
            cout << "There Is No Account Under That Account Number."<< endl;
            continue;
        }

    

    // This part of the program handles exiting, going back to the main menu, or creating another account
        cout << "Enter 1 to quit the program." << endl;
        cout << "Enter 2 to go back to the main menu" << endl;
        cout << "Enter 3 to go back again and create another account." << endl;
        cin >> choice;

        switch (choice){
            case 1: {
                cout << "Quitting" << endl;
                Run = false;
                IsRunning = false; 
                break;
            }
            case 2: {
                cout << "Going back to main menu" << endl;
                Run = false;
                break;
            }
            case 3: {
                cout << endl;
                break;
            }
            default:{
                cout << "Enter a valid input." << endl;
            }
        }
        cout << endl;
    }


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
    while (Run == true && IsRunning == true){
        for(int i = 0; i < count; i++){
// Display information or prompt to user
            cout << "-------------------------------------------------------------------------------"<< endl;
            cout << "Account Number | " << AccountNumber[i] << endl;
            cout << "-------------------------------------------------------------------------------"<< endl;
            cout << "Full Name | " << FirstName[i] << " " << MiddleName[i] << " " << LastName[i] << endl;
            cout << "-------------------------------------------------------------------------------"<< endl;
            cout << "Deposit | " << AccDeposit[i] << endl;
            cout << "-------------------------------------------------------------------------------"<< endl;
            cout << endl;
        }
    // This part of the program handles exiting, going back to the main menu, or creating another account
        cout << "Enter 1 to quit the program." << endl;
        cout << "Enter 2 to go back to the main menu" << endl;
        cout << "Enter 3 to go back again and create another account." << endl;
        cin >> choice;

        switch (choice){
            case 1: {
                cout << "Quitting" << endl;
                Run = false;
                IsRunning = false; 
                break;
            }
            case 2: {
                cout << "Going back to main menu" << endl;
                Run = false;
                break;
            }
            case 3: {
                cout << endl;
                break;
            }
            default:{
                cout << "Enter a valid input." << endl;
            }
        }
        cout << endl;
    }

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