// Piotr Debicki

#include <iostream>
using namespace std;

//problem 1
int iterative(int num) //Iterative function
{
    int revNum = 0;
    while(num > 0)
    {
        revNum = revNum*10 + num%10;
        num = num/10;
    }
    return revNum;
}
//problem 2
int recursive(int num)//Recursive function
{
  static int revNum = 0; // reversed number storage
  static int base = 1; // base of revNum for each recursion
  if(num > 0)
  {
    recursive(num/10);
    revNum  += (num%10)*base;
    base *= 10;
  }
  return revNum;
}

int main()
{
	int num;
	cout << "type in a number: " << endl;
	cin >> num;
	cout <<"Reverse of your number using the iterative function is "<<  iterative(num) << endl;
	cout <<"Reverse of your number using the recursive function is "<<  recursive(num) << endl;

	return 0;

}
