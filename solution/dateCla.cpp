/*******************************************************
 * File Name: dateCla.cpp 
 * Author Name: Matthew Morrison
 * E-mail: matt.morrison@nd.edu
 *
 * This file contains a sample solution for Challenge 1 
 * Part 1 where the Date is a class in "dateCla.h:
 *******************************************************/

#include "dateCla.h"  // Contains Date Struct
 
DATE::DATE() : year(2000), month(1), day(1) {
 
}
 
DATE::DATE(int year, int month, int day) : year(year), month(month), day(day) {
 
}

int& DATE::getYear(){
	return year;
}

int& DATE::getMonth(){
	return month;
}

int& DATE::getDay(){
	return day;
}
	
void DATE::setYear(int& setYear){
	year = setYear;
}
	
void DATE::setMonth(int& setMonth){
	month = setMonth;
}
	
void DATE::getDay(int& setDay){
	day = setDay;
}

bool DATE::operator<(DATE &checkDate){
	if(year < checkDate.year) {
		return true;
	}
	else if(year == checkDate.year){
		if(month < checkDate.month) {
			return true; 
		}
		else if(month == checkDate.month){
			if(day < checkDate.day){
				return true;
			}
		}
	}
	return false;
}

bool DATE::operator>=(DATE &checkDate){
	if(year > checkDate.year) {
		return true;
	}
	else if(year == checkDate.year){
		if(month > checkDate.month) {
			return true; 
		}
		else if(month == checkDate.month){
			if(day >= checkDate.day){
				return true;
			}
		}
	}
	return false;
}

bool DATE::operator<=(DATE &checkDate){
	if(year < checkDate.year) {
		return true;
	}
	else if(year == checkDate.year){
		if(month < checkDate.month) {
			return true; 
		}
		else if(month == checkDate.month){
			if(day <= checkDate.day){
				return true;
			}
		}
	}
	return false;
}