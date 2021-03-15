#pragma once
#include "fileWatchlist.h"
#include "Repository.h"
#include <string>

class csvWatchlist : public FileWatchlist
{
public:
	/*
	Writes the Watchlist to file.
	Throws: FileException - if it cannot write.
	*/
	//suprascrie functia writeToFile() din repo
	void writeToFile() override;

	/*
	Displays the Watchlist.
	*/
	void displayWatchlist() const override;
};



