#include <iostream>
#include <string>

struct Customer
{
	std::string CustomerName;
	int ArrivalTime;
	int ServiceTime;
	int FinishTime;
};

struct CustomerNode
{
		Customer data;
		CustomerNode *next;
};

struct FCFSQueue
{
	CustomerNode *head, *tail;
	int size;
};

bool IsEmpty(FCFSQueue myQueue)
{
	if(myQueue.size == 0)
		return true;
	else return false;
}
int GetLength(FCFSQueue myQueue)
{
	return myQueue.size;
}
void Enqueue(FCFSQueue & myQueue, Customer cus)
{	
	CustomerNode * temp = new CustomerNode;
	temp->data = cus;
	if(myQueue.size < 100)
	{
		if(myQueue.head == 0)
		{
			myQueue.head = myQueue.tail = temp;
			myQueue.size++;
		}
		else
		{
			myQueue.tail -> next = temp;
			myQueue.tail = temp;
			myQueue.tail -> next = myQueue.head;
			myQueue.size++;
		}
		
	}
	else std::cout << "the queue is full" << std::endl;
}
void Dequeue(FCFSQueue & myQueue,Customer & cus)
{
	CustomerNode * temp = myQueue.head;
	if(myQueue.head)
	{
		myQueue.head = myQueue.head->next;
		cus = temp->data;
		delete temp;
		if(!myQueue.head)
			myQueue.tail=0;
		myQueue.size--;
	}
}

int main()
{
	FCFSQueue myQueue;
	myQueue.tail = 0;
	myQueue.head = 0;
	myQueue.size = 0;
	Customer newCus;
	newCus.CustomerName = "Tom";
	newCus.ArrivalTime = 1;
	newCus.ServiceTime = 0;
	newCus.FinishTime = 0;
	Enqueue(myQueue, newCus);
	newCus.CustomerName = "Bob";
	newCus.ArrivalTime = 3;
	newCus.ServiceTime = 0;
	newCus.FinishTime = 0;
	Enqueue(myQueue, newCus);
	std::cout << "Current customer list:" << std::endl;
	CustomerNode * temp = myQueue.head;
	for(int i = 0; i < myQueue.size; i++)
	{
		std::cout << temp->data.CustomerName << std::endl;
		temp = myQueue.head->next;
	}
	std::cout << "Departing Customers: " << std::endl;
	Dequeue(myQueue, newCus);
	std::cout << newCus.CustomerName << std::endl;
	Dequeue(myQueue, newCus);
	std::cout << newCus.CustomerName << std::endl;
	Dequeue(myQueue, newCus);
	std::cout << newCus.CustomerName << std::endl;





	return 0;
}
