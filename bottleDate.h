#pragma once
/*************************************
* File name: pillBottle.h
* Author: Carson Lance, Aaron Reardon, Matthew Dadamio, Joseph Gripenstraw
* Email: clance1@nd.edu, areardon@nd.edu, mdadamio@nd.edu , jgripens@nd.edu 
*
* This is the header for the PillBottle class.
* ***********************************/


#include <iostream>
#include <array>
#include <string>

using namespace std;

class BottleDate {

	public:
		// Constructor
		BottleDate();
		// Initialization constructor
		BottleDate(int, int, int);
		// Copy Constructor
		BottleDate(const BottleDate&);
		// Gets the prescription name
		string getPresName();
		// Gets the Expiration Year
		int getExpYear();
		int getExpYear() const;
		// Gets the Expiration Month (Number)
		int getExpMon();
		int getExpMon() const;
		// Gets the Expiration Day
		int getExpDay();
		int getExpDay() const;
		// Gets the Expiration Month (Acronym)
		string getMonName();
		// Sets the prescription name
		void setPresName(string);
		// Sets the Expiration Year
		void setExpYear(int);
		// Sets the Expiration Month (Number)
		void setExpMon(int);
 		// Sets the Expiration Day
		void setExpDay(int);
		// Sets Expiration Date
		void setExpDate(int, int, int);
		// Sets the Expiration Month (Acronym) from an array of	acronyms
		void setMonName(string);
		// Converts the expiration month from a number to the acronym
		void convMon(int);
		// Compares two pill bottles and starts with the year then goes to the month and then the day. If the bottle being passed expires before the function returns true.
		bool compareExp(BottleDate);
		// Prints the expiration date in Day Mon(Acronym) Year format
		void printExp();
		// Prints the abreviated version of the expiration date
		void setAbrevExp();
		string getAbrevExp();
		friend ostream& operator<<(ostream& os, const BottleDate& bot);
		// Destructor
		~BottleDate();
	private:
		int expYear;
		int expMon;
		int expDay;
		string monName;
		string presName;
		string abrevExp;
		string monAcr[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
};
