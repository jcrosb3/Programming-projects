/*
  Systems Programmingp project 1: Binary Calculator
  
  This C program is a binary calculator which can perform +, - , * , and / with 
  two binary numbers up to 31 bits each.
  
  Jeremy Crosby
  
  01/14/20
*/
//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Function prototypes
int input_validation(char *, char *, char);
int binary_to_decimal(char *);
void calculate(int, int , char);
void decimal_to_binary(int);

//Main function
int main(void){
  //Variable declerations
  char operand_1[32];
  char operand_2[32];
  char operation;
  int data_Validation;
  int decimal_1;
  int decimal_2;

  //Prompts the user to enter a calculation
  printf("Input your calculation in the format: operand1 operator operand2 [Enter]");
  printf("\n");
  scanf("%s %c %s", operand_1, &operation, operand_2);

  //Calls the input_validation function which checks to see if the calculation input from the user fits the given
  //criteria and is in the right fomat. This is stored in the data_Validation variable
  data_Validation = input_validation(operand_1, operand_2, operation);

  //Function call to convert the first binary string by the user into a decimal number
  int decimal_1 = binary_to_decimal(operand_1);
  //Function call to convert the second binary string by the user into a decimal number
  int decimal_2 = binary_to_decimal(operand_2);
  //Function call to perform arithmetic on the user entered values, and then converts them back to binary numbers using the function decimal_to_binary, which also prints the results
  calculate(decimal_1, decimal_2, operation);

}
//Function to validate if the users imput is in the correct format and meets the conditions
int input_validation(char operand_1[32], char operand_2[32], char operation){
  //Initializing loop variable
  int i;

  //Returns appropriate error message if invalid operation symbol is entered
  if (operation != '+' && operation != '-' && operation != '*' &&  operation != '/'){
    printf("\nThere was an invalid operator symbol entered. Please try again choosing one of the following operators (+, -, x, /)");
    return -1;
  }
  //Returns appropriate error message if the binary string enterd is over 31 bits
  if (((strlen(operand_1)) > 31) || ((strlen(operand_2))) > 31 ){
    printf("Either operand 1 or operand 2 is over 31 bits. Please try again.");
    return -1;
  }

  //Checks each index in the first binary string to check if the number consist of only ones and zeros
  for (i = 0; i <= (strlen(operand_1)) - 1; i++){
    if((int)operand_1[i] - 48 != 0 && (int)operand_1[i] - 48 != 1){
      printf("Operand 1 is not a binary number, please try again.");
      return -1;
    }
  }
  //Checks each index in the first binary string to check if the number consist of only ones and zeros
  for (i = 0; i <= (strlen(operand_2)) - 1; i++){
    if((int)operand_2[i] - 48 != 0 && (int)operand_2[i] - 48 != 1){
      printf("Operand 2 is not a binary number, please try again.");
      return -1;
    }
  }
}
//Function that converts the entered binary string to a decimal number
int binary_to_decimal(char operand_1[32]){
  //Variable declerations
  int n = 0;
  int decimal = 0;
  int i;
  //For loop that multiplies each index by its integer value and 2 raised to the n power where n is incremented each iteration
  for(i = (strlen(operand_1))-1; i >= 0; i--){
    decimal += ((int)operand_1[i] - 48)*  pow(2,n);
    n++;
  }
  return decimal;
}
//Function to perform arithmetic with the decimal values
void calculate(int decimal_1, int decimal_2, char operation){
  //Variable declerations
  int answer;
  int remain;
  //Multiple conditions to check if the user entered operation is valid
  if(operation == '+') {
    answer = decimal_1 + decimal_2;
    decimal_to_binary(answer);
    printf("\n");
  }
  else if(operation == '-') {
    answer = decimal_1 - decimal_2;
    decimal_to_binary(answer);
    printf("\n");
  }
  else if(operation == '*') {
    answer = decimal_1 * decimal_2;
    decimal_to_binary(answer);
    printf("\n");
  }
  else if(operation == '/') {
    answer = decimal_1 / decimal_2;
    remain = decimal_1 % decimal_2;
    printf("answer: ");
    decimal_to_binary(answer);
    printf(" remainder: ");
    decimal_to_binary(remain);
    printf("\n");
  }
}
//Function to convert the decimal back to binary after arithmetic is performed
void decimal_to_binary(int answer){
  //Variable declerations
  int remainder_array[32];
  int i = 0;
  //While loop to store the remainder of the decimal arithmetic in an array.The answer is updated to half its original value each iteration
  while (answer > 0){
    remainder_array[i] = answer % 2;
    answer /= 2;
    i++;
  }
  //Prints the array used for holding the remainders in reverse order
  if(i != 0){
    for (int j = i -1; j >= 0; j--){
    printf("%d",remainder_array[j]);
    }
  }
  else{
    printf("0");
  }
}
