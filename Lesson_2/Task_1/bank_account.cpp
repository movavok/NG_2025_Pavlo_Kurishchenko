#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void welcomeMsg(){
    cout << "Welcome to the Bank Account Program!\n";
    cout << "What would you like to do today?\n";
    cout << "(Enter: '1') -> Request access to one of your accounts\n";
    cout << "(Enter: '2') -> View the balance of each individual account\n";
    cout << "(Enter: '3') -> View the total amount across all accounts\n";
    cout << "(Enter: 'x') -> Close the program\n\n";
}

int getAccNumber(int accountNumber){
    cout << "Enter the number of one of your accounts (1-10): ";
    cin >> accountNumber;
    return accountNumber;
}

bool getTransaction(char &transactionType, double &transactionAmount){
    cout << "For withdrawing money, enter '-' followed by a space and the amount.\n";
    cout << "For depositing  money, enter '+' followed by a space and the amount.\n";
    cout << "Enter (+/- and amount): ";
    cin >> transactionType >> transactionAmount;

    if ((transactionType == '+' || transactionType == '-') && transactionAmount > 0) return true;

    cout << "Invalid input. You have been moved to the previous operation.\n";
    return false;
}

bool validTransaction(double &accountBalance, char transactionType, double transactionAmount) {
    if (transactionType == '-' && transactionAmount > accountBalance) {
        cout << "Insufficient funds. You have been moved to the previous operation.\n";
        return false;
    }

    accountBalance = (transactionType == '+') ? accountBalance + transactionAmount : accountBalance - transactionAmount;
    return true;
}

void showAllBalances(double accountCells[]){
    cout << "Amount of money in\n";
    for (int index = 0; index < 10; index++){
        cout << "account number " << index + 1 << " (" << accountCells[index] <<" UAH)\n";
    }
}

void showTotalBalance(double accountCells[]){
    double accountSumm = 0;
    for (int index = 0; index < 10; index++){
        accountSumm += accountCells[index];
    }
    cout << "The sum of your money from all accounts (" << accountSumm <<" UAH)\n";
}

int main()
{
    welcomeMsg();

    char enteredSymbol;

    double accountCells[10];

    srand(time(0));

    for (int index = 0; index < 10; index++){
        accountCells[index] = rand();
        //cout << accountСells[index] << " ";
    }

    while(true){
        cout << "Enter (1/2/3/x): ";
        cin >> enteredSymbol;

        int accountNumber = 0;
        char transactionType = 0;
        double transactionAmount = 0;

        switch(enteredSymbol){
        case '1':

            accountNumber = getAccNumber(accountNumber);

            if (accountNumber < 1 || accountNumber > 10) {
                cout << "Invalid input. You have been moved to the previous operation.\n";
                break;
            }

            cout << "Balance in this account is (" << accountCells[accountNumber - 1] << " UAH)\n";

            if (getTransaction(transactionType, transactionAmount))
                if (validTransaction(accountCells[accountNumber - 1], transactionType, transactionAmount))
                    cout << "Now this account contains (" << accountCells[accountNumber - 1] << "UAH)\n";
            break;

        case '2':
            showAllBalances(accountCells);
            break;

        case '3':
            showTotalBalance(accountCells);
            break;

        case 'x':
            return 0;
            break;

        default:
            cout << "Invalid input. Please try again.\n";
            break;
        }
    }
}
