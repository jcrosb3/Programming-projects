/*
  Body Weight Calculator - This C program prompts the user to enter a gender and the all the input appropriate to the gender,
  then calculates and displays the Body Fat and Body Fat Percentage based off the inputted measurements.

  Jeremy Crosby
  09/22/19
*/

//Libraries
#include<stdio.h>

//Main function
int main(void) {

  //Variable declerations
  char gender;
  double waistmeasurement, wristmeasurement, hipmeasurement, forarmmeasurement;
  double A1, A2, A3, A4, A5;
  double B, bodyweight, Bodyfat, Bodyfatpercentage;

  //Prompts the user to enter the gender
  printf("This program determines the body fat of a person. \nEnter your gender (f|F|m|M):\n ");
  scanf("%c", &gender);

  //Conditional for the appropriate calculations for a Female
  if(gender == 'F' || gender == 'f'){

      //Prompts the user to enter the body weights in lbs
      printf("Enter body weight (in pounds):\n ");
      scanf("%lf", &bodyweight);

      //Prompts the user to enter wrist measurement in inches
      printf("Enter wrist measurement at fullest point (in inches):\n ");
      scanf("%lf", &wristmeasurement);

      //Prompts the user to enter waist measurement in inches
      printf("Enter waist measurement at navel (in inches):\n ");
      scanf("%lf", &waistmeasurement);

      //Prompts the user to enter hip measurement in inches
      printf("Enter hip measurement at fullest point (in inches):\n ");
      scanf("%lf", &hipmeasurement);

      //Prompts the user to enter forearm measurement in inches
      printf("Enter forearm measurement at fullest point (in inches):\n ");
      scanf("%lf", &forarmmeasurement);

      //Calculations on user inputted body measurements
      A1 = (bodyweight * 0.732) + 8.987;
      A2 = (wristmeasurement / 3.140);
      A3 = (waistmeasurement * 0.157);
      A4 = (hipmeasurement * 0.249);
      A5 = (forarmmeasurement * 0.434);
      B = A1 + A2 - A3 - A4 + A5;
      Bodyfat = bodyweight - B;
      Bodyfatpercentage = (Bodyfat * 100) / bodyweight;

      //Prints the calculated bodyfat and bodyfat percentage for a Female
      printf("Body fat: %.6lf", Bodyfat);
      printf("\nBody fat percentage: %.6lf", Bodyfatpercentage);
    }

    //Conditional for the appropriate calculations for a Male
    else if(gender=='M' || gender=='m'){

      //Prompts the user to enter body weight in lbs
      printf("Enter body weight (in pounds):\n ");
      scanf("%lf", &bodyweight);

      //Prompts the user to enter waist measurement measurement in inches
      printf("Enter waist measurement at fullest point (in inches):\n ");
      scanf("%lf", &waistmeasurement);

      //Performs calculations on user inputted values
      A1 = (bodyweight * 1.082) + 94.42;
      A2 = waistmeasurement * 4.15;
      B = A1 - A2;
      Bodyfat = bodyweight - B;
      Bodyfatpercentage = (Bodyfat * 100) / bodyweight;

      //Prints the calculated bodyfat and bodyfat percentage for a Male
      printf("Body fat: %.6lf", Bodyfat);
      printf("\nBody fat percentage: %.6lf", Bodyfatpercentage);
    }

    else{
        //Returns an error message if invalid gender character is inputted by user
        printf("Invalid gender code.");
        return(0);
        }
  return(0);
  }
