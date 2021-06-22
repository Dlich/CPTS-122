#include "manager.h"

void mainMenu(void)
{
	printf("(1) load\n");
	printf("(2) store\n");
	printf("(3) display\n");
	printf("(4) insert\n");
	printf("(5) delete\n");
	printf("(6) edit\n");
	printf("(7) sort\n");
	printf("(8) rate\n");
	printf("(9) play\n");
	printf("(10) shuffle\n");
	printf("(11) exit\n");
}
Node *makeNode(Record r)
{
	Node *temp = NULL;
	temp = (Node *)malloc(sizeof(Node));
	if (temp != NULL)
	{
		temp->data.rating = r.rating;
		temp->data.songsPlays = r.songsPlays;
		temp->data.songLength.minutes = r.songLength.minutes;
		temp->data.songLength.seconds = r.songLength.seconds;
		strcpy(temp->data.artist, r.artist);
		strcpy(temp->data.album, r.album);
		strcpy(temp->data.songTitle, r.songTitle);
		strcpy(temp->data.genre, r.genre);
		temp->pPrev = NULL;
		temp->pNext = NULL;
	}
	return temp;
}

int insertAtFront(Node **pHead, Record r)
{
	Node *pTemp = NULL;
	pTemp = makeNode(r);
	int success = 0;
	if (pTemp != NULL)
	{
		success = 1;
		pTemp->pNext = *pHead;
		if (!isEmpty(*pHead))
		{
			(*pHead)->pPrev = pTemp;
		}
		*pHead = pTemp;
		
	}
	return success;
}

int isEmpty(Node *pList)
{
	return (pList == NULL);
}

void load(FILE *infile, Node **pHead)
{
	/*
		This method goes through each line and splits the part up based on commas and semi-colons
		It then adds them all to a record and inserts the record at the front of the list
	*/
	infile = fopen("musicPlayList.csv", "r");
	while (!feof(infile))
	{
		char line[100] = "";
		fgets(line, 100, infile);
		char *pch;
		pch = strtok(line, ",:");
		int temp = 0;
		Record tempRecord = { 0 };
		while (pch != NULL)
		{
			if (temp == 0)
			{
				strcpy(tempRecord.artist, pch);
				if (strstr(pch, "\"") != NULL)
				{
					pch = strtok(NULL, ",:");
					strcat(tempRecord.artist, ",");
					strcat(tempRecord.artist, pch);
				}
			}
			else if (temp == 1)
			{
				strcpy(tempRecord.album, pch);
			}
			else if (temp == 2)
			{
				strcpy(tempRecord.songTitle, pch);
			}
			else if (temp == 3)
			{
				strcpy(tempRecord.genre, pch);
			}
			else if (temp == 4)
			{
				int min = atoi(pch);
				tempRecord.songLength.minutes = min;
			}
			else if (temp == 5)
			{
				int sec = atoi(pch);
				tempRecord.songLength.seconds = sec;
			}
			else if (temp == 6)
			{
				int plays = atoi(pch);
				tempRecord.songsPlays = plays;
			}
			else if (temp == 7)
			{
				int rate = atoi(pch);
				
				tempRecord.rating = rate;
				
			}

			temp++;
			pch = strtok(NULL, ",:");
		}
		int i = insertAtFront(pHead, tempRecord);
	}
	fclose(infile);
}
void store(FILE *infile, Node *pHead)
{
	/*
		This function starts at the beginning of the list and goes through everything in the list.
		It then prints everything into musicPlayList.csv
	*/
	Node *pTemp = pHead;
	infile = fopen("musicPlayList.csv", "w");
	while (pTemp != NULL)
	{
		fputs(pTemp->data.artist, infile);
		fputc(',', infile);
		fputs(pTemp->data.album, infile);
		fputc(',', infile);
		fputs(pTemp->data.songTitle, infile);
		fputc(',', infile);
		fputs(pTemp->data.genre, infile);
		fprintf(infile, ",%d:%d,%d,%d", pTemp->data.songLength.minutes, pTemp->data.songLength.seconds, pTemp->data.songsPlays, pTemp->data.rating);
		if (pTemp->pNext != NULL)
		{
			fprintf(infile, "\n");
		}
		pTemp = pTemp->pNext;
	}
	fclose(infile);
}
void display(Node *pHead, int option)
{
	/*
		This function checks to see which option the user chooses. If the user chooses 1, then it prints out the details of every record.
		If the user chooses 2, then it prints out all the songs from the artist the user chose.
	*/
	Node *pTemp = pHead;
	if (option == 1)
	{
		while (pTemp != NULL)
		{
			printf("Artist: %s ", pTemp->data.artist);
			printf("Album Title: %s ", pTemp->data.album);
			printf("Song Title: %s ", pTemp->data.songTitle);
			printf("Genre: %s ", pTemp->data.genre);
			printf("Song Length: %d:%d ", pTemp->data.songLength.minutes, pTemp->data.songLength.seconds);
			printf("Times Played: %d ", pTemp->data.songsPlays);
			printf("Rating: %d", pTemp->data.rating);
			printf("\n");
			pTemp = pTemp->pNext;
		}
	}
	else
	{
		printf("What artist would you like to see all of the songs from?\n");
		char artist[100];
		int c;
		while ((c = getchar()) != EOF && c != '\n'); // this makes sure that the program cuts out \t and doesn't register the new line.
		gets(artist);

		while (pTemp != NULL)
		{
			if (strstr(pTemp->data.artist, artist) != NULL)
			{
				printf("%s\n\n", pTemp->data.songTitle);
			}
			pTemp = pTemp->pNext;
		}
	}
}

int exitProgram(FILE *infile, Node *pHead)
{
	/*
		Stores and returns 1 which lets me know the user wants to end
	*/
	store(infile, pHead);
	return 1;
}
void edit(Node **pHead)
{
	printf("What artist would you like to search for?\n");
	char artist[100];
	int c;
	while ((c = getchar()) != EOF && c != '\n');
	gets(artist);
	Node *pTemp = *pHead;
	int option = 0;
	while (pTemp != NULL)
	{
		if (strstr(pTemp->data.artist, artist) != NULL)
		{
			printf("Do you want to change the Artist? Type 1 for yes, 2 for no.\n");
			scanf("%d", &option); 
			if (option == 1)
			{
				printf("What is the name of the new Artist?\n");
				char newArtist[100] = "";
				int c;
				while ((c = getchar()) != EOF && c != '\n');
				gets(newArtist);
				strcpy(pTemp->data.artist, newArtist);
			}
			printf("Do you want to change the Song Name? Type 1 for yes, 2 for no.\n");
			scanf("%d", &option);
			if (option == 1)
			{
				printf("What is the name of the new Song?\n");
				char newSong[100] = "";
				int c;
				while ((c = getchar()) != EOF && c != '\n');
				gets(newSong);
				strcpy(pTemp->data.songTitle, newSong);
			}
			printf("Do you want to change the Songs Played? Type 1 for yes, 2 for no.\n");
			scanf("%d", &option);
			if (option == 1)
			{
				printf("How many song plays would you like to change it to?\n");
				int plays = 0;
				scanf("%d", &plays);
				pTemp->data.songsPlays = plays;
			}
			printf("Do you want to change the Album? Type 1 for yes, 2 for no.\n");
			scanf("%d", &option);
			if (option == 1)
			{
				printf("What is the name of the new Album\n");
				char newAlbum[100] = "";
				int c;
				while ((c = getchar()) != EOF && c != '\n');
				gets(newAlbum);
				strcpy(pTemp->data.album, newAlbum);
			}
			printf("Do you want to change the Genre? Type 1 for yes, 2 for no.\n");
			scanf("%d", &option);
			if (option == 1)
			{
				printf("What is the name of the new Genre?\n");
				char newGenre[100] = "";
				int c;
				while ((c = getchar()) != EOF && c != '\n');
				gets(newGenre);
				strcpy(pTemp->data.genre, newGenre);
			}
			printf("Do you want to change the Minutes? Type 1 for yes, 2 for no.\n");
			scanf("%d", &option);
			if (option == 1)
			{
				printf("How many minutes would you like to change it to?\n");
				int minutes = 0;
				scanf("%d", &minutes);
				pTemp->data.songLength.minutes = minutes;
			}
			printf("Do you want to change the Seconds? Type 1 for yes, 2 for no.\n");
			scanf("%d", &option);
			if (option == 1)
			{
				printf("How many seconds would you like to change it to?\n");
				int seconds = 0;
				scanf("%d", &seconds);
				pTemp->data.songLength.seconds = seconds;
			}
			printf("Do you want to change the Rating? Type 1 for yes, 2 for no.\n");
			scanf("%d", &option);
			if (option == 1)
			{
				printf("What rating would you like to change it to?\n");
				int rating = 0;
				scanf("%d", &rating);
				pTemp->data.rating = rating;
			}
			break;
		}
		pTemp = pTemp->pNext;
	}
}
void rate(Node **pHead)
{
	printf("What song would you like to change the rating for?\n");
	char song[100];
	int c;
	while ((c = getchar()) != EOF && c != '\n');
	gets(song);
	Node *pTemp = *pHead;
	while (pTemp != NULL)
	{
		if (strstr(pTemp->data.songTitle, song) != NULL)
		{
			printf("What rating would you like to assign?\n");
			int tempRating = 0;
			scanf("%d", &tempRating);
			while (tempRating > 5 || tempRating <= 0)
			{
				printf("Please choose a rating between 1 and 5!\n");
				scanf("%d", &tempRating);
			}
			pTemp->data.rating = tempRating;
			break;
		}
		pTemp = pTemp->pNext;
	}
}
void play(Node *pHead, char *song, int n)
{
	Node *pTemp = pHead;
	if (n == 0)
	{
		while (pTemp != NULL)
		{
			if (strcmp(pTemp->data.songTitle, song) == 0)
			{
				printf("Artist: %s \n", pTemp->data.artist);
				printf("Album Title: %s \n", pTemp->data.album);
				printf("Song Title: %s \n", pTemp->data.songTitle);
				printf("Genre: %s ", pTemp->data.genre);
				printf("Song Length: %d:%d \n", pTemp->data.songLength.minutes, pTemp->data.songLength.seconds);
				printf("Times Played: %d \n", pTemp->data.songsPlays);
				printf("Rating: %d \n", pTemp->data.rating);
				Sleep(3000);
				system("cls");
				break;
			}
			pTemp = pTemp->pNext;
		}
	}
	else
	{
		char song[100] = "";
		int n2 = 1;
		printf("What song would you like to start from?");
		int c;
		while ((c = getchar()) != EOF && c != '\n');
		gets(song);
		Node *pTemp = pHead;
		while (pTemp != NULL)
		{
			if (strstr(pTemp->data.songTitle, song) != NULL)
			{
				break;
			}
			n2++;
			pTemp = pTemp->pNext;
		}
		int temp = n2;
		while ((temp != 0 || temp != 1) && pTemp != NULL)
		{
			printf("Artist: %s \n", pTemp->data.artist);
			printf("Album Title: %s \n", pTemp->data.album);
			printf("Song Title: %s \n", pTemp->data.songTitle);
			printf("Genre: %s \n", pTemp->data.genre);
			printf("Song Length: %d:%d \n", pTemp->data.songLength.minutes, pTemp->data.songLength.seconds);
			printf("Times Played: %d \n", pTemp->data.songsPlays);
			printf("Rating: %d \n", pTemp->data.rating);
			printf("\n");
			pTemp = pTemp->pNext;
			Sleep(3000);
			system("cls");
			temp--;
		}
		pTemp = pHead;
		for (int i = 1; i < n2; i++)
		{
			printf("Artist: %s \n", pTemp->data.artist);
			printf("Album Title: %s \n", pTemp->data.album);
			printf("Song Title: %s \n", pTemp->data.songTitle);
			printf("Genre: %s \n", pTemp->data.genre);
			printf("Song Length: %d:%d \n", pTemp->data.songLength.minutes, pTemp->data.songLength.seconds);
			printf("Times Played: %d \n", pTemp->data.songsPlays);
			printf("Rating: %d \n", pTemp->data.rating);
			printf("\n");
			pTemp = pTemp->pNext;
			Sleep(3000);
			system("cls");
		}
	}
}

void insertNewSong(Node **pHead)
{
	char song[100] = "", album[100], genre[100], artist[100];
	int rating = 0, minutes = 0, seconds = 0, numPlayed = 0;
	Record r = { 0 };
	printf("Who is the artist?\n");
	int c;
	while ((c = getchar()) != EOF && c != '\n');
	gets(artist);
	printf("What album?\n");
	gets(album);
	printf("What is the name of the song?\n");

	gets(song);
	printf("What genre?\n");
	
	gets(genre);
	printf("How many minutes is the song?\n");
	scanf("%d", &minutes);
	printf("How many seconds is the song?\n");
	scanf("%d", &seconds);
	while (seconds < 0 || seconds > 59)
	{
		printf("Please choose seconds between 0 and 59!\n");
		scanf("%d", &seconds);
	}
	printf("How many times played?\n");
	scanf("%d", &numPlayed);
	while (numPlayed < 0)
	{
		printf("Please choose a valid number for times played!\n");
		scanf("%d", &numPlayed);
	}
	printf("What is the rating?\n");
	scanf("%d", &rating);
	while (rating <= 0 || rating > 5)
	{
		printf("Please choose a rating between 1 and 5!\n");
		scanf("%d", &rating);
	}
	strcpy(r.album, album);
	strcpy(r.artist, artist);
	strcpy(r.songTitle, song);
	strcpy(r.genre, genre);
	r.rating = rating;
	r.songsPlays = numPlayed;
	r.songLength.minutes = minutes;
	r.songLength.seconds = seconds;
	insertAtFront(pHead, r);

}

void deleteRecord(Node **pHead)
{
	char song[100];
	printf("What song would you like to delete?\n");
	int c;
	while ((c = getchar()) != EOF && c != '\n');
	gets(song);
	Node *pTemp = *pHead;

	while (pTemp != NULL)
	{
		if (strstr(pTemp->data.songTitle, song) != NULL)
		{
			if (pTemp->pPrev == NULL)
			{
				*pHead = pTemp->pNext;
				pTemp->pNext->pPrev = NULL;
			}
			else if (pTemp->pNext == NULL)
			{
				pTemp->pPrev->pNext = pTemp->pNext;
			}
			else
			{
				pTemp->pNext->pPrev = pTemp->pPrev;
				pTemp->pPrev->pNext = pTemp->pNext;
			}
			free(pTemp);
			break;
		}
		pTemp = pTemp->pNext;
	}
}
void sort(Node **pHead)
{
	/*
		Same algorithm as selection sort except its for linked lists. This algorithm changes the data of the lists without changing the links which helps me not break the data.
	*/
	printf("How would like to sort?");
	printf(" Press 1 to sort by artist(A-Z), press 2 to sort by album(A-Z), press 3 to sort by rating (1-5) or press 4 to sort by times played(largest-smallest).\n");
	int option = 0;
	scanf("%d", &option);
	Node *pTemp = *pHead, *pTemp2 = *pHead;
	Node *pMin = NULL;
	while (pTemp != NULL)
	{
		pMin = pTemp;
		pTemp2 = pTemp;
		while (pTemp2 != NULL)
		{
			if (option == 1)
			{
				char tempString1[100] = "", tempString2[100] = "";
				strcpy(tempString1, pMin->data.artist);
				strcpy(tempString2, pTemp2->data.artist);
				stringBuilder(tempString1);
				stringBuilder(tempString2);
				if (strcmp(tempString1, tempString2) > 0)
				{
					pMin = pTemp2;
				}
			}
			else if (option == 2)
			{
				if (strcmp(pMin->data.album, pTemp2->data.album) > 0)
				{
					pMin = pTemp2;
				}
			}
			else if (option == 3)
			{
				if (pMin->data.rating > pTemp2->data.rating)
				{
					pMin = pTemp2;
				}
			}
			else if (option == 4)
			{
				if (pMin->data.songsPlays < pTemp2->data.songsPlays)
				{
					pMin = pTemp2;
				}
			}
			pTemp2 = pTemp2->pNext;
		}
		Node *pTemp3 = NULL;
		pTemp3 = makeNode(pTemp->data);
		pTemp->data = pMin->data;
		pMin->data = pTemp3->data;
		pTemp = pTemp->pNext;
	}
}

void stringBuilder(char str[])
{
	/*
		This functions checks to see if the string entered has quotations. If it does then it rebuilds the string.
		It chops off the quotations and rebuilds the string to be lastname,firstname. This lets me sort the list alphabetically much easily.
	*/
	if (strstr(str, "\""))
	{
		char *pch;
		char fullName[100] = "";
		char fn[100] = "";
		char ln[100] = "";
		pch = strtok(str, ", \"");
		strcpy(ln, pch);
		pch = strtok(NULL, ", \"");
		strcpy(fn, pch);
		strcat(fullName, ln);
		strcat(fullName, " ");
		strcat(fullName, fn);
		strcpy(str, fullName);
	}
	
	

}

void shuffle(Node *pHead, int order[], int len)
{
	int temp = order[0];
	Node *pTemp = pHead;
	for (int i = 0; i < len; i++)
	{
		int temp2 = order[i];
		if (temp2 > temp)
		{
			while (temp2 > temp && pTemp != NULL)
			{
				temp2--;
				pTemp = pTemp->pPrev;
			}
			play(pHead, pTemp->data.songTitle, 0);
		}
		else
		{
			while (temp2 < temp && pTemp != NULL)
			{
				temp2++;
				pTemp = pTemp->pNext;
			}
			play(pHead, pTemp->data.songTitle, 0);
		}
		temp = order[i];

	}
}

int listLen(Node *pHead)
{
	int items = 0;
	Node *pTemp = pHead;
	while (pTemp != NULL)
	{
		items++;
		pTemp = pTemp->pNext;
	}
	return items;
}

