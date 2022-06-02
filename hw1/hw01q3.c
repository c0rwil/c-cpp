// Carlos Corral-Williams 

#include <stdio.h>
// #pragma warning(disable : 4996) // needed if using Visual Studio

// CSE 240 Spring 2022 Homework 1 Question 3 (20 points)
// Before starting this assignment, please compile and run this program. 
// You will first notice that the program will not compile. Fix the errors and define the error types.
// Next, you will notice that the program is printing incorrect information. Fix the errors and define those error types.

int main(){

	// Problem 1: (4 points)
	// The statement below should cause the program to not compile. Correct the error(s). (2 points).
  // A: p was assigned a value before being defined, the type of the variable was omitted, and p is later formatted as a float for a printf 
  //    without being declared as such. Making it an obvious example of a Contextual Error.

	float p = 20.18;

	printf("p is equal to %.2f\n", p); 

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Contextual \n\n"); 


	// Problem 2: (4 points)
	// Half of 50 is 25, why is the program printing that half of 50 is 0? Correct the error(s) (2 points).
  // A: Tediously enough, this question messes up because of the 0.5 being used on q, which is declared as an int.
  //    Since the number is simply being read in as 0, the program will return 0 because 50*0 IS 0, this is yet another contexual error.

	int q = 50;

	printf("Half of %d is %.2f\n", q, q * ((float)1/2));

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Contextual \n\n");

     //Problem 3    (2 points)
     //Integer variable y is initialized to 100 and its value needs to be printed. Correct the error(s).(1 point)
     //A: Y is initialized correctly, however, in the printf function we incorrectly try to use %c to print out our integer type as a character.
   int y = 100;
   printf("y is %d\n",y); 
    // Your answer should be either Syntactic, Semantic, or Contextual. (1 point)
	printf("Error Type: Contextual \n\n");
     
     //Give your explanation here:
     printf("A: Y is initialized correctly, however, in the printf function we incorrectly try to use '%%c' to print out our integer type as a character. \n\n");
	// Problem 4: (2 points)
	// Float variable f has been initialized to 3.14, why does the program seem to think otherwise? Correct the error(s) (2 points).
  // A: In this part, f is initialized to 3.14, but in the parameters of our first if statement, we incorrectly utilized '=' and
  //    incidentally reassign the value of f, creating this fall-through effect.

	float f = 3.14;

	if (f == 10) // incorrectly using '=' instead of '==' causes this syntactic error, reassigning the value of f.
	printf("f is equal to 10.\n");
	if (f > 10)
	printf("f is greater than 10.\n");
	if (f < 10)
	printf("f is less than 10.\n");

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Syntactic \n\n");


	// Problem 5: (4 points)
	// Surely, 60 is an even number. Why is the program printing that 60 is an odd number? Correct the error(s) ( points).
  // A: After reassigning the value of our integer 'q' to 60, we are not correctly setting up the evaluation formula for indentifying our result as odd or even.
  //    This is clearly a logical/semantic error, because instead of comparing the remainder of q/2 we are instead asking if the resulting number IS or ISN'T the value 0,
  //    which ultimately proves whether or not the result is exactly 0, or not 0. This is fixed by utilizing modulus '%' and '=='.

	q = 60;

	if ((q % 2) == 0)
		printf("%d is an even number.\n", q);
	if ((q % 2) != 0)
		printf("%d is an odd number.\n", q);

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Semantic \n\n");


	// Problem 6: (4 points)
	// This bit of code is meant to print "Hello World!". Correct the error(s) (2 points).
  // A: Here, we for some reason place a %c in our print statement, which causes the error of printing "Hello { ", I fixed this by replacing it with %s since it was causing
  //    "World!" to be replaced by the single character of ' { ' . This is clearly a contextual error, we are incorrectly using %c in the context of our string 'World!'.

	printf("Hello %s \n", "World!");

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Contextual \n\n");

return 0;
}
