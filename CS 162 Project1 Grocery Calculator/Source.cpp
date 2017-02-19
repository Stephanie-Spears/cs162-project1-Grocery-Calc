#include <iostream>
#include <cstring> //need?
#include <cctype> //need?

using namespace std;

int CallMenu();
double CallPrice();

int main() //KNOWN BUG: ACCEPTS SPACE AS OPTION, NO REACTION 
{
	bool bRun_Code;
	bool bRun_Name;
	int iNum_Chars;
	int iMax_Char = 50;
	int iMenu_Result;
	char cProduct_Name[50];
	double dProduct_Price;
	double dProduct_Total = 0;


	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	cout.precision(2);


	cout << "Welcome to Shopsmart!" << endl << endl;

	bRun_Code = true;

	while (bRun_Code == true)
	{
		iMenu_Result = CallMenu();

		while (iMenu_Result != 3)
		{
			if (iMenu_Result == 1)
			{
				bRun_Name = true;

				while (bRun_Name == true)
				{
					cout << endl;
					cout << "Please enter the product name: " << endl;
					cin >> cProduct_Name;

					iNum_Chars = strnlen(cProduct_Name, '\n');

					if (iNum_Chars > iMax_Char)
					{
						cout << "Input Error. Characters must not exceed 49." << endl;
						cin.clear();
						cin.ignore(100, '\n');
					}
					else
					{
						cout << "Item Name: " << cProduct_Name << endl << endl;
						bRun_Name = false;
					}
				}

				dProduct_Price = CallPrice();
				dProduct_Total = dProduct_Total + dProduct_Price;
				cout << cProduct_Name << ": $" << dProduct_Price << endl;
				cout << "Running Total: $" << dProduct_Total << endl << endl;
				break; 
			}
			else if (iMenu_Result == 2)
			{
				cout << "Your Current Total is: $" << dProduct_Total << endl << endl;
				break; 
			}
			else
			{
				cout << "Unknown Error--Debug Message in Main. " << endl;
				break;
			}
		}
		if (iMenu_Result == 3)
		{
			cout << "Have a good day!" << endl << endl;
			bRun_Code = false;
		}
	}
	return (0);
}

int CallMenu()
{
	bool bValidInput;
	int iMenu_Result;

	bValidInput = true;

	while (bValidInput == true)
	{
		cout << "1) Add Item" << endl;
		cout << "2) Check Out" << endl;
		cout << "3) Quit" << endl;
		cout << "Enter Choice: ";
		cin >> iMenu_Result;

		if (iMenu_Result == 1)
		{
			cout << "You Chose Option 1. " << endl;
			return iMenu_Result;
		}
		else if (iMenu_Result == 2)
		{
			cout << "You Chose Option 2. " << endl;
			return iMenu_Result;
		}
		else if (iMenu_Result == 3)
		{
			cout << "You Chose Option 3. " << endl;
			return iMenu_Result;
		}
		else
		{
			cout << "Input error. Please choose an option from the menu." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	return (0);
}


double CallPrice()
{
	int iDollar;
	int iCents;
	double dProduct_Price;
	bool bRun_Price;


	bRun_Price = true;

	while (bRun_Price == true)
	{
		cout << endl;
		cout << "Please enter the product price in dollars: " << endl;
		cin >> iDollar;
		cout << "Please enter the price in cents: " << endl;
		cin >> iCents;

		if (cin.fail())
		{
			cout << "Input error. Please enter whole numbers only." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		else
		{
			cout << "Item PRICE: " << iDollar << "." << iCents << endl;
			bRun_Price = false;
		}
		
	}
	dProduct_Price = iDollar + (iCents / 100.0);
	return dProduct_Price;
}





/*

double CallPrice()
{
	char cDollar_Price[10];
	char cCents_Price[3];
	double dDollar;
	double dProduct_Price = 0.00; //need?
	int iNum_Chars;
	bool bRun_Price;



	bRun_Price = true;

	while (bRun_Price == true)
	{
		cout << endl;
		cout << "Please enter the dollar amount: " << endl;
		cin >> cDollar_Price;

		iNum_Chars = strnlen(cDollar_Price, '\n');

		for (int i = 0; i < iNum_Chars; i++) //is this if else going to g through each char one by one and evaluate true/false for each? Crash? Take out if/else
		{
			if (!isdigit(cDollar_Price[i]))
			{
				cout << "Input error. Please enter numbers only. " << endl;
				cin.clear();
				cin.ignore(100, '\n');
				break;
			}
		}

		
		
		dDollar = atoi(cDollar_Price);
	}

		return dProduct_Price;
}
*/

/*


What Your Program Should Do :
1. Allow the shopper(user) to enter in the product name and the cost.
This should be echoed and confirmed.Make sure to check for bad data.
2. The user should be allowed to continue this until they want to check out.
3. Your program needs to keep a running total.
4. Upon checkout, the grand total should be displayed.
5. Display money using proper formatting
You will need to have the following before displaying dollars and cents :
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint); cout.precision(2);

	*/