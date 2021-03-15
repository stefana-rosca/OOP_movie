#include "Repository.h"
#include "Validation.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "Exceptions.h"
using namespace std;


Repository::Repository( const string &filename) {
	this->filename = filename;
	this->read_file();
}

//adaug un film daca nu exista deja; daca exista -> arunc exceptie
void Repository::addMovie(const Film& m)
{
	Film m1{};
	try
	{
		m1 = this->findByTitleandGenre(m.get_titel(), m.get_genre(), m.get_erscheinungsjahr());
		throw DuplicateMovieException();
	}
	catch (InexistentMovieException& e) {}
	this->movies.push_back(m);
	this->writeToFile();
}

//parcurg cu un iterator vectorul de filme, iar daca ajung la final inseamna ca nu exista filmul si arunc exceptie
//altfel il sterg din movies si actualizez fisierul txt de filme
void Repository::removeMovie(const Film& m)
{
	for (int i = 0; i < movies.size(); i++)
		if (movies[i].get_titel() == m.get_titel())
			movies.erase(movies.begin() + i);
	this->writeToFile();

	/*
	auto it = find(this->movies.begin(), this->movies.end(), m);
	if (it == this->movies.end())
		throw InexistentMovieException{};
	this->movies.erase(it);
	this->writeToFile();
	*/
}

//citirea din fiser; daca nu se poate deschide, arunc exceptie
//altfel citesc si salvez in vector
void Repository::read_file()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	Film m;
	while (file >> m)
		this->movies.push_back(m);

	file.close();
}

//scrierea in fisier; din nou, daca nu se poate deschide arunc exceptie, altfel scriu din vector in fisier
void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	for (auto m : this->movies)
	{
		file << m;
	}

	file.close();
}

void Repository::updateMovie(const Film& m)
{
	removeMovie(m);
	cout << "Current number of likes is: " << m.get_likes();
	cout << "Do you want to change it?(y/n)";
	std::string w;
	Film m1 = m;
	cin >> w;
	//throw ConsoleerrorChar("Your answer must be or the letter y or n");
	if (w == "y")
	{
		int likes;
		cout << "The new amount of likes is: ";
		cin >> likes;
		m1.set_likes(likes);
	}

	cout << "The current source is: " << m.get_trailer();
	cout << "Do you want to change it?(y/n)";
	cin >> w;
	if (w == "y")
	{
		std::string link;
		cout << "The new link is: ";
		cin >> link;
		m1.set_trailer(link);
	}
	addMovie(m1);
}

//returnez filmul cu titlul si genul date ca parametru
//daca nu exista -> arunc exceptie
Film Repository::findByTitleandGenre(const std::string& title, const std::string& genre, const int &year) const
{
	for (int i = 0; i < movies.size(); i++)
		if (movies[i].get_titel() == title && movies[i].get_genre() == genre)
			return movies[i];
	throw InexistentMovieException{};
	/*
	for (auto m : this->movies)
	{
		if (m.get_titel() == title && m.get_genre() == genre)
			return m;
	}

	throw InexistentMovieException{};
	*/
}



/*
void Repository::add_film(Film film)
{
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i].get_titel() == film.get_titel())
		{
			return;
		}
	}
	movies.push_back(film);
}

vector <Film> Repository::delete_film_repo(string titel)
{
	vector<Film> sters;
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i].get_titel() != titel)
		{
			sters.push_back(movies[i]);
		}
	}
	movies = sters;
	return sters;
}

vector<Film> Repository::delete_film_watchliste(vector<Film> aux,string titel)
{
	vector<Film> sters;
	for (int i = 0; i < aux.size(); i++)
	{
		if (aux[i].get_titel() != titel)
		{
			sters.push_back(aux[i]);
		}
	}
	return sters;
}

Film Repository::get_film(vector<Film> aux, string titel)
{
	for (int i = 0; i < aux.size(); i++)
		if (aux[i].get_titel() == titel)
			return aux[i];
}

bool Repository::update_film(string titel, string genre, int jahr, int likes, string trailer)
{
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i].get_titel() == titel)
		{
			movies[i].set_genre(genre);
			movies[i].set_erscheinungsjahr(jahr);
			movies[i].set_likes(likes);
			movies[i].set_trailer(trailer);
			return true;
		}
	}
	return false;
}

vector<Film> Repository::nach_genre_anzeigen(string genre)
{
	if (genre == "")
		return movies;
	vector<Film> aux;
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i].get_genre() == genre)
			aux.push_back(movies[i]);
	}
	return aux;
}

/*
void Repository::zehn_eintrage()
{
	Film f1 = Film("Titanic", "Drama", 1997, 1000, "https://www.youtube.com/watch?v=kVrqfYjkTdQ");
	add_film(f1);

	Film f2 = Film("The Pianist", "Drama", 2002, 890, "https://www.youtube.com/watch?v=BFwGqLa_oAo");
	add_film(f2);

	Film f3;
	f3.set_titel("Focus");
	f3.set_genre("Comedie");
	f3.set_erscheinungsjahr(2015);
	f3.set_likes(1277);
	f3.set_trailer("https://www.youtube.com/watch?v=MxCRgtdAuBo");
	add_film(f3);

	Film f4;
	f4.set_titel("The longest ride");
	f4.set_genre("Romance");
	f4.set_erscheinungsjahr(2015);
	f4.set_likes(1600);
	f4.set_trailer("https://www.youtube.com/watch?v=FUS_Q7FsfqU");
	add_film(f4);

	Film f5;
	f5.set_titel("Bird Box");
	f5.set_genre("Horror");
	f5.set_erscheinungsjahr(2018);
	f5.set_likes(2055);
	f5.set_trailer("https://www.youtube.com/watch?v=o2AsIXSh2xo");
	add_film(f5);

	Film f6;
	f6.set_titel("Closer");
	f6.set_genre("Romance");
	f6.set_erscheinungsjahr(2004);
	f6.set_likes(2235);
	f6.set_trailer("https://www.youtube.com/watch?v=MdCc_NBlQC4");
	add_film(f6);

	Film f7;
	f7.set_titel("One Day");
	f7.set_genre("Romance");
	f7.set_erscheinungsjahr(2011);
	f7.set_likes(1897);
	f7.set_trailer("https://www.youtube.com/watch?v=zVuuooZqVaU&t=101s");
	add_film(f7);

	Film f8;
	f8.set_titel("Ready Or Not");
	f8.set_genre("Horror");
	f8.set_erscheinungsjahr(2019);
	f8.set_likes(1009);
	f8.set_trailer("https://www.youtube.com/watch?v=ZtYTwUxhAoI");
	add_film(f8);

	Film f9;
	f9.set_titel("The Orphanage");
	f9.set_genre("Horror");
	f9.set_erscheinungsjahr(2007);
	f9.set_likes(2089);
	f9.set_trailer("https://www.youtube.com/watch?v=UkuKtS-N1rM");
	add_film(f9);

	Film f10;
	f10.set_titel("Over Her Dead Body");
	f10.set_genre("Comedie");
	f10.set_erscheinungsjahr(2008);
	f10.set_likes(1276);
	f10.set_trailer("https://www.youtube.com/watch?v=8NR5RA75yDU");
	add_film(f10);
}


void Repository::update_likes(Film f, int likes)
{
	for (int i = 0; i < movies.size(); i++)
		if (movies[i].get_titel() == f.get_titel())
			movies[i].set_likes(likes);
}

int Repository::Size()
{
	return movies.size();
}

bool Repository::search_nach_titel(string titel)
{
	for (int i = 0; i < movies.size(); i++)
		if (movies[i].get_titel() == titel)
			return true;
	return false;
}

bool Repository::search_nach_genre(string genre)
{
	for (int i = 0; i < movies.size(); i++)
		if (movies[i].get_genre() == genre)
			return true;
	return false;
}
*/

