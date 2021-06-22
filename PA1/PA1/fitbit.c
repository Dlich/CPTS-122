#include "fitbit.h"

void readData(FitbitData arr[], FILE *infile, char target[])
{
	// arrIndex tracks the index in arr[] 
	// t tracks the lines in the input file
	// index 2 is used to help track the array when shiting it over
	int t = 1;
	int arrIndex = 0;
	int index2 = 1;
	while (!feof(infile))
	{
		char line[100] = "";
		fgets(line, 100, infile);
		int index = 0;
		for (int i = 0; i < 100; i++)
		{
			if (line[i] == '\0') // finds the index of the null character
			{
				index = i; 
				break;
			}
		}
		// this shifts the array over by 1 when it finds two commas in a row and allows to place an '@' character as a placeholder
		for (int i = 0; i <= index; i++)
		{
			if (line[i] == ',' && line[1+i] == ',')
			{
				char templine[100] = "";
				int index2 = 0;
				for (int j = i + 1; j < index; j++)
				{
					templine[index2] = line[j];
					index2++;
				}
				line[i + 1] = '@';
				index2 = 0;
				for (int j = i + 2; j < index; j++)
				{
					line[j] = templine[index2++];
				}
				index++;
			}
		}
		
		if (line[strlen(line)] == ',')
		{
			line[strlen(line) + 1] = ',';
			line[strlen(line) + 2] = '\0';
			index++;
		}
		if (t == 1) // finds the target patients identification to know whose data to collect
		{
			char *pch;
			pch = strtok(line, ",");
			pch = strtok(NULL, ",");
			strcpy(target, pch);
		}
		t++;
		if (t > 2) // Starts at line 3
		{
			char *pch;
			pch = strtok(line, ",");
			int tempindex = 0; // tracks the strings returned by strtok in order to know in what fields to put them in
			while (pch != NULL)
			{
				if (tempindex == 0)
				{
						if (strcmp(pch, target) == 0)
						{
							strcpy(arr[arrIndex].patient, pch);
						}
				}
				else if (tempindex == 1)
				{
					strcpy(arr[arrIndex].minute, pch);
					
				}
				else if (tempindex == 2)
				{
					if (pch != '@')
					{
						double value = 0;
						value = atof(pch);
						arr[arrIndex].calories = value;
					}
					else
					{
						arr[arrIndex].calories = 12345.0;
					}
				}

				else if (tempindex == 3)
				{
					if (pch != '@')
					{
						double value = 0;
						value = atof(pch);
						arr[arrIndex].distance = value;
					}
					else
					{
						double d = 12345.0;
						arr[arrIndex].distance = d;
					}
				}
				else if (tempindex == 4)
				{
					if (pch != '@')
					{
						int value = 0;
						value = atoi(pch);
						arr[arrIndex].floors = value;
					}
					else
					{
						unsigned int r = 12345;
						arr[arrIndex].floors = r;
					}
				}
				else if (tempindex == 5)
				{
					if (strcmp(pch, "@") != 0)
					{
						int value = 0;
						value = atoi(pch);
						arr[arrIndex].heartRate = value;
					}
					else
					{
					
						unsigned int r = 12345;
						arr[arrIndex].heartRate = r;
						
					}
				}
				else if (tempindex == 6)
				{
					if (strcmp(pch, "@") != 0)
					{
						int value = 0;
						value = atoi(pch);
						arr[arrIndex].steps = value;
					}
					else
					{
						unsigned int r = 12345;
						arr[arrIndex].steps = r;
					}
				}
				else if (tempindex == 7)
				{
					if (strcmp(pch, "@") != 0)
					{
						int value = 0;
						value = atoi(pch);
						arr[arrIndex].sleepLevel = value;
					}
					else
					{
						printf("success!!!\n");
						Sleep s = 12345;
						arr[arrIndex].sleepLevel = s;
					}
				}
				
				tempindex++;
				pch = strtok(NULL, ",");
			}
			
			arrIndex++;
		}

	}
	
}
double totalCalories(FitbitData arr[], int size, char target[]) // finds the total calories by checking through all the calories field in the structs in FitBitData array
{
	double calories = 0.0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].calories != 12345.0 && strcmp(arr[i].patient, target) == 0) // makes sure the name of the patient in that struct at i and that the calories aren't a placeholder for invalid data
		{
			double temp = arr[i].calories;
			calories += temp;
		}
		
	}
	return calories;
}
double totalDistanceWalked(FitbitData arr[], int size, char target[]) // finds total distance by adding up all the distances for the target patien in the arr of FitBitData
{
	double distance = 0.0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].distance != 12345.0 && strcmp(arr[i].patient, target) == 0) // makes sure the name of the patient in that struct at i and that the distance isn't equal to the placeholder for invalid data
		{
			double temp = arr[i].distance;
			distance += temp;
		}
		
	}
	return distance;
}
int totalFloorsWalked(FitbitData arr[], int size, char target[]) // finds total floors walked by adding up all the floors walked for the target patien in the arr of FitBitData
{
	int floors = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].floors != (unsigned)12345 && strcmp(arr[i].patient, target) == 0) // makes sure the name of the patient in that struct at i and that the floors are not equal to the placeholder for invalid data
		{
			int temp = arr[i].floors;
			floors += temp;
		}
		
	}
	return floors;
}
int totalSteps(FitbitData arr[], int size, char target[]) // finds total steps by adding up all the steps for the target patien in the arr of FitBitData
{
	int steps = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].steps != (unsigned)12345 && strcmp(arr[i].patient, target) == 0) // makes sure the name of the patient in that struct at i and that the steps are not invalid data
		{
			int temp = arr[i].steps;
			steps += temp;
		}
		
	}
	return steps;
}
double averageHeartBeat(FitbitData arr[], int size, char target[]) // finds average by adding up all the distances for the target patien in the arr of FitBitData and diving by the amount of valid data
{
	double totalHeartBeat = 0.0;
	int ammount = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].heartRate != (unsigned)12345 && strcmp(arr[i].patient, target) == 0) // makes sure the name of the patient in that struct at i and that the heartRate isn't placeholder for invalid data
		{
			double temp = arr[i].heartRate;
			totalHeartBeat += temp;
			ammount++;
		}
		
	}
	return totalHeartBeat / (double)ammount;
}

int maxStepsInMinute(FitbitData arr[], int size, char minute[], char target[]) // compares each minute and sees in which minute the pation took the most steps
{
	int maxSteps = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].steps >= maxSteps && arr[i].steps != (unsigned)12345 && strcmp(arr[i].patient, target) == 0) // makes sure the name of the patient in that struct at i and that steps are greater than stepsand steps is not equal to the placeholder for invalid data
		{
			maxSteps = arr[i].steps;
			strcpy(minute, arr[i].minute);
		}
	}
	return maxSteps;
}
int longestRangePoorSleep(FitbitData arr[], int size, char startingMin[], char endingMin[], char target[]) // finds longest range of poor sleep, where sleepLevel is greater than 1
{
	int longestRangeInMinutes = 0;
	int tempRange = 0;
	int counter = 0;
	int t = 0;
	char tempString[9] = "";
	for (int i = 0; i < size; i++)
	{
		counter = i;

		while (arr[counter].sleepLevel > 1)
		{
			if (t == 0)
			{
				strcpy(tempString, arr[counter].minute);
				t++;
			}
			int temp = arr[counter].sleepLevel;
			tempRange += temp;
			strcpy(endingMin, arr[counter].minute);
			counter++;
		}
		
		if (tempRange > longestRangeInMinutes && strcmp(arr[i].patient, target) == 0) // makes sure the name of the patient in that struct at i and that the tempRange is greater than current longest range
			{
				longestRangeInMinutes = tempRange;
				strcpy(startingMin, tempString);
			}
			tempRange = 0;
			t = 0;
		}
	return longestRangeInMinutes;
	}
