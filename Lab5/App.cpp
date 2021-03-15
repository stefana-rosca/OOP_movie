#include "Exceptions.h"
#include "UI.h"
#include "csvWatchlist.h"
#include <iostream>



int main()
{

	try
	{
		Repository repo("./movies.txt");
		FileWatchlist* w = new csvWatchlist {};
		Controller ctrl(repo, w, MovieValidator{});
		UI ui(ctrl);
		ui.run();
		delete w;
	}
	catch (FileException&)
	{
		cout << "Repository file could not be opened! The application will terminate." << endl;
		return 1;
	}

	return 0;
}