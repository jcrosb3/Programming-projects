/*
  Project4_rot47.c - This project utilizes char and file pointers, malloc and realloc to accomplish the task of: printing the current string, encrypting
  and decrypting the current string, adding a new word to the string, clearing the data from the current string, saving the current
  string and string size to an output file, and loading a string and string size from a specified file.
*/

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function prototypes
void rotate47(char data[]);
int saveToFile(char filenameOutput[], const char data[]);
char* loadFromFile(char filenameInput[]);

//Main function
int main(int argc, char *argv[]) {

  //Initializes character pointer for the string
  char* str = NULL;
  //Initializes character for menu selection variable
  char menuOp = 'x';
  //Initializes input file name variable
  char filenameInput[100];
  //Initializes output file name variable
  char filenameOutput[100];
  //Initializes variable for adding a word to the current string
  char addWord[51];

  //Menu selection loop
  while (menuOp != 'q') {
		// Menu displayed on start of running program
    printf("\nMENU\n");
    printf("l - Load data from file\n");
    printf("s - Save data to file\n");
    printf("c - Clear all data in the current string\n");
    printf("a - Add a new word\n");
    printf("r - Encrypt/decrypt the current string\n");
    printf("p - Print the current string\n");
    printf("q - Quit\n");

    //Prompts the user to enter a menu option character
		printf("\nChoose an option: ");
		scanf(" %c", &menuOp);

    //A switch used for each menu option
		switch (menuOp) {

		//Case that loads data from requested file
		case 'l':
		  //Prompts user to enter the name of the file which data is loaded in from
		  printf("Enter file name: ");
		  scanf("%s",filenameInput);

		  //Calls the loadFromFile function that loads in a string from a specific input file, and stores in the variable str
      str = loadFromFile(filenameInput);
    	break;

		//Case that saves data to file
		case 's':
      //Prompts user to enter the name of the output file
		  printf("Enter file name: ");
		  scanf("%s",filenameOutput);

		  //Stores saved string into current string by calling saveToFile function
		  saveToFile(filenameOutput, str);
		  break;

		//Case that clears all data in the current string
		case 'c':
		    //If the string contains data, clear the data and set the string to NULL
		   if(str != NULL){
		       free(str);
		       str = NULL;
		    }
		    break;

		//Case that adds a new word
		case 'a':
		  //Prompts user to enter a new word
		  printf("Enter a new word up to 50 characters (no whitespace): ");
		  scanf("%s", addWord);

		  //If the string is empty, allocate enough memory for the new word
		  if(str == NULL){
		      str = (char*)malloc((strlen(addWord) + 1) * sizeof(char));
		    }

      //If the string already has data, reallocate enough space for the original data plus the new word
		  else{
		      str = (char*)realloc(str, (strlen(addWord) + strlen(str) + 1) * sizeof(char));
		    }
		  //Concatenate the original string data and new word
		  strcat(str, addWord);
		  break;

		//Applies the ROT-47 cipher to encrypt or decrypt the data
		case 'r':
		  //If the string contains data, call the rotate47 function to encrypt or decrypt data
		  if(str != NULL){
        //Calls rotate47 function
		    rotate47(str);
		  }
		  break;

		//Case that Prints the current string
		case 'p':
		  //If the string is not empty, print the string
		  if (str != NULL){
		      printf("Current string: %s\n", str);
		  }
		  break;

		//Case that quits the program
		case 'q':
		 break;
		default:

		//Error message for when invalid character is entered at the menu
    printf("\nInvalid option.");
		}
	}
	return 0;
}

//Rotate47 function for encryption and decryption of str
void rotate47(char data[]) {

    //Loop variable
    int i;

    //Loop that encrypts each element of the string
    for(i = 0; i < strlen(data); i++){
      //If the decimal value of the string is between 33 and 79, add 47 to the decimal value
      if(data[i] >= 33 && data[i] <= 79){
        data[i] = data[i] + 47;
      }
      //If the decimal value of the string is between 33 and 79, subtract 47 to the decimal value
      else if(data[i] >= 80 && data[i] <= 126){
        data[i] = data[i] - 47;
      }
    }
}

//Function that loads in string size and string from specified input file
char* loadFromFile(char filenameInput[]){

  //Initializes variable for the size of the string
  int size;

  //File pointer for input file
  FILE *inFile;

  //Opens input file of specified file name to read
  inFile = fopen(filenameInput,"r");

  //If file not found returns error message
  if(inFile == NULL){
      fprintf(stdout, "Error loading data from file: \"%s\".\n", filenameInput);
      return NULL;
  }
  //Scans the input file for the size of the string
  fscanf(inFile, "%d", &size);

  //Dynamically allocates enough memory to store the string from the input file
  char* loadFromFile = (char*)malloc(size * sizeof(char));

  //Populates string with data from input file
  fscanf(inFile, "%s", loadFromFile);

  //Closes input file
  fclose(inFile);

return loadFromFile;
}

//Function that saves string data and string size to specified output file
int saveToFile(char filenameOutput[], const char data[]){

    //File pointer for output file
    FILE *outFile;

    //Opens output file for writing
    outFile = fopen(filenameOutput,"w");

    //If file not found error message
    if(outFile == NULL){
        fprintf(stdout, " Error saving data to: \"%s\".\n" ,filenameOutput);
        return -1;
    }
    //Prints the size and the data of the current string into the save file
    fprintf(outFile, "%ld\n", strlen(data));
    fprintf(outFile,"%s", data);

    //Closes output file
    fclose(outFile);

return 0;
}
