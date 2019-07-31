/*************************************
* File name: testDate.cpp
* Author: Carson Lance, Aaron Reardon, Matthew Dadamio, Joseph Gripenstraw
* Email: clance1@nd.edu, areardon@nd.edu, mdadamio@nd.edu , jgripens@nd.edu 
*
* This file contains the main driver to test the PillBottle class. It creates 
* PillBottle objects and performs operations on them.
* ***********************************/

#include <iostream>
#include <string>

using namespace std;

#include "bottleDate.h"


/*********************************
* Function name: dateComp()
* Preconditions: BottleDate p1, BottleDate p2,
* ostream &out
* Postconditions: None
*
* This function takes in the two dates, and
* indicates to the user if the check date is later,
* meaning that the check date indicates an expiration.
* This function takes in an ostream variable.
* When called in main, the std::cout may be passed
***********************************/
 
void dateComp (BottleDate, BottleDate, ostream &);

/*********************************
* Function name: main()
* Preconditions: None
* Postconditions: int
*
* This function is the main driver 
* function that tests our date class.
* It includes creation of four dates: 
* an initial date, a check date that is 
* before the expiration date, a check 
* date that is the same day of the expiration 
* date, and a check date that is after the expiration date
* and it calls dateComp function.
***********************************/

int main() {

	// Creates an initial-p, before-pb, same-ps, after-pa
	BottleDate p, pb, ps, pa;
	int day, mon, year;

	// Prompts user to enter intial date
	cout << "Enter the initial date (Month, Day, Year): " << endl;
	cin >> mon >> day >> year;

	p.setExpDay(day);
	p.setExpMon(mon);
	p.setExpYear(year);
	
	// Prompts user to enter first check date
	cout << "Enter the check date that is before the initial expiration (Month, Day, Year):" << endl;
        cin >> mon >> day >> year;

        pb.setExpDay(day);
        pb.setExpMon(mon);
        pb.setExpYear(year);
	
	// Prompts user to enter the second same check date
        cout << "Enter the check date that is the same as the initial expiration (Month, Day, Year):" << endl;
        cin >> mon >> day >> year;

        ps.setExpDay(day);
        ps.setExpMon(mon);
        ps.setExpYear(year);

	// Prompts the user to enter the third after check date
        cout << "Enter the expiration date that is after the initial expiration (Month, Day, Year):" << endl;
        cin >> mon >> day >> year;

        pa.setExpDay(day);
        pa.setExpMon(mon);
        pa.setExpYear(year);
	
	// Creates the alphanumeric labels for each date
	p.setAbrevExp();
	pb.setAbrevExp();
	ps.setAbrevExp();
	pa.setAbrevExp();	

	// Calls compare functions for the inital date and each check date
	dateComp(p, pb, cout);
	dateComp(p, ps, cout);
	dateComp(p, pa, cout);

	return 0;
}

/*********************************
* Function name: dateComp()
* Preconditions: BottleDate p1, BottleDate p2,
* ostream &out
* Postconditions: None
*
* This function takes in the two dates, and 
* indicates to the user if the check date is later, 
* meaning that the check date indicates an expiration. 
* This function takes in an ostream variable. 
* When called in main, the std::cout may be passed
***********************************/


void dateComp(BottleDate p1, BottleDate p2, ostream &out) {
        // Checks if the date is the same day or after the intial input date
	bool b = p1.compareExp(p2);

	// Conditional outputs correct phrase based off of boolean value returned
	if (b == false) {
                out << "The check date " << p2.getAbrevExp() << " is the same day or after the initial date " << p1.getAbrevExp() << endl;
        }
        else if (b == true) {
                out << "The check date " << p2.getAbrevExp() << " is before the initial date " << p1.getAbrevExp() << endl;
        }
}
