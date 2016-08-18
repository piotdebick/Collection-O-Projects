#include <iostream>
using namespace std;

int sortascend(int *x)
{ 
	int j, k, temp;
	for (j = 0; j < 10; j ++)
	{
		for (k = j+1; k < 10; k++)
		{
			if (x[k] < x[j]) 
			{
				temp = x[k];
				x[k] = x[j];
				x[j] = temp;	
				
			}
			
		}
	
	}
	return *x;
}

 int sortdescend(int *ptr)
{ 
	int j, k, temp;
	for (j = 0; j < 10; j ++)
	{
		for (k = j+1; k < 10; k++)
		{
			if (ptr[k] > ptr[j]) 
			{
				temp = ptr[k];
				ptr[k] = ptr[j];
				ptr[j] = temp;	
				
			}
			
		}
	
	}
	return *ptr;
}


int main()
{
	int numbers[10], temp, i, j, k,m,n;
	int *ptr[10],*ptr2[10];
	
	cout << "Enter 10 numbers, homie: " << endl;
	for (i = 0; i <10; i++)
	{
		cin >> numbers[i];
		ptr[i] = &numbers[i];
		ptr2[i] = &numbers[i];
	}
	sortascend(*ptr2);
	sortdescend(*ptr);
	
	cout << endl;
	
	cout << endl;
	for (m = 0; m<10; m++)
	{
		cout << *ptr2[m] << endl;
	}
		
	cout << endl;
	for (int i = 0; i<10; i++)
	{
		cout << *ptr[i] << endl;
	}
	cout <<endl;
	for (int i = 0; i<10; i++)
	{
		cout << numbers[i] << endl;
	}
	return 0;
}