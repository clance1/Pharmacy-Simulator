#pragma once

/*************************************
 * File name: BottleQueue.cpp
 * Author: Matthew DaDamio, Carson Lance, Aaron Reardon, Joseph Gripenstraw
 * Email: mdadamio@nd.edu, clance1@nd.edu, areardon@nd.edu, jgripens@nd.edu
 *
 *  This file is an implementation for our Bottle queue.
 * ***********************************/

#include <queue>
using namespace std;

#include "Bottle.h"
#include "bottleQueue.h"

/*********************************************
 * Function Name: BottleQueue 
 * Preconditions: none  
 * Postconditions: none  
 * Empty Constructor
 * ******************************************/
BottleQueue::BottleQueue() {
	
 }

/*********************************************
 * Function Name: size
 * Preconditions: void 
 * Postconditions: int 
 * Returns size
 * *******************************************/
int BottleQueue::size(){return wrappedQueue.size();}
/*********************************************
 * Function Name: empty
 * Preconditions: none 
 * Postconditions: bool 
 * Returns true if queue is empty
 * *******************************************/
bool BottleQueue::empty() {
	return wrappedQueue.empty();
}

/*********************************************
 * Function Name: front() 
 * Preconditions: none  
 * Postconditions: Bottle&  
 * Returns the address to the front element in 
 * the bottle queue 
 * ******************************************/
Bottle& BottleQueue::front() {
	return wrappedQueue.front();
}

/*********************************************
 * Function Name: front() 
 * Preconditions: none  
 * Postconditions: Bottle&  
 * Returns the address to the front element in 
 * the bottle queue 
 * Const Function
 * ******************************************/
Bottle BottleQueue::front() const {
	return wrappedQueue.front();
}

/*********************************************
 * Function Name: back() 
 * Preconditions: none  
 * Postconditions: Bottle&  
 * Returns the address to the back element in 
 * the bottle queue 
 * ******************************************/
Bottle& BottleQueue::back() {
	return wrappedQueue.back();
}

/*********************************************
 * Function Name: pop() 
 * Preconditions: none  
 * Postconditions: none
 * Removes the top element from 
 * the bottle queue 
 * ******************************************/
void BottleQueue::pop() {
	wrappedQueue.pop();
}

/*********************************************
 * Function Name: push 
 * Preconditions: Bottle bot 
 * Postconditions: none 
 * Pushes an element into the queue (top of the 
 * stack)
 * *******************************************/ 
void BottleQueue::push(Bottle bot) {
	wrappedQueue.push(bot);
}

/*********************************************
 * Function Name: operator < 
 * Preconditions: const BottleQueue& comp
 * Postconditions: bool
 * 
 * Compares the front elements of this queue 
 * to the passed one using the < operator and
 * returns the result
 * *******************************************/

bool BottleQueue::operator < (const BottleQueue& comp) {
	if (this->front() < comp.front())
		return true;
	else
		return false;
}

/*********************************************
 * Function Name: operator > 
 * Preconditions: const BottleQueue& comp
 * Postconditions: bool
 * 
 * Compares the front elements of this queue 
 * to the passed one using the > operator and
 * returns the result
 * *******************************************/

bool BottleQueue::operator > (const BottleQueue& comp) {
	if (this->front() > comp.front())
		return true;
	else
		return false;
}

/*********************************************
 * Function Name: operator == 
 * Preconditions: const BottleQueue& comp
 * Postconditions: bool
 * 
 * Compares the front elements of this queue 
 * to the passed one using the == operator and
 * returns the result
 * *******************************************/

bool BottleQueue::operator == (const BottleQueue& comp) {
	if (this->front() == comp.front())
		return true;
	else
		return false;
}

/*********************************************
 * Function Name: operator != 
 * Preconditions: const BottleQueue& comp
 * Postconditions: bool
 * 
 * Compares the front elements of this queue 
 * to the passed one using the != operator and
 * returns the result
 * *******************************************/ 

bool BottleQueue::operator != (const BottleQueue& comp) {
	if (this->front() != comp.front())
		return true;
	else
		return false;
}
