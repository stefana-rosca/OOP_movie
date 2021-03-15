#include "Validation.h"
//#include "Repository.h"
//#include <string>
using namespace std;

MovieException::MovieException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> MovieException::getErrors() const
{
	return this->errors;
}

void MovieValidator::validate(Film& m)
{
	vector<string> errors;
	if (m.get_genre().size() < 3)
		errors.push_back(string("The genre name cannot be less than 3 characters!\n"));
	if (!isupper(m.get_titel()[0]))
		errors.push_back(string("The title must start with a capital letter!\n"));

	// search for "www" or "http" at the beginning of the source string
	int posWww = m.get_trailer().find("www");
	int posHttp = m.get_trailer().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The youtube link must start with one of the following strings: \"www\" or \"http\"");

	if (errors.size() > 0)
		throw MovieException(errors);
}

//Validation::Validation() 
//{
//}
//
//bool Validation::validate_string(string s)
//{
//	for (int i=0;i<s.length();i++)
//		if (isdigit(s[i]))
//			return false;
//	return true;
//}
//
//bool Validation::validate_int(string s)
//{
//	for (int i = 0; i < s.length(); i++)
//		if (isalpha(s[i]))
//			return false;
//	return true;
//}
//
//bool Validation::validate_ja_nein(string frage)
//{
//	if (frage == "Ja" || frage == "Nein")
//		return true;
//	return false;
//}
//
//bool Validation::invalid_year(int year)
//{
//	if (year < 1900 || year>2020)
//		return true;
//	return false;
//
//}
