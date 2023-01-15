// Van Cung
// CSCE 1040
// Homework #4

#ifndef LIB
#define LIB

#include <string> 
#include <fstream>
#include <iostream>
using namespace std;

class LibraryItem
{
	public:
		// Default 
		LibraryItem();
		// Mutators 
		void SetItemID(int ItemID);
		void SetItemCost(double itemCost);
		void SetItemStatus(string itemStatus);
		void SetLoanPeriod(int loanPeriod);
		virtual void PrintInfo();
		virtual void PrintRawInfo();
		// Accessors 
		int GetItemID();
		double GetItemCost();
		string GetItemStatus();
		int GetLoanPeriod();
	protected:
		int ItemID;
		double itemCost;
		string itemStatus;
		int loanPeriod;
};

#endif