

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
int Find (int x, int A[], int n);	
using namespace std;

int main()
{	
	int x = 0;
	int bound;
	
	srand((unsigned)time(0));		

	int n = 50;				
	double q;			
					
	double calculated_avg, real_avg;
	int Sequence[50];	
	int **Sequences = 0;			
	Sequences = new int *[10000] ;
	for( int i = 0 ; i < 10000 ; i++ )
		Sequences[i] = new int[50];

	cout<<left<<setw(20)<<"Bound"<<setw(25)<<"Calculated Average"<<"Real Average\n";
	cout<<"------------------------------------------------------------"<<endl;
	
	for (int i=0; i<=6;i++)
	{
		switch(i)
		{
		case 0 :bound = 30;
			break;
		case 1: bound =50;
			break;
		case 2: bound = 80;
			break;
		case 3: bound = 100;
			break;
		case 4: bound =1000;
			break;
		case 5: bound = 10000;
			break;
		case 6: bound = 1000000000;
			break;

		}

		double hits = 0;

	for (int k=0; k<10000; k++)
	{
		for (int i = 0; i<n; i++)
		{
			Sequence [i] = ( rand() % (bound + 1) ) ;	
			Sequences [k][i] = Sequence [i];
		}
		
		if ((Find (x, Sequence, n))>0)	 
			hits++;	  		
	}
	
	q= hits / 10000;				
	
	calculated_avg = ( n + q / 2 - q * n / 2 );	
	
	double total_steps = 0;
	
	for (int k=0; k<10000; k++)				

	{
		for (int i=0; i<n; i++)
			Sequence [i] = Sequences [k][i];
		
		if ((Find (x, Sequence, n))>0)
			total_steps = total_steps + (Find (x, Sequence, n));
		else
			total_steps = total_steps + n;
	}
	
	
	real_avg = (total_steps)/10000;
	
	cout<<left<<setw(24)<<bound<<setw(23)<<calculated_avg<<real_avg<<endl;
			
} 

	for( int i = 0 ; i < 10000 ; i++ )		
		delete [] Sequences[i] ;
		delete [] Sequences;
	
	return 0;
}



int Find (int x, int A[], int n)				
{
	
	int j;
	
	for (j=0; j<n; j++)						//the position is 1 more than the index
	{
		if (x==A[j])
			return (j+1);				
	}
	
	return 0;							//x is not an element of the array
};

