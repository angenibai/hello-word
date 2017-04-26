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

void testNewGame (void) {
	int disciplines[] = DEFAULT_DISCIPLINES;
	int dice[] = DEFAULT_DICE;
	Game g = newGame (disciplines, dice);

	assert (getTurnNumber(g) == -1);
	
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