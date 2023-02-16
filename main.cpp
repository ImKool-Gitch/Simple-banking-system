#include <iostream>

using namespace std;

enum Option {
    deposit = 1,
    withdraw = 2,
    balance = 3,
    quit = 4
};

enum ERR {
    higher_than_balance,
    negative_value,
    good
};

class BankAccount {
private:
    string f_name;
    string l_name;
    long a_num;
    long b_b;
public:
    BankAccount();
    int logs;
    ERR deposit(int n);
    ERR withdraw(int n);
    void balance();
};

int main() {
    BankAccount b1;
    int vv;
    long amount_d;
    long amount_w;
    int quit_s = 0;
    while(1) {
        cout << "Enter any option from the menu below: \n";
        cout << "(1): Deposit money\n(2): Withdraw money\n(3): Check balance\n(4): Quit\n:... ";
        cin >> vv;
        cout << "--------------------" << endl;
        switch (vv) {
        case deposit:
                cout << "Enter amount to deposit:... ";
                cin >> amount_d;
                if (b1.deposit(amount_d)==negative_value)
                    cout << "Error, Cannot deposit a negative value !" << endl;
                amount_d = 0;
                break;
        case withdraw:
            cout << "Enter amount to withdraw:... ";
            cin >> amount_w;
            if (b1.withdraw(amount_w)==higher_than_balance)
                cout << "Error, The requested amount was higher than the current balance !" << endl;
            else if (b1.withdraw(amount_w)==negative_value)
                cout << "Error, The requested amount was a negative value !" << endl;
            amount_w = 0;
            break;
        case balance:
            b1.balance();
            break;
        case quit:
            cout << "Exiting system...." << endl;
            quit_s = 1;
            break;
        default:
            cout << "Invalid option !" << endl;
        }
        if (quit_s==1)
            break;
        cout << "--------------------" << endl;
        b1.logs++;
    }
    return 0;
}

BankAccount::BankAccount() {
    logs = 0;
    cout << "Welcome to Bank 2.0, Enter info: \n";
    cout << "Enter first name:... ";
    cin >> f_name;
    cout << "Enter last name:... ";
    cin >> l_name;
    cout << "Enter account number (must be less than 8 digits):... ";
    cin >> a_num;
    if (a_num>99999999) {
        cout << "The account number was entered incorrectly !" << endl;
        do {
            cout << "Enter account number (must be less than 8 digits):... ";
            cin >> a_num;
        }while(a_num>999999999||a_num<0);
    }
    cout << "Enter starting balance (must be less than 1000):... ";
    cin >> b_b;
    if (b_b>1000||b_b<0) {
        cout << "The starting balance was higher than 1000 or the value was negative" << endl;
        do {
            cout << "Enter starting balance (must be less than 1000):... ";
            cin >> b_b;
        }while(b_b>1000||b_b<0);
    }
}

ERR BankAccount::deposit(int n) {
    if (n<0)
        return negative_value;
    b_b += n;
    return good;
}

ERR BankAccount::withdraw(int n) {
    if (n>b_b)
        return higher_than_balance;
    else if (n<0)
        return negative_value;
    b_b -= n;
    return good;
}

void BankAccount::balance() {
    cout << "The acount has the following info: " << endl;
    cout << "Name: " << f_name << " " << l_name << endl;
    cout << "Account number: " << a_num << endl;
    cout << "Balance: " << b_b << '$' << endl;
    cout << "Logs: " << logs << endl;
}
