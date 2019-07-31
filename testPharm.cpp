#pragma once
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
#include "node.h"
#include "Shelf.h"
void readFile(std::string, std::ifstream & readFile);
void dispense(BottleQueue&,std::string,int,BottleDate, bool *);



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
/*
    //Shelf<BottleQueue>, the data structure 
    Shelf<BottleQueue> shelf;
    BottleQueue tempQueue;
    BottleQueue nextQueue;
    BottleQueue midQueue;
    BottleQueue frontQueue;
    Bottle d;
    d.setDrugName("Aaaah");
    frontQueue.push(d);
    Bottle a;
	cout << "The absolute basic is working" << endl;
    
   Bottle b;
   b.setDrugName("Yooray");
   b.setLotNum(69);
   Bottle c;
   c.setDrugName("Okay");
   midQueue.push(c);
    tempQueue.push(a);
   frontQueue.push(d);
	cout << "The push works" << endl;
    nextQueue.push(b);
    bool temp = false;
    bool * check = &temp;

    Node<BottleQueue>* A = shelf.insert(tempQueue, check);

	cout << "the insert works " << endl;
    cout << (*check) << endl;
    
    *check = false;
    Node<BottleQueue>* B = shelf.insert(nextQueue, check);
    cout << (*check) << endl;
    cout << "Atempting to insert between" << endl;
    Node<BottleQueue>* C = shelf.insert(midQueue, check);
    cout << "Success!!" << endl;
    cout << (*check) << endl;
    Node<BottleQueue>* D = shelf.insert(frontQueue, check);
   
    cout << (*(*A).getData()).front() << endl;
    cout << (*(*C).getData()).front()<< endl;
*/
     
   
     
    Shelf<BottleQueue> shelf;
    // Throws an error if user doesn't input enough args and ends program
    if (argc < 2) {
	cout << "Error, incorrect usage. Usage: ./testPharm filename" << endl;
	return 1;
	}

    std::ifstream testFile;
    readFile(argv[1], testFile); 

    Bottle bottle2;//for the STOCK test
    BottleDate inspcDate;//for the INSPC and SCRIP test	
    std::string drugName, opName;//test
    int day, month, year, pills; //for the tests
    bool check;
    while ((testFile).peek() != EOF && (testFile).peek() != ' ') 
    { 
	testFile >> opName;
	if (opName == "STOCK") 
	{ 
		std::cout << "STOCK: ";
		testFile >> bottle2;
		cout << "Attempting to stock new bottle: ";
		cout << bottle2;
		/*
		*BottleQueue tempRow;
		temp = insert(tempRow, &check)
		if(check)
		{
			cout << "Successful stock!" << endl;
		}
		else{
			temp->data.push(bottleTemp);
		}
		*/
	
		BottleQueue rowT;
    	rowT.push(bottle2);
		bool a = 0;
		bool * b = &a;
		shelf.insert(rowT,b)->getData()->push(bottle2);
		if(*b){cout << "Successful stock of new bottle type " << bottle2;}
		else{cout << "Putting bottle in existing row of " << bottle2.getDrugName();}
	
	}//end if STOCK
	else if (opName == "INSPC")
	{ 
	    testFile >> year >> month >> day;    
	    inspcDate.setExpDate(month, day, year);
	    cout << "INSPECTION on " << inspcDate << endl;
		
		if(shelf.first)
	    	{cout << "No comparison possible. Shelf is empty" <<endl;}
	    else
		{
			Node<BottleQueue>* iter = shelf.head;
			while(iter != nullptr)
			{
				cout << "Inspecting ";
				cout << iter->getData()->front().getDrugName() << endl;
				//cout << temp << endl;
			BottleQueue* row = (iter->getData());
	    	if(row->empty()){cout << "No comparison possible. Row is empty" <<endl;}
	    	else if(!row->front().compDate(cout, inspcDate))//bottle is not expired
	    	{
				cout << endl;
				cout << "Bottle in front of " << row->front().getDrugName();
				cout << " with "<<row->front().getExpDate() << " passes ";
				cout << "inspection!!" << endl;;
				
            	}
	    	else 
	    	{ 
			bool bottleFound = false;	
			while(!row->empty() && !bottleFound)
			{
		    	if(!row->front().compDate(cout, inspcDate))//bottle not expired
		    	{
				cout << endl << "Unexpired bottle found" << endl;
				bottleFound = true;
		    	}
		    	else//bottle is expired
		    	{
				if(row->size() > 1)
					row->pop();//take off expired bottle
				else
				{
				bool a = 0;
				bool *b = &a;
		
				Node<BottleQueue>* tNode = shelf.insert(*(iter->getData()),b);
			
				shelf.deleteNode(tNode);
				row->pop();		

				}
		    	}
			
			}//end while
		
			if(!bottleFound)
				cout << "The entire row is expired and has been tossed "<<endl;
	    		
			}
		
				iter = iter->head;
				if(iter == nullptr){break;}				
			}
		  
	    }

	
	
	}
	else if (opName == "SCRIP")
	{
	    testFile >> year >> month >> day;
	    inspcDate.setExpDate(month, day, year);	
		
	    testFile >> drugName >> pills;
	    cout << "SCRIPT! Patient brought in a prescription on " << inspcDate;
	    cout << " for " << pills << " " << drugName << endl;
	    
		Bottle tempBot;
		tempBot.setDrugName(drugName);
	    BottleQueue tempBQ;
		tempBQ.push(tempBot);
		bool teB = false;
		bool *didWork = &teB;
		Node<BottleQueue>* tempNode;
	
		tempNode = shelf.insert(tempBQ,didWork);
		*didWork = true;
	    dispense(*(tempNode->getData()), drugName, pills, inspcDate,didWork);
		if(!*didWork){
			shelf.deleteNode(tempNode);}
	}
	else if (opName == "INVEN")
	{
		
		// go through all the rows in the shelf, and print the contents of the first bottle
		Node<BottleQueue>* iter = shelf.head;
		while(iter  != nullptr)
		{
			if(!iter->getData()->empty())
			{
				cout << iter->getData()->front() << endl;
			}
			iter = iter->head;
			if(iter == nullptr){break;} //end of list reached
		}

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
void dispense(BottleQueue& row,std::string drug, int pills, BottleDate date, bool * check)
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
                cout <<  "The front bottle of " << drug << " is expired as of "; 
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
		// Checks if bottle is out of pills
	       if (row.front().getLotNum() <= 0){
	       		cout << "Front Bottle is empty, removing bottle" << endl;
		        row.pop();
	       }
	       cout << "Prescription filled! " << endl;
            }
        }//end while	
        if(pills > 0)
        {
	    cout << "There were not enough pills of " <<drug<< " in the row and ";
	    cout << pills << " are still needed." << endl;
        }	
	if (row.empty()) {
		cout << "The Row is now empty!" << endl;
		*check = false;

	}
    }//end else
}//end dispense

