// Van Cung
// CSCE 1040
// Homework #4

#include <string>
#include <fstream> 
#include <iostream>
using namespace std;

#include "audio.h"

// Default 
Audio::Audio()
{
	artist = "No Name";
	title = "No Title";
	tracks = 0;
	releaseDate = "No Date";
	genre = "No Genre";
}
// Mutators 
void Audio::SetArtist(string artist)
{
	this->artist = artist;
}
void Audio::SetTitle(string title)
{
	this->title = title;
}
void Audio::SetTracks(int tracks)
{
	this->tracks = tracks;
}
void Audio::SetReleaseDate(string releaseDate)
{
	this->releaseDate = releaseDate;
}
void Audio::SetGenre(string genre)
{
	this->genre = genre;
}
void Audio::PrintInfo()
{
	cout << "AUDIO ID: " << GetItemID() << " | " << "COST: $" << GetItemCost();
	cout << " | " << "MAX LOAN PERIOD: " << GetLoanPeriod() << " | " << "STATUS: " << GetItemStatus();
	cout << " | " << "TITLE: " << GetTitle() << " | " << "ARTIST: " << GetArtist() << " | ";
	cout << "GENRE: " << GetGenre() << " | " << "TRACKS: " << GetTracks() << " | ";
	cout << "RELEASE DATE: " << GetReleaseDate() << endl << endl; 
}
void Audio::PrintRawInfo()
{
	int num = 2;
	
	ofstream fout("items.dat" , ios::app);
	fout << num << endl << GetItemID() << endl << GetItemCost() << endl << GetLoanPeriod() << endl;
	fout << GetItemStatus() << endl << GetTitle() << endl << GetArtist() << endl << GetGenre() << endl;
	fout << GetTracks() << endl << GetReleaseDate() << endl; 
}	
// Accessors
string Audio::GetArtist()
{
	return artist;
}
string Audio::GetTitle()
{
	return title;
}
int Audio::GetTracks()
{
	return tracks;
}
string Audio::GetReleaseDate()
{
	return releaseDate;
}
string Audio::GetGenre()
{
	return genre;
}