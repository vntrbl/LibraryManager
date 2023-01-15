// Van Cung
// CSCE 10240
// Homework #4

#include <string>
#include <iostream>
using namespace std;

class Patron
{
	public:
		// Default
		Patron();
		// Parameterized 
		Patron(int patronID, string patronName, double fineBal, int booksOut);
		// Mutators
		void SetID(int patronID);
		void SetName(string patronName);
		void SetBooksOut(int booksOut);
		void SetFineBal(double fineBal);
		// Accessors 
		int GetID();
		string GetName();
		int GetBooksOut1();
		double GetFineBal();
	private:
		int patronID;
		string patronName; 
		int booksOut;
		double fineBal;
};

