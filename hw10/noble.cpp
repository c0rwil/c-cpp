
// Q2b: Define displayBook() for Noble class (5 points)
// Define the function displayBook() that you declared within the Noble class in the header file
// See expected output in question file.

// (displayList() function in hw10.cpp should call this function.)
// Include necessary header files
#include "noble.h"
#include <string>
#include <iostream>

void Noble::displayBook()
{
	cout << "\nBook name: " << Book::getName();
	cout << "\nPrice: " << Book::getPrice();
	string lib2String;
	lib2String = Book::getLibraryType() == 1 ? "Noble" : "Hayden";
	cout << "\nLibrary: " << lib2String << endl;
}
