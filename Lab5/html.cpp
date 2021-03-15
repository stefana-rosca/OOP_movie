#include "html.h"
#include "Exceptions.h"
#include <Windows.h>
#include <shellapi.h>
#include<iostream>


void HTMLBuilder::writeToFile()
{
    ofstream f(this->filename);

    if (!f.is_open())
        throw FileException(" The file could not be opened!");

    for (auto m : this->movielist)
        f << m;

    f.close();
}


void HTMLBuilder::build_watchlist(vector <int> watchlist, Repository& repo) 
{
    ofstream fin;
    fin.open("watchlist.html", std::fstream::in | std::fstream::out | std::fstream::app);

    fin << "<!DOCTYPE html>\n<html>\n<head>\n<title>Watchliste</title>\n</head>\n<body>\n<table border =";
    fin << "'1'";
    fin << "> \n<tr>\n<td>Titel</td>\n<td>Genre</td>\n<td>Jahr</td>\n<td>Likes</td>\n<td>Trailer link </td>\n";

    for (int i = 0; i < movielist.size(); i++) {
        Film m = movielist[i];
        fin << "</tr>\n<tr>\n<td>" << m.get_titel() << "</td>\n<td>" << m.get_genre() << "</td>\n<td>" << m.get_erscheinungsjahr() << "</td>\n<td>" << m.get_likes() << "</td>\n<td><a href = '" << m.get_trailer() << "'>Link</a></td>\n";
    }
    fin << "</tr>\n</table>\n</body>\n</html>";
    //fin.close();
}


void HTMLBuilder::displayWatchlist() const
{
    string aux = "watchlist.html"; // if the path contains spaces, we must put it inside quotations
    ShellExecuteA(NULL, "open", aux.c_str(), "watchlist.html", NULL, SW_SHOWMAXIMIZED);
}