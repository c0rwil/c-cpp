// CSE240 Spring 2022 HW9
// Carlos Corral-Williams
// Write the compiler used: Visual Studio

// READ BEFORE YOU START:
// You are given a partially completed program which consist of a class 'Patient' defined in patient.h
// The definitions of class member functions are to be filled in patient.cpp
// hw09q1.cpp (this file) creates an array of objects 'p[]' and uses a menu driven program to add a patient, display patient info, 
// sort the patient list and to find the oldest patient(by birth year).
// You should start completing the program from from Q1. Question numbers are given around line 33.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// If you modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().

// ***** WRITE COMMENTS FOR IMPORANT STEPS OF YOUR CODE. *****
// ***** GIVE MEANINGFUL NAMES TO VARIABLES. *****

#include "patient.h"
#include <iostream>
#include <string>

#define MAX_PATIENTS 10

using namespace std;

// forward declaration of functions (already implmented)
void executeAction(char);

// functions that need implementation:
// in patient.cpp :
// Q1 Patient constructor			// 2 points
// Q2 Patient member functions		// 18 points

// in this file (hw09q1.cpp) : Q3 to Q6
int addPatient(string name_input, int age_input, int DOByear_input, int ID_input);	// 10 points
void displayPatients();																// 5 points
void sort();																		// 10 points
void youngestPatient();																// 5 points

Patient p[MAX_PATIENTS];			// array of objects
int currentCount = 0;				// number of patients in the list

int main()
{
	char choice = 'i';		// initialized to a dummy value
	do
	{
		cout << "\nCSE240 HW9\n";
		cout << "Please select an action:\n";
		cout << "\t a: add a new patient\n";
		cout << "\t d: display patient list\n";
		cout << "\t s: sort the patients in descending order based on age (within a range)\n";
		cout << "\t n: display the youngest patient whose name starts with a specific letter\n";
		cout << "\t q: quit\n";
		cin >> choice;
		cin.ignore();			// ignores the trailing \n
		executeAction(choice);
	} while (choice != 'q');

	return 0;
}


// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	string name_input;
	int age_input, DOByear_input, ID_input, result = 0;

	switch (c)
	{
	case 'a':	// add patient
				// input patient details from user
		cout << "Please enter patient name: ";
		getline(cin, name_input);
		cout << "Please enter age: ";
		cin >> age_input;
		cin.ignore();
		cout << "Please enter year of birth: ";
		cin >> DOByear_input;
		cin.ignore();
		cout << "Please enter ID: ";
		cin >> ID_input;
		cin.ignore();

		// add the patient to the list
		result = addPatient(name_input, age_input, DOByear_input, ID_input);
		if (result == 0)
			cout << "\nThat patient is already in the list or list is full! \n\n";
		else
			cout << "\nPatient successfully added to the list! \n\n";
		break;

	case 'd':		// display the list
		displayPatients();
		break;

	case 's':		// sort the list
		sort();
		break;

	case 'n':		// find and display oldestt patient
		youngestPatient();
		break;

	case 'q':		// quit
		break;

	default: cout << c << " is invalid input!\n";
	}

}

// Q3 addPatient (10 points)
// This function adds a new patient with the details given in function arguments.
// Add the patient in 'p' (array of objects) only if there is remaining capacity in the array and if the patient does not already exist in the list
// This function returns 1 if the patient is added successfully, else it returns 0 for the cases mentioned above.
// Assume user enters age in 0.0 - any positive integer range.
int addPatient(string name_input, int age_input, int DOByear_input, int ID_input)
{
	// Write the code below

    if(currentCount == MAX_PATIENTS) // if maxed out return 0
    {
    return 0;
    }

	Patient tempPat; // temp variable
	tempPat.setAge(age_input); // passing parameters to temp variable
	tempPat.setName(name_input);
	tempPat.setDOByear(DOByear_input);
	tempPat.setID(ID_input);
    for(int i = 0; i < currentCount; i++) // parse array
    {
        if(p[i].getID() == tempPat.getID()) // if given element already exists return 0
        {
        return 0;
        }
    }
	p[currentCount] = tempPat; // add newly created patient at end of array
	currentCount++; // increment count
	return 1;	// edit this line if needed
}

// Q4 displayPatients (5 points)
// This function displays the list of patients.
// Parse the object array 'p' and display the details of all patientss in the array. See expected output given in question file.
// You can call the class function 'displayPatients()' here. Note that these are two different functions.
// Patient::displayPatient() displays details of one Patient object, while displayPatients() should display all patients
void displayPatients()
{
	// Write the code below
    for(int i = 0; i < currentCount; i++) // parse array
    {
        p[i].displayPatient(); // display patients in array currently
    }
	
}

// Q5 sort (10 points)
// This function sorts the patients in descending order of age, and then display the patients within a given range.
// You may use the 'tempPatient' object for sorting logic, if needed.
void sort()
{
	Patient tempPatient;
	int lowerBoundAge;
	int higherBoundAge;
	// Write the code below
	cout << "\nPlease enter the lower bound of age: "; // prompt and store userinput for lower age
	cin>>lowerBoundAge;
	cin.ignore();
	cout << "\nPlease enter the higher bound of age: "; // prompt and store userinput for higher age
	cin >> higherBoundAge;
	cin.ignore();
	
		for (int i = 0; i < currentCount; i++) // parse
		{
			for (int j = i + 1; j < currentCount; j++) // parse offset
			{
				if (p[i].getAge() < p[j].getAge()) // if leftside is less than right side
				{
					tempPatient = p[i]; // swap toBeMoved to temp
					p[i] = p[j]; // swap index value with updated value
					p[j] = tempPatient; // toBeMoved value in it's updated location
				}
			}
		}

	for (int i = 0; i < currentCount; i++) // parse
	{
		if (p[i].getAge() >= lowerBoundAge && p[i].getAge() <= higherBoundAge) // if within age limits
		{
			p[i].displayPatient(); // display given patient
		}
	}

}

// Q6 youngestPatient (5 points)
// This functions displays patients who is youngest and whose name starts with a specific letter
// Parse the array to check if the patient is the youngest patient based of the character input
// If the patient is the youngest patient year then copy that patient's details (object's data members) 
// to 'newPatient' object created using 'new' and display those patient details using 'newPatient' object.
// Finally delete the 'newPatient' object.
// NOTE: You necessarily have to use the 'newPatient' object to store the patient details in it and delete it after displaying.
//       You should not display patient details using 'p[]' object.
void youngestPatient()
{
	char startingCharacter;				// Ask the user for a character
	Patient* newPatient = new Patient; 
	Patient tempPat; // temp holder
	// Write the code below
	cout << "\nEnter the first letter of the patient's name: "; // prompt user for input
	cin >> startingCharacter; // store input in variable
	for (int i = 0; i < currentCount; i++) // parse array
	{
		if (p[i].getName()[0] == startingCharacter) // if element's name at 0th index matches startingChar
		{
			tempPat = p[i]; // store variable in tempPatient
			if (tempPat.getAge()>p[i].getAge()) // if tempPatient's age is greater than the current element's age
				{
					tempPat = p[i]; // update
				}
		}
	}
	newPatient->setAge(tempPat.getAge()); // reading values into newPatient
	newPatient->setDOByear(tempPat.getDOByear());
	newPatient->setID(tempPat.getID());
	newPatient->setName(tempPat.getName());
	newPatient->displayPatient(); // displaying youngestPatient
	delete(newPatient);// deleting newPatient variable
}
