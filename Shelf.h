/**********************************************
* File: Shelf.h
* Author: Aaron Reardon, Carson Lance, Joeseph Gripenstraw, Matthew Dadamio
* Email: areardon@nd.edu, clance1@nd.edu, jgripens@nd.edu, mdadamio@nd.edu
*  
**********************************************/

#include <stdexcept>
#include "node.h"
#include "Bottle.h"
template<typename T>
class Shelf {
	public:
		Node<T> *head;
		Node<T> *tail;
		Shelf<T>();
		~Shelf<T>();
		Node<T>* insert(T value, bool*);
		void deleteNode(Node<T>* key);
		bool first = true;
};

/**********************************************
* File: Shelf.cpp
* Author: Aaron Reardon, Carson Lance, Joeseph Gripenstraw, Matthew Dadamio
* Email: areardon@nd.edu, clance1@nd.edu, jgripens@nd.edu, mdadamio@nd.edu
*  
**********************************************/

/********************************************
* Function Name  : Shelf<T>
* Pre-conditions : none
* Post-conditions: none
* This is the constructor 
********************************************/
template <class T>
Shelf<T>::Shelf() {
	// new Node() creates a Node will a nullptr
	this->head = new Node<T>();
}

/********************************************
* Function Name  : ~Shelf<T>
* Pre-conditions : none
* Post-conditions: none
* This is the destructor 
********************************************/
template <class T>
Shelf<T>::~Shelf() {
	Node<T>* current = head;

	while (current != nullptr) {
		Node<T>* next = current->head;
		delete current;
		current = next;
	}

	head = nullptr;
}

/********************************************
* Function Name  : insert
* Pre-conditions : T value and bool*
* Post-conditions: none
* This will insert a Node into the DLList 
********************************************/
template <class T>
Node<T>* Shelf<T>::insert(T value, bool* check){
	Node<T>* iter = head; // Creates an iterator with the node class that starts at the head
	if (first) { // Checks to see if this is the first value in the list
		Node<T>* newNode = new Node<T>(value);
		head = newNode;
		*check = true;
		first = false;
		return newNode;
	}
	while (iter != NULL) {
		// Checks to see if the value should be the new head
		if ((*(iter->getData()) > value) && (iter->tail == NULL)) {
			Node<T>* tempNode = new Node<T>(value);
			tempNode->tail = iter;
			iter->tail = tempNode;
			*check = true;
			return tempNode;
		}
		// Normal insert
		if (*(iter->getData()) > value) {
			Node<T>* tempNode = new Node<T>(value);
			tempNode->tail = iter->tail;
			tempNode->head = iter;
			iter->tail = tempNode;
			iter->tail->tail->head = tempNode;
			*check = true;
			return tempNode;
		}
		// This will output the node when the row has already been inserted
		if (*(iter->getData()) == value) {
			return iter;
		}
		// This is when the list has been totally parsed
		if(iter->head == nullptr){break;}
		iter = iter->head;
	}
	// this is when you are making a new tail
	Node<T>* tempNode = new Node<T>(value);
	if(iter != nullptr)
	{
		tempNode->tail = iter;
	}
	else{tempNode->tail = nullptr;}
	if(iter != nullptr){iter->head = tempNode;}
	
	*check = true;
	return tempNode;
}

/********************************************
* Function Name  : deleteNode
* Pre-conditions : T key
* Post-conditions: none
* This will delete a node from the DLList 
********************************************/
template <class T>
void Shelf<T>::deleteNode(Node<T>* key){  //key is pointer to Node to be deleted
	if(head == nullptr)
		throw std::out_of_range("No items in the Shelf");
		if(key->tail == nullptr && key->head == nullptr){head=new Node<T>();first=true;}
	//Node<T>* current = head;
	//Node<T>* previous = nullptr;

	// If the value is not the head or tail
	if(key->tail != nullptr && key->head != nullptr)
	{
		head = key->head;
		key->tail->head = key->head;
		key->head->tail = key->tail;
	}
	// If the value is the head
	else if(key->head != nullptr && key->tail == nullptr)
	{
		head = key->head;
		key->head->tail = nullptr;
	}
	// If the value is the tail
	else if(key-> tail != nullptr && key->head == nullptr)	//=>key->head == nullptr
	{
		key->tail->head = key->head;
	}
	else
	{
		first = 1;
		head = new Node<T>();
	}
	key->tail = nullptr;
	key->head = nullptr;
}

