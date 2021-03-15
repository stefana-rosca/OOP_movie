#pragma once


#include "Watchlist.h"
#include "fileWatchlist.h"
#include "Repository.h"
#include <stdio.h>
#include <fstream>

class HTMLBuilder : public FileWatchlist {
public:
	/*
	Writes the Watchlist to file.
	Throws: FileException - if it cannot write.
	*/
	//suprascrie functia writeToFile() din repo
	void writeToFile() override;

    void build_watchlist(vector <int> watchlist, Repository& repo);

	/*
	Displays the Watchlist.
	*/
	void displayWatchlist() const override;
};

 