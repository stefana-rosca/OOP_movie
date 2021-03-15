#pragma once
#include <string>
#include <vector>

//sterge space-urile de la inceput si de la sfarsit
std::string trim(const std::string& s);

//Returneaza un vector de string-uri delimitate de un delimitator dat ca si parametru 
std::vector<std::string> tokenize(const std::string& word, char delimiter);
