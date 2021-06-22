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

BSTNode::BSTNode(char engChar, string morseCodeString)
{
	character = engChar;
	morseCode = morseCodeString;
	right = nullptr;
	left = nullptr;
}
BSTNode::~BSTNode()
{

}
char BSTNode::getChar()
{
	return character;
}
string BSTNode::getString()
{
	return morseCode;
}
BSTNode *BSTNode::getRight()
{
	return right;
}
BSTNode *BSTNode::getLeft()
{
	return left;
}
void BSTNode::setChar(char newChar)
{
	character = newChar;
}
void BSTNode::setString(char newString)
{
	morseCode = newString;
}
void BSTNode::setRight(BSTNode *newRight)
{
	right = newRight;
}
void BSTNode::setLeft(BSTNode *newLeft)
{
	left = newLeft;
}