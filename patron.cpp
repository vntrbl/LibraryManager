#include <string>
#include <iostream>
using namespace std;

#include "patron.h"

// Default 
Patron::Patron()
{
	patronID = 0;
	patronName = "No Name"; 
	booksOut = 0;
	fineBal = 0.0;
}
//Parameterized
Patron::Patron(int patronID, string patronName, double fineBal, int booksOut)
{
	this->patronID = patronID;
	this->patronName = patronName;
	this->fineBal = fineBal;
	this->booksOut = booksOut; 
}
// Mutators 
void Patron::SetID(int patronID)
{
	this->patronID = patronID;
}
void Patron::SetName(string patronName)
{
	this->patronName = patronName;
}
void Patron::SetFineBal(double fineBal)
{
	this->fineBal = fineBal;
}
void Patron::SetBooksOut(int booksOut)
{
	this->booksOut = booksOut;
}
//Accessors
int Patron::GetID()
{
	return patronID;
}
string Patron::GetName()
{
	return patronName;
}
double Patron::GetFineBal()
{
	return fineBal;
}
int Patron::GetBooksOut1()
{
	return booksOut;
}

