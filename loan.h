#include <string>
#include <iostream>
using namespace std;

class Loan
{
	public:
		// Default
		Loan();
		// Mutators 
		void SetLoanID(int LoanID);
		void SetPatronID(int patronID);
		void SetBookID(int bookID);
		void SetDueDateSec(int dueSec);
		void SetDueDate(string dueDate);
		void SetLoanStatus(string loanStatus);
		// Accessors 
		int GetLoanID();
		int GetPatronID1();
		int GetBookID2();
		int GetDueDateSec();
		string GetDueDate();
		string GetLoanStatus();
	private:
		int loanID;
		int patronID;
		int bookID;
		int dueSec;
		string dueDate;
		string loanStatus;
};

