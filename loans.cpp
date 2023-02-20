#include <ctime>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#include "loans.h" 
// Check out item
void Loans::CheckOut(Patrons& lpatrons, LibraryItems& litems)
{
	int id;
	int b_id;
	Loan loan;
	
	srand(time(0));
	time_t due_sec = time(0) + 864000; // 10 days 
	char* dt = ctime(&due_sec);
	
	string due_date(dt);
	
	lpatrons.PrintPatrons();
	
	litems.PrintInItems();
	
	cout << "Enter Patron's ID To Check Out: ";
	cin >> id;
	cout << endl;
	cout << "Enter ID For Item To Check Out: ";
	cin >> b_id;
	
	// Conditions for checking out book 
	if((lpatrons.GetBooksOut2(id) < 6) && (lpatrons.PatronIDCheck(id) == true) && (litems.ItemIDCheck(b_id) == true))
	{
		loan.SetPatronID(lpatrons.GetPatronID3(id));
		loan.SetBookID(litems.GetItemID1(b_id));
		loan.SetLoanStatus("On Time");
		loan.SetLoanID(rand () % 8999 + 1000);
		loan.SetDueDate(due_date);
		loan.SetDueDateSec(due_sec);
		lpatrons.EditPatron1(lpatrons.FindPatron2(id));
		litems.EditStatusIn(litems.FindItem(b_id));
		
		loansList.push_back(loan);
	}
	else
	{
		if(lpatrons.PatronIDCheck(id) == false)
		{
			cout << endl;
			cout << "Patron's ID Not Found" << endl << endl;
		}
		else if(litems.ItemIDCheck(b_id) == false)
		{
			cout << endl;
			cout << "Item's ID Not Found" << endl << endl;
		}
		else if(lpatrons.GetBooksOut2(id) == 6 && lpatrons.PatronIDCheck(id) == true)
		{
			cout << endl; 
			cout << "Patrons Check Outs Are: " << lpatrons.GetBooksOut2(id) << " (Patron Can Not Check Out Anymore Items)" << endl << endl; 
		}
	}
}
// Update loan 
void Loans::UpdateLoanStatus(Patrons& lpatrons, LibraryItems& litems)
{
	time_t now = time(0);
	
	unsigned int i;
	for(i = 0; i < loansList.size(); i++)
	{
		int secOver = now - loansList.at(i).GetDueDateSec();
		
		if(loansList.at(i).GetDueDateSec() > now && secOver > 86400)
		{
			loansList.at(i).SetLoanStatus("Late");
			lpatrons.EditPatron3(lpatrons.FindPatron2(loansList.at(i).GetPatronID1()), secOver);
		}
	}
}
// Check in book 
void Loans::CheckIn(Patrons& lpatrons, LibraryItems& litems)
{
	int loan_id;
	int patron_id;
	
	lpatrons.PrintPatrons();
	
	cout << "Enter Patorn's ID To Check In: ";
	cin >> patron_id;
	
	PrintPatronCheckOuts2(patron_id);
	
	cout << "Enter Loan ID For Item To Check In: ";
	cin >> loan_id;
	
	unsigned int i;
	for(i = 0; i < loansList.size(); i++)
	{
		if(loansList.at(i).GetLoanID() == loan_id)
		{
			lpatrons.EditPatron2(lpatrons.FindPatron2(loansList.at(i).GetPatronID1()));
			litems.EditStatusOut(litems.FindItem(loansList.at(i).GetBookID2()));
			loansList.erase(loansList.begin() + 1);
		}
	}
}
// Report a lost book & assign balance 
void Loans::ReportLost(Patrons& lpatrons, LibraryItems& litems)
{
	int loan_id;
	int patron_id;
	
	lpatrons.PrintPatrons();
	
	cout << "Enter Patron's ID To Report Lost Item: ";
	cin >> patron_id;
	
	PrintPatronCheckOuts2(patron_id);
	
	cout << "Enter Loan ID For The Lost Item: ";
	cin >> loan_id;
	
	unsigned int i;
	for(i = 0; i < loansList.size(); i++)
	{
		if(loansList.at(i).GetLoanID() == loan_id)
		{
			int book_id = loansList.at(i).GetBookID2();
			
			lpatrons.EditPatron2(lpatrons.FindPatron2(loansList.at(i).GetPatronID1()));
			lpatrons.EditPatron4(lpatrons.FindPatron2(loansList.at(i).GetPatronID1()), book_id, litems);
			litems.EditStatusLost(litems.FindItem(loansList.at(i).GetBookID2()));
			loansList.erase(loansList.begin() + 1);
		}
	}
}
// Print all check outs 
void Loans::PrintPatronCheckOuts()
{
	cout << endl;
	cout << "ALL PATRON CHECK OUTS:" << endl << endl;
	
	unsigned int i;
	for(i = 0; i < loansList.size(); i++)
	{
		cout << "PATRON ID: " << loansList.at(i).GetPatronID1() << " | ";
		cout << "LOAN ID: " << loansList.at(i).GetLoanID() << " | ";
		cout << "LOAN STATUS: " << loansList.at(i).GetLoanStatus() << " | ";
		cout << "ITEM ID: " << loansList.at(i).GetBookID2() << " | ";
		cout << "LOAN DUE DATE: " << loansList.at(i).GetDueDate() << endl << endl; 
	}
}
// Print single patron's check outs 
void Loans::PrintPatronCheckOuts2(int id)
{
	cout << "PATRON'S CHECK OUTS:" << endl << endl; 
	
	unsigned int i;
	for(i = 0; i < loansList.size(); i++)
	{
		if(loansList.at(i).GetPatronID1() == id)
		{
		cout << "PATRON ID: " << loansList.at(i).GetPatronID1() << " | ";
		cout << "LOAN ID: " << loansList.at(i).GetLoanID() << " | ";
		cout << "LOAN STATUS: " << loansList.at(i).GetLoanStatus() << " | ";
		cout << "ITEM ID: " << loansList.at(i).GetBookID2() << " | ";
		cout << "LOAN DUE DATE: " << loansList.at(i).GetDueDate() << endl << endl; 
		}
	}
}
// Print all overdue books 
void Loans::PrintOverdue()
{
	cout << "ALL OVERDUE CHECK OUTS: " << endl << endl;
	
	unsigned int i;
	for(i = 0; i < loansList.size(); i++)
	{
		if(loansList.at(i).GetLoanStatus() == "Late")
		{
		cout << "PATRON ID: " << loansList.at(i).GetPatronID1() << " | ";
		cout << "LOAN ID: " << loansList.at(i).GetLoanID() << " | ";
		cout << "LOAN STATUS: " << loansList.at(i).GetLoanStatus() << " | ";
		cout << "BOOK ID: " << loansList.at(i).GetBookID2() << " | ";
		cout << "LOAN DUE DATE: " << loansList.at(i).GetDueDate() << endl << endl; 
		}
	}
}
// Store loans w/ size 
void Loans::StoreLoans()
{
	ofstream fout("loans.dat");
	
	fout << loansList.size() << endl; 
	
	unsigned int i;
	for(i = 0; i < loansList.size(); i++)
	{
		fout << loansList.at(i).GetPatronID1() << endl;
		fout << loansList.at(i).GetLoanID() << endl;
		fout << loansList.at(i).GetLoanStatus() << endl;
		fout << loansList.at(i).GetDueDate() << endl;
		fout << loansList.at(i).GetBookID2() << endl;
		fout << loansList.at(i).GetDueDateSec() << endl;
	}
	fout.close();
}
// Load loans 
void Loans::LoadLoans()
{
	Loan loan;
	ifstream fin("loans.dat");
	
	int loan_id;
	int patron_id;
	string status;
	string due_date;
	int book_id;
	int due_sec;
	
	int count = 0;
	
	fin >> count;
	fin.ignore();
	
	int i;
	for(i = 0; i < count; i++)
	{
		fin >> loan_id;
		fin.ignore();
		
		fin >> patron_id;
		fin.ignore();
		
		getline(fin, status);
		getline(fin, due_date);
		
		fin >> book_id;
		fin.ignore();
		
		fin >> due_sec;
		fin.ignore();
		
		loan.SetPatronID(patron_id);
		loan.SetBookID(book_id);
		loan.SetLoanStatus(status);
		loan.SetLoanID(loan_id);
		loan.SetDueDate(due_date);
		loan.SetDueDateSec(due_sec);
		loansList.push_back(loan);
	}
	fin.close();
}
