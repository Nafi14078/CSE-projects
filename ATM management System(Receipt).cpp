#include <iostream>
#include <fstream>  // Added for file handling
#include <iomanip>
#include <string>
#include <stdlib.h>
#include<ctime>
#include<stdexcept>

using namespace std;

class Bank
{
public:

    double limit;

    Bank()
    {
        //constructor
    }

    virtual void setLimit(double newLimit)
    {
        //virtual function
    }
    virtual double getLimit()const
    {
        //virtual function
    }

     ~Bank()
    {
        // destructor
    }


};
class Limit:public Bank
{

public:
        // Setter function to set the withdrawal limit
        void setLimit(double newLimit) override
        {
            if (newLimit > 0)
            {
                limit = newLimit;
            }
            else
            {
                cout<<"Invalid limit value.";
            }
        }
        // Getter function to retrieve the withdrawal limit
        double getLimit() const override
        {
            return limit;
        }
    };

class ATMAccountHolders //: public Bank
{
    string accountHolder;
    string accountHolderAddress, branch;
    int accountNumber;
    double startBalance;
    double accountBalance;
    double accountInterest;
    double amount;
    int count;

public:
    ATMAccountHolders()
    {
        // Initialize default values
        accountNumber = 210041263;
        accountHolder = "Asif Rayhan";
        accountHolderAddress = "IUT";
        startBalance = 60000.00;
        accountBalance = 60000.00;
        branch = "AB Bank";
    }

    void deposit();
    void withdraw();
    void details();
    void payBills();
    void accountExit();
    void interest();
    void saveToFile();  // Added function to save account details to a file
    void readFromFile();  // Added function to read account details from a file
    void showTransactionHistory();
    void clearTransactionHistory();
};
void ATMAccountHolders::showTransactionHistory()
{
    try
    {

        system("cls");
        ifstream inFile("transaction_history.txt");

        if (!inFile.is_open())
        {
            throw runtime_error("No transaction history found.");
            return;
        }

        cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACcount Transaction History \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";

        string line;
        while (getline(inFile, line))
        {
            cout << line << endl;
        }

        inFile.close();
        cout<<"\n\n\tPress any key to Return to the Main Menu\n\n";
        system("PAUSE");
        system("cls");
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}
void ATMAccountHolders::clearTransactionHistory()
{
    try
    {

        ofstream outFile("transaction_history.txt", ofstream::out | ofstream::trunc);

        if (!outFile.is_open())
        {
            throw runtime_error("Error opening file for clearing transaction history.");
            return;
        }

        outFile.close();
        system("cls");
        cout << "\tTransaction history cleared.\n";
        cout<<"\n\n\tPress any key to Return to the Main Menu\n\n";
        system("PAUSE");
        system("cls");

    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

void ATMAccountHolders::interest()
{

    system("cls");
    cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACcount INTEREST PAYMENT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
    cout<<"\t\tThe Interest is calculated over the last 1 year on the present available balance\n\n";
    cout<<"\n\t\tInterest Rate payable is 5% per annual."<<endl<<endl;
    cout<<"\t\tView the accumulated interest? Press any key...\n\n";

    system("pause");
    system("cls");

    cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACcount INTEREST PAYMENT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";

    cout<<"\tAccountHolder name :"<<accountHolder<<"\n\n";
    cout<<"\tThe Account Holders' address is :"<<accountHolderAddress<<"\n\n";
    cout<<"\tThe Bank name is :"<<branch<<"\n\n";
    cout<<"\tAccount number :"<<accountNumber<<"\n\n";
    cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
    cout<<"\tStarting account balance :BDT" << startBalance<<"\n\n";
    cout<<"\tOne year ago the available balance :BDT" << accountBalance<<"\n\n";
    accountInterest=accountBalance*0.05*1;
    cout<<"\tAfter 1 year,the interest will be:BDT"<< accountInterest<<endl<<endl;
    accountBalance=accountBalance+accountInterest;
    cout<<"\tAfter 1 year,the total available balance will be:BDT"<< accountBalance<<endl<<endl;
    cout<<"\tPress any key to Return to the Main Menu\n\n";
    system("PAUSE");
    system("cls");
}

void ATMAccountHolders::deposit()
{
    try
    {


        system("cls");
        cout << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACcount DEPOSIT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
        cout<<"\tAccountHolder name :"<<accountHolder<<"\n\n";
        cout<<"\tThe Account Holders' address is :"<<accountHolderAddress<<"\n\n";
        cout<<"\tThe Bank name is :"<<branch<<"\n\n";
        cout<<"\tAccount number :"<<accountNumber<<"\n\n";
        cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
        cout<<"\tStarting account balance :BDT" << startBalance<<"\n\n";
        cout<<"\tPresent available balance :BDT" << accountBalance<<"\n\n";
        cout<<"\tEnter the Amount to be Deposited :BDT";

        double amount;
        cin >> amount;
        cout << "\n\n";

        if (amount < 0)
        {

            throw invalid_argument("Deposited amount cannot be negetive");

        }
        else if(amount==0)
        {
            throw invalid_argument("Invalid diposited amount. Amount must be greater than 0.");

        }

        else
        {
            accountBalance = accountBalance + amount;

            // Open the file in append mode to add the transaction to the history
            ofstream outFile("transaction_history.txt", ios::app);

            if (!outFile.is_open())
            {
                cout << "Error opening file for writing transaction history.\n";
                return;
            }

            // Write deposit information to the file
            time_t now;
            time(&now);
            outFile << "\t\tDeposited amount is : " << amount << " BDT"<<"//"<<"Transaction Time:"<<ctime(&now)<<endl;


            outFile.close();

            cout << "\n\tYour new available Balance is: BDT" << accountBalance << endl;
            cout << "\n\t\t\tThank You!\n\n" << endl;
            cout<<"\nWant to Print the receipt?Press 1 for yes or press 0 for no"<<endl;
            int i;
            cin>>i;
            if(i==1)
            {
                system("cls");
                cout<< "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM Receipt Voucher \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                cout<<"\n\t\tAccount Holder name: Asif Rayhan"<<endl;
                cout<<"\t\tAccount Holder Address:IUT"<<endl;
                cout<<"\t\tDeposited Amount is:"<<amount<< "BDT"<<endl;
                cout<<"\t\tTransaction time:"<<ctime(&now);
                cout<<"\t\tCurrent Balance:"<<accountBalance<< "BDT"<<endl;
                cout<<"\t\tBank name:AB Bank"<<endl;
                cout<< "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                cout << "\n\nPress any key to Return to the Main Menu\n\n";
                system("PAUSE");
                system("cls");

            }
            if(i==0)
            {

                cout<<"\t\tThank you"<<endl;
                cout << "\nPress any key to Return to the Main Menu\n\n";
                system("PAUSE");
                system("cls");
            }
        }
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;

        cout<<"\n\t\tThank you"<<endl;
        cout << "\nPress any key to Return to the Main Menu\n\n";
        system("pause");
        system("cls");
    }
}


void ATMAccountHolders::withdraw()
{
    try
    {

        system("cls");
        cout << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACcount WITHDRAWAL \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";

        cout<<"\tAccountHolder name :"<<accountHolder<<"\n\n";
        cout<<"\tThe Account Holders' address is :"<<accountHolderAddress<<"\n\n";
        cout<<"\tThe Bank name is :"<<branch<<"\n\n";
        cout<<"\tAccount number :"<<accountNumber<<"\n\n";
        cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
        cout<<"\tStarting account balance :BDT" << startBalance<<"\n\n";
        cout<<"\tPresent available balance :BDT" << accountBalance<<"\n\n";
        cout<<"\tEnter the Amount to be Withdrawn BDT";


        double amount;
        cin >> amount;
        cout<<"\n\n";
        Limit withdrawalLimit;
        withdrawalLimit.setLimit(10000.0);


        if (amount > accountBalance)
        {

            throw invalid_argument ("Insufficient  Balance in your account.");

        }
        else if(amount<=0)
        {
            throw invalid_argument("Withdrawal amount cannot be 0 or negetive\n\n");

        }

        else if (amount > withdrawalLimit.getLimit())
        {

            throw invalid_argument("Withdrawal limit excceded\n\n");

        }

        else
        {
            accountBalance = accountBalance - amount;

            // Open the file in append mode to add the transaction to the history
            ofstream outFile("transaction_history.txt", ios::app);

            if (!outFile.is_open())
            {
                cout << "Error opening file for writing transaction history.\n";
                return;
            }

            // Write withdrawal information to the file
            system("cls");
            cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACcount WTHDRAWAL \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
            cout<<"\tAccountHolder name :"<<accountHolder<<"\n\n";
            cout<<"\tThe Account Holders' address is :"<<accountHolderAddress<<"\n\n";
            cout<<"\tThe Bank name is :"<<branch<<"\n\n";
            cout<<"\tAccount number :"<<accountNumber<<"\n\n";
            time_t now;
            time(&now);
            outFile << "\t\tWithdrawal amount is : " << amount << " BDT"<<"//"<<"Transaction Time:"<<ctime(&now)<<endl;
            outFile.close();

            system("cls");
            cout << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACcount WITHDRAWAL \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
            cout << "\tYour new available Balance is BDT" << accountBalance << endl << endl;
            cout << "\t\t\tThank you" << endl;
            cout<<"\nWant to Print the receipt?Press 1 for yes or press 0 for no"<<endl;
            int i;
            cin>>i;
            if(i==1)
            {
                system("cls");
                cout<< "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM Receipt Voucher \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                cout<<"\n\t\tAccount Holder name: Asif Rayhan"<<endl;
                cout<<"\t\tAccount Holder Address:IUT"<<endl;
                cout<<"\t\tWithdrawal Amount is:"<<amount<< "BDT"<<endl;
                cout<<"\t\tTransaction time:"<<ctime(&now);
                cout<<"\t\tCurrent Balance:"<<accountBalance<< "BDT"<<endl;
                cout<<"\t\tBank name:AB Bank"<<endl;
                cout<< "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                cout << "\n\nPress any key to Return to the Main Menu\n\n";
                system("PAUSE");
                system("cls");

            }
            if(i==0)
            {
                cout << "\tPress any key to Return to the Main Menu\n\n";
                system("PAUSE");
                system("cls");
            }
        }
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;

        cout<<"\n\t\tThank you"<<endl;
        cout << "\nPress any key to Return to the Main Menu\n\n";
        system("pause");
        system("cls");
    }
}

void ATMAccountHolders::payBills()
{
    try
    {

        system("cls");


        cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM BILLS PAYMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";

        cout<<"\n\tAccountHolder name :"<<accountHolder<<"\n\n";
        cout<<"\tThe Account Holders' address is :"<<accountHolderAddress<<"\n\n";
        cout<<"\tThe Bank name is :"<<branch<<"\n\n";
        cout<<"\tAccount number :"<<accountNumber<<"\n\n";
        cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
        cout<<"Pay Electricity bill in BDT now?\n\n";
        cout<<"\t\tPress 1 for Yes OR Press 0 for No\n\n";

        int r;

        cin>>r;
        system("cls");
        cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM BILLS PAYMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";
        cout<<"\nEnter bill in BDT:\n"<<endl;
        if(r==1)
        {
            int bill;
            cin>>bill;
            if(bill<accountBalance)
            {
                accountBalance=accountBalance-bill;
                ofstream outFile("transaction_history.txt", ios::app);

                if (!outFile.is_open())
                {
                    cout << "Error opening file for writing transaction history.\n";
                    return;
                }

                // Write deposit information to the file
                time_t now;
                time(&now);
                outFile << "\t\tBill pay amount is : " << bill << " BDT"<<"//"<<"Transaction Time:"<<ctime(&now)<<endl;

                outFile.close();
                system("cls");
                cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM BILLS PAYMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";
                cout << "\n\tYour electricity bill of BDT " << bill << " has been paid.\n\n";

                cout<<"\tYour account new available balance is BDT" << accountBalance<<endl ;
                cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                cout<<"\nWant to Print the receipt?Press 1 for yes or press 0 for no"<<endl;
                int i;
                cin>>i;
                if(i==1)
                {
                    system("cls");
                    cout<< "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM Receipt Voucher \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                    cout<<"\n\t\tAccount Holder name: Asif Rayhan"<<endl;
                    cout<<"\t\tAccount Holder Address:IUT"<<endl;
                    cout<<"\t\tBill Paid:"<<bill<< "BDT"<<endl;
                    cout<<"\t\tTransaction time:"<<ctime(&now);
                    cout<<"\t\tCurrent Balance:"<<accountBalance<< "BDT"<<endl;
                    cout<<"\t\tBank name:AB Bank"<<endl;
                    cout<< "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                    cout << "\n\nPress any key to Return to the Main Menu\n\n";
                    system("PAUSE");
                    system("cls");

                }
                if(i==0)
                {

                    cout<<"\n\t\tThank you"<<endl;
                    cout<<"Press any key to Return to the Main Menu\n\n";
                    system("PAUSE");
                    system("cls");

                }
            }

            else
            {
                throw invalid_argument("Insufficient Balance..Sorry!!");
            }

        }
        if(r==0)
        {
            system("cls");
            cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM BILLS PAYMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";
            cout<<"\n\n\tExiting Bill Payment System.\n\n";
            cout<<"====================THANK YOU============================\n\n";
            system("PAUSE");
            system("cls");

        }

    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;

        cout<<"\n\t\tThank you"<<endl;
        cout << "\nPress any key to Return to the Main Menu\n\n";
        system("pause");
        system("cls");
    }
}


void ATMAccountHolders::details()
{

    system("cls");


    cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACcount DETAILS \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
    cout<<"\tAccountHolder name :"<<accountHolder<<"\n\n";
    cout<<"\tThe Account Holders' address is :"<<accountHolderAddress<<"\n\n";
    cout<<"\tThe Bank name is :"<<branch<<"\n\n";
    cout<<"\tAccount number :"<<accountNumber<<"\n\n";
    cout<<"\tAvailable balance:"<<accountBalance<<"\n\n";
    cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
    cout<<"Press any key to Return to the Main Menu\n\n";

    system("PAUSE");
    system("cls");
}

void ATMAccountHolders::accountExit()
{
    system("cls");
    cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACcount EXIT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";
    exit(1);
}

void ATMAccountHolders::saveToFile()
{
    try
    {


        ofstream outFile("account_details.txt");
        if (outFile.is_open())
        {
            outFile << accountNumber << endl;
            outFile << accountHolder << endl;
            outFile << accountHolderAddress << endl;
            outFile << branch << endl;
            outFile << startBalance << endl;
            outFile << accountBalance << endl;
            outFile.close();
        }
        else
        {
            throw runtime_error("Unable to save account details to file.");
        }
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}


void ATMAccountHolders::readFromFile()
{
    try
    {

        ifstream inFile("account_details.txt");
        if (inFile.is_open())
        {
            inFile >> accountNumber;
            inFile.ignore(); // Ignore the newline character
            getline(inFile, accountHolder);
            getline(inFile, accountHolderAddress);
            getline(inFile, branch);
            inFile >> startBalance;
            inFile >> accountBalance;
            inFile.close();
        }
        else
        {
            throw runtime_error("Unable to read account details from file.");
        }
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

int main()
{
    try
    {

        ATMAccountHolders p;

        int e;

        // Read account details from file
        p.readFromFile();

        system ("Color 3f");
        cout<<"\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb WELCOME TO ATM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
        //Prompt to show today's date
        cout << "\n\t\t\t\t\tCurrent date : ";
        //Show date and time function
        time_t now;
        time(&now);

        cout<<ctime(&now);
        //Give space for the function of date and time

        cout<<"\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
        cout<<"\n\t\t\t\t\tPress [1] to Enter into Account \n\n";
        cout<<"\t\t\t\t\tPress [0]  to Get Help.\n\n";

        int access;
        cin>>access;
        switch(access)
        {
        case 1://account number to access account
            system("cls");
            int i,account_number,pin;

            cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACcount ACCESS \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
            cout<<"\n\nEnter Your Account number to Access! [Only one attempt is allowed]\n\n"<<endl;
            cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
            cout<<"Forget Account Number?"<<endl;
            cout<<"\nTry to contact Your Bank Representative!!"<<endl;
            cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";

            cin>>account_number;
            system("cls");

            if(account_number==210041263)

            {
                system("cls");
                cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACcount ACCESS \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                cout<<"\n\nEnter your account pin number![only one attempt is allowed]\n\n"<<endl;
                cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                cout<<"Forget pin Number?"<<endl;
                cout<<"\nTry to contact Your Bank Representative!!"<<endl;
                cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                cin>>pin;
                system("cls");
                if(pin==263)
                {
                    system("cls");

                    do
                    {
                        cout << endl << "\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM Main Menu Screen \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n" << endl;
                        cout << "\t\tEnter [1] To  Deposit Cash" << endl;
                        cout << "\t\tEnter [2] To Withdraw Cash" << endl;
                        cout << "\t\tEnter [3] To Check AccountHolder details" << endl;
                        cout << "\t\tEnter [4] To Pay Bills" << endl;
                        cout << "\t\tEnter [5] To See Account Interest" << endl;
                        cout << "\t\tEnter [6] To Show Transaction History" << endl;
                        cout << "\t\tEnter [7] To Clear Transaction History" << endl;
                        cout << "\t\tEnter [0] To Exit ATM" << endl << endl;
                        cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
                        cout << "\n\n\tPLEASE ENTER A SELECTION AND PRESS ENTER TO CONTINUE: \n";
                        cin >> e;

                        switch (e)
                        {
                        case 1:
                            p.deposit();
                            p.saveToFile();  // Save account details after each transaction
                            break;

                        case 2:
                            p.withdraw();
                            p.saveToFile();  // Save account details after each transaction
                            break;

                        case 3:
                            p.details();
                            break;

                        case 4:
                            p.payBills();
                            p.saveToFile();  // Save account details after each transaction
                            break;

                        case 5:
                            p.interest();
                            p.saveToFile();  // Save account details after each transaction
                            break;
                        case 6:
                            p.showTransactionHistory();
                            p.saveToFile();
                            break;
                        case 7:
                            p.clearTransactionHistory();
                            p.saveToFile();
                            break;

                        case 0:
                            p.accountExit();
                            break;

                        default:
                            cout << "\n\t\tInvalid Input. Please Enter valid Input.\n";
                        }
                    }
                    while (e != 0);
                    break;
                }
                else
                {
                    system("cls");
                    cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACcount ACCESS \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";

                    throw invalid_argument("You had made your attempt which failed!!! No More attempts allowed!! Sorry!!\n\n");
                    cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";

                    //system("PAUSE");
                    exit (1);
                }

            case 0://pin to access account
                system("cls");
                cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACcount HELP CENTER \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                cout<<"\tYou must have the correct account number as well as pin number to access this account. See your\n\n";
                cout<<"\t  bank representative for assistance during bank opening hours\n\n";
                cout<<"\t\tThanks for, your choice today!!\n\n";
                cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                system ("PAUSE");
                exit(1);
                break;

            }
            else
            {
                system("cls");
                cout<<"\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ATM ACcount ACCESS \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";

                throw invalid_argument("You had made your attempt which failed!!! No More attempts allowed!! Sorry!!\n\n");
                cout<<"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";

                //system("PAUSE");
                exit (1);
            }

            //system("PAUSE");
        }

    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

