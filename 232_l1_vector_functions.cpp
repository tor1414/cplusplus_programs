/*
Name: Victoria L. Hagan
Date: 02.13.2015
Assignment: Lab1
Platform/IDE: Windows/VS2013

Description:
This program allows the coder to gain understanding of vectors
from basic vector functions [ .size(), .resize(), .assign(), 
.pop_back(), .push_back(), .at(), .begin(), .end()] to more
complicated functions of interator, sort, shuffle, and insert.
*/

#include <cstdlib>
#include <iostream>
#include <algorithm> //sort, shuffle, insert
#include <vector> //vector functions
using  namespace std;

//create a comparison function for sort function
bool my_compare(int a, int b){
	return a < b;
}

int main(){
	//1)
	//i. ititalize a vector variable size of 5 
	//   each element = 99
	vector<int> nums(5, 99);

	//ii. use a for loop and .at() to print the elements
	for (int i = 0; i < nums.size(); i++){
		cout << nums.at(i) << endl;
	};
	
	//2)
	//   set all vector elements to 0 using .assign
	nums.assign(5, 0);
	cout << endl;

	//3)
	//i.   resize the vector to 7 elements
	nums.resize(7);
	//ii.  use a for loop and the .push_back method 
	//     to fill th vector with ints from 71 to 77
	//iii. add a cout statement to print
	int n = 71;
	for (int i = 0; i < nums.size(); i++){
		//.push_back appends to the end 
		// and that causes a contiuous loop
		nums[i] = n;
		n = n + 1;
		cout << nums.at(i) << endl;
	};

	//4) 
	//   .pop_back the last element
	nums.pop_back();
	cout << endl;

	//7)
	// create an iterator for the vector
	vector<int>::iterator it;
	it = nums.begin();

	//5)
	// insert 100 before the first element
	nums.insert(it, 100);

	//6)
	// resize the vector to 10
	nums.resize(10);
	cout << endl;
	
	//8)
	// use the iterator to print the vector elements
	for (it = nums.begin(); it != nums.end(); ++it){
		cout << (*it) << endl;
	};
	cout << endl;

	//9)
	// use the uterator to replace each element with 
	// a random number and print each new element 
	for (it = nums.begin(); it != nums.end(); ++it){
		int digit = (rand() % 100); 
		*it = digit; 
		cout << (*it) << endl; 
	};
	cout << endl;

	//10)
	//i. sort the vector then print it.
	sort(nums.begin(), nums.end(), my_compare);
	for (it = nums.begin(); it != nums.end(); ++it){
		cout << (*it) << endl;
	}
	cout << endl; 

	//ii. shuffle the vector then print it
	random_shuffle(nums.begin(), nums.end()); 
	for (it = nums.begin(); it != nums.end(); ++it){
		cout << (*it) << endl;
	}

	//pause for visual effect
	system("pause");
}