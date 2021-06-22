#include "ExercisePlan.h"

ExercisePlan::ExercisePlan()
{
	// Basic constructor which doesn't do anything. This is here so visual studio doesn't give me an error because later in the program i create DietPlans without puting in parameters
	// and visual studio was not letting me do that without creating a basic constructor
}
ExercisePlan::ExercisePlan(int steps, string name, string newDate)
{
	//Constructor sets all the values

	goalSteps = steps;
	planName = name;
	date = newDate;
}
ExercisePlan::~ExercisePlan()
{
	//Destructor
}
ExercisePlan::ExercisePlan(ExercisePlan &obj)
{
	//Copy constructor takes all the values from obj parameter and sets them in the new constructor

	goalSteps = obj.getSteps();
	planName = obj.getPlanName();
	date = obj.getDate();
}
int ExercisePlan::getSteps()
{
	return goalSteps;
}
string ExercisePlan::getPlanName()
{
	return planName;
}
string ExercisePlan::getDate()
{
	return date;
}
void ExercisePlan::setSteps(int newSteps)
{
	goalSteps = newSteps;
}
void ExercisePlan::setPlanName(string newName)
{
	planName = newName;
}
void ExercisePlan::setDate(string newDate)
{
	date = newDate;
}
void ExercisePlan::editGoal()
{
	// Asks the user what they want to change the calories to and then it sets the goalCalories parameter to the new calories

	cout << "What do you want to change the steps goal to?" << endl;
	int newGoal = 0;
	cin >> newGoal;
	goalSteps = newGoal;
	
}
ostream & operator << (ostream &out, ExercisePlan &t)
{
	out << "PlanName: " << t.getPlanName() << " GoalSteps: " << t.getSteps() << " Date: " << t.getDate();
	return out;
}
istream & operator >> (istream &in, ExercisePlan &t)
{
	in >> t.getDate();
	return in;
}
