#pragma once

#include<iostream>

using namespace std;

class clsDepositScreen:protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n============================================";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n============================================\n";

    }


public:

	static void ShowDepositScreen()
	{
        clsScreen::_DrawScreenHeader("\tDeposit Screen");

        string AccountNumber = "";
        double DepositAmount = 0;

        cout << "\nPlease Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient With ["<<AccountNumber<<"] Not exist.";

            cout << "\n\nPlease Enter Account Number : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);

        cout << "\nPlease Enter Deposit Amount : ";
        DepositAmount =  clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to Perform this Transactions ? y/n ? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

           Client1.Deposit(DepositAmount);

           cout << "\n\nDone Successfully.\n";
           cout << "\nNew Balance is : " << Client1.AccountBalance << endl;

        }
        else
        {
            cout << "\nOperation Was Canceeled.\n";
        }

	}

};

