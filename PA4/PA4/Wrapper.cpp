#include "Wrapper.h"

FitnessAppWrapper::FitnessAppWrapper()
{
	// The constructor for FitnessAppWrapper opens the files so I can start loading the data into my arrays

	input.open("dietPlans.txt");
	output.open("exercisePlans.txt");
}
void FitnessAppWrapper::runApp(void)
{
	int continueprogram = 0;
	while (continueprogram == 0) // program continues running until user chooses to exit
	{
		displayMenu(); // displays the menu at the beginning showing the user what options they have
		int option = 0;
		cout << "Choose a option" << endl;
		cin >> option;
		if (option == 1) // loads DietPlans into the array
		{
			loadWeeklyDietPlan(input, weeklyDietArr);
		}
		else if (option == 2) // loads ExercisePlans into the array
		{
			loadWeeklyExercisePlan(output, weeklyExerciseArr);
		}
		else if (option == 3) // Closes the file and reopens it so i can write to it
		{
			input.close();
			input.open("dietPlans.txt");
			storeWeeklyDietPlan(input, weeklyDietArr);
		}
		else if (option == 4) // closes the file and reopens it so i can write to it
		{
			output.close();
			output.open("exercisePlans.txt");
			storeWeeklyExercisePlan(output, weeklyExerciseArr);
		}
		else if (option == 5) // displays dietArr
		{
			displayWeeklyDietPlan(weeklyDietArr);
		}
		else if (option == 6) // displays Exercise array
		{
			displayWeeklyExercisePlan(weeklyExerciseArr);
		}
		else if (option == 7) // Allows the user to edit a diet plan to change the goal calories
		{
			editDiet(weeklyDietArr);
		}
		else if (option == 8) // allows the user to edit a exercise plan to change the goal steps
		{
			editExercise(weeklyExerciseArr);
		}
		else if (option == 9) // stores the data into the .txt files and exits the program
		{
			input.close();
			input.open("dietPlans.txt");
			storeWeeklyDietPlan(input, weeklyDietArr);
			output.close();
			output.open("exercisePlans.txt");
			storeWeeklyExercisePlan(output, weeklyExerciseArr);
			continueprogram = 1;
		}
	}
}
void FitnessAppWrapper::loadDailyDietPlan(fstream &fileStream, DietPlan &plan)
{
	if (fileStream.is_open()) // checks to confirm fileStream is open
	{
		string line = "";
		int counter = 1;
		getline(fileStream, line); // gets the first line from the file
		while (line.length()!=0) // goes through each line in the files until it reaches a new line
		{
			if (counter % 4 == 1) // if the counter mod 4 is 1, then it means its the line with the plan name
			{
				plan.setPlanName(line);
			}
			else if (counter % 4 == 2) // if the counter mod 4 is 2, then it means its the line with the goal
			{
				int goal = 0;
				stringstream temp(line); // this allows the string to be converted into an integer so i can set the goal steps
				temp >> goal;
				plan.setCalories(goal);
			}
			else if (counter % 4 == 3) // if the counter mod 4 is 3, then it means its the line with the date
			{
				plan.setDate(line);
			}
			counter++;
			getline(fileStream, line); // gets the next line at the end
		}
		
	}
}
void FitnessAppWrapper::loadDailyExercisePlan(fstream &fileStream, ExercisePlan &plan)
{
	if (fileStream.is_open()) // checks to confirm fileStream is open
	{
		string line = "";
		int counter = 1;
		getline(fileStream, line); // gets the first line from the file
		while (line.length() != 0) // goes through each line in the files until it reaches a new line
		{
			if (counter % 4 == 1) // if the counter mod 4 is 1, then it means its the line with the plan name
			{
				plan.setPlanName(line);
			}
			else if (counter % 4 == 2) // if the counter mod 4 is 2, then it means its the line with the goal
			{
				int goal = 0;
				stringstream temp(line); // this allows the string to be converted into an integer so i can set the goal steps
				temp >> goal;
				plan.setSteps(goal);
			}
			else if (counter % 4 == 3) // if the counter mod 4 is 3, then it means its the line with the date
			{
				plan.setDate(line);
			}
			counter++;
			getline(fileStream, line); // gets the next line at the end
		}

	}
}
void FitnessAppWrapper::loadWeeklyDietPlan(fstream &fileStream, DietPlan weeklyPlan[])
{
	/*
		Creates a new diet plan and Goes through every diet plan in the file.
		Then it calls loadDailyDietPlan with the new plan and adds that plan to the array
	*/
	for (int i = 0; i < 7; i++)
	{
		DietPlan temp;
		loadDailyDietPlan(fileStream, temp);
		weeklyPlan[i] = temp;
	}
}
void FitnessAppWrapper::loadWeeklyExercisePlan(fstream &fileStream, ExercisePlan weeklyPlan[])
{
	/*
		Creates a new exercise plan and Goes through every exercise plan in the file. 
		Then it calls loadDailyExercisePlan with the new plan and adds that plan to the array
	*/
	for (int i = 0; i < 7; i++)
	{
		ExercisePlan temp;
		loadDailyExercisePlan(fileStream, temp);
		weeklyPlan[i] = temp;
	}
}
void FitnessAppWrapper::displayDailyDietPlan(DietPlan &plan)
{
	// Displays the diet plan because of the overloaded stream operator
	cout << plan << endl;
}
void FitnessAppWrapper::displayDailyExercisePlan(ExercisePlan &plan)
{
	// Displays the exercise plan because of the overloaded stream operator
	cout << plan << endl;
}
void FitnessAppWrapper::displayWeeklyDietPlan(DietPlan arr[])
{
	/*
		This method goes through the array and calls displayDailyExercisePlan on each plan
	*/
	for (int i = 0; i < 7; i++)
	{
		displayDailyDietPlan(arr[i]);
	}
}
void FitnessAppWrapper::displayWeeklyExercisePlan(ExercisePlan arr[])
{
	/*
		This method goes through the array and calls displayDailyExercisePlan on each plan
	*/
	for (int i = 0; i < 7; i++)
	{
		displayDailyExercisePlan(arr[i]);
	}
}
void FitnessAppWrapper::editDiet(DietPlan arr[])
{
	/*
		This method asks the user which plan they would like to change. Afterwards it goes through the array to find
		which plan has the same name as the one the user chose, and then calls editGoal on that data plan.
	*/
	string name = "";
	cout << "Which plan do you want to change? (Type DietPlan followed by a number 1-7, no space)" << endl;
	cin >> name;
	cout << name << "!!!!!!!" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i].getPlanName() << "!!!!!!" << endl;
		if (name.compare(arr[i].getPlanName()) == 0)
		{
			arr[i].editGoal();
		}
	}
}
void FitnessAppWrapper::editExercise(ExercisePlan arr[])
{
	/*
		This method asks the user which plan they would like to change. Afterwards it goes through the array to find
		which plan has the same name as the one the user chose, and then calls editGoal on that data plan.
	*/
	string name = "";
	cout << "Which plan do you want to change? (Type ExercisePlan followed by a number 1-7, no space)" << endl;
	cin >> name;
	for (int i = 0; i < 7; i++)
	{
		if (name.compare(arr[i].getPlanName()) == 0)
		{
			arr[i].editGoal();
		}
	}
}
void FitnessAppWrapper::storeDailyDietPlan(fstream &fileStream, DietPlan &plan)
{
	/*
		It calls the getters on plan and writes them to the fileStream a.k.a input
	*/
	fileStream << plan.getPlanName() << endl;
	fileStream << plan.getCalories() << endl;
	fileStream << plan.getDate() << endl;
	fileStream << "\n";
}
void FitnessAppWrapper::storeDailyExercisePlan(fstream &fileStream, ExercisePlan &plan)
{
	/*
		It calls the getters on plan and writes them to the fileStream a.k.a output
	*/
	fileStream << plan.getPlanName() << endl;
	fileStream << plan.getSteps() << endl;
	fileStream << plan.getDate() << endl;
	fileStream << "\n";
}
void FitnessAppWrapper::storeWeeklyDietPlan(fstream &fileStream, DietPlan arr[])
{
	/*/
		This method goes through each Diet plan in the arr and calls storeDailyDietPlan.
		storeDailyDietPlan writes all the data to the .txt files
	*/
	for (int i = 0; i < 7; i++)
	{
		storeDailyDietPlan(fileStream, arr[i]);
	}
}
void FitnessAppWrapper::storeWeeklyExercisePlan(fstream &fileStream, ExercisePlan arr[])
{
	/*/
		This method goes through each Exercise plan in the arr and calls storeDailyExercisePlan.
		storeDailyExercisePlan writes all the data to the .txt files
	*/
	for (int i = 0; i < 7; i++)
	{
		storeDailyExercisePlan(fileStream, arr[i]);
	}
}
void FitnessAppWrapper::displayMenu(void)
{
	cout << "1. Load weekly diet plan from file." << endl;
	cout << "2. Load weekly exercise plan from file." << endl;
	cout << "3. Store weekly diet plan from file." << endl;
	cout << "4. Store weekly exercise plan from file." << endl;
	cout << "5. Display weekly diet plan from file." << endl;
	cout << "6. Display weekly exercise plan from file." << endl;
	cout << "7. Edit daily diet plan from file." << endl;
	cout << "8. Edit daily exercise plan from file." << endl;
	cout << "9. Exit" << endl;
}

