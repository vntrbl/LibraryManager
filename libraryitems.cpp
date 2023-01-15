// Van Cung
// CSCE 1040
// Homework #4

#include <ctime>
#include <time.h>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "dvd.h"
#include "book.h"
#include "audio.h"
#include "libraryitem.h" 
#include "libraryitems.h"

// Mutators
// Function: Add Item to collection (vector)
void LibraryItems::AddItem()
{
	Book* addBook;
	Audio* addAudio;
	DVD* addDVD;
	
	cout << "Choose Item Type (1 = Book | 2 = Audio | 3 = DVD): ";
	
	int type;
	cin >> type;
	cin.ignore();
	
	srand(time(0));
	if(type == 1)
	{
		addBook = new Book();
		
		string title; 
		string author;
		
		cout << "Enter Name Of Book To Add: ";
		getline(cin, title);
		cout << "Enter Name Of Book's Author: ";
		getline(cin, author);

		addBook->SetTitle(title);
		addBook->SetAuthor(author);
		addBook->SetItemStatus("In");
		addBook->SetItemID(rand () % 999999 + 100000);
		addBook->SetISBN(rand () % 1000000 + 1000000);
		addBook->SetItemCost(rand () % 47 + 2);
		addBook->SetLoanPeriod(0);
		libItems.push_back(addBook);
	}
	else if(type == 2)
	{
		addAudio = new Audio();
		
		string title;
		string artist;
		string genre;
		
		time_t release = time(0) - rand() % 946708560 + 10000;
		char* dt = ctime(&release);
		
		string release2(dt);
		
		cout << "Enter Title Of Audio: ";
		getline(cin, title);
		cout << "Enter Name Of Artist: ";
		getline(cin, artist);
		cout << "Enter Genre Of Audio: ";
		getline(cin, genre);
		
		addAudio->SetTitle(title);
		addAudio->SetArtist(artist);
		addAudio->SetTracks(rand () % 10 + 2);
		addAudio->SetReleaseDate(release2);
		addAudio->SetItemID(rand () % 9999 + 1000);
		addAudio->SetItemCost(rand () % 47 + 2);
		addAudio->SetItemStatus("In");
		addAudio->SetGenre(genre);
		addAudio->SetLoanPeriod(0);
		libItems.push_back(addAudio);
	}
	else if(type == 3)
	{
		addDVD = new DVD();
		
		string title;
		string studio;
		string genre;
		
		time_t release = time(0) - rand() % 946708560 + 10000;
		char* dt = ctime(&release);
		
		string release2(dt);
		
		cout << "Enter Title Of DVD: ";
		getline(cin, title);
		cout << "Enter Name Of Studio: ";
		getline(cin, studio);
		cout << "Enter Genre Of DVD: ";
		getline(cin, genre);
		
		addDVD->SetTitle(title);
		addDVD->SetStudio(studio);
		addDVD->SetItemID(rand () % 9999 + 1000);
		addDVD->SetItemCost(rand () % 47 + 2);
		addDVD->SetItemStatus("In");
		addDVD->SetGenre(genre);
		addDVD->SetLoanPeriod(0);
		addDVD->SetRunTime(rand () % 100 + 60);
		addDVD->SetReleaseDate(release2);
		libItems.push_back(addDVD);
	}
	else
	{
		cout << "Invalid Choice Type" << endl; 
	}
}
// Function: Item status (Out, In, Lost)
void LibraryItems::EditStatusOut(int i)
{
	libItems.at(i)->SetItemStatus("Out");
}
void LibraryItems::EditStatusIn(int id)
{
	libItems.at(id)->SetItemStatus("In");
}
void LibraryItems::EditStatusLost(int id)
{
	libItems.at(id)->SetItemStatus("Lost");
}
// Function: Remove/Delete Item 
void LibraryItems::DeleteItem(int id)
{
	ItemIDCheck(id);
	int i = FindItem(id);
	
	if(libItems.at(i)->GetItemStatus() == "In" && ItemIDCheck(id) == true)
	{
		if(i == 0)
		{
			libItems.erase(libItems.begin());
		}
		else if(i != 0 && i != libItems.size())
		{
			libItems.erase(libItems.begin() + i);
		}
		else if(i == libItems.size())
		{
			libItems.erase(libItems.end());
		}
	}
	else
	{
		if(libItems.at(i)->GetItemStatus() != "In" && ItemIDCheck(id) == true)
		{
			cout << "Item Is Still Checked Out (Please Check Back In)" << endl; 
		}
		else if(ItemIDCheck(id) != true)
		{
			cout << "Not A Item ID" << endl; 
		}
	}
}
// Function: Store size of items 
void LibraryItems::StoreItems()
{
	unsigned int i;
	
	ofstream fout("items.dat");
	fout << libItems.size() << endl;
	
	for(i = 0; i < libItems.size(); i++)
	{
		fout << libItems.at(i);
	}
	fout.close();
}
// Function: Load items to stored file 
void LibraryItems::LoadItems()
{
	ifstream fin("items.dat");
	
	int size = 0;
	fin >> size;
	fin.ignore();
	
	int i;
	for(i = 0; i < size; i++)
	{
		int type = 0;
		fin >> type;
		fin.ignore();
		
		if(type == 1)
		{
			Book* book;
			
			int id;
			double cost;
			int loan_time;
			string status;
			
			string title;
			string author;
			int isbn;
			
			fin >> id;
			fin.ignore();
			
			fin >> cost;
			fin.ignore();
			
			fin >> loan_time;
			fin.ignore();
			
			getline(fin, status);
			getline(fin, title);
			getline(fin, author);
			
			fin >> isbn;
			fin.ignore();
			
			book = new Book();
			
			book->SetTitle(title);
			book->SetAuthor(author);
			book->SetItemID(id);
			book->SetISBN(isbn);
			book->SetItemCost(cost);
			book->SetItemStatus(status);
			book->SetLoanPeriod(loan_time);
			libItems.push_back(book);
		}
		else if(type == 2)
		{
			Audio* audio;
			
			int id;
			double cost;
			int loan_time;
			string status;
			
			string title;
			string artist;
			string genre;
			int tracks;
			string release;
			
			fin >> id;
			fin.ignore();
			
			fin >> cost;
			fin.ignore();
			
			fin >> loan_time;
			fin.ignore();
			
			getline(fin, status);
			getline(fin, title);
			getline(fin, artist);
			getline(fin, genre);
			
			fin >> tracks;
			fin.ignore();
			
			getline(fin, release);
			
			audio = new Audio();
			
			audio->SetTitle(title);
			audio->SetArtist(artist);
            audio->SetTracks(tracks);
            audio->SetReleaseDate(release);
            audio->SetItemID(id);
            audio->SetItemCost(cost);
            audio->SetItemStatus(status);
            audio->SetGenre(genre);
            audio->SetLoanPeriod(loan_time);
            libItems.push_back(audio);
		}
		else if(type == 3)
		{
			DVD* dvd;
			
			int id;
			double cost;
			int loan_time;
			string status;
			
			string title;
			string studio;
			string genre;
			int run_time;
			string release;
			
			fin >> id;
			fin.ignore();
			
			fin >> cost;
			fin.ignore();
			
			fin >> loan_time;
			fin.ignore();
			
			getline(fin, status);
			getline(fin, title);
			getline(fin, studio);
			getline(fin, genre);
			
			fin >> run_time;
			fin.ignore();
			
			getline(fin, release);
			
			dvd = new DVD();
			
			dvd->SetTitle(title);
			dvd->SetStudio(studio);
			dvd->SetItemID(id);
            dvd->SetItemCost(cost);
            dvd->SetItemStatus(status);
            dvd->SetGenre(genre);
            dvd->SetLoanPeriod(loan_time);
            dvd->SetRunTime(run_time);
            dvd->SetReleaseDate(release);
            libItems.push_back(dvd);
		}
		else 
		{
			cout << "Nothing" << endl;
		}
	}
	fin.close();
}
// Function: Output all items  
void LibraryItems::PrintItems()
{
	cout << "ALL LIBRARY ITEMS:" << endl << endl; 
	
	unsigned int i;
	for(i = 0; i < libItems.size(); i++)
	{
		libItems.at(i)->PrintInfo();
	}
}
// Function: Output all (In) items
void LibraryItems::PrintInItems()
{
	cout << "ALL AVAILABLE LIBRARY ITEMS:" << endl << endl; 
	
	unsigned int i;
	for(i = 0; i < libItems.size(); i++)
	{
		if(libItems.at(i)->GetItemStatus() == "In")
		{
			libItems.at(i)->PrintInfo();
		}
	}
}
// Accessors 
// Function: Find item 
int LibraryItems::FindItem(int id)
{
	unsigned int i;
	for(i = 0; i < libItems.size(); i++)
	{
		if(libItems.at(i)->GetItemID() == id)
		{
			return i;
		}
	}
	return 0;
}
// Function: Get item ID
int LibraryItems::GetItemID1(int id)
{
	return libItems.at(FindItem(id))->GetItemID();
}
//Function: Get item cost 
double LibraryItems::GetItemCost(int id)
{
	return libItems.at(FindItem(id))->GetItemCost();
}
// Function: Check item ID
bool LibraryItems::ItemIDCheck(int id)
{
	unsigned int i;
	for(i = 0; i < libItems.size(); i++)
	{
		if(libItems.at(i)->GetItemID() == id)
		{
			return true;
		}
	}
	return 0;
}