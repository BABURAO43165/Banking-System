#include <iostream>
using namespace std;


class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    
    BankAccount(string holder, int number, double initialBalance) {
        accountHolder = holder;
        accountNumber = number;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }


    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;  
            cout << "Withdrawal successful! New balance: $" << balance << endl;
        } else {
            cout << "Invalid amount or insufficient balance!" << endl;
        }
    }

    void checkBalance() {
        cout << "\nAccount Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    string name;
    int accountNumber;
    double initialDeposit;


    cout << "Enter account holder's name: ";
    getline(cin, name);

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter initial deposit: ";
    cin >> initialDeposit;

 
    BankAccount myAccount(name, accountNumber, initialDeposit);

    int choice;
    double amount;

  
    do {
        cout << "\n=== Banking System Menu ===" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            myAccount.deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            myAccount.withdraw(amount);
            break;
        case 3:
            myAccount.checkBalance();
            break;
        case 4:
            cout << "Thank you for using the banking system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please choose again." << endl;
        }
    } while (choice != 4);

    return 0;
}
