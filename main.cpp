// Van Cung
// CSCE 10240
// Homework #4

#include <string>
#include <iostream>
using namespace std;

#include "loans.h"

void PrintMenu(); // Menu function declaration 

int main()
{
	// Class objects 
	Patrons patrons;
	LibraryItems items;
	Loans loans;
	
	char option; // User input 
	
	// Load objects
	patrons.LoadPatrons();
	items.LoadItems();
	loans.LoadLoans();
	loans.UpdateLoanStatus(patrons, items);
	
	while(option != 'q' && option != 'Q') // If input is not 'q' or 'Q'
	{
		PrintMenu();
		cin >> option;
		cin.ignore();
		cout << endl << endl;
		
		switch(option)
		{
			case 'a':
			case 'A':
				patrons.AddPatron();
				break;
			case 'b':
			case 'B':
				items.AddItem();
				break;
			case 'c':
			case 'C':
				loans.CheckOut(patrons, items);
				break;
			case 'd':
			case 'D':
				loans.CheckIn(patrons, items);
				break;
			case 'e':
			case 'E':
				loans.ReportLost(patrons, items);
				break;
			case 'f':
			case 'F':
				int id_fine;
				patrons.PrintPatrons();
				
				cout << "Enter ID of patron paying fine: ";
				cin >> id_fine;
				cin.ignore();
				
				patrons.PayFines(id_fine);
				break;
			case 'g':
			case 'G':
				int id_remove;
				patrons.PrintPatrons();
				
				cout << "Enter ID of patron to be removed: ";
				cin >> id_remove;
				cin.ignore();
				
				patrons.DeletePatron(id_remove);
				break;
			case 'h':
			case 'H':
				int id_delitem;
				items.PrintItems();
				
				cout << "Enter ID of Item to be removed: ";
				cin >> id_delitem;
				cin.ignore();
				
				items.DeleteItem(id_delitem);
				break;
			case 'i':
			case 'I':
				patrons.PrintPatrons();
				break;
			case 'j':
			case 'J':
				items.PrintItems();
				break;
			case 'k':
			case 'K':
				loans.PrintPatronCheckOuts();
				break;
			case 'l':
			case 'L':
				loans.PrintOverdue(); 
				break;
			case 'm':
			case 'M':
				patrons.PrintPatrons();
				items.PrintItems();
				loans.PrintPatronCheckOuts();
				break;
			case 'q':
			case 'Q':
				break;
			default:
				cout << "Invalid Option (Choose Again)" << endl;
				break;
		}
	} 
	
	patrons.StorePatrons();
	items.StoreItems();
	loans.StoreLoans();
	
	return 0;
}

void PrintMenu() // Menu function 
{
	cout << "MENU" << endl;
	cout << "Select A Charactar Option:" << endl;
	cout << " [a] - Add A Patron" << endl;
	cout << " [b] - Add A Item" << endl;
	cout << " [c] - Check Out" << endl;
	cout << " [d] - Check In" << endl;
	cout << " [e] - Report Lost Item" << endl;
	cout << " [f] - Pay Patron Fine Balance" << endl;
	cout << " [g] - Remove A Patron" << endl;
	cout << " [h] - Remove A Item" << endl;
	cout << " [i] - Print All Patrons" << endl;
	cout << " [j] - Print All Items" << endl;
	cout << " [k] - Print All Check Outs" << endl;
	cout << " [l] - Print All Overdue Items" << endl;
	cout << " [m] - Print All Information" << endl;
	cout << " [q] - Quit" << endl << endl;
	cout << "Choose A Option: ";
}

