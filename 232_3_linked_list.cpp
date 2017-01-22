/*
Name: Victoria Hagan
Date: 3/1/2015
Assignment:  Asn4
Platform/IDE: Windows/VS2013

Description:
This code contains 2 classes; Node and Linked List. 
These classes were coded in Template E.
Node is the standard node class for C++ (and other languages).
Linked List is a class that creates a singly linked list and 
has basic operations to check for emptiness, fill the list, 
and empty list, as well as options for transversing the list. 
There is also a method to print the list and a method that will 
sort the list from least to greatest (which, might I say, I am
incredibly proud of).
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <exception>
#include <time.h>
#include <iomanip>

using namespace std;

//--------------NODE_CLASS.h----------------

template <typename E> // E for Element.
class Node{
private:
	E element;
	Node<E>* next;
	template <typename E> friend class LinkedList;
};

//----------LINKED_LIST_CLASS.h--------------
template <typename E>
class LinkedList{
private:
	Node<E>* head;  // pointer to 1st element
	Node<E>* iterator;  //iterator
public:
	LinkedList();  //constructor
	~LinkedList();  //deconstructor

	/*      Basic Operations     */
	bool isEmpty() const; //list empty?
	// Get front element.
	const E& getFront() const;
	// Add element to front.
	void addToFront(const E& e);
	// Delete front element.
	void removeFromFront();

	/*     Transversing the List     */
	// Reset the iterator to head before using.
	void reset(); 
	// Returns true if there's another node after iterator.
	bool hasNext(); 
	// Return the element at the iterator
	const E& getElement() const; 
	// Advance the iterator to the next node.
	void advItr(); 


	/*      ASN4 Additional Code     */
	// Sort the elements of the list. 
	void sortList();
	//Print the elements of the list. 
	void printList();



};

//-----------ASN4.CPP----------------

//Constructor. 
template <typename E>
LinkedList<E>::LinkedList(){
	head = NULL;
	iterator = head; 
};

//Destructor.
template <typename E>
LinkedList<E>::~LinkedList(){
	while (!isEmpty())
		removeFromFront();
};

/*     Basic Operations     */

//Is the list empty?
template <typename E>
bool LinkedList<E>::isEmpty() const{
	return head == NULL;
};

//Get the front element.
template <typename E>
const E& LinkedList<E>::getFront()const{
	return head->element; 
};

//Add to the front of the list.
template <typename E>
void LinkedList<E>::addToFront(const E& e){
	Node<E>* node = new Node < E > ;
	node->element = e;  //store the new data
	node->next = head; //old head now follows new node
	head = node; //set new node to head
	if (iterator == NULL){ //in the case of the first node
		iterator = head;
	};
	
};

//Remove from the of the list.
template <typename E>
void LinkedList<E>::removeFromFront(){
	Node<E>* old = head;  //save the current head 
	if (!isEmpty()){
		head = old->next;  //skip over the old head
		if (iterator == old){  // if the iterator points the node to be deleted
			iterator = head;
		};
		delete old;
	};
};


/*     Methods for Transversing the List     */

// Set the iterator back to head. 
template <typename E>
void LinkedList<E>::reset(){
	iterator = head; 
}; 

// Check if the iterator is pointing to tail.
template <typename E>
bool LinkedList<E>::hasNext(){
	return (iterator != NULL ? true : false);
}

// Get the Element at the iterator location. 
template <typename E>
const E& LinkedList<E>::getElement()const{
	if (iterator != NULL){
		return iterator->element;
	}
	else {
		return NULL;
	};
};

// Advance the iterator.
template <typename E>
void LinkedList<E>::advItr(){
	if (iterator != NULL){
		iterator = iterator->next;
	};
};

/*     Methods for ASN4    */

// Print the elements of the list.
template <typename E>
void LinkedList<E>::printList(){
	reset();
	do{
		E data = getElement();
		cout << data << endl;
		advItr();
	} while (hasNext());

};

// Sort the elements of the list.
template <typename E>
void LinkedList<E>::sortList(){
	//Itialize holding varibles for link swapping. 
	Node<E>* currentN = head;  //set a node to the currently observed element
	Node<E>* nextN = currentN->next;  //set a node to the next element after obeserved element
	Node<E>* previousN = head;  //set a node to the previous element before observed element (ititally same as observed)
	Node<E>* holder = NULL;  //set a temporary element to store information during swap

	do{
		//Check to see if the Current's data is greater than Next's data.
		if (currentN->element > nextN->element){
			//This part of the fuction executes if...
			// 1) Current's data > Next's data. Now, check the location of Current.
			if (currentN == head){
				//This part of the fuction executes if...
				// 1) Current's data > Next's data, 2) Current != head, respectively.
				holder = nextN->next;  //hold Next's link for later swap
				previousN->next = nextN;  //set Previous's link to Next 
				nextN->next = currentN;  //set  Next's link to Current
				currentN->next = holder;  //set Current's link to saved Next's link in holder

				head = nextN;  //set the head to new head of the list (Next)

				// Since a swap has been made, return to the begining of the list. 
				// Reititalize values to begining of list. 
				currentN = head; 
				nextN = currentN->next; 
				previousN = head;
				
			}
			else if (nextN != NULL){
				//This part of the fuction executes if...
				// 1) Current's data > Next's data, 2) Current != head, and 3) Next != NULL, respectively.
				holder = nextN->next;  //hold Next's link for later swap
				previousN->next = nextN;  //set Previous's link to Next
				nextN->next = currentN;  //set Next's link to Current
				currentN->next = holder;  //set Current's link to saved Next's link in holder
				
				// Since a swap has been made, return to the begining of the list. 
				// Reititalize values to begining of list.
				currentN = head;
				nextN = currentN->next;
				
				previousN = head;
			}
			//This part of the fuction is reached if...
			// 1) Current's data > Next's data, 2) Current != head, and 3) Next == NULL, respectively.
			//We have found the end of the list. 
		}
		else{
			//This part of the function executes if...
			// 1) Current's data < Next's data.
			//Advance all elements to next element and continue sort. 
			previousN = currentN;  //set Previous to Current
			currentN = nextN;  //set Current to Next 
			nextN = nextN->next;  //set Next to the node after Next
		};
	} while (nextN != NULL); //will exit when the end of the list has been found. 
};

// This function returns specifically a random number with two decimal places. 
float randomNumber(){
	float x, y, z, b;
	x = (rand() % 9 + 1);  //the ones place
	y = (rand() % 9 + 1);  //the tenths place
	z = (rand() % 9 + 1);  //the hundreths place
	y = y / 10;
	z = z / 100;
	b = x + y + z; //the random number itself. 
	return b;
};

int main(){
	srand(time(NULL));
	LinkedList<float> SLL;
	for (int i = 0; i < 10; ++i){
		float num = randomNumber();
		SLL.addToFront(num);
	};
	SLL.printList();
	cout << endl; 
	SLL.sortList(); 
	SLL.printList();

	system("PAUSE"); 

};