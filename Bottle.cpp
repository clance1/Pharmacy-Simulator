#pragma once
/*************************************
 * File name: Bottle.cpp
 * Author: Matthew DaDamio, Carson Lance, Aaron Reardon, Joseph Gripenstraw
 * Email: mdadamio@nd.edu, clance1@nd.edu, areardon@nd.edu, jgripens@nd.edu
 *
 *  This file is the implementation for our Bottle class.
 *
 * ***********************************/
#include <iostream>
#include <string>

using namespace std;
#include "Bottle.cpp"
#include "Bottle.h"
/*************************************
 * Function name: Bottle()
 * Preconditions: None
 * Postconditions: None
 *
 * Default constructor that sets the bottle name to No Name, 
 * lot number = 0, and expiration date to jan 1st 2019
 * ***********************************/
Bottle::Bottle() {
        setDrugName("No Name");
        setLotNum(0);
        expDate.setExpMon(1);
	expDate.setExpDay(1);
	expDate.setExpYear(2019); 
};

/*************************************
 * Function name: Bottle()
 * Preconditions: string drug, int pills, BottleDate date
 * Postconditions: None
 *
 * Initialization constructor that takes in
 * the name of the drug, pills, and BottleDate
 * ***********************************/
Bottle::Bottle(string name, int pills, BottleDate date) {
	setDrugName(name);
	setLotNum(pills);
	setExpDate(date);
}

/*************************************
 * Function name: Bottle()
 * Preconditions: const Bottle& bot
 * Postconditions: None
 *
 * This function is the copy constructor.
 * It copies the Bottle class's objects
 * ***********************************/
Bottle::Bottle(const Bottle& bot) {
	setDrugName(bot.drugName);
	setLotNum(bot.lotNum);
	setExpDate(bot.expDate);
}

/*************************************
* Function name: setDrugName()
* Preconditions: string name
* Postconditions: None
*
* This function sets the drugName
************************************/
void Bottle::setDrugName(string name) {
	drugName = name;
}

/*************************************
* Function name: setLotNum()
* Preconditions: int num
* Postconditions: None
*
* This function sets the lotNum
************************************/
void Bottle::setLotNum(int num) {
	lotNum = num;
}

/*************************************
* Function name: setExpDate()
* Preconditions: BottleDate date
* Postconditions: None
*
* This function sets the expDate by using
* the get/set functions of the BottleDate class
************************************/
void Bottle::setExpDate(BottleDate date) {
	expDate.setExpMon(date.getExpMon());
	expDate.setExpDay(date.getExpDay());
	expDate.setExpYear(date.getExpYear());
}

/*************************************
* Function name: getDrugName()
* Preconditions: None
* Postconditions: string
*
* This function returns the drugName
************************************/
string Bottle::getDrugName() { return drugName; }

/*************************************
* Function name: getDrugName()
* Preconditions: None
* Postconditions: string
*
* This const function returns the drugName
************************************/
string Bottle::getDrugName() const { return drugName; }


/*************************************
* Function name: getLotNum()
* Preconditions: None
* Postconditions: int
*
* This function returns the lotNum
************************************/
int Bottle::getLotNum() { return lotNum; }

/*************************************
* Function name: getExpDate()
* Preconditions: None
* Postconditions: BottleDate
*
* This function returns the expDate
************************************/
BottleDate Bottle::getExpDate() { return expDate; }

/*************************************
* Function name: getExpDate()
* Preconditions: None
* Postconditions: BottleDate
*
* This function returns the expDate
* Const function
************************************/
BottleDate Bottle::getExpDate() const { return expDate; }


/*************************************
* Function name: dispensePills()
* Preconditions: int pills
* Postconditions: None
*
* This function takes in a number and removes
* that number from the number of pills in the 
* bottle. pre-condition is that the number passed
* should be less than or equal to the number of
* pills prior to calling
************************************/
void Bottle::dispensePills(int pills) {
	lotNum -= pills;
	// A precondition is that pills > lotNum, so this should never happen
	if (lotNum < 0) {
		cout << endl << "!*******! ERROR: lotNum has negative value! This should never happen! **************!" << endl;
	}
}

/*************************************
* Function name: checkDate()
* Preconditions: BottleDate date
* Postconditions: bool
*
* This function uses the compareExp function in
* our BottleDate class and takes in a date and
* checks if the bottle is expired. If the date
* passed to the function is equal to or exceeded
* the date stored in the bottle class, then return
* true. Otherwise, return false.
************************************/
bool Bottle::checkDate(BottleDate date) { return date.compareExp(expDate); }


/*************************************
* Function name: compDate()
* Preconditions: ostream& out, BottleDate date
* Postconditions: bool
*
* This function takes in an ostream and
* a Date, and prints the comparison between
* the two dates
************************************/
bool Bottle::compDate(ostream& out, BottleDate date) {
	bool b = checkDate(date);
	
	if (b == false) {
		out << "The check date " << date.getAbrevExp() << " is before the intial date " << expDate.getAbrevExp();
	}
	else {
		out << "The check date " << date.getAbrevExp() << " is the same day or after the initial date " << expDate.getAbrevExp();
	}
	return b;
}


/********************************************
* Function Name  : operator!=() 
* Pre-conditions : Bottle&
* Post-conditions: bool
*  
*  This is an overloaded != operator which
*  compares the drug name of this and comp
*  and returns whether this != comp
********************************************/
bool Bottle::operator!=(const Bottle& comp)
{
	if(this->getDrugName().compare(comp.getDrugName()) != 0)
		return true; //strigns are not equal
	return false;
	 		   			    			    	      	       
}
/********************************************
* Function Name  : operator==() 
* Pre-conditions : Bottle&
* Post-conditions: bool
*  
*  This is an overloaded == operator which
*  compares the drug name of this and comp
*  and returns whether this == comp
********************************************/
bool Bottle::operator==(const Bottle& comp)
{
	if(this->getDrugName().compare(comp.getDrugName()) == 0)
		return true; //strigns are equal
	return false;
		   			    			    	      	       
}
/********************************************
* Function Name  : operator>() 
* Pre-conditions : Bottle&
* Post-conditions: bool
*  
*  This is an overloaded > operator which
*  compares the drug name of this and comp
*  and returns whether this > comp
********************************************/
bool Bottle::operator>(const Bottle& comp)
{
	if(this->getDrugName().compare(comp.getDrugName()) > 0)
		return true; //this.name is greater than comp.name
	return false;		    			    	      	       
}


/********************************************
* Function Name  : operator<() 
* Pre-conditions : Bottle&
* Post-conditions: bool
*  
*  This is an overloaded < operator which
*  compares the drug name of this and comp
*  and returns whether this < comp
********************************************/
bool Bottle::operator<(const Bottle& comp)
{
	if(this->getDrugName().compare(comp.getDrugName()) < 0)
		return true; //this.name < comp.name
	return false;	   			    			    	      	       
}

/*************************************
* Function name: operator<<()
* Preconditions: ostream& os, const Bottle& bot
* Postconditions: ostream &
*
* This is the friend std::ostream operator
* << to print the Bottle contents
************************************/
ostream & operator<<(ostream& os, const Bottle& bot) {
	os << bot.drugName << ". Pills = " << bot.lotNum << ". " << "EXP: " << bot.expDate << endl;
}

/*************************************
* Function name: operator>>()
* Preconditions: istream& is, const Bottle& bot
* Postconditions: istream &
*
* This is the friend std::sstream operator
* << which takes an input stream and inputs 
* the values in the following order:
* Drug Name, Lot Number, Date Year, Date Month, Date Day
************************************/
istream & operator>>(istream& is, Bottle& bot) {
	int day, month, year;
	is >> bot.drugName >> bot.lotNum;
	is >> year >> month >> day;
	bot.expDate.setExpDay(day);
	bot.expDate.setExpMon(month);
	bot.expDate.setExpYear(year);
	return is;
}

/*********************************
 * Function name: ~Bottle()
 * Preconditions: None
 * Postconditions: None
 *
 * This function is the destructor. Calls the 
 * destructors of all the object's class-type members
 * ***********************************/
Bottle::~Bottle() {
}

/**********************************
 * Function Name: operator=
 * Preconditions: const Bottle& bot
 * Postconditions: Bottle&
 * This is the Bottle copy assignment operator.
 * It performs a memberwise copy
 * ***********************************/
Bottle& Bottle::operator=(const Bottle& bot) {
	drugName=bot.drugName;
	lotNum=bot.lotNum;
	expDate=bot.expDate;
	return *this;
	       
}
 
