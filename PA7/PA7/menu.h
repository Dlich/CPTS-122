#include "list.h"
#include "data.h"
#include <fstream>
#include <sstream>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::fstream;
using std::stoi;
using std::stringstream;
using std::cin;
class Menu
{
public:
	Menu();
	~Menu();
	void printMenu();
	void RunApp();
	void importCourses(fstream &infile, List<Data> &t);
	void loadMasterList(fstream &masterFile, List<Data> &t);
	void storeMasterList(fstream &masterFile, List<Data> &t);
	void markAbsences(List<Data> &t);
	void editAbsences();
	void generateReport(fstream &masterFile, List<Data> &t);
private:

};

Menu::Menu()
{
	
}
Menu::~Menu()
{

}
void Menu::printMenu() // prints the menu for the user
{
	cout << "1. Import course list" << endl;
	cout << "2. Load master list" << endl;
	cout << "3. Store master list" << endl;
	cout << "4. Mark absences" << endl;
	cout << "5. Edit absences" << endl;
	cout << "6. Generate report" << endl;
	cout << "7. Exit" << endl;

}
void Menu::RunApp()
{
	fstream classList, masterList, reportList;
	List<Data> students; // the linked list of all the students
	classList.open("classList.csv"); // opens the original class csv file with all the students
	masterList.open("master.txt"); // opens the master class txt file with the previous nodes
	reportList.open("reports.txt"); // opens the file where the reports will be generated
	bool continueProject = true;
	while (continueProject == true)
	{
		cout << "Welcome to your gradebook. Select an option below." << endl; // asks the user to choose an option
		printMenu();
		int option = 0;
		cin >> option;
		
		
		system("CLS"); // clears screen after user
		if (option == 1)
		{
			importCourses(classList, students); // calls import courses function that reads in the students in the classList.csv file and inserts the students into the list
			cout << "Students from course list have been imported to grade book" << endl;
			
		}
		else if (option == 2)
		{
			loadMasterList(masterList, students); // loads in previous students from master.txt and inserts into the list
			cout << "Students from previous master list have been imported to grade book" << endl;

		}
		else if (option == 3)
		{
			storeMasterList(masterList, students); // stores the current list of students into master.txt
			cout << "Students have been imported to the master list file." << endl;
		}
		else if (option == 4)
		{
			markAbsences(students); // marks students absences
		}
		else if (option == 5)
		{
			editAbsences();
		}
		else if (option == 6)
		{
			generateReport(reportList, students); // generates report about students absences
		}
		else if (option == 7) // if user wants to exit then it breaks and exits the loop
		{
			break;
		}
		system("PAUSE");
		system("CLS");
	}
	classList.close();
	masterList.close();
	reportList.close();
	

}
void Menu::importCourses(fstream &infile, List<Data> &t)
{
	string line = "";
	getline(infile, line);
	getline(infile, line); // calls getline twice so it doesn't try loading in the first line in classList.csv 
	while (line.length() != 0)
	{
		string recordNumber = line.substr(0, line.find(',')); // finds the record number by substrining from the beginning to the first comma
		line = line.substr(line.find(',') + 1); // after the recordNumber is found, line gets shortened to be everything after the found comma
		int integerRecord = 0;
		stringstream rNstring(recordNumber); // creates a new stringStream which takes in recordNumber and changes it to an integer
		rNstring >> integerRecord; // reads in the string and makes it an integer

		string IDNum = line.substr(0, line.find(',')); // same as above
		line = line.substr(line.find(',') + 1); 
		int id = 0;
		stringstream IDstring(IDNum);
		IDstring >> id;

		string firstname = line.substr(0, line.find(',')); // finds the last name
		line = line.substr(line.find(',')+1);
		string secondname = line.substr(0, line.find(',')); // finds the first name
		line = line.substr(line.find(',') + 1);
		string name = firstname + "," + secondname; // adds them together with a comma
		name = name.substr(1, name.length()-2); // substrings the full name to get rid of the quotes
		
		string email = line.substr(0, line.find(',')); 
		line = line.substr(line.find(',') + 1);
		
		string credits = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		
		string program = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);

		string level = line; // the final line is just the level so i dont need to substring anythng
		
		int potentialCredits = -1;
		if (credits.compare("AU") != 0) // checks to see if the credits are not AU. If the credits are a number then it converts the string into an integer and sets potentialCredits to that number
		{
			stringstream creditsStream(credits);
			creditsStream >> potentialCredits;
		}
		Data d(integerRecord, id, name, email, potentialCredits, program, level, 0); // creates a new data object with all the information
		t.insertAtFront(d); // inserts the new node at the front
		getline(infile, line);
	}


}
void Menu::loadMasterList(fstream &masterFile, List<Data> &t)
{
	/*
		Same as the importCourses function except it also extracts the number of absences and the latest absence.
		It adds that to the new node and inserts it at the front of the list
	*/
	string line = "";
	getline(masterFile, line);
	getline(masterFile, line);
	while (line.length() != 0)
	{
		string recordNumber = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		int integerRecord = 0;
		stringstream rNstring(recordNumber);
		rNstring >> integerRecord;

		string IDNum = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		int id = 0;
		stringstream IDstring(IDNum);
		IDstring >> id;

		string firstname = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		string secondname = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		string name = firstname + "," + secondname;
		name = name.substr(1, name.length() - 2);



		string email = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);

		string credits = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);

		string program = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);

		string level = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);

		string numberAbsences = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		int absences = 0;
		stringstream AbsencesString(numberAbsences);
		AbsencesString >> absences;

		string latestAbsence = line;

		int potentialCredits = -1;
		if (credits.compare("AU") != 0)
		{
			stringstream creditsStream(credits);
			creditsStream >> potentialCredits;
		}
		Data d(integerRecord, id, name, email, potentialCredits, program, level, absences);
		d.setLatestAbscence(latestAbsence);
		t.insertAtFront(d);

		getline(masterFile, line);
	}
}
void Menu::storeMasterList(fstream &masterFile, List<Data> &t)
{
	t.storeMasterList(masterFile); // calls storeMasterList
}
void Menu::editAbsences()
{
	
}
void Menu::generateReport(fstream &masterFile, List<Data> &t)
{
	int optionChosen = 0;
	cout << "1. Report for all students" << endl;
	cout << "2. Generate report for students with absences that match or exceed your limit" << endl;
	cin >> optionChosen; // gets which option the user wants to do
	if (optionChosen == 1)
	{
		t.printReports(1, masterFile); // calls printreport with option 1
	}
	else
	{
		t.printReports(2, masterFile); // calls printReport with option 2
	}
	
}
void Menu::markAbsences(List<Data> &t)
{
	t.markAbsent(); // calls markAbsent 
}
