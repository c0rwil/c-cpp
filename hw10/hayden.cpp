// Q2a: Define displayBook() for Hayden class (5 points)
// Define the function displayBook() that you declared within the Hayden class in the header file
// See expected output in question file.

// (displayList() function in hw10.cpp should call this function.)
// Include necessary header files
#include "hayden.h"
#include <string>
#include <iostream>

void Hayden::displayBook()
{
	cout << "\nBook name: " << Book::getName();
	cout << "\nPrice: " << Book::getPrice();
	string lib2String;
	lib2String = Book::getLibraryType() == 1 ? "Noble" : "Hayden";
	cout << "\nLibrary: " << lib2String << endl;
}
