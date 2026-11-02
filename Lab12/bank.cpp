
#include <iostream>
#include <string>
using namespace std;


class Account {
protected:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    Account(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolder = name;
        balance = bal;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully!\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully!\n";
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    virtual void displayStatement() {
        cout << "\n----- Account Statement -----\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    virtual ~Account() {}
};


class SavingsAccount : public Account {
public:
    SavingsAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal) {}

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Savings account withdrawal successful!\n";
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void displayStatement() override {
        cout << "\n--- Savings Account Statement ---\n";
        Account::displayStatement();
    }
};


class CheckingAccount : public Account {
public:
    CheckingAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal) {}

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance + 5000) {
            balance -= amount;
            cout << "Checking account withdrawal successful!\n";
        } else {
            cout << "Withdrawal limit exceeded!\n";
        }
    }

    void displayStatement() override {
        cout << "\n--- Checking Account Statement ---\n";
        Account::displayStatement();
    }
};


int main() {
    int choice, accType;
    double amount;

    cout << "===== SIMPLE BANKING SYSTEM =====\n";

    cout << "1. Savings Account\n";
    cout << "2. Checking Account\n";
    cout << "Enter account type: ";
    cin >> accType;

    Account* acc;

    if (accType == 1) {
        acc = new SavingsAccount(101, "Rahul", 10000);
    } else if (accType == 2) {
        acc = new CheckingAccount(102, "Rahul", 10000);
    } else {
        cout << "Invalid account type!\n";
        return 0;
    }

    do {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Account Statement\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                acc->deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                acc->withdraw(amount);
                break;

            case 3:
                acc->displayStatement();
                break;

            case 4:
                cout << "Thank you for using our banking system!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
        
    } while (choice != 4);
    delete acc;
    return 0;
}
