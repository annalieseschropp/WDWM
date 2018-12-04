/************************schroppAnnalieseA2.c **************
Student Name: Annaliese Schropp Email Id: aschropp
Date: November 9th, 2018 Course Name: CIS 1500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and
all material (data, images, ideas or words) that I have used, whether directly
quoted or paraphrased. Furthermore, I certify that this assignment was prepared
by me specifically for this course.
**********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_QUESTIONS 7

//function prototypes

void promptPlayerForName(char player [50]);
void printWelcomeMessage(char player [50]);
int  calculateCurrentAward (int questionNum, int currentMoney);
void popUpCurrentQuestion4choices (int currentMoney);
char askPlayerForLifeLine (void);
void popUpCurrentQuestion2choices (int currentMoney);
char acceptPlayersFinalAnswer (void);
bool isCorrectFinalAnswer (char answer, int questionNum, char correct[MAX_QUESTIONS]);
void generateRandomGreeting (char greeting[20]);
int calculateReducedAward (int questionNum, int currentMoney);

int main(){

	char allCorrectAnswers [MAX_QUESTIONS + 1] = "CBCBACA";   // for my set of questions
	char greet [20];
	char nameForGame[50];
	int lifeLineUsed = 0;
	int questionNumber = 1;
	char playersResponseLifeLine;
	char finalAnswer;
	int currentAwardAmount ;
  int reducedAmount;

	promptPlayerForName(nameForGame);

	printWelcomeMessage(nameForGame);

	while (questionNumber <= MAX_QUESTIONS)
    {

		currentAwardAmount = calculateCurrentAward(questionNumber, currentAwardAmount);

		popUpCurrentQuestion4choices(currentAwardAmount);

		if (lifeLineUsed == 0)
        {
			playersResponseLifeLine = askPlayerForLifeLine();

			if (playersResponseLifeLine == 'Y' || playersResponseLifeLine == 'y')
            {

				popUpCurrentQuestion2choices(currentAwardAmount);
				lifeLineUsed ++;
				printf("\nReminder - You get only 1 50-50 lifeline - and you are using it now \n\n");
			}
		}

		finalAnswer = acceptPlayersFinalAnswer ();

		if (isCorrectFinalAnswer (finalAnswer, questionNumber, allCorrectAnswers) )
        {

		 	generateRandomGreeting(greet);
			printf("%s - You just won $ %d\n", greet, currentAwardAmount);

			if (questionNumber < MAX_QUESTIONS)
            {
				printf("Let us play the next question now\n\n");
			}
		}

		else {
			printf  ("Oops - that was incorrect.");

            reducedAmount = calculateReducedAward (questionNumber, currentAwardAmount);

			printf("You still won $%d. Well done.\n\n", reducedAmount);

            questionNumber = MAX_QUESTIONS;
		}
		questionNumber ++;
	}

	printf("It was fun playing with you \n\n");

	return 0;

}
//Functions

/* Function asks for first and last name, combines them into one string and
stores it in the main function */
void promptPlayerForName (char player [50]){
  char last[25];

  printf("Enter your first name: ");
  scanf("%s", player);
  printf("Enter your last name: ");
  scanf("%s", last);

  strcat(player, " "); //Allows for a space between the first and last name
  strcat(player, last);
}

/* Using the player's name, the function prints out a message and a design
using *'s */
void printWelcomeMessage(char player [50]){

	//Prints out a triangle formation
  for (int i = 0; i < 3; i++){
    for (int j = 0; j <= i; j++){
      printf("*");
    }
    printf("\n");
  }
	//Prints the same number of *'s as the length of the name and 'Welcome'
  for (int i = 0; i <= (7 + strlen(player)); i++){
    printf ("*");
  }
  printf("\nWelcome %s\n", player);
  printf("Let's play WDWM!\n");

  for (int i = 0; i <= (7 + strlen(player)); i++){
    printf ("*");
  }
  printf("\n");
	//Prints out a triangle formation reversed
  for (int i = 3; i > 0; i--){
    for (int j = 0; j < i; j++){
      printf("*");
    }
    printf("\n");
  }

}

/* Based on the question that the user is on, it will calculate the correct
amount of money */
int  calculateCurrentAward (int questionNum, int currentMoney){

  if (questionNum == 1){
    currentMoney = 100;
  }
  else if ((questionNum % 2) != 0){ //For all odd questions
    currentMoney = currentMoney * 2;
  }
  else if ((questionNum % 2) == 0){ //For all even questions
    currentMoney = currentMoney * 5;
  }

  return currentMoney;

}

/* Based on the current money the player has, it will print the corresponding
question */
void popUpCurrentQuestion4choices (int currentMoney){

  printf("\nHere is the $ %d question:\n", currentMoney);
  if (currentMoney == 100){
    printf("\nWhich of the following programming languages is taught in\nCIS1500 at the University of Guelph?\n");
    printf("\nA. Python\t\tB.Cobra\nC. C\t\t\tD. Java\n");
  }
  else if (currentMoney == 500){
    printf("\nWhich Canadian chain first opened in Hamilton in 1964?\n");
    printf("\nA. McDonalds\t\t\tB. Tim Hortons\nC. Wendys\t\t\tD. Mr. Sub\n");
  }
  else if (currentMoney == 1000){
    printf("\nWhat is Canada's national sport?\n");
    printf("\nA. Hockey\t\t\tB.Lacrosse\nC. Hockey and Lacrosse\t\tD. Baseball\n");
  }
  else if (currentMoney == 5000){
    printf("\nWhich Canadian city ranks as the most educated in the country?\n");
    printf("\nA. Montreal\t\t\tB. Ottawa\nC. Vancouver\t\t\tD. Toronto\n");
  }
  else if (currentMoney == 10000){
    printf("\nWhat is Canada's highest mountain?\n");
    printf("\nA. Mount Logan, Yukon\t\t\tB.Whistler Mountain, BC\nC. Mon Tremblant, Quebec\t\tD. Tip Top Mountain, Ontario\n");
  }
  else if (currentMoney == 50000){
    printf("\nWhat is the easternmost province of Canada?\n");
    printf("\nA. Ontario\t\t\tB. Prince Edward Island\nC. Newfoundland\t\t\tD. Nova Soctia\n");
  }
  else if (currentMoney == 100000){
    printf("\nThe southernmost point of mainland Canada is called Point Pelee.\nWhat province is it in?\n");
    printf("\nA. Ontario\t\t\tB. Quebec\nC. Newfoundland\t\t\tD. Nova Scotia\n");
  }

}

/* Checks for if the player would like to use their lifeline, does not allow
other characters to be entered */
char askPlayerForLifeLine (void){
  char answer = ' ';

  printf("\nWould you like to use a lifeline (50-50)?\n");

  do {
    printf("Enter Y or y, N or n:");
    scanf("%c", &answer); //Dummy scanf to prevent it from looping twice
    scanf("%c", &answer);

		//Prevents user from entering other options
    if (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n'){
      printf("Invalid option entered\n");
    }
  } while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');

  return answer;
}

/* If they use the lifeline, then based on the current money they have, it will
give them two of the four answer options */
void popUpCurrentQuestion2choices (int currentMoney){

  printf("\nOK - here are your 2 choices after using the 50-50 lifeline\n");

  if (currentMoney == 100){
    printf("\nC. C\nD. Java\n");
  }
  else if (currentMoney == 500){
    printf("\nA. McDonald's\nB. Tim Horntons\n");
  }
  else if (currentMoney == 1000){
    printf("\nA. Hockey\nC. Hockey and Lacrosse\n");
  }
  else if (currentMoney == 5000){
    printf("\nB. Ottawa\nD. Toronto\n");
  }
  else if (currentMoney == 10000){
    printf("\nA. Mount Logan, Yukon\nB. Whistler Mountain, BC\n");
  }
  else if (currentMoney == 50000){
    printf("\nC. Newfoundland\nD. Nova Scotia\n");
  }
  else if (currentMoney == 100000){
    printf("\nA. Ontario\nB. Quebec\n");
  }

}

/* Function recieves the final answer from the user, prevents users from
entering options other than the 4 choices */
char acceptPlayersFinalAnswer (void){

  char answer = ' ';

  do {
    printf("\nEnter your FINAL ANSWER ('A', 'B', 'C', 'D') here: ");
    scanf("%c", &answer); //Dummy scanf to prevent it from looping twice
    scanf("%c", &answer);

    if (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D'){
      return answer;
    }
  } while (answer != 'A' || answer != 'B' || answer != 'C' || answer != 'D');

  return answer;

}

/* Function checks if the user's answer is correct based on the answer key */
bool isCorrectFinalAnswer (char answer, int questionNum, char correct[MAX_QUESTIONS]){

  if (answer == correct[questionNum - 1]){ //-1 because the array starts at 0 but questionNum does not
    return true;
  }
  else {
    return false;
  }

}

/* Prints a random congraduations statement for the user when they get a
correct answer */
void generateRandomGreeting(char greeting[20]){

  strcpy (greeting, ""); //sets the greeting string to be empty
  int randNum = (rand() % 5); //sets randNum to be a random number from 0-4

  switch (randNum){
    case 0:
      strcat (greeting, "Bravo");
      break;
    case 1:
      strcat (greeting, "Congrats");
      break;
    case 2:
      strcat (greeting, "Well done");
      break;
    case 3:
      strcat (greeting, "Very nice");
      break;
    case 4:
      strcat (greeting, "Proud of you");
      break;
  }

}

/* If/when the user gets a wrong answer, they do not get the award amount for
the question they failed to answer correctly. Function sets the awarded money
to the previous question's amount */
int calculateReducedAward (int questionNum, int currentMoney){

  if (questionNum == 1){
    currentMoney = 0; //If they fail the first question, they get no award amount
  }
  else if ((questionNum % 2) != 0){
    currentMoney = currentMoney / 2;
  }
  else if ((questionNum % 2) == 0){
    currentMoney = currentMoney / 5;
  }

  return currentMoney;

}
