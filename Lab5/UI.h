#pragma once
#include "Controller.h"

class UI
{
private:
	Controller& ctrl;	// reference to the controller (controller cannot be copied!)

	static void printMenu();
	static void printUserMenu();
	static void printAdminMenu();

	void addMovieToRepo();
	void removeMovieFromRepo();
	void updateMovieFromRepo();
	void displayAllMoviesRepo();
	void addMovieToWatchlist();
	void saveWatchlistToFile();
	void removeMovieFromWatchlist();
	void view();

public:
	UI(Controller& c) : ctrl(c) {}

	void run();
};

