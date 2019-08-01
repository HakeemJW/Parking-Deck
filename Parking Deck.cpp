// C++ Program			Project3.cpp
// Course				CSE1311/W01
// Name:				Hakeem Wilson
// Assignment #:		Project 3
// Due Date:			03/31/2019

/*
	The purpose of this project is to create a program that emulates a parking garage
	it must read in data from a file,
	calculate the passage of time,
	determine the parking rate,
	and print the data in a table format.
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;
double eh, em, exh, exm, hp, mp, total_time_passed;
string rate;
ifstream fin("time.txt");	//opens file

void timepassage()	//Calculates passage of time
{
	if (exh < eh)
	{
		hp = ((exh + 24) - eh);
	}
	else hp = (exh - eh);
	
	mp = (exm - em);
	total_time_passed = ((hp*60) + mp);
}

void cost()	//Uses nested if-else statements to determine rate
{
	if (eh == 99 && em == 99)
		rate = "5.00";
	else if (exh == 55 && exm == 55)
		rate = "110.00";
	else if (total_time_passed <= 30)
		rate = "3.00";
	else if (total_time_passed >= 31 && total_time_passed <= 59)
		rate = "5.00";
	else if (total_time_passed >= 60 && total_time_passed <= 119)
		rate = "10.00";
	else if (total_time_passed >= 120 && total_time_passed <= 179)
		rate = "15.00";
	else if (total_time_passed >= 180 && total_time_passed <= 239)
		rate = "30.00";
	else if (total_time_passed >= 240 && total_time_passed <= 269)
		rate = "35.00";
	else if (total_time_passed >= 270 && total_time_passed <= 299)
		rate = "40.00";
	else if (total_time_passed >= 300 && total_time_passed <= 329)
		rate = "45.00";
	else if (total_time_passed >= 330 && total_time_passed <= 359)
		rate = "50.00";
	else if (total_time_passed >= 360 && total_time_passed <= 389)
		rate = "55.00";
	else if (total_time_passed >= 390 && total_time_passed <= 419)
		rate = "60.00";
	else if (total_time_passed >= 420 && total_time_passed <= 449)
		rate = "65.00";
	else if (total_time_passed >= 450 && total_time_passed <= 479)
		rate = "70.00";
	else if (total_time_passed >= 480 && total_time_passed <= 509)
		rate = "75.00";
	else if (total_time_passed >= 510 && total_time_passed <= 539)
		rate = "80.00";
	else if (total_time_passed >= 540 && total_time_passed <= 569)
		rate = "85.00";
	else if (total_time_passed >= 570 && total_time_passed <= 599)
		rate = "90.00";
	else if (total_time_passed >= 600 && total_time_passed <= 629)
		rate = "95.00";
	else if (total_time_passed >= 630 && total_time_passed <= 659)
		rate = "100.00";
	else if (total_time_passed >= 660 && total_time_passed <= 689)
		rate = "115.00";
	else if (total_time_passed >= 690 && total_time_passed <= 719)
		rate = "120.00";
	else if (hp > 12 && hp < 24)
		rate = "ERROR";

}

void print()	//Prints the data in table format
{
	
	cout << eh << "\t\t" << em << "\t\t" << exh << "\t\t" << exm << "\t\t" << total_time_passed << "\t\t  " << rate << endl;
	//cout << eh << "\t\t" << em << "\t\t" << exh << "\t\t" << exm << "\t\t" << total_time_passed << "\t\t  " << rate << endl;
}

void readtimes() //Reads data in from file to perform calculations
{
	do
	{
		fin >> eh >> em >> exh >> exm;
		timepassage(); //calls to time passage function	
		cost();	//calls to rate calculator
		print();	//prints data
	} while (!fin.eof());	//Repeats line by line until the end of the file

}

int main()
{
	cout << "Enter Hour" <<"\t"<< "Enter Minute" << "\t" << "Exit Hour" << "\t" << "Exit Minute" << "\t" << "Minutes Passed" << "\t  " << "Rate" << endl;
	readtimes();	//Calls to readtimes
	fin.close();
	cout << "This program was coded by Hakeem Wilson" << endl;
	system("PAUSE");
	return 0;
}
