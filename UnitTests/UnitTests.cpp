#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5/Film.h"
#include "../Lab5/Repository.h"
#include "../Lab5/Validation.h"
#include "../Lab5/Watchlist.h"

#include <string>
#include <vector>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestss
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestConstructorFilm)
		{
			auto film = new Film("a", "b", 2000, 150, "www");
			Assert::AreEqual(string("a"), film->get_titel());
			Assert::AreEqual(string("b"), film->get_genre());
			Assert::AreEqual(2000, film->get_erscheinungsjahr());
			Assert::AreEqual(150, film->get_likes());
			Assert::AreEqual(string("www"), film->get_trailer());
		}

	/*	TEST_METHOD(TestRepo)
		{
			auto repo = new Repository();
			int i = 5;
			int j = 0;
			Assert::AreEqual(repo->Size(), i);
			Assert::AreEqual(repo->Size(), j);

			Film film = Film("a", "b", 2000, 150, "www");
			repo->add_film(film);
			int k = 6;
			Assert::AreEqual(repo->Size(), k);

			repo->delete_film_repo("a");
			repo->delete_film_repo("Titanic");
			int l = 4;
			Assert::AreEqual(repo->Size(), l);
		}

		/*TEST_METHOD(TestModify)
		{
			auto repo = new Repository();
			Assert::AreEqual(repo->movies[0].get_titel(), string("Titanic"));
			Assert::AreEqual(repo->movies[0].get_genre(), string("Drama"));
			Assert::AreEqual(repo->movies[0].get_erscheinungsjahr(), 1997);

			repo->update_film("Titanic", "nou", 2005, 1234, "https.www.trailer_titanic");

			Assert::AreEqual(repo->movies[0].get_genre(), string("nou"));
			Assert::AreEqual(repo->movies[0].get_erscheinungsjahr(), 2005);

			Film f1 = Film("Titanic", "Drama", 1997, 1000, "https://www.youtube.com/watch?v=kVrqfYjkTdQ");
			Assert::AreEqual(repo->movies[0].get_likes(), 1234);
			repo->update_likes(f1, 2050);
			Assert::AreEqual(repo->movies[0].get_likes(), 2050);

			vector<Film> aux = repo->nach_genre_anzeigen("Horror");
			Assert::AreEqual(aux.size(), size_t (1));
		}*/

		/*TEST_METHOD(TestValidation)
		{
			Validation v;
			Repository repoo;

			Film f1 = Film("Titanic", "Drama", 1997, 1000, "https://www.youtube.com/watch?v=kVrqfYjkTdQ");
			repoo.add_film(f1);

			Film f2 = Film("The Pianist", "Drama", 2002, 890, "https://www.youtube.com/watch?v=BFwGqLa_oAo");
			repoo.add_film(f2);

			Film f3;
			f3.set_titel("Focus");
			f3.set_genre("Comedie");
			f3.set_erscheinungsjahr(2015);
			f3.set_likes(1277);
			f3.set_trailer("https://www.youtube.com/watch?v=MxCRgtdAuBo");
			repoo.add_film(f3);

			Film f4;
			f4.set_titel("The longest ride");
			f4.set_genre("Romance");
			f4.set_erscheinungsjahr(2015);
			f4.set_likes(1600);
			f4.set_trailer("https://www.youtube.com/watch?v=FUS_Q7FsfqU");
			repoo.add_film(f4);

			Film f5;
			f5.set_titel("Bird Box");
			f5.set_genre("Horror");
			f5.set_erscheinungsjahr(2018);
			f5.set_likes(2055);
			f5.set_trailer("https://www.youtube.com/watch?v=o2AsIXSh2xo");
			repoo.add_film(f5);

			bool actual = v.validate_string("string");
			bool expected = true;
			Assert::AreEqual(actual, expected);

			bool actual2 = v.validate_string("abc12");
			bool expected2 = false;
			Assert::AreEqual(actual, expected);

			bool actual3 = v.validate_int("1234");
			bool expected3 = true;
			Assert::AreEqual(actual3, expected3);

		}*/
	};
}
