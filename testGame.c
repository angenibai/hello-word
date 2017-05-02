/* Angie Bai and Chrissy Shi
 * Creates the game and tests all of its interface functions
 * Edit history:
 *	1.0 - 24/04/2017 - write main function
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "game.h"

#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
	                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
	                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
	                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
	                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}

//rip i forgot this was in game.h
/*
void testNewGame (void); //Angeni
void testDisposeGame (void); 
void testMakeAction (void); //Angeni
void testThrowDice (void); //Christina

void testGetDiscipline (void); //Angeni
void testGetDiceValue (void); //Christina - DONE
void testGetMostARCs (void); //Angeni
void testGetMostPublications (void); //Christina
void testGetTurnNumber (void); //Angeni
void testGetWhoseTurn (void); //Christina - DONE
void testGetCampus (void); //Angeni
void testGetARC (void); //Christina

void testIsLegalAction (void); //Christina

void testgetKPIPoints (void); //Angeni
void testGetARCs (void); //Christina
void testGetGO8s (void); //Angeni
void testGetCampuses (void); //Angeni
void testGetIPs (void); //Christina
void testGetPublications (void); //Christina
void testGetStudents (void); //Angeni
void testGetExchangeRate (void); //Christina
*/

typedef struct _players {
	int students [NUM_DISICPLINES];
	int campuses;
	int G08s;
	int ARCs;
	int publications;
	int patents;
	int KPI;
	int retrainingcentres [NUM_DISICPLINES];
} players;

typedef struct _Game {
	int turnNumber;
	players UNI_A;
	players UNI_B;
	players UNI_C;
} Game;

int main (int argc, char *argv[]) {


	// create the default game called g
	
	
	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);

	printf ("BEGINNING TESTING\n");
	// some of these tests are not written yet
	testNewGame(); //Angeni
	testDisposeGame(); 
	testMakeAction(); //Angeni
	testThrowDice(); //Christina

	testGetDiscipline(); //Angeni
	testGetDiceValue(); //Christina - DONE
	testGetMostARCs(); //Angeni
	testGetMostPublications(); //Christina
	testGetTurnNumber(); //Angeni
	testGetWhoseTurn(); //Christina - DONE
	testGetCampus(); //Angeni
	testGetARC(); //Christina

	testIsLegalAction(); //Christina

	testgetKPIPoints(); //Angeni
	testGetARCs(); //Christina
	testGetGO8s(); //Angeni
	testGetCampuses(); //Angeni
	testGetIPs(); //Christina
	testGetPublications(); //Christina
	testGetStudents(); //Angeni
	testGetExchangeRate(); //Christina

	printf ("All tests passed, you are Awesome!\n");
}

//Christina
void testGetDiceValue (void) {
	printf ("Testing getDiceValue\n");

	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);

	//after throwing a 6 the value is then a 6
	throwDice (g, 6);
	assert (getDiceValue (g) == 6);

	//after throwing a 2 the value is then a 2
	throwDice (g, 2);
	assert (getDiceValue (g) == 2);

	//after throwing a 11 the value is then a 11
	throwDice (g, 11);
	assert (getDiceValue (g) == 11);

	//after throwing a 9 the value is then a 9
	throwDice (g, 9);
	assert (getDiceValue (g) == 9);

	//after throwing a 3 the value is then a 3
	throwDice (g, 3);
	assert (getDiceValue (g) == 3);

   	disposeGame (g);
	printf ("...getDiceValue passes!\n");
}



// Angeni
void testNewGame (void) {

	printf (" Testing newGame\n");

	// create game
	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);
	// no turns yet
	assert (getTurnNumber (g) == -1);
	// no one should have most ARCs
	assert (getMostARCS (g) == NO_ONE);
	// same with most publications
	assert (getMostPublications (g) == NO_ONE);
	// no one's turn
	assert (getWhoseTurn (g) == NO_ONE);
	// campuses are allocated correctly
	assert (getCampus (g, "") == UNI_A);
	assert (getCampus (g, "L") == VACANT_VERTEX);

	disposeGame (g);
	printf (" ...newGame passes!\n");
}

//Christina
void testGetMostPublications (void) {

   	printf(" Testing getMostPublications");
   	
   	//create game
   	int disciplines[] = DEFAULT_DISCIPLINES;
   	int dice[] = DEFAULT_DICE;
   	Game g = newGame (disciplines, dice);
   
   	//no turns as of now
   	assert (getMostPublications (g) == 0);

   	//TO DO


   	disposeGame (g);
	printf (" ...getMostPublications passes!\n");

}

//Christina
void testGetWhoseTurn (void) {

	printf ("Testing getWhoseTurn\n");

	//1st turn should be UNI_A's
	throwDice (g, 8);
	assert(getWhoseTurn(g) == UNI_A);

	//throwing dice moves onto next turn
	//next turn should be UNI_B's
	throwDice (g, 3);
	assert(getWhoseTurn(g) == UNI_B);

	//repeat for UNI_C
	throwDice (g, 11);
	assert(getWhoseTurn(g) == UNI_C);

	//repeat for one more cycle
	throwDice (g, 4);
	assert(getWhoseTurn(g) == UNI_A);
	
	throwDice (g, 9);
	assert(getWhoseTurn(g) == UNI_B);
	
	throwDice (g, 3);
	assert(getWhoseTurn(g) == UNI_C);

	disposeGame (g);
	printf ("...getWhoseTurn passes!\n");

}

void testMakeAction (void) {

	printf (" Testing makeAction\n");

	// create game
	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);
	// no turns yet
	assert (getTurnNumber(g) == -1);
	// 

	printf (" ...makeAction passes!\n");

}

void testGetCampus (void) {

	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);

	printf (" Testing getCampus\n");
	//
	assert (getCampus(g, "") == UNI_A);
	assert (getCampus(g, "LRRLRLRLRLR") == UNI_A);
	assert (getCampus(g, "RRLRL") == UNI_B);
	assert (getCampus(g, "LRLRLRRLRL") == UNI_B);
	assert (getCampus(g, "LRLRL") == UNI_C);
	assert (getCampus(g, "RRLRLLRLRL") == UNI_C);

	throwDice (g, 6);
}