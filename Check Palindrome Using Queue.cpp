#include <iostream>
#include <string>

struct arr_Queue
{
	char word[20];
	int tail;
	int length;
};
void Enqueue(arr_Queue myQueue, char s)
{
	
	if(myQueue.length < 20)
	{
		myQueue.tail++;
		myQueue.word[myQueue.tail] = s;
		myQueue.length++;
	}
}
void Dequeue(arr_Queue myQueue, char &s)
{
	if(myQueue.length > 0 || myQueue.tail >=0)
	{
		s = myQueue.word[0];
		for(int i = 0; i<myQueue.tail;i++)
		{
			myQueue.word[i] = myQueue.word[i+1];
			myQueue.tail--;
			myQueue.length--;
		}
	}
}
struct arr_Stack
{
	char arr[20];
	int top;
};
void push(arr_Stack myStack, char x)
{
	if(myStack.top < 19)
	{
		myStack.top++;
		myStack.arr[myStack.top] = x;
	}
}

void pop(arr_Stack myStack, char &x)
{
	if(myStack.top > -1)
	{
		x = myStack.arr[myStack.top];
		myStack.top--;
	}
}


int main()
{
	arr_Queue myQueue;
	arr_Stack myStack;
	myStack.top = -1;
	myQueue.tail = -1;
	myQueue.length = 0;
	std::string stuff;
	char single;
	char indiv = 0, indiv2 = 0;
	int notmatch = 0;
	std::cout << "Input string to be compared: " << std::endl;
	getline(std::cin, stuff);
	int num = stuff.size();
	for(int i = 0; i < num; i++)
	{	
		single = stuff[i];
		Enqueue(myQueue, single);
		push(myStack, single);

	}
	for(int i = 0; i < num; i++)
	{	
		pop(myStack, indiv);
		indiv = myStack.top;
		Dequeue(myQueue, indiv2);
		if(indiv == indiv2)
			notmatch++;
	}


	if(notmatch > 0)
		std::cout<< "This word is not a palindrome!" << std::endl;
	else std::cout<< "This word is a palindrome!" << std::endl;
	std::cout << std:: endl;

	return 0;
}

