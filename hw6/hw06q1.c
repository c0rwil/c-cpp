// CSE240 Spring 2022 HW6
// Carlos Corral-Williams
// Write the compiler used: Visual Studio
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996) 			// for Visual Studio Only

#define MAX_BOOKS 15
#define MAX_NAME_LENGTH 50

typedef enum { novel = 0, comic, history, art, nonfiction } bookType; // enum type

struct libraryRecord {					// struct for book details
	char bookTitle[MAX_NAME_LENGTH];
	char author[MAX_NAME_LENGTH];
	bookType booktype;
	unsigned int bookId;
	struct libraryRecord* next;			// pointer to next node
}*list = NULL;							// declare linked list 'list'

int count = 0;							// the number of books currently stored in the list (initialized to 0)

// functions already implmented
void flushStdIn();
void executeAction(char);
void save(char* fileName);

// functions that need implementation:
int add(char* bookTitle_input, char* author_input, char* booktype_input, unsigned int bookId_input); // 20 points
void sort();				  				// 10 points
int delete(unsigned int bookId_input);  // 10 points
void load(char* fileName);		  			// 10 points
void display();				  // given


int main()
{
	char* fileName = "Book_List.txt";
	load(fileName);			// load list of books from file (if it exists). Initially there will be no file.
	char choice = 'i';		// initialized to a dummy value
	do
	{
		printf("\nEnter your selection:\n");
		printf("\t a: add a new book\n");
		printf("\t d: display book list\n");
		printf("\t r: remove a book from list\n");
		printf("\t s: sort book list by ID\n");
		printf("\t q: quit\n");
		choice = getchar();
		flushStdIn();
		executeAction(choice);
	} while (choice != 'q');

	save(fileName); 		// save list of books to file (overwrites file, if it exists)
	return 0;
}

// flush out leftover '\n' characters
void flushStdIn()
{
	char c;
	do c = getchar();
	while (c != '\n' && c != EOF);
}

// ask for details from user for the given selection and perform that action
void executeAction(char c)
{
	char bookTitle_input[MAX_NAME_LENGTH], author_input[MAX_NAME_LENGTH];
	unsigned int bookId_input, add_result = 0;
	char booktype_input[20];
	switch (c)
	{
	case 'a':
		// input book record from user
		printf("\nEnter book title: ");
		fgets(bookTitle_input, sizeof(bookTitle_input), stdin);
		bookTitle_input[strlen(bookTitle_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Enter author name: ");
		fgets(author_input, sizeof(author_input), stdin);
		author_input[strlen(author_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Enter book type (Novel/Comic/History/Art/Nonfiction): ");
		fgets(booktype_input, sizeof(booktype_input), stdin);
		booktype_input[strlen(booktype_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Please enter book ID number: ");
		scanf("%d", &bookId_input);
		flushStdIn();


		// add the book to the list
		add_result = add(bookTitle_input, author_input, booktype_input, bookId_input);
		if (add_result == 0)
			printf("\nBook is already on the list! \n\n");
		else if (add_result == 1)
			printf("\nBook successfully added to the list! \n\n");
		else
			printf("\nUnable to add. Book list is full! \n\n");

		break;

	case 'r':
		printf("Please enter ID number of book to be deleted: ");
		scanf("%d", &bookId_input);
		flushStdIn();
		int delete_result = delete(bookId_input);
		if (delete_result == 0)
			printf("\nBook not found in the list! \n\n");
		else
			printf("\nBook deleted successfully! \n\n");
		break;
	case 'd': display();	break;
	case 's': sort();		break;

	case 'q': break;
	default: printf("%c is invalid input!\n", c);
	}
}

// Q1 : add (10 points)
// This function is used to add a book into the list. You can simply add the new book to the end of list (linked list of structs).
// Do not allow the book to be added to the list if it already exists in the list. You can do that by checking book names OR IDs already in the list.
// If the book already exists then return 0 without adding it to the list. If the book does not exist in the list then add the book at the end of the list and return 1.
// If book list is full, then do not add new book to the list and return 2.
// NOTE: Notice how return type of add() is checked in case 'a' of executeAction()
// NOTE: You must convert the string 'booktype_input' to an enum type and store it in the list because the booktype has enum type (not string type).
// The list should be case sensitive. For instance, 'Roger' and 'roger' should be considered two different names.
// Hint: 'count' holds the number of books currently in the list
int add(char* bookTitle_input, char* author_input, char* booktype_input, unsigned int bookId_input)
{
	struct libraryRecord* tempList = list;	// work on a copy of 'list'.
	// Write the code below
	struct libraryRecord* bookEnd= NULL;
	// if count is already at max and return 2
	if (count == MAX_BOOKS) { return 2; }
	// while list not empty, parse through it
	while (tempList != NULL)
	{
		// if id exists, return 0 and don't add
		if (tempList->bookId == bookId_input)
		{
			return 0;
		}
		//if id doesn't exist, add it
		else
		{
			bookEnd = tempList;
			tempList = tempList->next;
			count++;
		}
	}
	// creating a library record
	struct libraryRecord* freshAddition;
	freshAddition = malloc(sizeof(struct libraryRecord));

	// convert booktype to enumerated type
	bookType bookTypeIn = novel;
	if (strcmp(booktype_input, "novel") == 0 || strcmp(booktype_input, "Novel")==0) { bookTypeIn = novel; }
	else if (strcmp(booktype_input, "comic") == 0 || strcmp(booktype_input, "Comic")==0) { bookTypeIn = comic; }
	else if (strcmp(booktype_input, "history") ==0 || strcmp(booktype_input, "History") == 0) { bookTypeIn = history; }
	else if (strcmp(booktype_input, "art") == 0 || strcmp(booktype_input, "Art")==0) { bookTypeIn = art; }
	else if (strcmp(booktype_input, "nonfiction") == 0 || strcmp(booktype_input,"Nonfiction")==0) { bookTypeIn = nonfiction; }
	// adding parameters to the newly created record
	strcpy(freshAddition->bookTitle, bookTitle_input);
	strcpy(freshAddition->author, author_input);
	freshAddition->bookId = bookId_input; 
	freshAddition->booktype = bookTypeIn;
	freshAddition->next = NULL;

	// templist empty
	if(list == NULL)
	{	
		list = freshAddition;
		count++;
	}
	else
	{ 
		// if at end of list already
		bookEnd->next = freshAddition;
	}
	//then return 1 once added successfully
	return 1;			// edit this line as needed

}




// This function displays the book list with the details (struct elements) of each book. 
// Q2. display (10 points)
// Display all books.
void display()
{
	struct libraryRecord* tempList = list;						// work on a copy of 'list'
	// Write the code below
	// to store booktype as a string for displaying
	char *bookTypeChar="";
	
	
	while (tempList != NULL)
	{
		// finding the associating string equivalent for the enumerated type value of booktype
		switch (tempList->booktype)
		{
		// when enum value matches with either case, assign associated booktype to string variable.
		case novel: bookTypeChar = "Novel"; break;
		case comic: bookTypeChar = "Comic"; break;
		case history: bookTypeChar = "History"; break;
		case art: bookTypeChar = "Art"; break;
		case nonfiction: bookTypeChar = "Nonfiction"; break;
		}
		printf("\nBook Title: %s", tempList->bookTitle);
		printf("\nAuthor Name: %s", tempList->author);
		printf("\nBook Type: %s", bookTypeChar);
		printf("\nBook ID: %d\n", tempList->bookId);
		//move on
		tempList = tempList->next;
	}
}


void sort()
{
		struct libraryRecord* tempList = list;        // work on a copy of 'list'
		// Write the code below
		// the holders
		struct libraryRecord* holder = malloc(sizeof(struct libraryRecord));
		struct libraryRecord* switcher = malloc(sizeof(struct libraryRecord));

		// as long as the list not null
			while (tempList != NULL)
			{
				// set holder to next (after the node at templist)
				holder = tempList->next;
				// while the second to last is also not null
				while (holder != NULL) //travel till the second last element 
				{
					if (tempList->bookId > holder->bookId)// compare the data of the nodes 
					{
						//store title in tempList, then swap tempList with holder, lastly store holder in switcher variable
						strcpy(switcher->bookTitle, tempList->bookTitle);
						strcpy(tempList->bookTitle, holder->bookTitle);
						strcpy(holder->bookTitle, switcher->bookTitle);

						// as before but with author this time
						strcpy(switcher->author, tempList->author);
						strcpy(tempList->author, holder->author);
						strcpy(holder->author, switcher->author);

						// swapping booktypes
						switcher->booktype = tempList->booktype;
						tempList->booktype = holder->booktype;
						holder->booktype = switcher->booktype;
						//lastly bookId
						switcher->bookId = tempList->bookId;
						tempList->bookId = holder->bookId;
						holder->bookId = switcher->bookId;

					}
					holder = holder->next;    // move to the next node in holder
				}
				tempList = tempList->next;    // move to the next node in tempList
		
				}
			  
	// display message for user to check the result of sorting.
	printf("\nBook list sorted! Use display option 'd' to view sorted list.\n");
}

// save() is called at the end of main()
// This function saves the linked list of structures to file.
// save() is called at end of main() to save the book list to a file.
// The file is saved at the same place as your C file. For VS, the default directory looks like this:
// C:\Users\<username>\Documents\Visual Studio 2017\Projects\Project1\Project1
// You can simply delete the file to 'reset the list' or to avoid loading from it.
void save(char* fileName)
{
	struct libraryRecord* tempList = list;	// work on a copy of 'list'

	FILE* file;
	int booktypeValue = 0;
	file = fopen(fileName, "wb");		// open file for writing

	fwrite(&count, sizeof(count), 1, file);		// First, store the number of books in the list

	// Parse the list and write book record to file
	while (tempList != NULL) {
		fwrite(tempList->bookTitle, sizeof(tempList->bookTitle), 1, file);
		fwrite(tempList->author, sizeof(tempList->author), 1, file);
		// convert enum to a number for storing
		// novel = 0, comic = 1, history = 2, art = 3, nonfiction = 4
		if (tempList->booktype == novel)
			booktypeValue = 0;
		else if (tempList->booktype == comic)
			booktypeValue = 1;
		else if (tempList->booktype == history)
			booktypeValue = 2;
		else if (tempList->booktype == art)
			booktypeValue = 3;
		else
			booktypeValue = 4;

		fwrite(&booktypeValue, sizeof(booktypeValue), 1, file);
		fwrite(&tempList->bookId, sizeof(tempList->bookId), 1, file);
		// move on
		tempList = tempList->next;
	}

	fclose(file);			// close the file after writing
}

// Q4 : delete (10 points)
// This function is used to delete an book by ID.
// Parse the list and compare the book IDs to check which one should be deleted.
// Return 0 if the specified ID was not found. Return 1 upon successful removal of a record.
int delete(unsigned int bookId_input)
{
	struct libraryRecord* tempListCur = list;	// work on a copy of 'list'
	struct libraryRecord* tempListPrev = list;	// work on a copy of 'list'
	// Write the code below
	// while is not empty
	while (tempListCur != 0)
	{
		// if they match at first
		if (bookId_input == tempListCur->bookId)
		{
			//store elsewhere then free, as well as decrement count & return1
			tempListPrev = list;
			list = list->next;
			free(tempListPrev);
			count--;
			return 1;
		}
		
		else
		{ // else continue looking till found to delete, free, and decrement count.
			tempListPrev = tempListCur->next;
			tempListCur->next = tempListPrev->next;
			free(tempListPrev);
			count--;
			return 1;
		}
	}
	//when not found return 0 and do nothing
	return 0; // edit this line as needed
}

// Q5:  load (10 points)
// This function is called in the beginning of main().
// This function reads the book list from the saved file and builds the linked list of structures 'list'. 
// In the first run of the program, there will be no saved file because save() is called at the end of program.
// So at the begining of this function, write code to open the file and check if it exists. If file does not exist, then return from the function.
// (See expected output of add() in homework question file. It displays "Book_List.txt not found" because the file did not exist initially.)
// If the file exists, then parse the book list to read the book details from the file.
// Use the save function given above as an example of how to write this function. Notice the order in which the struct elements are saved in save()
// You need to use the same order to read the list back.
// NOTE: The saved file is not exactly readable because all elements of the struct are not string or char type.
//       So you need to implement load() similar to how save() is implemented. Only then the 'list' will be loaded correctly.
//		You can simply delete the file to 'reset the list' or to avoid loading from it.
void load(char* fileName)
{
	struct libraryRecord* tempList = list;	// work on a copy of 'list'
	// Write the code below
	// so it recognizes the variables we need to load/add our strucs
	char bookTitle[MAX_NAME_LENGTH];
	char author[MAX_NAME_LENGTH];
	char* booktype;
	unsigned int bookId;
	int booktypeValue;
	int countz = 0;

	FILE* fileBuffer;
	fileBuffer = fopen(fileName, "rb"); // "b" binary mode
	if (fileBuffer) // "w"  write	
	{
		// if filebuffer exists, begin to read 
		fread(&countz, sizeof(countz), 1, fileBuffer); // reads tail 
		// Parse the list and write book record to file
		for(int x = 0; x < countz; x++)
		{
			//read title and author of each individual
			fread(bookTitle, sizeof(bookTitle), 1, fileBuffer);
				fread(author, sizeof(author), 1, fileBuffer);
			// convert a number to enum for reading
		// novel = 0, comic = 1, history = 2, art = 3, nonfiction = 4
			fread(&booktypeValue, sizeof(booktypeValue), 1, fileBuffer);
			if (booktypeValue == 0)
				booktype = "novel";
			else if (booktypeValue == 1)
				booktype = "comic";
			else if (booktypeValue == 2)
				booktype = "history";
			else if (booktypeValue == 3)
				booktype = "art";
			else
				booktype = "nonfiction";
			// read bookid
			fread(&bookId, sizeof(bookId), 1, fileBuffer);
			//use add function to add to list when finalized through parsing for this struc
			add(author, bookTitle, booktype, bookId);
		}
		printf("Books record loaded from Book_List.txt");
		fclose(fileBuffer);	//closing buffer
	}
	//when fails
	else {
		printf("Book_List.txt not found.\n");
		 }
}
