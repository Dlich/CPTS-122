#include "testFunctions.h"

void insertTestFunction(void)
{
	Node *pHead = NULL;
	insertNewSong(&pHead);
	// the way my insertNewSong works is that i ask the user for input and they type it in
	// I tested my insertNewSong function by calling it and typing in what Andy said to type in on PA3 Specification
	
}
void deleteTestFunction(void)
{
	Node *pHead = NULL;
	insertNewSong(&pHead);
	deleteRecord(&pHead);

	//deleteRecord asks the user for which song they want to delete and then searches through the list, finds it and deletes it.
}
void shuffleTestFunction(void)
{
	Node *pHead = NULL;
	int order[3] = { 3,1,2 };
	insertNewSong(&pHead);
	insertNewSong(&pHead);
	insertNewSong(&pHead);
	shuffle(pHead, order, 3);

}