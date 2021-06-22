/*******************************************************************************
* Programmer: Daniel Lichtchouk                                                *
* Class: CptS 122; Lab Section 12                                              *
* Programming Assignment: PA6                                                  *
* Date: 3/28/19                                                                *
*                                                                              *
* Description: This program translates English into Morse Code using           *
*              a Binary Search Tree to store the character value and           *
*			   corresponding Morse Code Value.								   *
*                                                                              *
*																		       *
*                                                                              *
*******************************************************************************/

#include "morseCodeBST.h"
#include <iostream>
#include <fstream>

BST::BST()
{
	/*
		The constructor opens the Morse Code table and inserts a new node into the BST
	*/
	std::fstream input;
	input.open("MorseTable.txt");
	string line = "";
	getline(input, line);
	root = nullptr;
	while (line.length() != 0) // ends once their is a empty line
	{
		string temp = line.substr(0, line.find('\t')); // Extracts the string character 
		char c = temp.at(0); // converts the string into a char
		string other = line.substr(line.rfind('\t')+1, line.find('\n')); // Extracts the morse code string
		insert(other, c); // calls insert which creates a new BSTNode with the corresping morse code and character and inserts the Node into the BST
		getline(input, line);
	}
	input.close();
}
BST::~BST()
{
	Destroy(root); // deletes all nodes in the BST
}
void BST::insert(string code, char character)
{
	insert(root, code, character);
}
void BST::print()
{
	print(root);
}
string BST::search(char character)
{
	return search(root, character);
}
void BST::insert(BSTNode *pTemp, string code, char character)
{
	if (pTemp == nullptr) // if BST is Empty then then we set the root to the new BSTNode
	{
		this -> root = new BSTNode(character, code);
	}
	else // otherwise we iterate through the BST until we find a spot to insert the new Node
	{
		if (character < pTemp->getChar()) // 
		{
			if (pTemp->getLeft() != nullptr) // to make sure we don't enter a null Node
			{
				insert(pTemp->getLeft(), code, character); // recursively calls insert until it finds a spot to create a new Node
			}
			else
			{
				BSTNode *data = new BSTNode(character, code);
				pTemp->setLeft(data); // sets the left child the the current Node to the new Data
			}
		}
		else
		{
			if (pTemp->getRight() != nullptr) // to make sure we don't enter a null Node
			{
				insert(pTemp->getRight(), code, character); // recursively calls insert until it finds a spot to create a new Node
			}
			else
			{
				BSTNode *data = new BSTNode(character, code);
				pTemp->setRight(data); // sets the left child the the current Node to the new Data
			}
		}
	}
}
void BST::print(BSTNode *root)
{
	//prints the nodes in-order

	if (root != nullptr)
	{
		print(root->getLeft());
		std::cout << "Character: " << root->getChar() << "Morse Code: " << root->getString() << std::endl;
		print(root->getRight());
	}
}
string BST::search(BSTNode *root, char character)
{
		if (root == nullptr) // if the current node is null, then we return an empty string
		{
			return "";
		}
		if (root->getChar() == character) // if the character ascii equals the current nodes ascii then we return the current nodes morse code string
		{
			return root->getString();
		}
		string t1 = search(root->getLeft(), character); // otherwise we search through the left childs 
		string t2 = search(root->getRight(), character); // otherwise we search through the right childs
		if (t1.empty() == false) // if the final string t1 is not empty, then i return t1 because it contains the corresponding morse code value
		{
			return t1;
		}
		else // otherwise i return t2
		{
			return t2;
		}
	
}
void BST::Destroy(BSTNode *pTemp)
{
	// deletes the nodes in pre-order

	if (pTemp != nullptr)
	{
		Destroy(pTemp->getLeft());
		Destroy(pTemp->getRight());
		delete pTemp;
	}
}
void runApp()
{
	BST *morseCode = new BST(); // creates new BST
	std::fstream convertFile;
	convertFile.open("Convert.txt"); // opens the file which we want to translate to morse code
	string line = "";
	getline(convertFile, line); // gets the first line of the file
	while (line.length() != 0) // looks until it hits a new line
	{
		int space = 0; // index of the space character
		string temp2 = line; // creates a new temporary string equal to the current line
		while (temp2.empty()==false) // loops until the new temporary string is empty
		{
			space = temp2.find(" "); // locates index of the space
			string temp = temp2.substr(0, space); // substrings the temporary string and creates a new string from the beginning of the word until the space
			for (int i = 0; i < temp.length(); i++) // loops through each character
			{
				char c = temp.at(i);
				if (c >= 97 && c <= 122) // if the character is a lower case value then we make it uppercase
				{
					c = toupper(c);
				}
				string ty = morseCode->search(c); // creates new string which is the morse code value
				std::cout << ty << " "; // prints out the morse code
			}
			if (space < 0) // if the space is negative then it means there are no more spaces in front of the last character, therefore we break out of the loop
			{
				break;
			}
			std::cout << "   "; // prints three spaces
			temp2 = temp2.substr(space + 1); // sub strings the temporary string to go from the space index + 1 until the end
		}

		std::cout << std::endl;
		
		getline(convertFile, line);
	}
	morseCode->~BST();
	convertFile.close();
}