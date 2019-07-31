/*************************************
 * File name: Bottle.cpp
 * Author: Matthew DaDamio, Carson Lance, Aaron Reardon, Joseph Gripenstraw
 * Email: mdadamio@nd.edu, clance1@nd.edu, areardon@nd.edu, jgripens@nd.edu
 *
 *  This file tests our Bottle queue.
 * ***********************************/

#include <iostream>
#include <fstream>
#include <queue>
#include "bottleDate.h"
#include "Bottle.h"
#include "bottleQueue.h"
void readFile(std::string, std::ifstream & readFile);
void dispense(BottleQueue&,std::string,int,BottleDate);



/*********************************
* Function name: main()
* Preconditions: int argc, char **argv
* Postconditions: int
*
* This function is the main driver 
* function that tests the row.
* It includes adding bottle to the row
* and dispensing a given number of
* pills and catching invalid commands
***********************************/
int main(int argc, char **argv)
{

    //std::queue<Bottle> row;//create row with queue data structure
    BottleQueue row;
    // Throws an error if user doesn't input enough args and ends program
    if (argc < 2) {
	cout << "Error, incorrect usage. Usage: ./testRow filename" << endl;
	return 1;
	}

    std::ifstream testFile;
    readFile(argv[1], testFile);
    
    
	
	
    Bottle bottle2;//for the STOCK test
    BottleDate inspcDate;//for the INSPC and SCRIP test	
    std::string drugName, opName;//test
    int day, month, year, pills; //for the tests
  
    while ((testFile).peek() != EOF && (testFile).peek() != ' ') 
    { 
	testFile >> opName;
	if (opName == "STOCK") 
	{ 
		std::cout << "STOCK: ";
		testFile >> bottle2;
		cout << "Attempting to stock new bottle: ";
		cout << bottle2;
		
		if(row.empty())
		{
		    row.push(bottle2);
		    cout << "Successful stock!" << endl;
		}
		else
		{
		    if(bottle2.getDrugName() != row.front().getDrugName())
		    {
			cout << "This bottle cannot be stocked." << endl;
			cout << "The bottle and row do not match." << endl;
		    }
		    else
		    {
			row.push(bottle2);
			cout << "Successful stock!" << endl;
		    }
		}	
	}//end if STOCK
	else if (opName == "INSPC")
	{ 
	    testFile >> year >> month >> day;
	    
	    inspcDate.setExpDate(month, day, year);
	    cout << "INSPECTION on " << inspcDate << endl;
	    if(row.empty()){cout << "No comparison possible. Row is empty" <<endl;}
	   
	    else if(!row.front().compDate(cout, inspcDate))//bottle is not expired
	    {
		cout << endl << "The test passed! " << endl;
            }
	    else 
	    { 
		bool bottleFound = false;	
		while(!row.empty() && !bottleFound)
		{
		    if(!row.front().compDate(cout, inspcDate))//bottle not expired
		    {
			cout << endl << "Unexpired bottle found" << endl;
			bottleFound = true;
		    }
		    else//bottle is expired
		    {
			row.pop();//take off expired bottle
		    }
		}//end while
		
		if(!bottleFound)
		    cout << "The entire row is expired and has been tossed "<<endl;
	    }
		
	}
	else if (opName == "SCRIP")
	{
	    testFile >> year >> month >> day;
	    inspcDate.setExpDate(month, day, year);	
		
	    testFile >> drugName >> pills;
	    cout << "SCRIPT! Patient brought in a prescription on " << inspcDate;
	    cout << " for " << pills << " " << drugName << endl;
	    
	    
	    dispense(row, drugName, pills, inspcDate);
	    
	}
	else
        {
	    cout << "Unknown operation!" << endl;
	    return 1;
	}
	cout << endl;

    }//end while
	


     
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


void readFile(std::string filename, ifstream& testFile) 
{
	testFile.open(filename);

	if (testFile.is_open())
        { 
	    return;
	}
	// Checks if file is not open
	else 
	{
	    cout << "Unable to open file" << endl;	
	    exit(1);
	}
}

/*************************************
* Function name: dispense
* Preconditions: std::queue<Bottle>&, std::string, int, BottleDate
* Postconditions: None
*
* Dispenses given number of pills from the given row of the given string drug.  
* ***********************************/
void dispense(BottleQueue& row,std::string drug, int pills, BottleDate date)
{
    if (row.empty())
    {
	cout << "The row is empty and the medication cannot be dispensed." << endl;
    }    
    else if (drug != row.front().getDrugName()) 
    {
	cout << "The wrong row has been selected." << endl;
	cout << "The " << row.front().getDrugName(); 
	cout << " row was selected instead of " << drug << "." << endl;
	cout << "The prescription cannot be filled by the row" << endl;
    }
    else{

        while(!row.empty() && pills > 0)
        {
            if (row.front().checkDate(date))//if front bottle is expired
            {
                cout << "The front bottle of " << drug << " is expired as of "; 
                cout << row.front().getExpDate() << ". " << endl;;
	        row.pop();//remove expired front bottle
            }	
            else if(pills > row.front().getLotNum())//if not enough pills  
            {   
                cout << "Prescription exceeds pills in bottle";
	        cout << " so the front bottle will be emptied" << endl;
	        cout << "Still need " << (pills - row.front().getLotNum()) << endl;
	        pills -= row.front().getLotNum();//update pills still needed
	        row.front().dispensePills(row.front().getLotNum());//empty bottle
	        row.pop();//remove bottle
            }
           else
           {
	       cout << "Sufficient stock. Dispensing " << pills << " ";
	       cout << drug << "." << endl;
	  
	       row.front().dispensePills(pills);
	       pills = 0;//prescription is filled
	       cout << "The front bottle has " << row.front().getLotNum();
	       cout << " pills left " << endl;	
	       cout << "Prescription filled! " << endl;
            }
        }//end while	
        if(pills > 0)
        {
	    cout << "There were not enough pills of " <<drug<< " in the row and ";
	    cout << pills << " are still needed." << endl;
        }	
    }//end else
}//end dispense

