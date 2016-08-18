#include <iostream> 
#include <string>
using namespace std;

// function prototype
bool verifyPhoneNum(string phoneNum);
string formatPhoneNum(string phoneNum);

int main()
{
	string phoneNum;
	bool check = true;

	do
	{
		cout << "Please enter a 10 digit phone number: ";
		getline(cin, phoneNum);
		check = verifyPhoneNum(phoneNum);
		if(check == false)
		{
			if(phoneNum.length() > 10)
				cout << "Number is either too long, or contains inappropriate character." << endl;
			else if(phoneNum.length() < 10)
				cout << "Number is either too short, or contains inappropriate character." << endl;
		}
	} while (check == false);

	cout<< formatPhoneNum(phoneNum)<<endl;
	return 0;
}
//This function formats the user entry and prints it out.
string formatPhoneNum(string phoneNum)
{
	string area, exchange, number;
	area = phoneNum.substr(0, 3);
	exchange = phoneNum.substr(3, 3);
	number = phoneNum.substr(6, 4);
	return "(" + area + ") " + exchange + "-" + number;
}
//This function verifys if the entry is 10 digits long and has digits only.
bool verifyPhoneNum(string phoneNum)
{
	bool check = true;
	if(phoneNum.length() == 10)
	{
		for (int i = 0; i < 10; i++)
		{
			if (phoneNum[i]<'0' || phoneNum[i]>'9')
				check = false;
			else
				check = true;
		}
	}
	else check = false;
	return check;
}