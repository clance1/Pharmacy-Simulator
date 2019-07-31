#pragma once
/*************************************
 * File name: Bottle.h
 * Author: Carson Lance, Aaron Reardon, Matthew Dadamio, Joseph Gripenstraw
 * Email: clance1@nd.edu, areardon@nd.edu, mdadamio@nd.edu , jgripens@nd.edu 
 *
 * This is the header for the Bottle class.
 * ***********************************/

#include <iostream>
#include <string>
using namespace std;

#include "bottleDate.h"
class Bottle {

	public:
		//A constructor should take in the name of the bottle, the lot number (number of pills) and an expiration date, with correlating private member
		Bottle();
		Bottle(string, int, BottleDate);
		Bottle(const Bottle&);
		//copy assignment operator
		Bottle &operator=(const Bottle&);
		// Destructor
		~Bottle();

		//Accessor functions of the private members
		void setDrugName(string);
		void setLotNum(int);
		void setExpDate(BottleDate);  
		string getDrugName();
		string getDrugName() const;
		int getLotNum();
		BottleDate getExpDate();
		BottleDate getExpDate() const;
		
		// Various Functions
		void dispensePills(int);
		bool checkDate(BottleDate); 
		bool compDate(ostream&, BottleDate);
		
		// Overloaded operators
		bool operator<(const Bottle&);
		bool operator>(const Bottle&);
		bool operator==(const Bottle&);
		bool operator!=(const Bottle&);	
		friend ostream & operator<<(ostream &os, const Bottle&); 
		friend istream & operator>>(istream &is, Bottle&);
	private:
		string drugName;
		int lotNum;
		BottleDate expDate;  
};
