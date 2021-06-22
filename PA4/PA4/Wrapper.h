#pragma once
#include"DietPlan.h"
#include "ExercisePlan.h"
#include <sstream>
using std::stringstream;
class FitnessAppWrapper
{
public:
	FitnessAppWrapper(); // basic constructor
	void runApp(void); // runs the main application
	void loadDailyDietPlan(fstream &fileStream, DietPlan &plan); // loads data from the input file into plan
	void loadDailyExercisePlan(fstream &fileStream, ExercisePlan &plan); // loads data from the output file into plan
	void loadWeeklyDietPlan(fstream &fileStream, DietPlan weeklyPlan[]); // calls the loadDaily function to get data into DietPlan objects and insert them into the array
	void loadWeeklyExercisePlan(fstream &fileStream, ExercisePlan weeklyPlan[]); // calls the loadDaily function to get data into ExercisePlan objects and insert them into the array
	void displayDailyDietPlan(DietPlan &plan); // displays a diet plan
	void displayDailyExercisePlan(ExercisePlan &plan); // displays an exercise plan
	void displayWeeklyDietPlan(DietPlan arr[]); // displays the entire dietPlan Array
	void displayWeeklyExercisePlan(ExercisePlan arr[]); // displays the entire ExercisePlan array
	void storeDailyDietPlan(fstream &fileStream, DietPlan &plan); // stores a diet plan into the input file
	void storeDailyExercisePlan(fstream &fileStream, ExercisePlan &plan); // stores a Exercise plan into the input file
	void storeWeeklyDietPlan(fstream &fileStream, DietPlan arr[]); // stores all the DietPlans from the array into the input file
	void storeWeeklyExercisePlan(fstream &fileStream, ExercisePlan arr[]); // stores all the ExercisePlans from the array into the output file
	void displayMenu(void); // displays menu
	void editDiet(DietPlan arr[]); // lets you edit a diet plan goal
	void editExercise(ExercisePlan arr[]); // lets you edit a exercise plan goal
private:
	fstream input; // input is set to the "dietPlans.txt" file
	fstream output; // output is set to the "exercisePlans.txt" file
	DietPlan weeklyDietArr[7];
	ExercisePlan weeklyExerciseArr[7];
};
