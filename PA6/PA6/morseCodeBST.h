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

#include "BSTNode.h"
class BST
{
public:
	BST();
	~BST();
	void insert(string code, char character);
	void print();
	string search(char character);
private:
	BSTNode *root;
	void insert(BSTNode *pTemp, string code, char character); // helper function to insert a new BSTNode into the BST
	void print(BSTNode *root); // helper function to print out the BST
	string search(BSTNode *root, char character); // helper function to through the BST and find the corresponding character
	void Destroy(BSTNode *pTemp); // helper function that recursively deletes all nodes
};

void runApp();