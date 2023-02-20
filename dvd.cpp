#include <string>
#include <fstream> 
#include <iostream>
using namespace std;

#include "dvd.h"

// Default 
DVD::DVD()
{
	title = "No Title";
	genre = "No Genre";
	runTime = 0;
	studio = "No Studio";
	releaseDate = "No Date";
}
// Mutators 
void DVD::SetTitle(string title)
{
	this->title = title;
}
void DVD::SetGenre(string genre)
{
	this->genre = genre;
}
void DVD::SetRunTime(int runTime)
{
	this->runTime = runTime;
}
void DVD::SetStudio(string studio)
{
	this->studio = studio;
}
void DVD::SetReleaseDate(string releaseDate)
{
	this->releaseDate = releaseDate;
}
void DVD::PrintInfo()
{
	cout << "DVD ID: " << GetItemID() << " | " << "COST: $" << GetItemCost();
	cout << " | " << "MAX LOAN PERIOD: " << GetLoanPeriod() << " | " << "STATUS: " << GetItemStatus();
	cout << " | " << "TITLE: " << GetTitle() << " | " << "STUDIO: " << GetStudio() << " | ";
	cout << "GENRE: " << GetGenre() << " | " << "RUN TIME: " << GetRunTime() << " | ";
	cout << "RELEASE DATE: " << GetReleaseDate() << endl << endl; 
}
void DVD::PrintRawInfo()
{
	int num = 3;
	
	ofstream fout("items.dat" , ios::app);
	fout << num << endl << GetItemID() << endl << GetItemCost() << endl << GetLoanPeriod() << endl;
	fout << GetItemStatus() << endl << GetTitle() << endl << GetStudio() << endl << GetGenre() << endl;
	fout << GetRunTime() << endl << GetReleaseDate() << endl; 
}	
// Accessors 
string DVD::GetTitle()
{
	return title;
}
string DVD::GetGenre()
{
	return genre;
}
int DVD::GetRunTime()
{
	return runTime;
}
string DVD::GetStudio()
{
	return studio;
}
string DVD::GetReleaseDate()
{
	return releaseDate;
}
