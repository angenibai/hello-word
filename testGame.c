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

int main (int argc, char *argv[]) {


	// create the default game called g
	
	
	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);

	printf ("BEGINNING TESTING\n");
	// none of these tests are written yet
	testNewGame();
	testDisposeGame();
	testMakeAction();
	testThrowDice();

	testGetDiscipline();
	testGetDiceValue();
	testGetMostARCs();
	testGetMostPublications();
	testGetTurnNumber();
	testGetWhoseTurn();
	testGetCampus();
	testGetARC();

	testIsLegalAction();

	testgetKPIPoints();
	testGetARCs();
	testGetGO8s();
	testGetCampuses();
	testGetIPs();
	testGetPublications();
	testGetStudents();
	testGetExchangeRate();

	printf ("All tests passed, you are Awesome!\n");
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

	printf (" ...newGame passes!\n");
}

void testMakeAction (void) {

	printf (" Testing makeAction\n");

	// create game
	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);
	
	throwDice (g, 6); // UNI_A gets MJ. UNI_A's turn
	action a;
	a.actionCode = OBTAIN_ARC;
	a.destination = "L";
	makeAction (g, a); // UNI_A builds ARC
	assert (getArc (g, "L") == ARC_A); // checks that the action has happened
	// I should continue this

	printf (" ...makeAction passes!\n");

}

void testGetMostARCs (void) {

	printf (" Testing getMostARCS\n");

	// create game
	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);

	// at this point no one has any
	assert (getMostARCS (g) == NO_ONE);
	// start the turns
	throwDice (g, 11); // UNI_A gets MTV
	action a;
	a.actionCode = OBTAIN_ARC;
	a.destination = "L";
	makeAction (g, a); // UNI_A builds ARC
	assert (getMostARCS (g) == UNI_A);

	throwDice (g, 9); // UNI_B gets B?
	a.actionCode = OBTAIN_ARC;
	a.destination = "RRLRLL";
	makeAction (g, a); // UNI_B builds ARC

	throwDice (g, 5); // UNI_B gets BPS
	a.actionCode = PASS;
	makeAction (g, a); // UNI_C passes

	throwDice (g, 9); // UNI_B gets B?
	makeAction (g, a); // UNI_A passes

	throwDice (g, 5); // UNI_B gets BPS
	a.actionCode = OBTAIN_ARC;
	a.destination = "RRLRLLL";
	makeAction (g, a); // UNI_B builds ARC
	assert (getMostARCS (g) == UNI_B);

	printf (" ... makeAction passed\n");
}

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

	printf (" .... getTurnNumber passed\n");
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