/*************************************
 * File name: testBottleFinalOut.cpp
 * Author: Matthew DaDamio, Carson Lance, Aaron Reardon, Joseph Gripenstraw
 * Email: mdadamio@nd.edu, clance1@nd.edu, areardon@nd.edu, jgripens@nd.edu
 *
 *  This file is a test file for the new overloaded bottle functions.
 * ***********************************/
 
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#include "bottleDate.h"
#include "Bottle.h"

void readFile(string, ifstream &);
void dispense(Bottle&, string, int, BottleDate); 

/*************************************
* Function name: main()
* Preconditions: int argc, char *argv[]
* Postconditions: int
*
* This is the main driver function. It creates two bottles,
* prints the contents, performs the operation for stock, 
* inspection, or script read in from the input file.
************************************/
int main(int argc, char *argv[]) {
	// Creates Bottles
	BottleDate date(1, 23, 2019);
	Bottle bottle1("Azithromycin", 45, date);
	BottleDate date2(1,23,2018);
	Bottle bottle2("Lisinopril",45,date2);
	Bottle bottle3("Azithromycin",45,date2);
	// Prints out Bottle contents
	cout << bottle1 << bottle2 << bottle3;
	
	//test overloaded functions
	if (bottle1 < bottle2){cout << "bottle1 < bottle2" << endl;}
	if (bottle2 < bottle1){cout << "bottle2 < bottle1" << endl;}
	if (bottle1 < bottle3){cout << "bottle1 < bottle3" << endl;}
	if (bottle2 < bottle3){cout << "bottle2 < bottle3" << endl;}

	if (bottle1 > bottle2){cout << "bottle1 > bottle2" << endl;}
	if (bottle2 > bottle1){cout << "bottle2 > bottle1" << endl;}
	if (bottle1 > bottle3){cout << "bottle1 > bottle3" << endl;}
	if (bottle2 > bottle3){cout << "bottle2 > bottle3" << endl;}

	if (bottle1 != bottle2){cout << "bottle1 != bottle2" << endl;}
	if (bottle2 != bottle1){cout << "bottle2 != bottle1" << endl;}
	if (bottle1 != bottle3){cout << "bottle1 != bottle3" << endl;}
	if (bottle2 != bottle3){cout << "bottle2 != bottle3" << endl;}

	if (bottle1 == bottle2){cout << "bottle1 == bottle2" << endl;}
	if (bottle2 == bottle1){cout << "bottle2 == bottle1" << endl;}
	if (bottle1 == bottle3){cout << "bottle1 == bottle3" << endl;}
	if (bottle2 == bottle3){cout << "bottle2 == bottle3" << endl;}


	return 0;

}



		
