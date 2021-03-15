#include "Watchlist.h"
#include <fstream>

Watchlist::Watchlist() {
	this->current = 0;
}

//adaug film in watchlist
void Watchlist::add(Film& movie)
{
	this->movielist.push_back(movie);
}

Film Watchlist::getCurrentMovie()
{
	if (this->current == this->movielist.size())
		this->current = 0;
	return this->movielist[this->current];
	return Film{};
}

void Watchlist::play()
{
	if (this->movielist.size() == 0)
		return;
	this->current = 0;
	Film currentMovie = this->getCurrentMovie();
	currentMovie.runURL();
}

void Watchlist::next()
{
	if (this->movielist.size() == 0)
		return;
	this->current++;
	Film currentMovie = this->getCurrentMovie();
	currentMovie.runURL();
}

bool Watchlist::isEmpty()
{
	return this->movielist.size() == 0;
}

void Watchlist::display()
{
	if (this->movielist.size() == 0)
		return;
	for (auto i = movielist.begin(); i != movielist.end(); ++i)
	{
		i->toString();
	}
}

void Watchlist::removeFromWatchlist(const Film& m)
{
	if (this->movielist.size() == 0)
		return;
	for (int i = 0; i != movielist.size(); ++i)
	{
		if (movielist.at(i) == m)
		{
			movielist.erase(movielist.begin() + i);
		}
	}
}

int Watchlist::size()
{
	return movielist.size();
}