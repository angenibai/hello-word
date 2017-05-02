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

void testNewGame (void); //Angeni
//void testDisposeGame (void); 
void testMakeAction (void); //Angeni
//void testThrowDice (void); //Christina

//void testGetDiscipline (void); //Angeni
//void testGetDiceValue (void); //Christina - NOT DONE
void testGetMostARCs (void); //Angeni
void testGetMostPublications (void); //Christina
void testGetTurnNumber (void); //Angeni
void testGetWhoseTurn (void); //Christina - DONE
void testGetCampus (void); //Angeni
//void testGetARC (void); //Christina
/*
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

int main (int argc, char *argv[]) {

	printf ("BEGINNING TESTING\n");
	// some of these tests aren't written yet
	testNewGame(); //Angeni
	//testDisposeGame(); 
	testMakeAction(); //Angeni - started
	//testThrowDice(); //Christina

	//testGetDiscipline(); //Angeni
	//testGetDiceValue(); //Christina - NOT DONE
	testGetMostARCs(); //Angeni - DONE
	testGetMostPublications(); //Christina
	testGetTurnNumber(); //Angeni - DONE
	testGetWhoseTurn(); //Christina - DONE
	testGetCampus(); //Angeni - done
	//testGetARC(); //Christina
	/*
	testIsLegalAction(); //Christina

	testgetKPIPoints(); //Angeni
	testGetARCs(); //Christina
	testGetGO8s(); //Angeni
	testGetCampuses(); //Angeni
	testGetIPs(); //Christina
	testGetPublications(); //Christina
	testGetStudents(); //Angeni
	testGetExchangeRate(); //Christina
	*/

	printf ("All tests passed, you are Awesome!\n");

	return EXIT_SUCCESS;
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
	assert (getMostARCs (g) == NO_ONE);
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


// Angeni
void testMakeAction (void) {

	printf (" Testing makeAction\n");

	// create game
	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);
	
	throwDice (g, 6); // UNI_A gets MJ. UNI_A's turn
	action a;
	a.actionCode = OBTAIN_ARC;
	strcpy (a.destination, "L");
	makeAction (g, a); // UNI_A builds ARC
	assert (getARC (g, "L") == ARC_A); // checks that the action has happened
	// I should continue this

	disposeGame (g);

	printf (" ...makeAction passes!\n");

}
// Angeni
void testGetDiscipline (void) {

	printf ( "Testing getDiscipline\n");

	// create game
	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);



	printf (" ... getDiscipline passes!\n");
}

/*
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
*/

// Angeni
void testGetMostARCs (void) {

	printf (" Testing getMostARCs\n");

	// create game
	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);

	// at this point no one has any
	assert (getMostARCs (g) == NO_ONE);
	// start the turns
	throwDice (g, 11); // UNI_A gets MTV
	action a;
	a.actionCode = OBTAIN_ARC;
	strcpy (a.destination, "L");
	makeAction (g, a); // UNI_A builds ARC
	assert (getMostARCs (g) == UNI_A);

	throwDice (g, 9); // UNI_B gets B?
	a.actionCode = OBTAIN_ARC;
	strcpy (a.destination, "RRLRLL");
	makeAction (g, a); // UNI_B builds ARC

	throwDice (g, 5); // UNI_B gets BPS
	a.actionCode = PASS;
	makeAction (g, a); // UNI_C passes

	throwDice (g, 9); // UNI_B gets B?
	makeAction (g, a); // UNI_A passes

	throwDice (g, 5); // UNI_B gets BPS
	a.actionCode = OBTAIN_ARC;
	strcpy (a.destination, "RRLRLLL");
	makeAction (g, a); // UNI_B builds ARC
	assert (getMostARCs (g) == UNI_B);

	disposeGame (g);

	printf (" ... makeAction passed\n");
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

	// create game
	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);

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


// Angeni
void testGetTurnNumber (void) {

	printf (" Testing getTurnNumber\n");

	// create game
	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);

	assert (getTurnNumber (g) == -1);
	throwDice (g, 7);
	assert (getTurnNumber (g) == 0);
	throwDice (g, 11);
	assert (getTurnNumber (g) == 1);
	throwDice (g, 3);
	assert (getTurnNumber (g) == 2);
	throwDice (g, 9);
	assert (getTurnNumber (g) == 3);

	disposeGame (g);

	printf (" .... getTurnNumber passed\n");
}

// Angeni
void testGetCampus (void) {

	printf (" Testing getCampus\n");

	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);

	//
	assert (getCampus(g, "") == UNI_A);
	assert (getCampus(g, "LRRLRLRLRLR") == UNI_A);
	assert (getCampus(g, "RRLRL") == UNI_B);
	assert (getCampus(g, "LRLRLRRLRL") == UNI_B);
	assert (getCampus(g, "LRLRL") == UNI_C);
	assert (getCampus(g, "RRLRLLRLRL") == UNI_C);

	//throwDice (g, 6);
	// cbbs to do more turns

	disposeGame (g);

	printf (" .... getCampus passed\n");
}

// Angeni