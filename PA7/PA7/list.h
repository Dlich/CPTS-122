#include "node.h"
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
using std::fstream;
using std::cin;
using std::cout;
template <class T>
class List
{
public:
	List();
	~List();
	bool insertAtFront(T &pData);
	void printReports(int option, fstream &masterFile);
	void storeMasterList(fstream &masterFile);
	void markAbsent();
private:
	Node<T> *pHead;
	void destroyList();                        
	void destroyListHelper(Node<T> *pMem);
};
template<class T>
List<T>::~List()
{
	destroyList(); // destructor calls destroyList which deallocates all of the memory
}
template<class T>
void List<T>::destroyList()
{
	destroyListHelper(pHead); // calls helper method to not show the user we are using nodes
}
template<class T>
void List<T>::destroyListHelper(Node<T> *pMem)
{
	/*
		Recursively deletes any allocated nodes in he list
	*/
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getNext());
		delete pMem;
	}
}
template <class T>
List<T>::List()
{
	pHead = nullptr;
}
template <class T>
bool List<T>::insertAtFront(T &pData)
{
	/*
		Creates a new Node with the data of pData, and checks to see if memory was allocated
		If memory was allocated, then it sets the next of pMem to the Head and sets the head to the pMem
		This way, the node is being inserted at the front very effeciently
	*/
	Node<T> *pMem = new Node<T>(pData);
	bool success = false;
	if (pMem != nullptr)
	{
		pMem->setNext(pHead);
		pHead = pMem;
		success = true;
	}
	return success;
}
template <class T>
void List<T>::printReports(int option, fstream &masterFile)
{
	Node<T> *pCur = pHead; // starts the the beginning of the list
	if (option == 1)
	{
		while (pCur != nullptr) // goes through the entire list and prints out the student and their latest absence into the file passed in
		{
			masterFile << "Student: " << pCur->getData().getName() << " Latest Absence: " << pCur->getData().getLatestAbscence() << endl;
			pCur = pCur->getNext();
		}
	}
	else
	{
		int maxAbsences = 0;
		cout << "What is your max Absences?" << endl; // asks the user for the max absences they allow
		cin >> maxAbsences;
		while (pCur != nullptr)
		{
			if (pCur->getData().getNumAbsences() >= maxAbsences) // if the current students absences exceed the max then it prints out to the file the students name, their latest absence and the total absences.
			{
				masterFile << "Student: " << pCur->getData().getName() << " Latest Absence: " << pCur->getData().getLatestAbscence() << " Total absences: " << pCur->getData().getNumAbsences() << endl;
			}
			pCur = pCur->getNext();
		}
	}
}
template <class T>
void List<T>::storeMasterList(fstream &masterFile)
{
	/*
		Goes through the entire list and prints out to the file all the data about the student.
	*/
	Node <T> *pCur = pHead;
	masterFile << "RecordNumber,ID,Name,Email,Units,Program,Level,Number of Absences,Latest Absence" << endl;
	while (pCur != nullptr)
	{
		masterFile << pCur->getData().getRecordNumber() << ",";
		masterFile << pCur->getData().getIdNumber() << ",";
		masterFile << "\"" << pCur->getData().getName() << "\"" << ",";
		masterFile << pCur->getData().getEmail() << ",";
		if (pCur->getData().getUnits() == -1)
		{
			masterFile << "AU" << ",";
		}
		else
		{
			masterFile << pCur->getData().getUnits() << ",";
		}
		
		masterFile << pCur->getData().getProgram() << ",";
		masterFile << pCur->getData().getLevel() << ",";
		masterFile << pCur->getData().getNumAbsences() << ",";
		masterFile << pCur->getData().getLatestAbscence() << "," << endl;
		pCur = pCur->getNext();
	}
}
template <class T>
void List<T>::markAbsent()
{
	Node<T> *pCur = pHead;
	while (pCur != nullptr) // goes through entire list
	{
		int optionChosen = 0;
		cout << "Was " << pCur->getData().getName() << " Absent today? Press 1 for yes, 2 for no." << endl; // asks the user if the student was absent
		cin >> optionChosen;
		if (optionChosen == 1) // if the user says the student was absent then it gets todays date and pushes it to the stack of absences
		{

			time_t t = time(0);   // get time now
			struct tm * now = localtime(&t);
			string year = std::to_string(now->tm_year + 1900);
			string month = std::to_string(now->tm_mon + 1);
			string day = std::to_string(now->tm_mday);
			string fullDate = year + "-" + month + "-" + day;
			pCur->getData().setLatestAbscence(fullDate);
			pCur->getData().setNumAbsences();
		}
		pCur = pCur->getNext(); // goes to the next student in the list
	}
}