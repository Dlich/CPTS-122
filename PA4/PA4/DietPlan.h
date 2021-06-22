#pragma once
#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cin;
using std::cout;
using std::fstream;
using std::istream;
using std::ostream;
using std::ofstream;
using std::endl;

class DietPlan
{
private:
	int goalCalories;
	string planName;
	string date;
public:
	DietPlan(); // basic constructor
	DietPlan(int newCals, string newName, string newDate); // constructor
	~DietPlan(); // destructor
	DietPlan(DietPlan &obj); // copy constructor
	int getCalories(); // gets the calories
	string getPlanName(); // gets the plan name
	string getDate(); // gets the date
	void setCalories(int cals); // sets the amount of calories
	void setPlanName(string name); // sets the name of the plan
	void setDate(string newDate); // sets the date
	void editGoal(); // lets the user edit the goal calories
};
ostream & operator << (ostream &out, DietPlan &t); // overloaded stream operator
istream & operator >> (istream &in, DietPlan &t); // overloaded stream operator