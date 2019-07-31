#pragma once

/*************************************
 * File name: bottleQueue.h
 * Author: Matthew DaDamio, Carson Lance, Aaron Reardon, Joseph Gripenstraw
 * Email: mdadamio@nd.edu, clance1@nd.edu, areardon@nd.edu, jgripens@nd.edu
 *
 *  This file is a header for our BottleQueue
 *  class.
 * ***********************************/


#include <queue>
#include "Bottle.h"
using namespace std;

class BottleQueue {

	public:
		BottleQueue();
		bool empty();
		int size();
		Bottle& front();
		Bottle front() const;
		Bottle& back();
		void pop();
		void push(Bottle bot);
		bool operator < (const BottleQueue& comp);
		bool operator > (const BottleQueue& comp);
		bool operator == (const BottleQueue& comp);
		bool operator != (const BottleQueue& comp);
		
	private:
		queue<Bottle> wrappedQueue;
		 
};
