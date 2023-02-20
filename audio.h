#include <string>
#include <iostream>
using namespace std;

#include "libraryitem.h"

class Audio : public LibraryItem
{
	public:
		// Default
		Audio();
		// Mutators 
		void SetArtist(string artist);
		void SetTitle(string title);
		void SetTracks(int tracks);
		void SetReleaseDate(string releaseDate);
		void SetGenre(string genre);
		void PrintInfo() override;
		void PrintRawInfo() override;
		// Accessors 
		string GetArtist();
		string GetTitle();
		int GetTracks();
		string GetReleaseDate();
		string GetGenre();
	private:
		string artist;
		string title;
		int tracks;
		string releaseDate;
		string genre;
};
