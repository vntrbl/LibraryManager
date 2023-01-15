// Van Cung
// CSCE 1040
// Homework #4

#include <string>
#include <iostream>
using namespace std;

#include "libraryitem.h"

// Default
LibraryItem::LibraryItem()	
{
	ItemID = 0;
	itemCost = 0.0;
	itemStatus = "none";
	loanPeriod = 0;
}
// Mutators 
void LibraryItem::SetItemID(int ItemID)	
{
	this->ItemID = ItemID;
}

void LibraryItem::SetItemCost(double itemCost)	
{
	this->itemCost = itemCost;
}

void LibraryItem::SetItemStatus(string itemStatus)	
{
	this->itemStatus = itemStatus;
}

void LibraryItem::SetLoanPeriod(int loanPeriod)	
{
	this->loanPeriod = loanPeriod;
}
void LibraryItem::PrintInfo()
{
	cout << "ID: ";
}
void LibraryItem::PrintRawInfo()
{
	
}
// Accessors 
int LibraryItem::GetItemID()	
{
	return ItemID;
}

double LibraryItem::GetItemCost()	
{
	return itemCost;
}

string LibraryItem::GetItemStatus()	
{
	return itemStatus;
}

int LibraryItem::GetLoanPeriod()	
{
	return loanPeriod;
}