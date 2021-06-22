#include "node.h"

class Queue
{
public: // Member functions
	Queue();
	~Queue();
	bool enqueue(Data &pData);
	Data *dequeue();
	Data *peek(); // added a peek function so i can see the data in the first node without dequeing the node
	int size();
	void print();
private:
	QueueNode *pHead;
	QueueNode *pTail;
};

void runApp(int min); // runs the program, is called from main