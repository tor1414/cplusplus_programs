/*
Name: Victoria Hagan
Date: 1/19/2015
Assisnment: Assn1
Platform/IDE: Windows/VS2013

Desciption: 
This edited program will produce the seleceted interger followed by one's age. 
This is produced after many numerical functions act on the interger through a loop. 
*/
#include <cstdlib>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;

int main(){
	//this is the additional parlor trick code.
	for (int i = 1; i < 10; i++){
		int x = i;
		x = x * 2;
		x = x + 5;
		x = x * 50;
		x = x + 2014;
		x = x - 250;
		x = x - 1994;
		std::cout << "Current chosen value is " << i << ", so the three-digit number is " << x << "." << std::endl ; 
	}
	system("pause");
}