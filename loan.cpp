// Van Cung
// CSCE 10240
// Homework #4

#include <string>
#include <iostream>
using namespace std;

#include "loan.h"

// Default
Loan::Loan()
{
	loanID = 0;
	patronID = 0;
	bookID = 0;
	dueSec = 0;
	dueDate = "x/x/x"; 
	loanStatus = "none";
}
// Mutators 
void Loan::SetLoanID(int loanID)
{
	this->loanID = loanID;
}
void Loan::SetPatronID(int patronID)
{
	this->patronID = patronID;
}
void Loan::SetBookID(int bookID)
{
	this->bookID = bookID;
}
void Loan::SetDueDateSec(int dueSec)
{
	this->dueSec = dueSec;
}
void Loan::SetDueDate(string dueDate)
{
	this->dueDate = dueDate;
}
void Loan::SetLoanStatus(string loanStatus)
{
	this->loanStatus = loanStatus;
}
// Accessors 
int Loan::GetLoanID()
{
	return loanID;
}
int Loan::GetPatronID1()
{
	return patronID;
}
int Loan::GetBookID2() 
{
	return bookID;
}
int Loan::GetDueDateSec()
{
	return dueSec;
}
string Loan::GetDueDate()
{
	return dueDate;
}
string Loan::GetLoanStatus()
{
	return loanStatus;
}

