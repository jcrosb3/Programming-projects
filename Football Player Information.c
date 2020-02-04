/*
  Jeremy Crosby
  01/29/2020

  Prog2.c- This project allows data to be entered for a single college football player: first name, middle initial (optional),
  last name, suffix (optional), school, state, class, position, rating, age, sex, height, weight, twitter account,and phone number.
  Additional options are avaliable via the menu such as to display all data, clear all of the data, and quit the program.
  This program has an emphasis on data valadation.

*/
//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function prototypes
int name_Validation(char first_Name[100], char middle_Initial[100], char last_Name[100],char suffix[100]);
int school_Validation(char school[100], char state[100], char class[100], char position[100], int rating);
int stats_Validation(int age, char sex[100], int height_Feet, int height_Inches, int weight);
int contact_Validation(char twitter_Account[100],char area_Code[100], char first_Set[100], char second_Set[100]);

//Variable declerations related to name
char menuOp = 'x';
char first_Name[100];
char middle_Initial[100];
char ifmiddle_Initial;
char last_Name[100];
char suffix[100];
char ifsuffix;
int input_validation;
//Variable declerations related to school
char school[100];
char state[100];
char class[100];
char position[100];
int rating;
int school_Validation_Input;
//Variable declerations related to physical attributes
int age;
char sex[110];
int height_Feet;
int height_Inches;
int weight;
int stats_Validation_Input;
//Variable declerations related to contact information
char twitter_Account[100];
char area_Code[100];
char first_Set[100];
char second_Set[100];
int contact_Validation_Input;
int i;
//A 2-D array that contains state abbreviations for all 50 states
char state_List[][50] = {"AL", "AK", "AZ","AR","CA", "CO", "CT", "DE", "FL", "GA",
"HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD", "MA", "MI", "MN",
"MS", "MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "OH", "OK", "OR",
"PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VA", "WV", "WI", "WY" };
//A 2-D array that contains classes for each year
char class_List[][50] = {"FR", "SO", "JR", "SR", "GR", "RSO"};
//Variables related to indexing through each element in the states array
int state_Validate = -1;
int state_Index;
//Variables related to indexing through each element in the class array
int class_Index;
int class_Validate = -1;

int main (void){

  while (menuOp != 'q'){
    //MENU
    printf("\n\nSelect a menu option\n\n");
    printf("n - Enter Name\n");
    printf("s - Enter school information\n");
    printf("c - Enter Contacts\n");
    printf("p - Enter Age, Sex, Height, and Weight\n");
    printf("d - Display the data\n");
    printf("r - Clear all data\n");
    printf("q - Quit\n");

    //prompts user to select character option from the menu
		printf("\nChoose a menu option character: ");
		scanf(" %c", &menuOp);

    switch (menuOp) {

		case 'n':
      //prompts user to enter player first name
      printf("\nEnter First Name (Max. of 32 characters) [Enter] ");
      scanf("%s",first_Name);

      //Ask user if they would like to insert a middle initial
      printf("\nWould you like to enter a middle initial? Y/N [Enter]  ");
      scanf(" %c",&ifmiddle_Initial);

      //Prompts user to enter a middle initial if yes option is selected
      if (ifmiddle_Initial == 'Y'){
        printf("\nEnter Middle Initial [Enter] ");
        scanf("%s",middle_Initial);
      }

      //prompts user to enter player last name
      printf("\nEnter Last Name (Max. of 32 characters) [Enter] ");
      scanf("%s", last_Name);

      //Ask user if they would like to insert a suffix
      printf("\nWould you like to enter a suffix? Y/N [Enter]  ");
      scanf(" %c",&ifsuffix);

      //Prompts user to enter a suffix if yes option is selected
      if (ifsuffix == 'Y'){
        printf("\nEnter Suffix [Enter] ");
        scanf("%s",suffix);
      }
      else {
        strcpy(suffix, "N/A");
      }

      //Function call to validate name information inputted
      input_validation = name_Validation (first_Name, middle_Initial, last_Name, suffix);

      //If user decides not to enter a middle initial, middle initial is set to not applicable
      if (ifmiddle_Initial == 'N'){
        strcpy(middle_Initial, "N/A");
      }

      //if there is an error in the input of the name, do not keep any of the data entered
      if (input_validation == -1){
        strcpy(first_Name, "");
        strcpy(middle_Initial, "");
        strcpy(last_Name, "");
        strcpy(suffix, "");
      }
      break;

		case 's':

      //prompts user to enter school name
      printf("\nEnter School Name (Min. of 2 characters, Max. of 64 characters) [Enter] ");
      scanf("%s",school);

      //State abbreviation list
      printf("\nAlabama - AL,          Alaska - AK,         Arizona - AZ,       Arkansas - AR\n");
      printf("California - CA,       Colorado - CO,       Connecticut - CT,   Delaware - DE\n");
      printf("Florida - FL,          Georgia - GA,        Hawaii - HI,        Idaho - ID\n");
      printf("Illinois - IL,         Indiana - IN,        Iowa - IA,          Kansas - KS\n");
      printf("Kentucky - KY,         Louisiana - LA,      Maine - ME,         Maryland - MD\n");
      printf("Massachusetts - MA,    Michigan - MI,       Minnesota - MN,     Mississippi - MS\n");
      printf("Missouri - MO,         Montana - MT,        Nebraska - NE,      Nevada - NV\n");
      printf("New Hampshire - NH,    New Jersey - NJ,     New Mexico - NM,    New York - NY\n");
      printf("North Carolina - NC,   North Dakota - ND,   Ohio - OH,          Oklahoma - OK\n");
      printf("Oregon - OR,           Pennsylvania - PA,   Rhode Island - RI,  South Carolina - SC\n");
      printf("South Dakota - SD,     Tennessee - TN,      Texas - TX,         Utah - UT\n");
      printf("Vermont - VT,          Virginia - VA,       Washington - WA,    West Virginia - WV\n");
      printf("Wisconsin - WI,        Wyoming - WY");

      //prompts user to enter state abbreviation
      printf("\n\nEnter State Abbreviation from the provided list above [Enter] ");
      scanf("%s",state);

      //List of acceptable classes
      printf("\nFR, SO, JR, SR, GR, RSO\n");

      //prompts user to enter player class
      printf("\nEnter Class from the provided list above [Enter] ");
      scanf("%s",class);

      //prompts user to enter player position
      printf("\nEnter Position (Max. of 3 characters, must be all caps) [Enter] ");
      scanf("%s",position);

      //prompts user to enter player star rating
      printf("\nEnter Star Rating (between 0 and 5 inclusive) [Enter] ");
      scanf("%d",&rating);

      //Checks if the state abbreviation entered matches any of the elements in the states list array
      for (state_Index = 0; state_Index < 50; state_Index++){
        if (strcmp(state_List[state_Index], state) == 0){
          state_Validate = 0;
          break;
        }
      }
      //Error message if state abbreviation not found
      if (state_Validate == -1){
        printf("\nError: Invalid State");
        }
      //Checks if the suffix entered matches any of the elements in the suffix list array
      for (class_Index = 0; class_Index < 6; class_Index++){
        if (strcmp(class_List[class_Index], class) == 0){
          class_Validate = 0;
          break;
        }
      }
      //Error message if class not found
      if (class_Validate == -1){
        printf("\nError: Invalid Class");
        }

      //If there is an error in the input, do not keep any of the data entered
      school_Validation_Input = school_Validation(school, state, class, position, rating);
      if ((school_Validation_Input == -1) || (state_Validate == -1) || (class_Validate == -1)){
        strcpy(school, "");
        strcpy(state, "");
        strcpy(class, "");
        strcpy(position, "");
        rating = 0;
      }
      break;

		case 'c':
    //prompts user to enter twitter account name
    printf("\n\nEnter Twitter Account (Max. of 15 characters, must begine with ampersand (@)) [Enter] ");
    scanf("%s",twitter_Account);

    //prompts user to enter phone number
    printf("\nEnter Phone Number (ie. 888 888 8888 ) [Enter] ");
    scanf("%s %s %s", area_Code, first_Set, second_Set);

    //If there is an error in the input, do not keep any of the data entered
    contact_Validation_Input = contact_Validation(twitter_Account, area_Code, first_Set, second_Set);
    if (contact_Validation_Input == -1){
      strcpy(twitter_Account, "");
      strcpy(area_Code, "");
      strcpy(first_Set, "");
      strcpy(second_Set, "");
    }
      break;

		case 'p':
      //prompts user to enter age
      printf("\n\nEnter Age (21-99, inclusive) [Enter] ");
      scanf("%d",&age);

      //prompts user to enter player sex
      printf("\nEnter Sex (M or F) [Enter] ");
      scanf("%s",sex);

      //prompts user to enter player height
      printf("\nEnter Height(feet) [space] Height(inches) [Enter] ");

      scanf("%d %d",&height_Feet, &height_Inches);

      //prompts user to enter player star rating
      printf("\nEnter Weight (100 lbs - 500 lbs, inclusive) [Enter] ");
      scanf("%d",&weight);

      //If there is an error in the input, do not keep any of the data entered
      stats_Validation_Input = stats_Validation(age, sex, height_Feet, height_Inches, weight);
      if (stats_Validation_Input == -1){
        age = 0;
        strcpy(sex, "");
        height_Feet = 0;
        height_Inches = 0;
        weight = 0;
      }
      break;

		case 'd':

      //Displays all player information
      printf("\nPLAYER INFORMATION");
      printf("\n\nFirst Name: %s",first_Name);
      printf("\nMiddle Initial: %s",middle_Initial);
      printf("\nLast Name: %s",last_Name);
      printf("\nSuffix: %s",suffix);
      printf("\n\nSchool: %s",school);
      printf("\nState: %s", state);
      printf("\nClass: %s", class);
      printf("\nPosition: %s", position);
      printf("\nStar Rating: ");
      for (i = 0; i < rating; i++){
        printf("*");
      }
      printf("\n\nAge: %d",age);
      printf("\nSex: %s",sex);
      printf("\nHeight: %d", height_Feet);
      printf("'");
      printf("%d",height_Inches);
      printf("\nWeight: %d lbs", weight);
      printf("\n\nTwitter Account: %s", twitter_Account);
      printf("\nPhone Number: (%s) %s-%s", area_Code, first_Set, second_Set);
		  break;

		case 'r':

    //Clears all data
    strcpy(first_Name, "");
    strcpy(middle_Initial, "");
    strcpy(last_Name, "");
    strcpy(suffix, "");
    strcpy(school, "");
    strcpy(state, "");
    strcpy(class, "");
    strcpy(position, "");
    rating = 0;
    age = 0;
    strcpy(sex, "");
    height_Feet = 0;
    height_Inches = 0;
    weight = 0;
    strcpy(twitter_Account, "");
    strcpy(area_Code, "");
    strcpy(first_Set, "");
    strcpy(second_Set, "");
    printf("\n*Data Cleared*");
      break;

		case 'q':
        printf("Good Bye");
		    break;

	  default:
      //Error message for if invalid option is selected from the menu
      printf("\nError: Invalid menu option selected. Try again.");
	   }
  }
	return 0;
}

//Function that checks if all name information inputted by the user is valid
int name_Validation(char first_Name[100], char middle_Initial[100], char last_Name[100],char suffix[100]){
  //Error check value
  int check_value = 0;

  //checks if first name is over 32 characters
  if ((strlen(first_Name) > 32)){
    printf("\nError: First name can be no more than 32 characters.");
    check_value = -1;
  }

  //checks if middle initial is only one character
  if ((strlen(middle_Initial) > 1)){
    printf("\nError: Middle initial can be blank or 1 character");
    check_value = -1;
  }

  //checks if last name is over 32 characters
  if ((strlen(last_Name) > 32)){
    printf("\nError: Last name can be no more than 32 characters.");
    check_value = -1;
  }

  //checks if suffix is over 3 characters
  if ((strlen(suffix) > 3)){
    printf("\nError: Suffix can be no more than 3 characters");
    check_value = -1;
  }

return check_value;
}

int school_Validation(char school[100], char state[100], char class[100], char position[100], int rating){
  //Error check value
  int check_value = 0;

  //Checks if input is valid for school entered
  if ((strlen(school) < 2) || (strlen(school) > 64)){
    printf("\nError: School must be between 2 and 64 characters, inclusive.");
    check_value = -1;
  }

  //Checks if input is valid for state abbreviation
  if (strlen(state) > 2){
    check_value = -1;
  }
  //Checks if input is valid for class
  if ((strlen(class) !=2 ) && (strlen(class) != 3)){
    check_value = -1;
  }
  int i;
  //Checks if all characters in position are capital letters
  for (i = 0; i <= (strlen(position -1)) ;i++){
    if (position[i] >= 'A' && position[i] <= 'Z'){
      check_value = 0;
    }
   else{
      printf("\nError: Position must be all upercase characters");
      check_value = -1;
      break;
    }
  }

  //Checks if position inputted is no more than 3 characters
  if (strlen(position) > 3){
    printf("\nError: Position cant be longer than 3 characters");
    check_value = -1;
  }
  //Checks if input is valid for rating
  if ((rating < 0) || (rating > 5)){
    printf("\nError: Rating must be between 0 and 5, inclusive");
    check_value = -1;
  }
return check_value;
}

int stats_Validation(int age, char sex[100], int height_Feet, int height_Inches, int weight){
  int check_value = 0;

  //Checks if age inputted is valid
  if ((age < 21) || (age > 99)){
    printf("\nError: Age must be between 21 and 99, inclusive");
    check_value = -1;
  }
  //Checks if input is valid for school sex
  if (strlen(sex) > 1){
    printf("\nError: Sex must be a single character");
    check_value = -1;
  }
  //Checks if input is valid for sex
  if ((sex[0] != 77) && (sex[0] != 70) ){
    printf("\nError: Sex must be either 'M' or 'F' ");
    check_value = -1;
  }
  //Checks if input is valid for height in feet
  if ((height_Feet < 5) || (height_Feet > 7)){
  printf("\nError: The height(feet) must be between 5 and 7, inclusive");
  check_value = -1;
  }
  //Checks if input is valid for height in inches
  if ((height_Inches < 0) || (height_Inches > 11)){
    printf("\nError: The height(inches) must be between 0 and 11, inclusive");
    check_value = -1;
  }
  //Checks if input is valid for weight
  if ((weight < 100) || (weight > 500)){
    printf("\nError: The weight must be between 100 lbs and 500 lbs, inclusive");
    check_value = -1;
  }
return check_value;
}

int contact_Validation(char twitter_Account[100], char area_Code[100], char first_Set[100], char second_Set[100]){
  int check_value = 0;

  //Checks if input is valid for twitter account
  if (strlen(twitter_Account) > 15){
  printf("\nError: Twitter account must be less than 15 characters");
  check_value = -1;
  }

  //Checks if twitter account begins with ampersand
  if (twitter_Account[0] != '@'){
    printf("\nError: Twitter account must start with ampersand (@)");
    check_value = -1;
  }

  //Checks if input is valid for phone number
  if (strlen(area_Code) + strlen(first_Set) + strlen(second_Set) != 10){
    printf("\nError: Phone number must be 10 digits long");
    check_value = -1;
  }

return check_value;
}
