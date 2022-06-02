// CSE240 Spring 2022 HW 7 & 8
// Carlos Corral-Williams
// Write the compiler used: Visual Studio

// READ BEFORE YOU START:
// You are given a partially completed program that creates a linked list of employee information.
// The global linked list 'list' is a list of employees with each node being struct 'employeeList'.
// 'employeeList' consists of struct 'employee' which has: employee name, room number, and a linked list of 'supervisors'.
// The linked list of supervisors has each node containing simply the name of the supervisor.
// HW7 ignores the 'supervisors' linked list since there is no operation/manipulation to be done on 'supervisors' list in HW7.
// HW8 has operations/manipulations to be done with 'supervisors' list like add a supervisor, display last added supervisor.

// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// If you modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().
// You can use string library functions.

// ***** WRITE COMMENTS FOR IMPORANT STEPS OF YOUR CODE. *****
// ***** GIVE MEANINGFUL NAMES TO VARIABLES. *****
// ***** Before implementing any function, see how it is called in executeAction() *****


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996) // for Visual Studio

#define MAX_NAME 30

// global linked list 'list' contains the list of employees
struct employeeList {
	struct employee* employee;
	struct employeeList* next;
} *list = NULL;				// currently empty list

// structure "employee" contains the employee's name, room number and linked list of supervisors
struct employee {
	char name[MAX_NAME];
	unsigned int roomNumber;
	struct supervisor* supervisors;		// linked list 'supervisors' contains names of supervisors
};

//  structure 'supervisor' contains supervisor's name 
struct supervisor {
	char name[MAX_NAME];
	struct supervisor* next;
};

// forward declaration of functions (already implmented)
void flushStdIn();
void executeAction(char);

// functions that need implementation:
// HW 7
void addEmployee(char* employeeNameInput, unsigned int roomNumInput); // 20 points
void displayEmployeeList(struct employeeList* tempList);	      // 15 points
struct employee* searchEmployee(char* employeeNameInput);	      // 15 points
//HW 8
void addSupervisor(char* employeeNameInput, char* supervisorNameInput);	// 15 points
void displayEmployeeSupervisorList(struct employeeList* tempList);	// 15 points
void removeEmployee(char* employeeNameInput);			        // 20 points

int main()
{
	char selection = 'a';		// initialized to a dummy value
	do
	{
		printf("\nCSE240 HW 7,8\n");
		printf("Please enter your selection:\n");
		printf("HW7:\n");
		printf("\t a: add a new employee to the list\n");
		printf("\t d: display employee list (no supervisors)\n");
		printf("\t b: search for an employee on the list\n");
		printf("\t q: quit\n");
		printf("HW8:\n");
		printf("\t c: add a supervisor of a employee\n");
		printf("\t l: display employees who report to a specific supervisor\n");
		printf("\t r: remove an employee\n");
		printf("\t q: quit\n");

		selection = getchar();
		flushStdIn();
		executeAction(selection);
	} while (selection != 'q');

	return 0;
}

// flush out leftover '\n' characters
void flushStdIn()
{
	char c;
	do c = getchar();
	while (c != '\n' && c != EOF);
}

// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	char employeeNameInput[MAX_NAME], supervisorNameInput[MAX_NAME];
	unsigned int roomNumInput;
	struct employee* searchResult = NULL;

	switch (c)
	{
	case 'a':	// add employee
				// input employee details from user
		printf("\nPlease enter employee's name: ");
		fgets(employeeNameInput, sizeof(employeeNameInput), stdin);
		employeeNameInput[strlen(employeeNameInput) - 1] = '\0';	// discard the trailing '\n' char
		printf("Please enter room number: ");
		scanf("%d", &roomNumInput);
		flushStdIn();

		if (searchEmployee(employeeNameInput) == NULL)					
		{
			addEmployee(employeeNameInput, roomNumInput);
			printf("\nEmployee successfully added to the list!\n");
		}
		else
			printf("\nThat employee is already on the list!\n");
		break;

	case 'd':		// display the list
		displayEmployeeList(list);
		break;

	case 'b':		// search for an employee on the list
		printf("\nPlease enter employee's name: ");
		fgets(employeeNameInput, sizeof(employeeNameInput), stdin);
		employeeNameInput[strlen(employeeNameInput) - 1] = '\0';	// discard the trailing '\n' char

		if (searchEmployee(employeeNameInput) == NULL)				
			printf("\nEmployee name does not exist or the list is empty! \n\n");
		else
		{
			printf("\nEmployee name exists on the list! \n\n");
		}
		break;

	case 'r':		// remove employee
		printf("\nPlease enter employee's name: ");
		fgets(employeeNameInput, sizeof(employeeNameInput), stdin);
		employeeNameInput[strlen(employeeNameInput) - 1] = '\0';	// discard the trailing '\n' char

		if (searchEmployee(employeeNameInput) == NULL)					
			printf("\nEmployee name does not exist or the list is empty! \n\n");
		else
		{
			removeEmployee(employeeNameInput);
			printf("\nEmployee successfully removed from the list! \n\n");
		}
		break;

	case 'c':		// add supervisor
		printf("\nPlease enter employee's name: ");
		fgets(employeeNameInput, sizeof(employeeNameInput), stdin);
		employeeNameInput[strlen(employeeNameInput) - 1] = '\0';	// discard the trailing '\n' char

		if (searchEmployee(employeeNameInput) == NULL)					
			printf("\nEmployee name does not exist or the list is empty! \n\n");
		else
		{
			printf("\nPlease enter supervisor's name: ");
			fgets(supervisorNameInput, sizeof(supervisorNameInput), stdin);
			supervisorNameInput[strlen(supervisorNameInput) - 1] = '\0';	// discard the trailing '\n' char

			addSupervisor(employeeNameInput, supervisorNameInput);
			printf("\nSupervisor added! \n\n");
		}
		break;

	case 'l':		// list supervisor's employees
		displayEmployeeSupervisorList(list);
		break;

	case 'q':		// quit
		break;

	default: printf("%c is invalid input!\n", c);
	}
}

// HW7 Q1: addEmployee (20 points)
// This function is used to insert a new employee in the linked list. 
// You must insert the new employee to the head of linked list 'list'.
// You need NOT check if the employee already exists in the list because that is taken care by searchEmployee() called in executeAction(). Look at how this function is used in executeAction().
// Don't bother to check how to implement searchEmployee() while implementing this function. Simply assume that employee does not exist in the list while implementing this function.
// NOTE: The function needs to add the employee to the head of the list.
// NOTE: This function does not add supervisors to the employee info. There is another function addSupervisor() in HW8 for that.
// Hint: In this question, no supervisors means NULL supervisors.

void addEmployee(char* employeeNameInput, unsigned int roomNumInput)
{
	// write the code below.
	//forward declaring an employee struct for passing user-defined parameters into, for adding to list later.
	struct employee* tempEmp;
	//malloc used to allocate memory towards the forward-declared variable tempEmp
	tempEmp = malloc(sizeof(struct employee));
	//forward declaring a temporary employee list struct variable for adding user-defined employee into
	struct employeeList* tempEmpList;
	// memory allocation for the variable
	tempEmpList = malloc(sizeof(struct employeeList));
	
	//strcpy to copy the user input into the name attribute for temp employee.
	strcpy(tempEmp->name, employeeNameInput);
	//passing room number input into the employee object
	tempEmp->roomNumber = roomNumInput;
	//passing the NULL value supervisor, will be updated in functions for HW8
	tempEmp->supervisors = NULL;
	


	//passing newly created employee object to the empty temporary employeeList
	tempEmpList->employee = tempEmp;
	//updating the head by inserting new employee BEFORE the head and reassigning pointers
	tempEmpList->next = list;
	// updating "list" with the post-add templist.
	list = tempEmpList;
	
}

// HW7 Q2: displayEmployeeList (15 points)
// This function displays the employee details (struct elements) of each employee.
// Parse through the linked list 'list' and print the employee details (name and room number) one after the other. See expected output screenshots in homework question file.
// You should not display supervisor names (because they are not added in HW7).
// You MUST use recursion in the function to get full points. Notice that 'list' is passed to the function argument. Use recursion to keep calling this function till end of list.

void displayEmployeeList(struct employeeList* tempList)
{
	// write the code below.
	
	if (tempList == NULL) // if null, nothing to display
	{ }
	else
	{
		//prints employee's attributes as long as more to display
		printf("\nEmployee name: %s",tempList->employee->name);
		printf("\nRoom number: %d\n",tempList->employee->roomNumber);
		displayEmployeeList(tempList->next);
	}
}

// HW7 Q3: searchEmployee (15 points)
// This function searches the 'list' to check if the given employee exists in the list. Search by employee name.
// If it exists then return that 'employee' node of the list. Notice the return type of this function.
// If the employee does not exist in the list, then return NULL.
// NOTE: After implementing this fucntion, go to executeAction() to comment and un-comment the lines mentioned there which use searchEmployee()
//       in case 'a', case 'r', case 'l' (total 3 places)

struct employee* searchEmployee(char* employeeNameInput)
{
	struct employeeList* tempList = list;			// work on a copy of 'list'
	// write the code below.
	do
	{
		if (tempList != NULL) // if not a null value/node
		{
			if (strcmp(employeeNameInput, tempList->employee->name) == NULL)//if a match
			{
				return tempList->employee; // return said match

			}
			else
			{
				//else move to next node or try to
				tempList = tempList->next;
			}
		}
	} 
	while (tempList != NULL); // while not done or at end of list
	
	return NULL; // return null if no match is found
}



// HW8 Q1: addSupervisor (15 points)
// This function adds supervisor's name to a employee node.
// Parse the list to locate the employee and add the supervisor to that employee's 'supervisors' linked list. No need to check if the employee name exists on the list. That is done in executeAction().
// If the 'supervisors' list is empty, then add the supervisor. If the employee has existing supervisors, then you may add the new supervisor to the head or the tail of the 'supervisors' list.
// You can assume that the same supervisor name does not exist. So no need to check for existing supervisor names, like we do when we add new employee.
// NOTE: Make note of whether you add the supervisor to the head or tail of 'supervisors' list. 
//       (Sample solution has supervisor added to the tail of 'supervisors' list. You are free to add new supervisor to head or tail of 'supervisors' list.)

void addSupervisor(char* employeeNameInput, char* supervisorNameInput)
{
	struct employeeList* tempList = list;		// work on a copy of 'list'
	// write the code below.
	struct supervisor* tempSup; //forward declaration of supervisor struct 
	do
	{
		if (tempList != NULL) //if templist not null in first and future passes
		{
			if (strcmp(tempList->employee->name, employeeNameInput) == NULL) // if empName and input match
			{
				tempSup = malloc(sizeof(struct supervisor)); // memory allocating for new supervisor
				strcpy(tempSup->name, supervisorNameInput); // copy input into supervisor's name
				tempSup->next = tempList->employee->supervisors; // redirects next to this supervisor to beginning
				tempList->employee->supervisors = tempSup;// push supervisor into employee's supervisor
				break;
			}
			else
				tempList = tempList->next; // next node in list
		}
	} while (tempList != NULL); // as long as not null / end / empty list

}

// HW8 Q2: displayEmployeeSupervisorList (15 points)
// This function prompts the user to enter a supervisor name. This function then searches for employees with this supervisor.
// Parse through the linked list passed as parameter and print the matching employee details ( name and room number) one after the other. See expected output screenshots in homework question file.
// HINT: Use inputs gathered in executeAction() as a model for getting the supervisor name input.
// NOTE: You may re-use some HW7 Q2 displayEmployeeList(list) code here.

void displayEmployeeSupervisorList(struct employeeList* tempList)
{
	// write the code below.
	char supervisorNameIn[MAX_NAME]; // fwd declaration of supervisornam user input
	printf("\nPlease enter supervisor's name: ");
	fgets(supervisorNameIn, sizeof(supervisorNameIn), stdin); // gets user input
	supervisorNameIn[strlen(supervisorNameIn) - 1] = '\0';	// discard the trailing '\n' char

	if (tempList == NULL) // if null, nothing to display
	{
	}
	else
	{
		//prints employee's attributes as long as more to display and match supervisor name
		if (strcmp(supervisorNameIn, tempList->employee->supervisors->name) == NULL)
		{
			printf("\nEmployee name: %s", tempList->employee->name);
			printf("\nRoom number: %d\n", tempList->employee->roomNumber);
		}
		// check next node and call function to check/display if possible
		displayEmployeeList(tempList->next);
	}
	
}

// HW8 Q3: removeEmployee (20 points)
// This function removes an employee from the list.
// Parse the list to locate the employee and delete that 'employee' node.
// You need not check if the employee exists because that is done in executeAction()
//removeEmployee() is supposed to remove employee details like name and room number.
// The function will remove supervisors of the employee too.
// When the employee is located in the 'list', after removing the employee name and room number, parse the 'supervisors' list of that employee
// and remove the supervisors.

void removeEmployee(char* employeeNameInput)
{

	struct employeeList* tempList = list;	// work on a copy of 'list'
	struct supervisor* tempSupervisor;
	// write the code below.
	struct employeeList* tempTwin = list; // for holding a copy of list in diff position and utilizing for extra pointer
	do 
	{
		if (tempList != NULL) // if not end or null
		{
			if (strcmp(employeeNameInput, list->employee->name) == NULL) // when emp name matches input param at first index of list
			{
				tempList = list; // set tempList to equal to list's head node
				list = list->next; // set list's head equal to next node
				break;
			}
			else if (strcmp(employeeNameInput, tempList->employee->name) == NULL) // when input matches with current tempList employee
			{
				tempList = tempTwin->next; // templist is set to twin's next node
				tempTwin->next = tempList->next; // twin's next node is set to tempList's next node
				break;
			}
			else
			{
				tempTwin = tempList; // set tempTwin node to templist's current position
				tempList = tempList->next; // set tempList's node to the next node and continue to search
			}

		}
	} while (tempList != NULL);// while not empty or end of list
	
	do 
	{
		if (tempList->employee->supervisors != NULL) // if current supervisors are NOT null, continue
		{
			
			tempSupervisor = tempList->employee->supervisors; // tempSupervisor list set to current list in current employee
			tempList->employee->supervisors = tempSupervisor->next; // current supervisorslist node set to next TempSupervisor node
			free(tempSupervisor); // free tempSupervisor list
		}


	} while (tempList->employee->supervisors != NULL); // while not null/empty/end of list

	//finally, free found employee node and tempList
	free(tempList->employee); 
	free(tempList);
	
}