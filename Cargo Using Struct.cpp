#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct Cargo //Cargo Struct
{
	int height;
    int width;
    int length;
    double weight;
    string label;
	void initCargo(int Height, int Width, int Length, double Weight, string Label)//Input for cargo
    {
        height = Height;
        weight = Weight;
        length = Length;
        label = Label;
        width = Width;
    }
    double cargoWeight()//Returns weight
    {
        return weight;
    }
    int cargoVolume() //Returns volume
    {
        return length * width * height; 
    }
    void printCargo()
	{
		cout << length << " X " << height << " X " << width << setw(9) << cargoVolume() << setw(13) << weight << setw(16) << label << endl;
	}  //Prints stats in arranged format

};
void loadPlane(Cargo *allCargo, int &size, double usedWeight, double maxWeight, int maxVolume, int usedVolume); //The input function
void printTable(Cargo * allCargo, int size); //Prints stat table
void maxweight(Cargo * allCargo, int size, int maxweight); //Calculates unused weight
void maxvolume(Cargo * allCargo, int size, int maxvolume); //Calculates unused volume
void heaviestWeight(Cargo * allCargo, int size); //Finds the heaviest weight
void largestVolume(Cargo * allCargo, int size); //Finds the largest volume

int main()
{
	Cargo allCargo[25]; //array of all cargo
	double usedweight = 0, maxWeight = 50000.00; 
	int usedvolume = 0, maxVolume = 300000;
	int size = 0;

	loadPlane(allCargo, size, 0, maxWeight, maxVolume, 0);
	maxweight(allCargo, size, maxWeight);
	maxvolume(allCargo,size, maxVolume);
	heaviestWeight(allCargo, size);
	largestVolume(allCargo, size);
	
	cout << "--- Table of Cargo Containers ---" << endl;
	cout << "Dimensions" << setw(12) << "Volume"<< setw(12) << "Weight" << setw(12)<< "Label" << endl;
	printTable(allCargo, size);


	return 0;
}

void loadPlane(Cargo *allCargo, int &size, double usedWeight, double maxWeight, int maxVolume, int usedVolume)
{
	int height, width, length, i;
    double weight;
    string label;

	for (i = 0; i<30; i++) // User cargo input info
	{
		cout << "Input Label: ";
		cin >> label;
		if (label != "quit")
		{
		cout << "Input Weight: "; 
        cin >>weight;
			while(weight < 0)
			{
				cout << "Input Weight: ";
				cout << "No Negative Numbers! Try again!" << endl; // Negative number check
				cin >> weight;
			}
        cout << "Input Height: ";
        cin >> height;
			while(height < 0)
			{
				cout << "Input Height: ";
				cout << "No Negative Numbers! Try again!" << endl;
				cin >> height;
			}
        cout << "Input Width: ";
        cin >> width;
			while(width < 0)
			{
				cout << "Input Width: ";
				cout << "No Negative Numbers! Try again!" << endl;
				cin >> width;
			}
        cout << "Input Length: ";
        cin >> length;
			while(length < 0)
			{
				cout << "Input Length: ";
				cout << "No Negative Numbers! Try again!" << endl;
				cin >> length;
			}
        cout << endl;

		usedWeight += weight;
		usedVolume += height*width*length;
		}
		else 
		{	
			size = i;
			break;
		}

		if (usedWeight < maxWeight && usedVolume< maxVolume) 
        {	
            allCargo[i].initCargo(height, width, length, weight, label);
            usedWeight = weight + usedWeight;
            usedVolume = length * width *height + usedVolume;
        }

	}

}

void printTable(Cargo *allCargo, int size)
{
	for(int i = 0; i < size; i++) 
	{
		allCargo[i].printCargo();
	}
	cout << endl;
}

void maxweight(Cargo *allCargo, int size, int maxWeight)
{
	int weightused=0;
	for(int i=0; i<size; i++)
		weightused+=allCargo[i].weight;
	cout << "Maximum Weight: " << maxWeight << endl;
	cout << "Unused Weight:  " << maxWeight - weightused << endl;
	cout << endl;

}

void maxvolume(Cargo *allCargo, int size, int maxVolume)
{
	int volumeused=0;
	for(int i=0; i<size; i++)
		volumeused+=allCargo[i].cargoVolume();
	cout << "Maximum Volume: " << maxVolume << endl;
	cout << "Unused Volume:  " << maxVolume - volumeused << endl;
	cout << endl;
}

void heaviestWeight(Cargo *allCargo, int size)
{
	int heaviest=0;
	for(int i=0; i<size; i++)
	{
		allCargo[i].weight;
		if(allCargo[i].weight>heaviest)
		{
			heaviest=allCargo[i].weight;
		}
	}
	cout << "Heaviest container weighed: " << heaviest << endl;
}
void largestVolume(Cargo * allCargo, int size)
{
	int largest=0;
	for(int i=0; i<size; i++)
	{
		allCargo[i].cargoVolume();
		if(allCargo[i].cargoVolume()>largest)
		{
			largest=allCargo[i].cargoVolume();
		}
	}
	cout << "Largest container had volume of " << largest << " cubic inches" << endl;
	cout << endl;
}