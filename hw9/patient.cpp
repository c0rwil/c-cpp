// CSE240 Spring 2022 HW9
// Carlos Corral-Williams
// Write the compiler used: Visual Studio

#include "patient.h"
#include <iostream>
#include <string>

using namespace std;

// Q1 Patient (2 points)
// Patient() constructor assigns the following default values to class data members
// name: abc
// age: 19
// DOByear: 2000
// ID: 0
Patient::Patient()
{
	// Write the code below
    name = "abc"; // set to default 
    age = 19;
    DOByear = 2000;
    ID = 0;
	
}

// Q2 (18 points)
// 2 points for each function

// Define all the class member functions.
// While defining member functions, note that these functions will be called using 
// a 'Patient' object which will represent one patient.
// Eg-  Patient p[10]; creates 10 Patient objects
//		p[2].setAge(19); will set 3rd patient's age to 19

// setName assigns 'name_input' to class data member 'name'
void Patient::setName(string name_input)
{
	// Write the code below
	name = name_input; // attributes set to userinput
}

// setAge assigns age_input to class data member 'age'
void Patient::setAge(int age_input)
{
	// Write the code below
	age = age_input; //set age to userinput
}

// setDOByear assigns 'DOByear_input' to class data member 'DOByear'
void Patient::setDOByear(int DOByear_input)
{
	// Write the code below
	DOByear = DOByear_input; //set DOB to userinput
}

// setID assigns 'ID_input' to class data member 'ID'
void Patient::setID(int ID_input)
{
	// Write the code below
	ID = ID_input; // set ID to userinput
}

// displayPatients displays the name, age, year of birth and ID of the paatient
// See expected output in question file.
void Patient::displayPatient()
{
	// Write the code below
cout<<"Name: "<<Patient::getName()<<endl; // displaying each attribute of a patient along with subheadings
cout<<"Age: "<<Patient::getAge()<<endl;
cout<<"Year of birth: "<<Patient::getDOByear()<<endl;
cout<<"ID: "<<Patient::getID()<<endl;
cout << "\n"; 
}

// getName returns the class data member 'name'.
string Patient::getName()
{
	// Write the code below
	return name; // returning name value
}

// getAge returns the class data member 'age'.
int Patient::getAge()
{
	// Write the code below
	return age; // returning age value
}

// getDOByear returns the class data member 'DOByear'.
int Patient::getDOByear()
{
	// Write the code below
	return DOByear; // return DOB
}

// getID returns the class data member 'ID'.
int Patient::getID()
{	
	// Write the code below
	return ID; // returning ID
}
