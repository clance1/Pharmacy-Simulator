#pragma once
/*************************************
 * * File name: node.h
 * * Author: Carson Lance, Aaron Reardon, Matthew Dadamio, Joseph Gripenstraw
 * * Email: clance1@nd.edu, areardon@nd.edu, mdadamio@nd.edu , jgripens@nd.edu
 * *
 * * This is the header for the Node class.
 * * ***********************************/
#include "Bottle.h"

template<class T>
class Node {
	public:
		Node();
		Node(const Node&);
		Node(T);
		Node operator=(const Node&);
		Node<T>* getTail() const;
		void setTail(Node*);
		Node<T>* getHead() const;
		void setHead(Node*);
		T* getData();
		void setData(T);
		Node<T>* head;
		Node<T>* tail;
		T data;

};

#pragma once
/*************************************
 * * File name: node.cpp
 * * Author: Carson Lance, Aaron Reardon, Matthew Dadamio, Joseph Gripenstraw
 * * Email: clance1@nd.edu, areardon@nd.edu, mdadamio@nd.edu , jgripens@nd.edu
 * *
 * * This is the implementation for the Node class.
 * * ***********************************/

#include "node.h" 

template<class T>
Node<T>::Node()
{
	head = nullptr;
	tail = nullptr;
}

template<class T>
Node<T>::Node(T d)
{
	head = nullptr;
	tail = nullptr;
	data = d;
}
template<class T>
Node<T> Node<T>::operator=(const Node& right)
{
	Node left;	
	left.setTail(right.getTail());
	setData(right.getData());
	return left;
}

template<class T>
Node<T>* Node<T>::getTail() const
{
	return tail;
}

template<class T>
void Node<T>::setTail(Node* newTail)
{
	newTail = tail->getTail();
}

template<class T>
Node<T>* Node<T>::getHead() const
{
	return head;
}

template<class T>
void Node<T>::setHead(Node* newHead) 
{
	head = newHead->getHead();

}

template<class T>
T* Node<T>::getData() 
{
	return &data;
}

template<class T>
void Node<T>::setData(T value)
{
	T data;
	data = value;
}
