#include <iostream>
#include <string>
#include <limits>
#include <sstream>

using namespace std;
void showBalance(double choice, double *myBalance, double *wifeBalance, double *daughterBalance, double *sonBalance);
double depositeMoney(double choice, double amount, double *myBalance, double *wifeBalance, double *daughterBalance, double *sonBalance);
double withdrawMoney(double choice, double amount, double *myBalance, double *wifeBalance, double *daughterBalance, double *sonBalance);
int printAccounts();
char takeOperation();

int main(){
    double secim=0,secimNew = 0, amount = 0, myBalance = 0, wifeBalance = 10, daughterBalance = 20, sonBalance = 30;
    int password,choice;
    char transaction;
    cout << "************************* WELCOME TO THE ANT BANK *************************\n";
    while(true){
        cout << "Please enter your four digit password --> ";
        cin >> password;
        //fail() hatalı girişte tetiklenir ve uyarı yapılır
        if(cin.fail() || to_string(password).length() != 4){
            cout << "Invalid entry. Try again.\n";
            cout << "***************************************************************************\n";
            //yapılan uyarı clear() ile temizlenir
            cin.clear();
            //satır sonuna kadar girilen yanlış değer temizlenir
            cin.ignore(numeric_limits<streamsize>::max(), '\n');            
        }
        else{
            break;
        }
    }
    cout << "Welcome Mr.Ant .\n";
    cout << "***************************************************************************\n";
    do{
    cout << "1.Show balance.\n";
    cout << "2.Deposite money.\n";
    cout << "3.Withdraw money.\n";
    cout << "4.Transfer money to another account.\n";
    cout << "5.Exit.\n";
    cout << "Please select the transaction you want to do --> ";
    cin >> choice;
    while(cin.fail() || choice < 1 || choice > 5){
        cout << "Invalid entry.\n";
        cout << "***************************************************************************\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "1.Show balance.\n";
        cout << "2.Deposite money.\n";
        cout << "3.Withdraw money.\n";
        cout << "4.Transfer money to another account.\n";
        cout << "5.Exit.\n";
        cout << "Please select the transaction you want to do --> ";
        cin >> choice;
    }
    switch(choice){
        case 1: cout << "***************************************************************************\n";
                cout << "Which account's balance you want to see ?\n";
                secim = printAccounts();
                showBalance(secim,&myBalance,&wifeBalance,&daughterBalance,&sonBalance);
                break;
        case 2: cout << "***************************************************************************\n";
                cout << "Which account do you want to deposit money into ?\n";
                secim = printAccounts();
                cout << "Enter the amount : ";
                cin >> amount;
                cout << '\n' << endl;
                depositeMoney(secim,amount,&myBalance,&wifeBalance,&daughterBalance,&sonBalance);
                showBalance(secim,&myBalance,&wifeBalance,&daughterBalance,&sonBalance);
                break;
        case 3: cout << "***************************************************************************\n";
                cout <<"Which account do you want to withdraw money from ?\n";
                secim = printAccounts();
                cout << "Enter the amount : ";
                cin >> amount;
                cout << '\n' << endl;
                withdrawMoney(secim,amount,&myBalance,&wifeBalance,&daughterBalance,&sonBalance);
                showBalance(secim,&myBalance,&wifeBalance,&daughterBalance,&sonBalance);
                break;
        case 4: cout << "***************************************************************************\n";
                cout << "Enter first account, choose your operation then select second account.\n";
                secim = printAccounts();
                transaction = takeOperation();
                secimNew = printAccounts();
                cout << "Enter the amount : ";
                cin >> amount;
                cout << '\n' << endl;
                if(transaction == '>'){
                    withdrawMoney(secim,amount,&myBalance,&wifeBalance,&daughterBalance,&sonBalance);
                    depositeMoney(secimNew,amount,&myBalance,&wifeBalance,&daughterBalance,&sonBalance);
                }
                else if(transaction == '<'){
                    withdrawMoney(secimNew,amount,&myBalance,&wifeBalance,&daughterBalance,&sonBalance);
                    depositeMoney(secim,amount,&myBalance,&wifeBalance,&daughterBalance,&sonBalance);
                }
                showBalance(secim,&myBalance,&wifeBalance,&daughterBalance,&sonBalance);
                showBalance(secimNew,&myBalance,&wifeBalance,&daughterBalance,&sonBalance);
                break;
        case 5: cout << "***************************************************************************\n";
                cout << "Have a nice day Mr.Ant .\n";
                cout << "***************************************************************************\n";
                break;
        default : cout << "Invalid entry.\n";    
    }
    }while(choice != 5);
    return 0;
}
int printAccounts(){
    int account;
    cout << "1.My account.\n2.Wife's account.\n3.Daughter's account.\n4.Son's account.\n";
    cout << "Enter your choice : ";
    cin >> account;
    while(cin.fail() || account < 1 || account > 4){
        cout << "Invalid entry.\n";
        cout << "***************************************************************************\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "1.My account.\n2.Wife's account.\n3.Daughter's account.\n4.Son's account.\n";
        cout << "Enter your choice : ";
        cin >> account;   
    }
    cout << "***************************************************************************\n";
    return account;
}
void showBalance(double choice, double *myBalance, double *wifeBalance, double *daughterBalance, double *sonBalance){
    if(choice == 1){
        cout << "Current balance is : " << *myBalance << "TL\n";
    }
    else if(choice == 2){
        cout << "Current balance is : " << *wifeBalance << "TL\n";
    }
    else if(choice == 3){
        cout << "Current balance is : " << *daughterBalance << "TL\n";
    }
    else if(choice == 4){
        cout << "Current balance is : " << *sonBalance << "TL\n";
    }    
}
double depositeMoney(double choice, double amount, double *myBalance, double *wifeBalance, double *daughterBalance, double *sonBalance){
    if(amount < 0){
        cout << "\nThat's not a valid amount. Try again.\n";
        return 0;
    }
    else if(choice == 1){
        *myBalance += amount;
        return *myBalance;
    }
    else if(choice == 2){
        *wifeBalance += amount;
        return *wifeBalance;
    }
    else if(choice == 3){
        *daughterBalance += amount;
        return *daughterBalance;
    }
    else if(choice == 4){
        *sonBalance += amount;
        return *sonBalance;
    }
    else{
        return 0;
    }
}
double withdrawMoney(double choice, double amount, double *myBalance, double *wifeBalance, double *daughterBalance, double *sonBalance){
    if(amount < 0){
        cout << "\nThat's not a valid amount. Try again.\n";
        return 0;
    }
    else{
        if(amount <= *myBalance && choice == 1){
            *myBalance -= amount;
            return *myBalance;
        }
        else if(amount <= *wifeBalance && choice == 2){
            *wifeBalance -= amount;
            return *wifeBalance;
        }
        else if(amount <= *daughterBalance && choice == 3){
            *daughterBalance -= amount;
            return *daughterBalance;
        }
        else if(amount <= *sonBalance && choice == 4){
            *sonBalance -= amount;
            return *sonBalance;
        }
        else{
            cout << "Invalid entry.\n";
            return 0;
        }
    }
}
char takeOperation(){
    char operation;
    cout << "Select the transaction.(> deposite from to) : ";
    cin >> operation;
    if(operation != '<' || operation != '>'){
        cout << "Invalid entry.\n";
        return 0;
    }
    else{
        cout << '\n' << endl;
        return operation;  
    }
}