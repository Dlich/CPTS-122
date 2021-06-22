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

#include <iostream>
#include <string>

using std::string;
class BSTNode
{
public:
	BSTNode(char engChar = '\0', string morseCodeString = "");
	~BSTNode();
	char getChar();
	string getString();
	BSTNode *getRight();
	BSTNode *getLeft();
	void setChar(char newChar);
	void setString(char newString);
	void setRight(BSTNode *newRight);
	void setLeft(BSTNode *newLeft);

private:
	char character;
	string morseCode;
	BSTNode *right;
	BSTNode *left;
};