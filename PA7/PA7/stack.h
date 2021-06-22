#define MaxSize 1000
#include <string>
using std::string;
class Stack
{
public:
	Stack();
	void push(string newString);
	string pop();
	string peek();
	bool isEmpty();
private:
	string arr[MaxSize];
	int topStack;
};

Stack::Stack()
{
	topStack = -1;
}
void Stack::push(string newString)
{
	/*
		Increments the top index and then inserts the new string into the array at the top
	*/
	arr[++topStack] = newString;
}
string Stack::pop()
{
	/*
		Sets a new string to the string at the top of the stack, decrements the index for the top and returns that string.
	*/
	string t = arr[topStack];
	topStack--;
	return t;
}
bool Stack::isEmpty() // if the top index is -1, then it means there is noting in there so it returns true, otherwise it returns false
{
	if (topStack == -1)
	{
		return true;
	}
	return false;
}
string Stack::peek() // returns the string at the top of the stack
{
	return arr[topStack];
}
