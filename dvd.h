// Van Cung
// CSCE 1040
// Homework #4

#include <string>
#include <iostream>
using namespace std;

#include "libraryitem.h"

class DVD : public LibraryItem
{
	public:
		// Default 
		DVD();
		// Mutators 
		void SetTitle(string title);
		void SetGenre(string genre);
		void SetRunTime(int runTime);
		void SetStudio(string studio);
		void SetReleaseDate(string releaseDate);
		void PrintInfo() override;
		void PrintRawInfo() override;
		// Accessors 
		string GetTitle();
		string GetGenre();
		int GetRunTime();
		string GetStudio();
		string GetReleaseDate();
	private:
		string title;
		string genre;
		int runTime;
		string studio;
		string releaseDate;
};