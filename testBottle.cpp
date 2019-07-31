/*************************************
 * File name: testBottle.cpp
 * Author: Matthew DaDamio, Carson Lance, Aaron Reardon, Joseph Gripenstraw
 * Email: mdadamio@nd.edu, clance1@nd.edu, areardon@nd.edu, jgripens@nd.edu
 *
 *  This file is a test file for our Bottle class.
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
	Bottle bottle2;
	BottleDate date(1, 23, 2019);
	Bottle bottle1("Azithromycin", 45, date);
	// Prints out Bottle contents
	cout << bottle1 << endl << bottle2 << endl;
	
	if (argc < 2) {
		cout << "Error, incorrect usage. Usage: ./testBottle filename" << endl;
		return 1;
	}
		
	string filename = argv[1];
	// Creates ifstream pointer that points to the ifstream address returned by the function
	ifstream testFile;
	readFile(filename, testFile);
	
	string opName, drugName;
	
	BottleDate inspcDate;
	BottleDate dispDate;
	int year, month, day, pills;
	
	while ((testFile).peek() != EOF && (testFile).peek() != ' ') { 
		testFile >> opName;
		
		if (opName == "STOCK") { 
			cout << "STOCK: ";
			testFile >> bottle2;
			cout << bottle2;
		}
		else if (opName == "INSPC") { 
			testFile >> year >> month >> day;
			inspcDate.setExpDate(month, day, year);

			cout << "INSPECTION on " << inspcDate << endl;

			cout << "For Bottle 1: ";
			if (bottle1.compDate(cout, inspcDate)) {
				cout << endl << "Bottle 1 is expired" << endl;
			}
			
			cout << "For Bottle 2: ";
			if (bottle2.compDate(cout, inspcDate)) {
				cout << endl << "Bottle 2 is expired" << endl;
			}
			else { cout << endl; }
				
		
		}
		else if (opName == "SCRIP") {
			testFile >> year >> month >> day;
			dispDate.setExpDate(month, day, year);	
			
			testFile >> drugName >> pills;
			
			cout << "SCRIPT! ";
			dispense(bottle1, drugName, pills, dispDate);
			dispense(bottle2, drugName, pills, dispDate);
		}
		else {
			cout << "Unknown operation!" << endl;
			return 1;
		}
		cout << endl;
	}
	
	return 0;
}

/*************************************
* Function name: readFile()
* Preconditions: string filename, ifstream& testFile
* Postconditions: None
*
* This function takes in a character string,
* and an ifstream by reference, opens a file,
* checks it, and terminates the program if
* the file does not open.
************************************/

void readFile(string filename, ifstream& testFile) {
	testFile.open(filename);
	if (testFile.is_open()){ 
		return;
	}
	// Checks if file is not open
	else {
		cout << "Unable to open file" << endl;	
		exit(1);
	}
}

/*************************************
* Function name: dispense()
* Preconditions: Bottle& bot, string drug, int pills, BottleDate date
* Postconditions: None
*
* This function takes in the bottle contents, checks
* the name, if its expired and if the number of pills 
* exceeds the number of pills currently in the bottle,
* and prints the results
************************************/
void dispense(Bottle& bot, string drug, int pills, BottleDate date) {
	if (drug != bot.getDrugName()) {
		return;
	}
	else if (bot.checkDate(date)) {
		cout << "Bottle " << drug << " is expired as of " << bot.getExpDate() << ". ";
		cout << "Cannot dispense pills!" << endl;
	}	
	else if (pills > bot.getLotNum()) {
		cout << "Prescription exceeds pills in bottle. Can only dispense " << bot.getLotNum() << " " << drug << "." << endl;
		cout << "Still need " << (pills - bot.getLotNum()) << " pills "<<  endl;
		bot.dispensePills(bot.getLotNum());
		cout << bot;
	}
	else {
		cout << "Sufficient stock. Dispensing " << pills << " " << drug << "." << endl;
		bot.dispensePills(pills);
		cout << bot;	
	}
	
}
