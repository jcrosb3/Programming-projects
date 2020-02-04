
/*
  Jeremy Crosby
  01/14/20

  Systems Programming: Binary Calculator - This C program is a binary calculator which accepts a two binary numbers (up to 31 bits each),
  converts them to decimal values, and then performs the desired arithmetic on those decimal values. After the arithmetic is performed the result
  is converted back to binary and returned to the user, the user is prompted to enter another calculation. A specific error message is returned
  and the user is reprompted to enter a calculation if either binary number is over 31 bits, either binary number is not binary (does not contain only ones and zeros),
  or if an invalid operation symbol is entered. The user may enter "quit" to terminate the program.

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
  //While loop that allows the program to continually accept input unless "quit is entered."
  int infinite_loop = 0;
  while (infinite_loop < 1){

    char operand_1[1000];
    char operand_2[1000];
    char operation;
    //Operand 1 as a decimal number
    int decimal_1;
    //Operand 2 as a decimal number
    int decimal_2;
    //The string that stores the user input
    char str[1000];
    //The exit statement for when the user wants to end the program
    char exit_statement[100] = "quit";
    //The variable where the function call for input validation is stored
    int data_Validation;

    //Prompts the user to enter a calculation in the correct format
    printf("\n\nInput your calculation in the format: operand1 operator operand2 [Enter]\n");
    printf("\n");

    //Use of fgets to store the user input as a single string
    fgets(str,1000,stdin);
    //Parses the single string inputted by the user into 3 seperate parts: operand1, operator, and operand2
    sscanf(str,"%s %c %s",operand_1, &operation, operand_2);

    //Checks string entered is "quit", if so the program prints "Goodbye" to the screen and ends
    int check = strcmp(exit_statement, operand_1);
    if(check == 0){
      printf("\nGood bye\n");
      //Terminates program
      exit(1);
    }
    //Function call for input validation stored in the variable data_Validation
    data_Validation = input_validation(operand_1,operand_2,operation);
    //Conditional to allow the program to continue with calculations if the user input does not return an error
    if(data_Validation != -1){

      //Function call to convert the first binary string by the user into a decimal number
      decimal_1 = binary_to_decimal(operand_1);
      //Function call to convert the second binary string by the user into a decimal number
      decimal_2 = binary_to_decimal(operand_2);
      //Function call to perform arithmetic on the user entered values, and then converts them back to binary numbers using the function decimal_to_binary, which also prints the results
      calculate(decimal_1, decimal_2, operation);
    }
  }
  return(0);
  }

  //Function to validate if the users imput is in the correct format and meets the conditions
  int input_validation(char operand_1[1000], char operand_2[1000], char operation){
    //Loop variable
    int i;
    //Value returned by the input validaton function
    int check_value = 0;

    //Returns appropriate error message if invalid operation symbol is entered
    if (operation != '+' && operation != '-' && operation != 'x' &&  operation != '/'){
      printf("\nThere was an invalid operator symbol entered. Please try again choosing one of the following operators ( +, -, x, / ).");
      check_value = -1;
    }

    //Returns appropriate error message if both binary strings enterd are over 31 bits
    if (((strlen(operand_1)) > 31) && ((strlen(operand_2))) > 31) {
      printf("\nBoth operands are over 31 bits. Please try again.");
      check_value = -1;
    }
    //Returns appropriate error message if operand1 binary strings is over 31 bits
    else if ((strlen(operand_1) > 31)) {
      printf("\nOperand 1 is over 31 bits. Please try again.");
      check_value = -1;
    }

    //Returns appropriate error message if operand2 binary strings is over 31 bits
    else if ((strlen(operand_2) > 31)) {
      printf("\nOperand 2 is over 31 bits. Please try again.");
      check_value = -1;
    }
    //Conditional that limits the bit lenght to 16 for multiplication
    if ((operation == 'x') && ((strlen(operand_1)) > 16) && ((strlen(operand_2))) > 16){
      printf("\nBoth operands are over 16 bits. Limit operands to 16 bits for multiplication. Please try again.");
      check_value = -1;
    }
    //Conditional that limits the bit lenght to 16 for multiplication
    else if ((operation == 'x') && (strlen(operand_1) > 16)) {
      printf("\nOperand 1 cannot be over 16 bits for multiplication. Please try again.");
      check_value = -1;
    }
    //Conditional that limits the bit lenght to 16 for multiplication
    else if ((operation == 'x') && (strlen(operand_2) > 16)) {
      printf("\nOperand 2 cannot be over 16 bits for multiplication. Please try again.");
      check_value = -1;
    }

    //Checks each index in the first binary string to check if the number consist of only ones and zeros
    for (i = 0; i <= (strlen(operand_1)) - 1; i++){
      if((int)operand_1[i] - 48 != 0 && (int)operand_1[i] - 48 != 1){
        printf("\nOperand 1 is not a binary number, please try again.");
        check_value = -1;
        break;
      }
    }
    //Checks each index in the second binary string to check if the number consist of only ones and zeros
    for (i = 0; i <= (strlen(operand_2)) - 1; i++){
      if((int)operand_2[i] - 48 != 0 && (int)operand_2[i] - 48 != 1){
        printf("\nOperand 2 is not a binary number, please try again.");
        check_value = -1;
        break;
      }
    }
  //Returns check value as -1, if an error is found. Otherwise, a 0 is returned allowing the program to continue with calculations
  return check_value;
  }
  //Function that converts the entered binary string to a decimal number
  int binary_to_decimal(char operand_1[1000]){
    //The exponent is used to convert from binary to decimal
    int exponent = 0;
    //Holds the decimal value after the binary string is converted
    int decimal = 0;
    //Loop variable
    int i;

    //For loop that multiplies each index by its integer value and 2 raised to the n power where n is incremented each iteration
    for(i = (strlen(operand_1))-1; i >= 0; i--){
      decimal += ((int)operand_1[i] - 48) * pow(2, exponent);
      exponent++;
    }
    //Returns the number in decimal form
    return decimal;
  }
  //Function to perform arithmetic with the decimal values
  void calculate(int decimal_1, int decimal_2, char operation){
    //stores the arithmetic computed with decimal numbers in the variable answer
    int answer;
    //Stores the remainder (modulus) when using the division operator
    int remain;
    //Conditional for when the operator is addition
    if(operation == '+') {
      answer = decimal_1 + decimal_2;
      decimal_to_binary(answer);
      printf("\n");
    }
    //Conditional for when the operator is subtraction
    else if(operation == '-') {
      answer = decimal_1 - decimal_2;
      decimal_to_binary(answer);
      printf("\n");
    }
    //Conditional for when the operator is multiplication
    else if(operation == 'x') {
      answer = decimal_1 * decimal_2;
      decimal_to_binary(answer);
      printf("\n");
    }
    //Conditional for when the operator is division
    else if(operation == '/') {
      //Returns an error message when dividing by zero is attempted
      if(decimal_2 == 0){
        printf("Cannot divide by 0.\n");
      }
    else{
      answer = decimal_1 / decimal_2;
      remain = decimal_1 % decimal_2;
      printf("answer: ");
      decimal_to_binary(answer);
      printf(" remainder: ");
      decimal_to_binary(remain);
      printf("\n");
    }
  }
}
  //Function to convert the decimal back to binary after arithmetic is performed
  void decimal_to_binary(int answer){
    //Stores the remainder in an array when converting from decimalto binary
    int remainder_array[32];
    //Loop variable
    int i = 0;
    //Loop variable
    int j;
    //While loop to store the remainder of the decimal arithmetic in an array.The answer is updated to half its original value each iteration
    while (answer > 0){
      remainder_array[i] = answer % 2;
      answer /= 2;
      i++;
    }
    //Prints the array used for holding the remainders in reverse order
    if(i != 0){
      printf("= ");
      for (j = i -1; j >= 0; j--){
      printf("%d",remainder_array[j]);
      }
    }
    //Prints "= 0" if the answer is 0
    else{
      printf("= 0");
    }
  }
