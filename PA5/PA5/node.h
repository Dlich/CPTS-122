#include "data.h"

class QueueNode
{
public: // Member functions
	QueueNode(Data &pData);
	~QueueNode();
	Data *getData();
	QueueNode *getNext();
	void setData(Data *pData);
	void setNext(QueueNode *pNext);


private:
	Data *pData;
	QueueNode *pNext;
};