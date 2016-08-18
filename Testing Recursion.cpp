#include <iostream>

bool partition(int arr[], int sum, int i)
{

   // Base Case
   if (sum == 0)
     return true;
   if (i == 0 && sum != 0)
     return false;
 
   // ignore last element if it's greater than sum
   if (arr[i-1] > sum)
     return partition(arr, i-1, sum);

   return partition(arr, i-1, sum) || partition(arr, i-1, sum-arr[i-1]);


}
int main()
{	
	int arr[20];
	int n, total= 0, sum=0, i=0;
	bool answer;
	std::cout << "Enter number of integers of set A: " << std::endl;
	std::cin >> n;
	std::cout << "Enter " << n << " integers: " << std::endl;
	for(i=0;i<n;i++)
	{
		std::cin >> arr[i];
		sum+=arr[i];
	}
	
	answer = partition(arr, sum, n);
	if(answer == true)
		std::cout<<"Yes!"<<std::endl;
	else std::cout<<"No!"<<std::endl;

	return 0;
}