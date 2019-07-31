#pragma once
#include "bottleDate.h"
/*************************************
* File name: bottleDate.cpp
* Author: Carson Lance, Aaron Reardon, Matthew Dadamio, Joseph Gripenstraw
* Email: clance1@nd.edu, areardon@nd.edu, mdadamio@nd.edu , jgripens@nd.edu 
*
* This file implements the PillBottle class.
* ***********************************/

/*************************************
* Function name: BottleDate()
* Preconditions: None
* Postconditions: None
*
* Default constructor that sets the date to January, 1st, 2000
* ***********************************/
BottleDate::BottleDate() {
	setExpMon(1);
	setExpDay(1);
	setExpYear(2000);
	setAbrevExp();
};

/*************************************
 * * Function name: BottleDate()
 * * Preconditions: int mon, int day, int year
 * * Postconditions: None
 *Initialization constructor that sets
 * date equal to the inputted date  
 * * ***********************************/

BottleDate::BottleDate(int mon, int day, int year) {
	setExpMon(mon);
	setExpDay(day);
	setExpYear(year);
	setAbrevExp();
}

BottleDate::BottleDate(const BottleDate& date) {
	setExpMon(date.expMon);
	setExpDay(date.expDay);
	setExpYear(date.expYear);
	setAbrevExp();
}


/*************************************
* Function name: getPresName()
* Preconditions: None
* Postconditions: string presName
*
* This function returns the presName
************************************/

string BottleDate::getPresName() {
	return presName;
};

/*********************************
* Function name: getExpYear()
* Preconditions: None
* Postconditions: int expYear
*
* This function returns the expiration 
* year
***********************************/

int BottleDate::getExpYear() {
	return expYear;
};

/*********************************
* Function name: getExpYear()
* Preconditions: None
* Postconditions: int expYear
*
* This function returns the expiration 
* year. Const
***********************************/
int BottleDate::getExpYear() const{
	return expYear;
}
/*********************************
* Function name: getExpMon()
* Preconditions: None
* Postconditions: int expMon
*
* This function returns the expiration
* month as a number
***********************************/

int BottleDate::getExpMon() {
	return expMon;
};
/*********************************
* Function name: getExpMon()
* Preconditions: None
* Postconditions: int expMon
*
* This function returns the expiration
* month as a number. Const
***********************************/

int BottleDate::getExpMon() const{
	return expMon;
};


/*********************************
* Function name: getExpDay()
* Preconditions: None
* Postconditions: int expDay
*
* This function returns the expiration
* day 
***********************************/

int BottleDate::getExpDay() {
	return expDay;
};

/*********************************
* Function name: getExpDay()
* Preconditions: None
* Postconditions: int expDay
*
* This function returns the expiration
* day. Const
***********************************/
int BottleDate::getExpDay() const{
	return expDay;
};


/*********************************
* Function name: getMonName()
* Preconditions: None
* Postconditions: string monName
*
* This function returns the expiration 
* month as a name
***********************************/

string BottleDate::getMonName() {
	return monName;
};

/*********************************
* Function name: setPresName()
* Preconditions: string s
* Postconditions: None
*
* This function sets presName to the
* given string
***********************************/

void BottleDate::setPresName(string s) {
	presName = s;
};

/*********************************
* Function name: setExpYear()
* Preconditions: int x
* Postconditions: None
*
* This function assigns expYear to
* the inputted year
***********************************/

void BottleDate::setExpYear(int x) {
	expYear = x;
	setAbrevExp();
};

/*********************************
* Function name: setExpMon()
* Preconditions: int x
* Postconditions: None
*
* This function assigns expMon to 
* the inputted month. It also checks
* to see if the month is in between
* 1 and 12
***********************************/

void BottleDate::setExpMon(int x) {
	while (x > 12 || x < 1) { // Checks to make sure if month is valid
        	cout << "Error: The month cannot be greater than 12. Please re-enter." << endl;
 		cin >> x; // Prompts user to reinput
	}
	expMon = x;
	convMon(x); // Converts month number to the abbreviated name
};

/*********************************
* Function name: setExpDay()
* Preconditions: int x
* Postconditions: None
*
* This function assigns expDay to 
* the inputted day. It also checks
* to see if the day is between 
* 1 and 31
***********************************/

void BottleDate::setExpDay(int x) {
	while (x > 31 || x < 1) { // Checks to make sure day is valid
        	cout << "Error: The day cannot be greater than 31. Please re-enter." << endl;
	    	cin >> x; // Prompts user to reinput
	}
	expDay = x;
};


/*********************************
* Function name: setExpDate()
* Preconditions: int mon, int day, int year
* Postconditions: None
*
* This function sets the expiration date 
* using all three values instead of
* one at a time
***********************************/
void BottleDate::setExpDate(int mon, int day, int year) {
	setExpMon(mon);
	setExpDay(day);
	setExpYear(year);
	setAbrevExp();
}


/*********************************
* Function name: setMonName()
* Preconditions: string s
* Postconditions: None
*
* This function sets monName to 
* the inputted string
***********************************/

void BottleDate::setMonName(string s) {
	monName = s;
};

/*********************************
* Function name: convMon()
* Preconditions: int x
* Postconditions: None
*
* This function converts the 
* expiration month from a number 
* to the acronym
***********************************/

void BottleDate::convMon(int x) {
	string newMon;
	newMon = monAcr[x - 1]; // Goes to the array in the header file and picks the string that corresponds to the month number
	setMonName(newMon); // Sets the monName string to the month name 
};

/*********************************
* Function name: compareExp()
* Preconditions: PillBottle p
* Postconditions: bool
*
* This function compares two pill 
* bottles and starts with the year 
* then goes to the month and then 
* the day. If the bottle being 
* passed expires before the 
* function returns true.
***********************************/

bool BottleDate::compareExp(BottleDate p) {

	bool b;

	// Conditional checks each subsequent part of the date to ensure its later
	if (this->expYear > p.expYear) // First checks the year because this is the most obvious
		b = true;
   	else if ((this->expMon > p.expMon) && (this->expYear == p.expYear))
		b = true; 
    	else if ((this->expDay >= p.expDay) && (this->expMon == p.expMon) && (this->expYear == p.expYear))
		b = true;
    	else
      	        b = false;

	return b;
};


/*********************************
* Function name: printExp()
* Preconditions: None
* Postconditions: None
*
* This function outputs the expiration
* date in Day Mon(Acronym) Year format
***********************************/

void BottleDate::printExp() {
	cout << "The expiration date of " << presName << " is " << getExpDay() << " " << getMonName() << "," << getExpYear() << endl;
};

/*********************************
* Function name: setAbrevExp()
* Preconditions: None
* Postconditions: None
*
* This function combines the expiration
* date into one string
***********************************/

void BottleDate::setAbrevExp() {
	string s;
	string temp1, temp2, temp3;
	temp1 = to_string(getExpYear()); // Sets year number to string
	temp2 = getMonName(); 
	temp3 = to_string(getExpDay()); // Sets day number to string
	s =  temp1 + " " + temp2 + " " + temp3; // Concatenates the string
	abrevExp = s; // Sets the concatenated string to the abbreviated expression
};

/*********************************
* Function name: getAbrevExp()
* Preconditions: None
* Postconditions: string
*
* This function returns the expiration
* date string
***********************************/

string BottleDate::getAbrevExp() {
	return abrevExp;
};

/*********************************
* Function name: ~PillBottle()
* Preconditions: None
* Postconditions: None
*
* This function is the destructor
***********************************/

ostream & operator <<(ostream & os, const BottleDate& date) {
	os << date.abrevExp;
	return os;
}

BottleDate::~BottleDate() {
	
};
