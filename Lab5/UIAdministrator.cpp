#include "UIAdministrator.h"
//#include"ControllerAdministrator.h"
#include<iostream>

UIAdministrator::UIAdministrator() {
	UIcomun ui;
}

void UIAdministrator::meniu()
{
	cout << "\t Administratormodus \n\n"; 
	cout << "1.Fugen einen Film hinzu\n";
	cout << "2.Loschen einen Film\n";
	cout << "3.Beartbeiten die Informationen eines Film\n";
	cout << "4.Liste der Filme ansehen\n";
	cout << "0.Exit\n\n";
}

void UIAdministrator::optiuni()
{
	UIcomun ui;
	//ControllerAdministrator ctrl;
	while (true)
	{
		meniu();

		int optiune;
		cout << "Wahlen sie eine Option\n";
		cin >> optiune;
		if (optiune != 0) {
			switch (optiune)
			{
			/*case 0:
			{
				ui.menu();
				break;
			}*/
			case 1:
			{
				ctrl.add();
				break;
			}
			case 2:
			{
				ctrl.deletee();
				break;
			}
			case 3:
			{
				ctrl.edit_film_info();
				break;
			}
			case 4:
			{
				ctrl.show_filme();
				break;
			}
			}
		}else if(optiune==0){break;}
	}
}

/*
void UIAdministrator::optiuni()
{
	ControllerAdministrator ctrl;
	while (true)
	{
		meniu();

		int optiune;
		cout << "Wahlen sie eine Option\n";
		cin >> optiune;
		switch (optiune)
		{
		case 0:
			return;

		case 1:
		{
			cout << "New film to be added\n";
			string title, genre, link;
			int like, year;
			cout << "Title: ";
			cin >> title;
			cout << "Genre: ";
			cin >> genre;
			cout << "Year: ";
			cin >> year;
			cout << "Likes: ";
			cin >> like;
			cout << "Source: ";
			cin >> link;
			if (year < 0 || 1000 > year || year > 2020)
			{
				cout << "please enter a valid year!" << endl;
			}
			else {
				Film f = Film(title, genre, year, like, link);
				ctrl.add_film(f);
				break;
			}
			break;
		}
		case 2:
		{
			cout << "Film to be removed\n";
			string title, genre, link = "s";
			int like = 0, year;
			cout << "Title: ";
			cin >> title;
			cout << "Genre: ";
			cin >> genre;
			cout << "Year: ";
			cin >> year;
			if (year < 0 || 1000 > year || year > 2020)
			{
				cout << "please enter a valid year!" << endl;
			}
			else {
				Film f = Film(title, genre, year, like, link);
				ctrl.delete_film(f);
				break;
			}
			break;
		}
		case 3:
		{						cout << "Film to be updated\n";
		string title, genre, link = "s";
		int like = 0, year;
		cout << "Title: ";
		cin >> title;
		cout << "Genre: ";
		cin >> genre;
		cout << "Year: ";
		cin >> year;
		if (year < 0 || 1000 > year || year > 2020)
		{
			cout << "please enter a valid year!" << endl;
		}
		else {
			Film f = Film(title, genre, year, like, link);
			ctrl.edit_film_info(f);
			break;
		}
		case 4:
		{
			ctrl.show_film();
			break;
		}
		}
		
	}
}
*/