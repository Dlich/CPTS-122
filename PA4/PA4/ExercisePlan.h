#pragma once
#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cin;
using std::cout;
using std::fstream;
using std::ostream;
using std::istream;
using std::ofstream;
using std::endl;
class ExercisePlan
{
private:
	int goalSteps;
	string planName;
	string date;
public:
	ExercisePlan(); // basic constructor
	ExercisePlan(int steps, string name, string newDate); // constructor
	~ExercisePlan(); // destructor
	ExercisePlan(ExercisePlan &obj); // copy constructor
	int getSteps(); // gets the steps
	string getPlanName(); // gets the plan name
	string getDate(); // gets the date
	void setSteps(int newSteps); // sets the amount of steps
	void setPlanName(string newName); // sets the name of the plan
	void setDate(string newDate); // sets the date
	void editGoal(); // lets the user edit the goal steps
};
ostream & operator << (ostream &out, ExercisePlan &t); // overloaded stream operator
istream & operator >> (istream &in, ExercisePlan &t); // overloaded stream operator