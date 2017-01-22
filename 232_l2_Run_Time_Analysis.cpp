/*
Name: Victoria Hagan
Date: 3/20/15
Assignment:  Run Time Analysis
Platform/IDE: Windows/VS2013

Description:
This code includes a O(n) function {printNums}, and 
a O(n^2) function {bubblesort}. It then takes an user
inputed amount of elements, and outputs the runtime of 
the earlier functions. This program is mainly used for 
run time analysis. 
*/

// vector::begin/end
#include <iostream>
#include <vector>
#include <time.h>   // for clock

/*
using std::string;
using std::cout;
using std::cin;
using std::vector;
*/
using namespace std;


void bubbleSort(vector<int>::iterator first, vector<int>::iterator last)
{
	vector<int>::iterator i, j;
	for (i = first; i != last; ++i)
		for (j = first; j < i; ++j)
			if (*i < *j)
				iter_swap(i, j);
}

// my O(n) function 
void printNums(int n){
	for (int i = 0; i < n; i++)
		cout << i; 
	cout << endl << endl; 
}

int main()
{
	clock_t startTime1, endTime1, startTime2, endTime2; //itializes time stamps
	int elements; // number of elements in vector to be sorted
	std::cout << "please input an interger:" << endl;
	std::cin >> elements;
	vector<int> myvector;
	for (int i = 1; i <= elements; i++) myvector.push_back(rand());  // random contents to vector

	
	startTime1 = clock(); //time stamp of begin bubblesort
	bubbleSort(myvector.begin(), myvector.end());
	endTime1 = clock();  //time stamp of end bubblesort

	std::cout << "Execution time is " <<
		double(endTime1 - startTime1) / (double)CLOCKS_PER_SEC << " seconds." << endl << endl;

	/*
	cout << "myvector contains:";
	for (vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
	cout << *it << '\n';
	*/

	startTime2 = clock();  //time stamp of begin printNums
	printNums(elements);
	endTime2 = clock();  //time stamp of end printNums

	std::cout << "Execution time is " <<
		double(endTime2 - startTime2) / (double)CLOCKS_PER_SEC << " seconds." << endl << endl;
	
	int timeItTook = clock();  // Returns the processor time consumed by the program. 
	// printf ("Sorting %d items took %d clicks (%f seconds).\n", elements, timeItTook, ((float)timeItTook)/CLOCKS_PER_SEC);
	cout << "Sorting " << elements << " items took " << timeItTook << " clicks (" << (((float)timeItTook) / CLOCKS_PER_SEC) << "  seconds)." << endl;
	
	system("PAUSE");  //Pause for visual effect
	return 0; 
}
