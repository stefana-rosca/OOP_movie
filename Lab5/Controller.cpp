#include "Controller.h"
#include <algorithm>
#include "fileWatchlist.h"
#include "Exceptions.h"
#include <vector>
using namespace std;

//pt tot repo

void Controller::addMovieToRepository(const std::string& title, const std::string& genre, const int& year, const int& like, const std::string& trailer)
{
	Film m{ title, genre, year, like, trailer };
	this->validator.validate(m);
	this->repo.addMovie(m);
}

void Controller::removeMovieFromRepository(const std::string& title, const std::string& genre, const int& year)
{
	Film m = this->repo.findByTitleandGenre(title, genre, year);
	this->repo.removeMovie(m);

}

void Controller::updateMovieFromRepository(const std::string& title, const std::string& genre, const int& year)
{
	Film m = this->repo.findByTitleandGenre(title, genre, year);
	this->repo.updateMovie(m);
}

//pt Watchlist

void Controller::addMovieToWatchlist( Film& movie)
{
	if (this->watchlist == nullptr)
		return;
	this->watchlist->add(movie);
}

//void Controller::addAllMoviesByGenreToWatchlist(const std::string& genre)
//{
//	vector<Film> movielist = this->repo.get_movies();
//	int nMovies = count_if(movielist.begin(), movielist.end(),
//		[genre]( Film& m)
//		{
//			return m.get_genre() == genre;
//		});
//
//	vector<Film> moviesbyGenre(nMovies);
//	copy_if(movielist.begin(), movielist.end(), moviesbyGenre.begin(),
//		[genre]( Film& m)
//		{
//			return m.get_genre() == genre;
//		});
//
//	for (auto m : moviesbyGenre)
//		this->watchlist->add(m);
//}

void Controller::startWatchlist()
{
	if (this->watchlist == nullptr)
		return;
	this->watchlist->play();
}

void Controller::nextMovieWatchlist()
{
	if (this->watchlist == nullptr)
		return;
	this->watchlist->next();
}

void Controller::saveWatchlist(const std::string& filename)
{
	if (this->watchlist == nullptr)
		return;

	this->watchlist->setFilename(filename);
	this->watchlist->writeToFile();
}

void Controller::openWatchlist() const
{
	if (this->watchlist == nullptr)
		return;

	this->watchlist->displayWatchlist();
}

void Controller::display()
{
	if (this->watchlist == nullptr)
		return;

	this->watchlist->display();
}

void Controller::removeMovieFromWatchlist(const Film& m)
{
	if (this->watchlist == nullptr)
		return;

	this->watchlist->removeFromWatchlist(m);
}

vector<Film> Controller::addgenre(const std::string& genre)
{
	vector<Film> v;
	vector<Film> movielist = this->repo.get_movies();
	for (int i = 0; i < movielist.size(); i++)
		if (movielist[i].get_genre() == genre)
			v.push_back(movielist[i]);

	return v;

/*	int nMovies = count_if(movielist.begin(), movielist.end(),
		[genre](const Film& m)
		{
			return m.get_genre() == genre;
		});

	vector<Film> moviesbyGenre(nMovies);
	copy_if(movielist.begin(), movielist.end(), moviesbyGenre.begin(),
		[genre](const Film& m)
		{
			return m.get_genre() == genre;
		});

	for (auto m : moviesbyGenre)
		v.push_back(m);
	return v;*/
}