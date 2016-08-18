#include <iostream>
#include <cstdlib>
using namespace std;

int love(int num);
int school(int num);
int finance(int num);
void main()
{
	int num, q;
	char letter, ans;
	bool done = false;
	ans = 'y';
	while (ans == 'y' || ans == 'Y')
      {
		cout << "Please enter your lucky number" << endl;
		cin >> num; //Prompt the user for his/her lucky number. Use this number as input to the srand function found in cstdlib
		q = 2;
		while (q == 2)
		{ //  Prompt the user for which life topic he wishes his predictions based.  Based on the user's response call one of three functions. 
		
			cout << "Please enter the letter \"L\" for my predictions on your love life. " << endl;
			cout << "Please enter the letter \"S\" for my predictions on your school life. " << endl;
			cout << "Please enter the letter \"M\" for my predictions on your financial situation. " << endl;
			cin >>  letter;

		  // Use a nested if-else statement to control which function is called.
			if (letter == 'L' || letter == 'l')
				{
					cout << endl << "I am looking into my crystal ball" << endl;
					love(num);
					q = 3;
				}
			else if( letter == 'S' || letter == 's')
				{
					cout << endl << "I am looking into my crystal ball" << endl;
					school(num);
					q = 3;
				}
			else if( letter == 'M' || letter == 'm')
				{
					cout << endl << "I am looking into my crystal ball" << endl;
					finance(num);
					q = 3;
				}
			else 
				{
					cout << "Wrong input. Please Try again:" << endl << endl;
					q = 2;
				}	
		}
		
		//Prompt the user to see if they want another prediction. Keep executing the program until the user tells you to quit.  
		//Make sure that you code for all possible user inputs, including wrong ones.
		cout << "Thank you for using the computer psychic network." << endl;
		cout << "Would you like me to do another prediction? y/n " << endl;		
		cin >> ans;
	}
	
}

int love(int num)
{
	int luv = 0;
	srand(num);
	luv += rand()%5;// Call the rand function

	switch(luv)//Use value generated by the rand function and modulo division as the selector expression in a switch statement.
	{
		case 0:
			cout << endl << "You will lose the one you love most!" << endl << endl; //The switch statement will print out the predictions.
		break;
		case 1:
			cout << endl << "Your love life is in for a surprise tomorrow!" << endl << endl; 
		break;
		case 2:
			cout << endl << "Beware of green eyes!" << endl << endl; 
		break;
		case 3:
			cout << endl << "Your past love will come running back to you!" << endl << endl; 
		break;
		case 4:
			cout << endl << "You will rekindle a broken relationship!" << endl << endl; //Allow for five different predictions per function
		break;
	}
	return luv;
}

int school(int num)
{
	int skl = 0;
	srand(num);
	skl += rand()%5;// Call the rand function

	switch(skl)//Use value generated by the rand function and modulo division as the selector expression in a switch statement.
	{
		case 0:
			cout << endl << "You will have a surprise quiz tomorrow!!" << endl << endl; //The switch statement will print out the predictions.
		break;
		case 1:
			cout << endl << "There will be hair in your cafeteria food!" << endl << endl; 
		break;
		case 2:
			cout << endl << "Beware of the spilled soda after Math class!" << endl << endl; 
		break;
		case 3:
			cout << endl << "One of your teachers will be absent soon!" << endl << endl; 
		break;
		case 4:
			cout << endl << "Look under your teachers desk to find a special small gift!" << endl << endl; //Allow for five different predictions per function
		break;
	}
	return skl;
}

int finance(int num)
{
	int money = 0;
	srand(num);
	money += rand()%5;// Call the rand function

	switch(money)//Use value generated by the rand function and modulo division as the selector expression in a switch statement.
	{
		case 0:
			cout << endl << "Your promotion is only a few days away!" << endl << endl; //The switch statement will print out the predictions.
		break;
		case 1:
			cout << endl << "You will lose your job, but in a good way!" << endl << endl; 
		break;
		case 2:
			cout << endl << "You will find some money on your way to work!" << endl << endl; 
		break;
		case 3:
			cout << endl << "Be careful with your investments in the coming months!" << endl << endl; 
		break;
		case 4:
			cout << endl << "You will run into a bunch of money!" << endl << endl; //Allow for five different predictions per function
		break;
	}
	return money;
}