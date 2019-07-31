/*************************************
 * File name: testRowFinal.cpp
 * Author: Matthew DaDamio, Carson Lance, Aaron Reardon, Joseph Gripenstraw
 * Email: mdadamio@nd.edu, clance1@nd.edu, areardon@nd.edu, jgripens@nd.edu
 *
 *  This file is the new test file for the row  queue.
 * ***********************************/

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "bottleDate.h"
#include "Bottle.h"
#include "bottleQueue.h"

using namespace std;
/*********************************
 * Function name: main()
 * Preconditions: int argc, char *argv[]
 * Postconditions: int
 *
 * This function is the main driver 
 * function that tests the row.
 * Creates three bottles and three
 * Row Data Structures
 ***********************************/
int main(int argc, char *argv[])
{
	// Creates Bottles
	BottleDate date(1, 23, 2019);
	Bottle bottle1("Azithromycin", 45, date);
	BottleDate date2(1,23,2018);
	Bottle bottle2("Lisinopril",45,date2);
	Bottle bottle3("Azithromycin",45,date2);
	BottleQueue queue1;
	BottleQueue queue2;
	BottleQueue queue3;
	// put first bottle in first row and so on
	queue1.push(bottle1);
	queue2.push(bottle2);
	queue3.push(bottle3);
	// print the contents using a peek() type function
	cout << "queue1: " << queue1.front();
	cout << "queue2: " << queue2.front();
	cout << "queue3: " << queue3.front();

//test overloaded functions
if (queue1 < queue2){cout << "queue1 < queue2" << endl;}
if (queue2 < queue1){cout << "queue2 < queue1" << endl;}
if (queue1 < queue3){cout << "queue1 < queue3" << endl;}
if (queue2 < queue3){cout << "queue2 < queue3" << endl;}

if (queue1 > queue2){cout << "queue1 > queue2" << endl;}
if (queue2 > queue1){cout << "queue2 > queue1" << endl;}
if (queue1 > queue3){cout << "queue1 > queue3" << endl;}
if (queue2 > queue3){cout << "queue2 > queue3" << endl;}

if (queue1 != queue2){cout << "queue1 != queue2" << endl;}
if (queue2 != queue1){cout << "queue2 != queue1" << endl;}
if (queue1 != queue3){cout << "queue1 != queue3" << endl;}
if (queue2 != queue3){cout << "queue2 != queue3" << endl;}

if (queue1 == queue2){cout << "queue1 == queue2" << endl;}
if (queue2 == queue1){cout << "queue2 == queue1" << endl;}
if (queue1 == queue3){cout << "queue1 == queue3" << endl;}
if (queue2 == queue3){cout << "queue2 == queue3" << endl;}

return 0;

}

