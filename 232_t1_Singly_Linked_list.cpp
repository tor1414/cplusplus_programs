/*
Name: Victoria Hagan
Date:03.25.15
Assignment: Midterm Exam Part 2 Recapture
Platform/IDE: Windows/VS2013

Description:
This is a singly linked list with vector applications. 
The vector operations have been adjusted to work with a list structure. 
The push_back and insert functions have been reprogrammed to function. 
*/

#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include <cstdlib>
//#include <memory>

using std::cout; using std::endl;
using std::string; 

//** Template class for nodes of singly linked list. */
template <typename E>
class Node {
private:
	E elem;  //datatype independent element
	Node<E>* next;  //next list item

	Node<E>* operator =(const Node<E>* rhs);  //node pointer overload for = 
	bool operator ==(const Node<E>& rhs) const;  //overload for ==

	// Give SLinkedList access to Node object
	template <typename E> friend class SLinkedList;
};

/* Overload assignment for node* = node* (not my code) */
template <typename E>
Node<E>* Node<E>::operator =(const Node<E>* rhs) {
	if (this != rhs) {  //ignore self-assignment
		elem = rhs->elem;
		next = rhs->next;
	}
	return this;  //return pointer for assignment chaining (a=b=c)
}

/* Overload assignment for node == node (not my code)*/
template <typename E>
bool Node<E>::operator ==(const Node<E>& rhs) const {
	return (this == &rhs);
}

template <typename E>
class SLinkedList {
public:
	SLinkedList();  //constructor
	~SLinkedList();  //destructor

	/* Vector Operations */
	bool empty() const;  //is list empty?
	int size() const;  //get number of elements
	const E& front() const;  //get first element
	const E& back() const;  //get last element
	const E& at(const int pos) const;  //get element at index
	void insert(const int pos, const E& e);  //insert at index
	void push_back(const E& e);  //append to end of list

	/* Supplementary Methods */
	void removeFront();  //delete front element.
	Node<E>* retrieve(const int index) const;  //retrieve node pointer at index
	bool swap(Node<E>* m, Node<E>* n);  //swap positions of 2 nodes
	void insertionSort();  //by swapping nodes

	/* Printing */
	void printList() const;  //print the list
	void printDetails() const;  //print details of list

private:
	Node<E>* head;  //head of list
	Node<E>* backptr;  //last node
	Node<E>* itr;   //list iterator
	int listSize;  //size of list
};

// Constructor. (not my code)
template <typename E>
SLinkedList<E>::SLinkedList() {
	head = nullptr;
	itr = head;
	listSize = 0;
	backptr = head;
}

// Destructor. (not my code)
template <typename E>
SLinkedList<E>::~SLinkedList() {
	while (head != nullptr)
		removeFront();
}

/*---------------------------------------------------
*  Vector Operations
*/
//get number of elements (good)
template < typename E > 
int SLinkedList<E>::size() const{
	return listSize; 
}

//get first element (good)
template < typename E > 
const E& SLinkedList<E>::front() const{
	return head->elem; 
}

//get last element (good)
template < typename E > 
const E& SLinkedList<E>::back() const{
	return backptr->elem; 
}

//get element at index (good)
template < typename E > 
const E& SLinkedList<E>::at(const int pos) const{
	return retrieve(pos)->elem; 
}


// Delete the node at the specified position, then 
// add a new node there with element = e.
// *** Was addFront(). Modify this method. ***
template < typename E > 
void SLinkedList<E>::insert(const int pos, const E& e) {
	Node<E>* node = new Node < E > ;
	Node<E>* temp1 = NULL;
	Node<E>* temp2 = NULL; 
	node->elem = e;
	
	if (empty()){
		node->next = head; 
		head = node; 
		backptr = node; 
		listSize++;
	}
	else if (pos < 0){
		cout << "Error: index less than bounds. " << pos << endl;
	}
	else if (pos == 0){
		temp1 = head;
		node->next = temp1->next;
		delete temp1;
		head = node;
	}
	else if (pos > 0 && pos < (size() - 1)){
		temp1 = retrieve(pos);
		node->next = temp1->next;
		delete temp1;
		retrieve(pos - 1)->next = node;
	}
	else if (pos == (size() - 1)){
		temp1 = retrieve(pos - 1);
		temp2 = backptr;
		node->next = NULL;
		delete temp2;
		temp1->next = node;
		backptr = node;
	}

	else if (pos == (size())){
			push_back(e);
		}
	else if (pos > size()){
		cout << "Error: index greater than bounds. " << pos << endl;
	}
	if (itr == nullptr)  //give itr a value so it's not invalid
		itr = head;
}

//append to end of list (good)
template <typename E>
void SLinkedList<E>::push_back(const E& e){
	Node<E>* node = new Node < E >;
	node->elem = e;
	node->next = NULL;
	if (head==nullptr) 
		backptr = head = node; 
	else{
		backptr->next = node;
		backptr = node;
	}
	listSize++; 
}

//is list empty? (not my code)
template <typename E>
bool SLinkedList<E>::empty() const {
	return (head == nullptr);
}


// Remove front element and delete it. Required for destructor. (not my code)
template <typename E>
void SLinkedList<E>::removeFront() {
	Node<E>* old = head;
	if (!empty()) {
		head = old->next;
		if (itr == old)  //itr was pointing at node to delete
			itr = head;
		delete old;
		listSize--;
	}
}

// Retrieve a pointer to the node at index (not my code)
template <typename E>
Node<E>* SLinkedList<E>::retrieve(const int index) const {
	Node<E>* itr;

	// Boundary conditions
	if ((index < 0) || (index >= size())) {
		cout << "Error: index out of bounds." << index << endl;
		exit(EXIT_FAILURE);
	}

	//traverse list and return a pointer to node at index
	itr = head;
	for (int i = 0; i < index; i++) {
		itr = itr->next;
	}
	return itr;
}

/** Swap two adjacent nodes. Need pointers to 3 nodes
(2  nodes if one is head) to do the swap.  (not my code)*/
template <typename E>
bool SLinkedList<E>::swap(Node<E>* m, Node<E>* n) {
	Node<E>* itr;

	if (m->next != n)  //nodes aren't adjacent
		return false;

	itr = head;
	if (m != head) {  //advance itr to node before m
		while (itr->next != m) {
			itr = itr->next;
		}
		// Make the swap
		m->next = n->next;
		n->next = itr->next;
		itr->next = n;
	}
	else { //use head for the swap
		head->next = n->next;
		n->next = head;
		head = n;
	}
	return true;
}

/** Insertion sort  (not my code)*/
template <typename E>
void SLinkedList<E>::insertionSort() {
	int j;
	Node<E>* cur;
	for (int i = 1; i < size(); i++) {
		cur = retrieve(i);
		j = i - 1;
		while ((j >= 0) && (retrieve(j)->elem > cur->elem)) {
			swap(retrieve(j), retrieve(j + 1));
			j--;
		}
	}
}

// Print the list (not my code)
template <typename E>
void SLinkedList<E>::printList() const {
	Node<E>* itr = head;
	int i = 0;

	cout << "{";
	while (itr->next != nullptr) {  //print all but last
		//cout << "itr = " << itr << endl;
		cout << itr->elem << ", ";
		itr = itr->next;
		//cout << "itr = " << itr << endl;
	}
	cout << itr->elem << "}" << endl;  //print last
}

// Print the list with node addresses for debugging (not my code)
template <typename E>
void SLinkedList<E>::printDetails() const {
	Node<E>* itr = head;
	int i = 0;
	while (itr != nullptr) {
		cout << "index: " << i << "  data: " << itr->elem
			<< "  node address: " << itr << endl;
		itr = itr->next;
		i++;
		//if (i > 8)  //for debugging if list becomes circular
		//	break;
	}
}

/* End class methods ----------------------------------*/

/** Template non-member test function */
template <typename E>
void test(SLinkedList<E>& list) {
	E e;
	cout << "... TESTING ..." << endl;

	cout << "List size is " << list.size() << endl;
	cout << "Element at 3 is " << list.at(3) << endl;

	cout << "test insert...\n";
	list.insert(list.size(), 9);  //insert at end
	list.push_back(8);  //same
	list.printDetails();
	cout << endl; 
	list.insert(2, 7);  //insert in middle
	list.printDetails();
	cout << endl; 
	list.insert(0, 6);  //insert at head
	list.printDetails();
	cout << endl; 
	cout << "Front is " << list.front() << endl;
	cout << "Back is " << list.back() << endl;

	list.insert(-1, 3);
	list.insert((list.size() + 2), 4);

	cout << "\n*** TESTING DONE ***" << endl;
	
}


/*---------------------------------------------------*/
int main(int argc, char *argv[]) {
	SLinkedList<int> list;

	// Create a test list
	for (int i = 0; i <= 5; i++) {
		list.insert(i, i);
	}
	cout << "Initial list" << endl;
	list.printDetails();

	test(list);  //Uncomment to test

	list.insertionSort();  //Uncomment when testing complete
	cout << endl << "Sorted list" << endl;
	list.printDetails();

	getchar();
	return(EXIT_SUCCESS);
}