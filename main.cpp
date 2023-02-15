#include <iostream>

using namespace std;

enum Option {
    d = 1,
    w = 2,
    b = 3,
    q = 4
};

enum ERR {exit_g = 24, exit_b = 25};

class BankAccount {
private:
    char f_name[10];
    char l_name[10];
    int a_num;
    int b_b;
public:
    int logs;
    ERR init();
    void deposit(int n);
    ERR withdraw(int n);
    void balance();
};

int main() {
    BankAccount b1;
    if (b1.init()==exit_b) {
        cout << "An error was encountered !, restarting system !\n";
        int ret_v;
        do {
            ret_v = b1.init();
        }while(ret_v==exit_b);
    };
    int vv;
    int amount_d;
    int amount_w;
    int quit = 0;
    while(1) {
        cout << "Enter any option from the menu below: \n";
        cout << "(1): Deposit money\n(2): Withdraw money\n(3): Check balance\n(4): Quit\n:... ";
        cin >> vv;
        cout << "--------------------" << endl;
        switch (vv) {
        case d:
                cout << "Enter amount to deposit:... ";
                cin >> amount_d;
                b1.deposit(amount_d);
                amount_d = 0;
                break;
        case w:
            cout << "Enter amount to withdraw:... ";
            cin >> amount_w;
            if (b1.withdraw(amount_w)==exit_b)
                cout << "Error, The requested amount was either higher than the balance or it was a negative value" << endl;
            amount_w = 0;
            break;
        case b:
            b1.balance();
            break;
        case q:
            cout << "Exiting system...." << endl;
            quit = 1;
            break;
        default:
            cout << "Invalid option !" << endl;
        }
        if (quit==1)
            break;
        cout << "--------------------" << endl;
        b1.logs++;
    }
    return 0;
}

ERR BankAccount::init() {
    logs = 0;
    cout << "Welcome to Bank 2.0, Enter info: \n";
    cout << "Enter first name:... ";
    cin >> f_name;
    cout << "Enter last name:... ";
    cin >> l_name;
    cout << "Enter account number (must be less than 8 digits):... ";
    cin >> a_num;
    if (a_num>99999999)
        return exit_b;
    cout << "Enter starting balance (must be less than 1000):... ";
    cin >> b_b;
    if (b_b>1000)
        return exit_b;
    return exit_g;
}

void BankAccount::deposit(int n) {
    b_b += n;
}

ERR BankAccount::withdraw(int n) {
    if (n>b_b||n<0)
        return exit_b;
    b_b -= n;
    return exit_g;
}

void BankAccount::balance() {
    cout << "The acount has the following info: " << endl;
    cout << "Name: " << f_name << " " << l_name << endl;
    cout << "Account number: " << a_num << endl;
    cout << "Balance: " << b_b << '$' << endl;
    cout << "Logs: " << logs << endl;
}
