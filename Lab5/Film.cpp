#include "Film.h"
#include <string>
#include <windows.h>
#include <shellapi.h>
//#include<Windows.h>
#include <vector>
#include "Others.h"
#include <sstream>


Film::Film() : titel(""), genre(""), erscheinungsjahr(), likes(), trailer("") {}

Film::Film(const string &titel, const string &genre, const int &erscheinungsjahr, const int& likes, const string &trailer)
{
	this->titel = titel;
	this->genre = genre;
	this->erscheinungsjahr = erscheinungsjahr;
	this->likes = likes;
	this->trailer = trailer;
}

void Film::toString()
{
	string String;
	String = "Titel: " + this->titel + "  Genre: " + this->genre + "  Erscheinungsjahr: " ;
	string jahr = to_string(this->erscheinungsjahr);
	String += jahr;
	string likes = to_string(this->likes);
	String += "  Anzahl Likes: " + likes;
	String += "\n\tTralier: " + this->trailer + "\n";
	cout << String;
}

void Film::runURL()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->get_trailer().c_str(), NULL, SW_SHOWMAXIMIZED);


//	string a = this->trailer;
//	wstring b(a.begin(), a.end());
//	LPCWSTR c = b.c_str();
//	ShellExecute(0, 0, b.c_str(), 0, 0, SW_SHOW);
}

Film::~Film() {}

bool Film::operator==(const Film& m)
{
	return (this->titel == m.titel && this->genre == m.genre);
}

//citim din fisier
istream& operator>>(istream& is, Film& m)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5) // make sure all the data was valid
		return is;

	m.set_titel(tokens[0]) ;
	m.set_genre(tokens[1]);
	m.set_erscheinungsjahr(stoi(tokens[2]));
	m.set_likes (stoi(tokens[3]));
	m.set_trailer(tokens[4]);

	return is;

}

//scriem in fisier
ostream& operator<<(ostream& os, const Film& m)
{
	os << m.titel << ", " << m.genre << ", " << m.erscheinungsjahr << ", " << m.likes << ", " << m.trailer << "\n";
	return os;
}