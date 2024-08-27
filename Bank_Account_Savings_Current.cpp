#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account
{
protected:
    string account_holder;
    int account_number;
    string account_type;

public:
    void SetData(string holder, int number, string type)
    {
        account_holder = holder;
        account_number = number;
        account_type = type;
    }
};

class SavingsAccount : public Account
{
private:
    float interest_rate = 0.035;
    double principle_amount;

    void addInterest(void)
    {

        principle_amount = principle_amount * (1 + interest_rate);
    }

public:
    void Initialize_Savings(string holder, int number, string type, double balance)
    {
        SetData(holder, number, type);
        principle_amount = balance;
        addInterest();
    }
    void DepositBalance(int number, int amount)
    {
        if (account_number == number)
        {
            principle_amount += amount;
            addInterest();
            cout << "Balance updated successfully." << endl;
            cout << "Available balance: " << principle_amount << endl;
        }
        else
            cout << "Invalid A/C number." << endl;
    }

    void Withdrawal(int number, int amount)
    {
        if (account_number == number)
        {
            if (amount <= principle_amount)
            {
                principle_amount -= (double)amount;
                cout << "Rupees " << amount << " deducted from account." << endl;
                cout << "Available balance: " << principle_amount << endl;
            }
            else
            {
                cout << "Donot have sufficient amount of balance." << endl;
            }
        }
        else
            cout << "Invalid A/C number." << endl;
    }

    void Display(int number)
    {
        if (number == account_number)
        {
            cout << endl;
            cout << "Account Holder: " << account_holder << endl;
            cout << "Account Number: " << account_number << endl;
            cout << "Account Type: " << account_type << endl;
            cout << "Available Balance: " << principle_amount << endl;
        }
        else
            cout << "Invalid A/C number." << endl;
    }
};

class CurrentAccount : public Account
{
private:
    double principle_amount;
    double minimum_balance = 3000.0;
    double service_charge = 250.0;

    void checkMinimumBalance(void)
    {
        if (principle_amount < minimum_balance)
        {
            principle_amount -= service_charge;
            cout << "Balance is low!! \n Service charge applied. New balance is: " << principle_amount << endl;
        }
    }

public:
    void Initialize_Current(string holder, int number, string type, double balance)
    {
        SetData(holder, number, type);
        principle_amount = balance;
        checkMinimumBalance();
    }
    void DepositBalance(int number, int amount)
    {
        if (account_number == number)
        {
            principle_amount += amount;
            cout << "Balance updated successfully." << endl;
            cout << "Available balance: " << principle_amount << endl;
        }
        else
            cout << "Invalid A/C number." << endl;
    }

    void Withdrawal(int number, int amount)
    {
        if (account_number == number)
        {
            if (amount <= principle_amount)
            {
                principle_amount -= (double)amount;
                cout << "Rupees " << amount << " deducted from account." << endl;
                cout << "Available balance: " << principle_amount << endl;
            }
            else
            {
                cout << "Donot have sufficient amount of balance." << endl;
            }
            checkMinimumBalance();
        }
        else
            cout << "Invalid A/C number." << endl;
    }

    void Display(int number)
    {
        if (account_number == number)
        {
            cout << endl;
            cout << "Account Holder: " << account_holder << endl;
            cout << "Account Number: " << account_number << endl;
            cout << "Account Type: " << account_type << endl;
            cout << "Available Balance: " << principle_amount << endl;
        }
        else
            cout << "Invalid A/C number." << endl;
    }
};

int main()
{
    SavingsAccount Savings;
    CurrentAccount Current;

    string account_holder, account_type;
    double balance;
    int choice, account_number;

    cout << "Type of account (savings or current): ";
    cin >> account_type;
    cout << "Enter account holder name: ";
    cin.ignore();
    getline(cin, account_holder);
    cout << "Enter account number: ";
    cin >> account_number;
    cout << "Enter opening balance: ";
    cin >> balance;

    if (account_type == "savings" || account_type == "Savings")
    {

        Savings.Initialize_Savings(account_holder, account_number, account_type, balance);

        Savings.Display(account_number);
    }

    else if (account_type == "current" || account_type == "Current")
    {
        Current.Initialize_Current(account_holder, account_number, account_type, balance);
        Current.Display(account_number);
    }
    else
        cout << "Invalid Account type!!" << endl;

    do
    {
        cout << endl;
        cout << "1.Check A/C details: " << endl;
        cout << "2.Deposit balance: " << endl;
        cout << "3.Withdraw amount: " << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter A/C number: ";
            cin >> account_number;
            if (account_type == "savings" || account_type == "Savings")
                Savings.Display(account_number);
            else
                Current.Display(account_number);
            break;

        case 2:
            cout << "Enter deposit balance: ";
            cin >> balance;
            cout << "Enter A/C number: ";
            cin >> account_number;
            if (account_type == "savings" || account_type == "Savings")
                Savings.DepositBalance(account_number, balance);
            else
                Current.DepositBalance(account_number, balance);
            break;

        case 3:
            cout << "Enter withdrawal balance: ";
            cin >> balance;
            cout << "Enter A/C number: ";
            cin >> account_number;
            if (account_type == "savings" || account_type == "Savings")
                Savings.Withdrawal(account_number, balance);
            else
                Current.Withdrawal(account_number, balance);
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid Choice!!" << endl;
        }

    } while (choice != 4);

    return 0;
}