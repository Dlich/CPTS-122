#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
typedef struct duration
{
	int minutes;
	int seconds;
}Duration;

typedef struct record
{
	char artist[100];
	char album[100];
	char songTitle[100];
	char genre[100];
	Duration songLength;
	int songsPlays;
	int rating;
}Record;


typedef struct node
{
	Record data;
	struct node *pNext;
	struct node *pPrev;
}Node;

void load(FILE *infile, Node **pHead);
Node *makeNode(Record r);
int insertAtFront(Node **pHead, Record r);
void store(FILE *infile, Node *pHead);
void display(Node *pHead, int option);
int isEmpty(Node *pList);
int exitProgram(FILE *infile, Node *pHead);
void mainMenu(void);
void edit(Node **pHead);
void rate(Node **pHead);
void play(Node *pHead, char *song, int n);
void insertNewSong(Node **pHead);
void deleteRecord(Node **pHead);
void sort(Node **pHead);
void stringBuilder(char str[]); // helper function that rebuilds the string for me
void shuffle(Node *pHead, int order[], int len);
int listLen(Node *pHead); // helper function to find length of the list
