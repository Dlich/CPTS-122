/*******************************************************************************
* Programmer: Daniel Lichtchouk                                                *
* Class: CptS 122; Lab Section 12                                              *
* Programming Assignment: PA 1                                                 *
* Date: 1/25/2019                                                              *
*                                                                              *
* Description: This program extracts FitBit data, fixes up any broken data     *
*              and calculates various things such as average heartRate,        *
*			   total steps taken, distance travelled, calories expended etc.   *
******************************************************************************/



#include "fitbit.h"


void main(void)
{
	FILE *file = NULL, *output = NULL;
	file = fopen("FitbitData.csv", "r");
	output = fopen("Results.csv", "w");
	FitbitData dataArr[MAXSIZE] = { 0 };
	char startMin[9] = "", endMin[9] = "", maxMin[9] = "", target[10] = "";
	readData(dataArr, file, target);
	double calories = totalCalories(dataArr, MAXSIZE, target);
	double distance = totalDistanceWalked(dataArr, MAXSIZE, target);
	int floors = totalFloorsWalked(dataArr, MAXSIZE, target);
	int steps = totalSteps(dataArr, MAXSIZE, target);
	double heartRate = averageHeartBeat(dataArr, MAXSIZE, target);
	int sleep = longestRangePoorSleep(dataArr, MAXSIZE, startMin, endMin, target);
	int maxSteps = maxStepsInMinute(dataArr, MAXSIZE, maxMin, target);
	fprintf(output, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
	fprintf(output, "%lf,%lf,%d,%d,%lf,%d,%s:%s\n", calories, distance, floors, steps, heartRate, maxSteps, startMin, endMin);
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (strcmp(dataArr[i].patient, target) == 0)
		{
			fprintf(output, "%s,%s,%lf,%lf,%d,%d,%d,%d\n", dataArr[i].patient, dataArr[i].minute, dataArr[i].calories, dataArr[i].distance, dataArr[i].floors, dataArr[i].heartRate, dataArr[i].steps, dataArr[i].sleepLevel);
		}
		
	}
	fclose(file);
	fclose(output);
}