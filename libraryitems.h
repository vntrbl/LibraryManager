// Van Cung
// CSCE 1040
// Homework #4

#ifndef LIBS
#define LIBS

#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "libraryitem.h"

class LibraryItems
{
	public:
		// Mutators
		void AddItem();
		void EditStatusOut(int i);
		void EditStatusIn(int id);
		void EditStatusLost(int id);
		void DeleteItem(int id);
		void StoreItems();
		void LoadItems();
		void PrintItems();
		void PrintInItems();
		// Accessors 
		int FindItem(int id);
		int GetItemID1(int id);
		double GetItemCost(int id);
		bool ItemIDCheck(int id);
	private:
		vector<LibraryItem*> libItems;
};
#endif 