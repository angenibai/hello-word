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

// all the info for each of the players
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
	players UNI_A;
	players UNI_B;
	players UNI_C;

	int turnNumber;
} game;
