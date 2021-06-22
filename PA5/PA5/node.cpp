#include "node.h"

QueueNode::QueueNode(Data &pData)
{
	this->pData = new Data(pData);
	this->pNext = nullptr;
}
QueueNode::~QueueNode()
{

}
Data *QueueNode::getData()
{
	return this->pData;
}
QueueNode *QueueNode::getNext()
{
	return this->pNext;
}
void QueueNode::setData(Data *pData)
{
	this->pData = pData;
}
void QueueNode::setNext(QueueNode *pNext)
{
	this->pNext = pNext;
}