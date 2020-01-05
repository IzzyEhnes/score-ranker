// Izzy Ehnes
// CS 10B, Section 3031
// a5_2.cpp
// 9/24/18
//
// DESCRIPTION:
// This program garners user input for names and their corresponding scores.
// It then sorts the scores and ranks the names from highest to lowest score.



#include <iostream>
using namespace std;



void initializeArrays(string[], int[], int);
void sortData(string[], int[], int);
void displayData(const string[], const int[], int);



int main()
{
	string *p1;
	int *p2 = 0, size = 0;
	
	cout << "How many scores will you enter?: ";
	cin >> size;
	
	p1 = new string[size];
	p2 = new int[size];
	
	initializeArrays(p1, p2, size);
	sortData(p1, p2, size);
	displayData(p1, p2, size);
		
	
	return 0;
}







void initializeArrays(string names[], int scores[], int size)
{
	string name;
	int score;
	
	for (int count = 0; count < size; count++)
	{
		cout << "Enter the name for score #" << (count +1) << ": ";
		cin >> name;
		names[count] = name;
		
		cout << "Enter the score for score #" << (count +1) << ": ";
		cin >> score;
		scores[count] = score;
		
	}
}






void sortData(string names[], int scores[], int size)
{
	bool swap;
	int scores_temp;
	string names_temp;

	do
	{
	    swap = false;
	    
	    for (int count = 0; count < (size - 1); count++)
	    {
	        if (scores[count] < scores[count + 1])
	        {
	        	scores_temp = scores[count];
	        	names_temp = names[count];
	            scores[count] = scores[count + 1];
	            names[count] = names[count + 1];
	            scores[count + 1] = scores_temp;
	            names[count + 1] = names_temp;
	            swap = true;
	        }
	    }
	} while (swap);
}






void displayData(const string names[], const int scores[], int size)
{
	cout << "\nTop scorers: \n";
	
	for (int count = 0; count < size; count++)
	{
		cout << names[count] << ": ";
		cout << scores[count] << endl;
	}
}


/* SAMPLE OUTPUT:

How many scores will you enter?:  5
Enter the name for score #1:  Dee
Enter the score for score #1:  200
Enter the name for score #2:  Frank
Enter the score for score #2:  400
Enter the name for score #3:  Charlie
Enter the score for score #3:  -100
Enter the name for score #4:  Dennis
Enter the score for score #4:  300
Enter the name for score #5:  Mac
Enter the score for score #5:  100

Top scorers: 
Frank: 400
Dennis: 300
Dee: 200
Mac: 100
Charlie: -100

*/