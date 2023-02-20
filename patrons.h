#include <vector>
#include <string> 
#include <iostream>
using namespace std;

#include "patron.h"
#include "libraryitems.h"

class Patrons 
{
	public:
		// Mutators 
		void AddPatron();
		void EditPatron1(int i);
		void EditPatron2(int id);
		void EditPatron3(int id, int sec);
		void EditPatron4(int id, int bookID, LibraryItems& items);
		void DeletePatron(int id);
		void PayFines(int id);
		void LoadPatrons();
		void StorePatrons();
		void PrintPatron(int id);
		void PrintPatrons();
		// Accessors 
		int FindPatron1(string name);
		int FindPatron2(int id);
		int GetPatronID2(string name);
		int GetPatronID3(int id);
		bool PatronIDCheck(int id);
		int GetBooksOut2(int id);
	private:
		vector<Patron> patronList;
};
