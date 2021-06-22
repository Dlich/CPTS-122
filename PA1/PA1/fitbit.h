#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1450

typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;
typedef struct fitbit
{
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;


void readData(FitbitData arr[], FILE *infile,char target[]); // Reads in the 24 hour data from the FitbitData input file and fixes it up. 
															 // Also inserts all the data in the FitbitData struct array.


double totalCalories(FitbitData arr[], int size, char target[]); // Calculates the total calories burned over the day for the target



double totalDistanceWalked(FitbitData arr[], int size, char target[]); // Calculates the total distance walked over the day for the target



int totalFloorsWalked(FitbitData arr[], int size, char target[]); // Calculates total floors climbed over the day for the target


int totalSteps(FitbitData arr[], int size, char target[]); // Calculates total steps climbed over the day for the target



double averageHeartBeat(FitbitData arr[], int size, char target[]); // Calculates average heart rate for the target

int longestRangePoorSleep(FitbitData arr[], int size, char startingMin[], char endingMin[], char target[]); // Calculates the longest range of poor sleep for the target


int maxStepsInMinute(FitbitData arr[], int size, char minute[], char target[]); // Finds the maximum minute of steps for the target

