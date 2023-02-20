#include <string> 
#include <iostream>
using namespace std;

#include "loan.h"
#include "patrons.h"
#include "libraryitems.h"

class Loans
{
	public:
		void CheckOut(Patrons& lpatrons, LibraryItems& litems);
		void UpdateLoanStatus(Patrons& lpatrons, LibraryItems& litems);
		void CheckIn(Patrons& lpatrons, LibraryItems& litems);
		void ReportLost(Patrons& lpatrons, LibraryItems& litems);
		void PrintPatronCheckOuts();
		void PrintPatronCheckOuts2(int id);
		void PrintOverdue();
		void StoreLoans();
		void LoadLoans();
	private:
		vector<Loan> loansList;
};

