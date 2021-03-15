#pragma once
#include <string>
#include <iostream>
using namespace std;

class Film
{
private:
	string titel;
	string genre;
	int erscheinungsjahr;
	int likes;
	string trailer;

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Film();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	///
	/// <param name="parameter1">	The first parameter. </param>
	/// <param name="parameter2">	The second parameter. </param>
	/// <param name="parameter3">	The third parameter. </param>
	/// <param name="parameter4">	The fourth parameter. </param>
	/// <param name="parameter5">	The fifth parameter. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Film(const string &titel, const string &genre, const int &erscheinungsjahr, const int &likes, const string &trailer);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the titel. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	///
	/// <returns>	The titel. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	string get_titel() const { return this->titel; }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the genre. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	///
	/// <returns>	The genre. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	string get_genre() const { return this->genre; }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the erscheinungsjahr. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	///
	/// <returns>	The erscheinungsjahr. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int get_erscheinungsjahr() const { return this->erscheinungsjahr; }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the likes. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	///
	/// <returns>	The likes. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int get_likes() const { return this->likes; }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the trailer. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	///
	/// <returns>	The trailer. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	string get_trailer() const { return this->trailer; }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a titel. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	///
	/// <param name="titel">	The titel. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void set_titel(string titel) { this->titel = titel; }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a genre. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	///
	/// <param name="genre">	The genre. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void set_genre(string genre) { this->genre = genre; }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets an erscheinungsjahr. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	///
	/// <param name="erscheinungsjahr">	The erscheinungsjahr. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void set_erscheinungsjahr(int erscheinungsjahr) { this->erscheinungsjahr = erscheinungsjahr; }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the likes. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	///
	/// <param name="likes">	The likes. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void set_likes(int likes) { this->likes = likes; }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a trailer. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	///
	/// <param name="trailer">	The trailer. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void set_trailer(string trailer) { this->trailer = trailer; }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Convert this  into a string representation. </summary>
	///
	/// <remarks>	Popai, 23/04/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void toString();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Executes the URL operation. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void runURL();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Popai, 24/04/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	~Film();

	bool operator==(const Film& m);


	//pt citire si scriere in fisier
	friend std::istream& operator>>(std::istream& is, Film& m);
	friend std::ostream& operator<<(std::ostream& os, const Film& m);
};
