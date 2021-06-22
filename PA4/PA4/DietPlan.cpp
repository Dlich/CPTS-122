#include "DietPlan.h"

DietPlan::DietPlan()
{
	// Basic constructor which doesn't do anything. This is here so visual studio doesn't give me an error because later in the program i create DietPlans without puting in parameters
	// and visual studio was not letting me do that without creating a basic constructor
}
DietPlan::DietPlan(int newCals, string newName, string newDate)
{
	//Constructor sets all the values

	goalCalories = newCals;
	planName = newName;
	date = newDate;
}
DietPlan::~DietPlan()
{
	//Destructor
}
DietPlan::DietPlan(DietPlan &obj)
{
	//Copy constructor takes all the values from obj parameter and sets them in the new constructor
	goalCalories = obj.getCalories();
	planName = obj.getPlanName();
	date = obj.getDate();
}
int DietPlan::getCalories()
{
	return goalCalories;
}
string DietPlan::getPlanName()
{
	return planName;
}
string DietPlan::getDate()
{
	return date;
}
void DietPlan::setCalories(int cals)
{
	goalCalories = cals;
}
void DietPlan::setPlanName(string name)
{
	planName = name;
}
void DietPlan::setDate(string newDate)
{
	date = newDate;
}
void DietPlan::editGoal()
{
	// Asks the user what they want to change the calories to and then it sets the goalCalories parameter to the new calories

	cout << "What do you want to change the calories goal to?" << endl;
	int newGoal = 0;
	cin >> newGoal;
	goalCalories = newGoal;
}
ostream &operator<<(ostream &out, DietPlan &t)
{
	out << "PlanName: " << t.getPlanName() << " GoalCalories: " << t.getCalories() << " Date: " << t.getDate();
	return out;
}
istream & operator >> (istream &in, DietPlan &t)
{
	in >> t.getPlanName();
	return in;
}


