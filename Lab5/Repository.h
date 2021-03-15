#pragma once
#include <vector>
#include "Film.h"
//#include "Validation.h"


class Repository
{
	friend class ControllerAdministrator;
	friend class ControllerBenutzer;

private:
	vector<Film> movies;
	string filename;

	void read_file();
	void writeToFile();

public:

	Repository(const string& filename);

	/*Adds a movie to the repository.
	Input: m - Movie.
	Output: the movie is added to the repository.
	Throws: FileException - if the file cannot be opened.
	DuplicateMovieException - if there is another song with the same artist and title.
	*/
	void addMovie(const Film& m);

	/*
	Updates the movie with the given genre and title.
	Throws: InexistenSongException - if there are no songs with the given artist and title.
	*/
	void updateMovie(const Film& m);

	/*
	Removes the song with the given artist and title.
	Throws: InexistenSongException - if there are no songs with the given artist and title.
	*/
	void removeMovie(const Film& m);

	/*
	Finds a song, by artist and title.
	Input: artist, title - string
	Output: the song that was found, or an "empty" song (all fields empty and duration 0), if nothing was found.
	*/
	Film findByTitleandGenre(const std::string& title, const std::string& genre, const int& year) const;

	std::vector<Film> get_movies() const { return movies; }



	/*
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a film. </summary>
	///
	/// <remarks>	Popai, 23/04/2020. </remarks>
	///
	/// <param name="film">	The film. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void add_film(Film film);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deletes the film described by film. </summary>
	///
	/// <remarks>	Popai, 23/04/2020. </remarks>
	///
	/// <param name="film">	The film. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	vector<Film> delete_film_watchliste(vector<Film> aux, string titel);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Updates the film described by film. </summary>
	///
	/// <remarks>	Popai, 23/04/2020. </remarks>
	///
	/// <param name="film">	The film. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	bool update_film(string titel, string genre, int jahr, int likes, string trailer);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Genres. </summary>
	///
	/// <remarks>	Popai, 23/04/2020. </remarks>
	///
	/// <param name="genre">	The genre. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	vector<Film> nach_genre_anzeigen(string genre);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the film. </summary>
	///
	/// <remarks>	Popai, 23/04/2020. </remarks>
	///
	/// <returns>	The film. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Film get_film(vector<Film> aux, string titel);


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Updates the likes. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	///
	/// <param name="f">		A Film to process. </param>
	/// <param name="likes">	The likes. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void update_likes(Film f, int likes);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deletes the film repo described by titel. </summary>
	///
	/// <remarks>	Popai, 01/05/2020. </remarks>
	///
	/// <param name="titel">	The titel. </param>
	///
	/// <returns>	A vector&lt;Film&gt; </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	vector<Film> delete_film_repo(string titel);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the size. </summary>
	///
	/// <remarks>	Popai, 05/05/2020. </remarks>
	///
	/// <returns>	An int. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int Size();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Searches for the first match. </summary>
	///
	/// <remarks>	Popai, 05/05/2020. </remarks>
	///
	/// <param name="titel">	The titel. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool search_nach_titel(string titel);

	bool search_nach_genre(string genre);

	Film findByTitleandGenre(const std::string& title, const std::string& genre) const;

	vector<Film> get_movies() { return movies; }
	*/

	

};

