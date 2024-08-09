#include <iostream>
#include <strings.h>
#include <fstream>
#include <vector>
using namespace std;
class customer
{
    string name, father_name;
    int acc_no;
    int balance, id, pass;

protected:
    int total_bank_balance;

public:
    customer()
    {
    }
    customer(string name, string father_name, int acc_no, int balance, int id, int pass)
    {
        this->name = name;
        this->father_name = father_name;
        this->acc_no = acc_no;
        this->balance = balance;
        this->id = id;
        this->pass = pass;
        total_bank_balance = this->balance + balance;
    }
    int get_total_bank_balance()
    {
        return total_bank_balance;
    }
    int get_acc_no()
    {
        return acc_no;
    }
    int get_balance()
    {
        return balance;
    }
    int get_id()
    {
        return id;
    }
    int get_pass()
    {
        return pass;
    }
    void display()
    {
        cout << "here are the details of your customer\n"
             << "acc_no : " << acc_no << "\n"
             << "name : " << name << "\n"
             << "father name : " <<father_name<< "\n"
             << "balance" << balance << "\n";
    }
    void withdraw(int amnt)
    {
        if (amnt < balance && amnt > 0)
        {
            balance -= amnt;
            total_bank_balance -= amnt;
            cout << "the amount of rupees " << amnt << " debited from your account" << endl;
            cout << "total balance of your account : " << balance << endl;
        }
        else
        {
            cout << "enter some valid amount" << endl;
        }
    }
    void deposite(int amnt)
    {
        if (amnt > 0)
        {
            balance += amnt;
            total_bank_balance += amnt;
            cout << "the amount of rupees " << amnt << "credited to your account" << endl;
            cout << "total balance of your account : " << balance << endl;
        }
    }
};
class bank : public customer
{

public:
    bank() {}
    int get_total_balance()
    {
        return total_bank_balance;
    }
};

int main()
{

    vector<customer> customers;
    cout << "welcome to BANK OF INDIA" << endl;
    cout << "press enter to continue" << endl;
    string dummy;
    getline(cin, dummy);
    cout << "firstly enter the password to login as an administrartor " << endl;
    int pass = 1, k;
    cin >> k;
    while (k != pass)
    {
        cout << "incorrect pass" << endl;
        cout << "enter the pass again : ";
        cin >> k;
    }

    if (k == pass)
    {
        cout << "log in successfull \n \n \n \n " << endl;
    }
    cout << "here are the functionalities of our bank \n"
         << endl;
    cout << "press the no. show in front of functionalitiy to use it \n"
         << endl;

    int n;
    do
    {
        cout << "1. create an account" << endl;
        cout << "2. fetch balance" << endl;
        cout << "3. get the customers detail" << endl;
        cout << "4. do transaction" << endl;
        cout << "5. total balance availaible in bank" << endl;
        cout << "6. exit the bank window" << endl;

        cout << "enter the no : ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "Please enter the customer details to create an account:" << endl;

            cout << "Name: ";
            string name;
            cin.ignore();
            getline(cin, name);

            cout << "Father's Name: ";
            string father_name;
            cin.ignore();
            getline(cin, father_name);

            cout << "Account Number: ";
            int acc_no;
            cin >> acc_no;

            cout << "Balance: ";
            int balance;
            cin >> balance;

            cout << "ID: ";
            int id;
            cin >> id;

            cout << "Password: ";
            int pass;
            cin >> pass;

            customer newCustomer(name, father_name, acc_no, balance, id, pass);
            customers.push_back(newCustomer);
            // Add the new customer to your customer list (e.g., vector)
            cout << "Account created successfully!" << endl;
            break;
        }
        case 2:
        {
            int acc;
            cout<<"enter account no : ";
            cin >> acc;
            for (auto &customer : customers)
            {
                if (customer.get_acc_no() == acc)
                {
                    cout << "the balance of this account : " << customer.get_balance() << endl;
                }
            }
            break;
        }
        case 3:
        {
            int acc, identity, password;
            cout << "account number : ";
            cin >> acc;
            cout << "identity number : ";
            cin >> identity;
            cout << "enter password";
            cin >> password;
            for (auto &customer : customers)
            {
                if (customer.get_acc_no() == acc && customer.get_id() == identity && customer.get_pass() == password)
                {
                    cout << "here are the dtails of the customer " << endl;
                    customer.display();
                }
                else
                {
                    cout << "account not found";
                }
            }
            break;
        }
        case 4:
        {
            int m;
            cout << "press \n 1.withdrawl \n 2.deposite" << endl;
            cin >> m;
            switch (m)
            {
            case 1:
            {
                int acc, identity, password;
                cout << "account number : ";
                cin >> acc;
                cout << "identity number : ";
                cin >> identity;
                cout << "enter password";
                cin >> password;
                for (auto &customer : customers)
                {
                    if (customer.get_acc_no() == acc && customer.get_id() == identity && customer.get_pass() == password)
                    {
                        int amnt;
                        cout << "enter the amount you want to withdraw : ";
                        cin >> amnt;
                        customer.withdraw(amnt);
                    }
                    else
                    {
                        cout << "account not found";
                    }
                }
                break;
            }
            case 2:
            {
                int acc, identity, password;
                cout << "account number : ";
                cin >> acc;
                cout << "identity number : ";
                cin >> identity;
                cout << "enter password";
                cin >> password;
                for (auto &customer : customers)
                {
                    if (customer.get_acc_no() == acc && customer.get_id() == identity && customer.get_pass() == password)
                    {
                        int amnt;
                        cout << "enter the amount you want to deposite : ";
                        cin >> amnt;
                        customer.deposite(amnt);
                    }
                    else
                    {
                        cout << "account not found";
                    }
                }
            }
            break;
            }
            break;
        }
        case 5:
        {
            cout << "total amount of money present at this time in our bank : ";
            bank m;
            int l;
            l = m.get_total_bank_balance();
            cout << l << endl;
            break;
        }
        default:
        {
            cout << "select any of the functionalities either for exit press 6\n";
            break;
        }
        }
    } while (n != 6);
    cout << "exited from bank window successfully";
}