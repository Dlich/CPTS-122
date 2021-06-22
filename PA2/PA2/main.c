#include "manager.h"

int main(void)
{
	FILE *infile = NULL, *outfile = NULL;
	Node *pHead = NULL;
	srand(time(NULL));
	
	int stopLoop = 0;
	while (stopLoop == 0)
	{
		int option = 0;
		printf("Hello! This is a Digital Music Manager!\n");
		printf("Choose an option below to begin using this program!\n");
		printf("Make sure to select load the tracks in from the file into the program!\n");
		mainMenu();
		scanf("%d", &option);
		if (option == 1)
		{
			system("cls");
			load(infile, &pHead);
			printf("Successfully Loaded tracks into the Manager!\n\n");
		}
		else if (option == 2)
		{
			system("cls");
			store(outfile, pHead);
			printf("Successfully stored tracks into musciPlayList.csv!\n\n");
		}
		else if (option == 3)
		{
			system("cls");
			printf("Would you like to print all records or just the records for an artist? Press 1 for all, 2 for a specific artist.\n");
			int option = 0;
			scanf("%d", &option);
			display(pHead, option);
		}
		else if (option == 4)
		{
			system("cls");
			insertNewSong(&pHead);
			printf("Successfully Inserted new track into the manager!\n\n");
		}
		else if (option == 5)
		{
			system("cls");
			deleteRecord(&pHead);
			printf("Successfully Deleted track from the manager!\n\n");
		}
		else if (option == 6)
		{
			system("cls");
			edit(&pHead);
		}
		else if (option == 7)
		{
			system("cls");
			sort(&pHead);
			printf("Successfully Sorted tracks in the manager!\n\n");
		}
		else if (option == 8)
		{
			system("cls");
			rate(&pHead);
		}
		else if (option == 9)
		{
			char song[100] = "";
			int n = 10;
			system("cls");
			play(pHead, song, n);
		}
		else if (option == 10)
		{
			system("cls");
			int len = listLen(pHead);
			int order[100] = { 0 };
			for (int i = 0; i < len; i++)
			{
				order[i] = rand() % len + 1;
			}
			shuffle(pHead, order, len);
		}
		else if (option == 11)
		{
			system("cls");
			stopLoop = exitProgram(outfile, pHead);
		}
	}
	
	return 0;
}