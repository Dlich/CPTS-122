#include <iostream>
#include <string>
#include "stack.h"

class Data
{
public:
	Data(int newRecordNumber = 0, int newIDNumber = 0, string newName = "", string newEmail = "", int newCredits = -1, string newProgram = "", string newLevel = "", int newAbscences = 0);
	int getRecordNumber();
	int getIdNumber();
	string getName();
	string getEmail();
	int getUnits();
	string getProgram();
	string getLevel();
	int getNumAbsences();
	string getLatestAbscence();
	void setRecordNumber(int newNumber);
	void setIdNumber(int newId);
	void setName(string newName);
	void setEmail(string newEmail);
	void setUnits(int newUnits);
	void setProgram(string newProgram);
	void setLevel(string newLevel);
	void setNumAbsences();
	void setLatestAbscence(string newDate);

	void operator = (const Data& copy);
	
private:
	int recordNumber;
	int idNumber;
	string name;
	string email;
	int units;
	string program;
	string level;
	int num_absences;
	Stack abscences;
};

Data::Data(int newRecordNumber, int newIDNumber, string newName, string newEmail, int newCredits, string newProgram, string newLevel, int newAbscences)
{
	recordNumber = newRecordNumber;
	idNumber = newIDNumber;
	name = newName;
	email = newEmail;
	units = newCredits;
	program = newProgram;
	level = newLevel;
	num_absences = newAbscences;

}
int Data::getRecordNumber()
{
	return recordNumber;
}
int Data::getIdNumber()
{
	return idNumber;
}
string Data::getName()
{
	return name;
}
string Data::getEmail()
{
	return email;
}
int Data::getUnits()
{
	return units;
}
string Data::getProgram()
{
	return program;
}
string Data::getLevel()
{
	return level;
}
int Data::getNumAbsences()
{
	return num_absences;
}

string Data::getLatestAbscence()
{
	return abscences.peek();
}
void Data::setRecordNumber(int newNumber)
{
	recordNumber = newNumber;
}
void Data::setIdNumber(int newId)
{
	idNumber = newId;
}
void Data::setName(string newName)
{
	name = newName;
}
void Data::setEmail(string newEmail)
{
	email = newEmail;
}
void Data::setUnits(int newUnits)
{
	units = newUnits;
}
void Data::setProgram(string newProgram)
{
	program = newProgram;
}
void Data::setLevel(string newLevel)
{
	level = newLevel;
}
void Data::setNumAbsences()
{
	num_absences++;
}
void Data::setLatestAbscence(string newDate)
{
	abscences.push(newDate);
}

inline void Data::operator=(const Data & copy) // Overloaded equals operator that copies over all of the information into a new data file. This retains all the data when i insert it into my list
{
	this->name = copy.name;
	this->email = copy.email;
	this->idNumber = copy.idNumber;
	this->recordNumber = copy.recordNumber;
	this->units = copy.units;
	this->program = copy.program;
	this->level = copy.level;
	this->num_absences = copy.num_absences;
	this->abscences = copy.abscences;
}
