/*
  Jeremy Crosby
  10/01/19

  Project 1 FizzBuzz - This C program takes a number inputted by the user between 1 and 100 (inclusive)
  and prints the numbers 1 through the number inputted. If the number printed is a multiple of 3 the output
  will be "Fizz", rather than printing the number itself. Likewise, for multiples of 5 "Buzz" will be printed.
  In the case the number printed is a multiple of both 3 and 5, "FizzBuzz"  will be printed.
*/

//Libraries
#include <stdio.h>
#include <stdlib.h>

//Main function
int main(void) {
  //Variable declerations
  int number;
  int counter;

  //Prints welcome message
  printf("Welcome to FizzBuzz\n");

  //Prompts the user to input a number
  printf("Enter a number between 1 and 100: ");
  scanf("%d", &number);

  //Conditional statement that evaluated if the user input is within the requested range
  if(number >= 1 && number <= 100){

    //For loop that checks for condition of the counter being >=1 and for the counter to be <= the number enterd by the user, with 1 being added to the counter each time the loop is ran. The loop will continue to run as long as counter is <= the user enterd number.The starting value of counter is 1.
    for(counter = 1; counter >= 1 && counter <= number; counter++){

      //Conditional that prints "FizzBuzz" if counter variable is evenly divisible by 15
      if (counter % 15 ==0){
        printf ("\nFizzBuzz");
      }
      //Conditional that prints "Fizz" if counter variable is evenly divisible by 3
      else if ((counter %3 ) == 0){
        printf("\nFizz");
      }
      //Conditional that prints "Buzz" if counter variable is evenly divisible by 5
      else if ((counter % 5) == 0) {  //If counter is divisible by 5 print Buzz
        printf("\nBuzz");
      }
      //Conditional that prints the number if not divisible by 3,5, or both
      else {
        printf("\n%d", counter);
      } // Prints

    }
      printf("\n");
  }
   //Error message printed if user inputted number is not within range of 1 to 100 (inclusive)
    else{
        printf("Invalid input\n");
    }
return 0;
}
