

template <class T>
class Node
{
public:
	Node(T &pNewData);
	T &getData();
	Node <T> *getNext();
	void setData(T &newData);
	void setNext(Node<T> *pNewNext);

private:
	T mpData;
	Node<T> *pNext;
};
template <class T>
Node<T>::Node(T &pNewData)
{
	mpData = pNewData;
	pNext = nullptr;
}
template<class T>
T& Node<T>::getData()
{
	return mpData;
}
template<class T>
Node <T> *Node<T>::getNext()
{
	return this->pNext;
}
template<class T>
void Node<T>::setData(T &newData)
{
	*(this->mpData) = newData;
}
template<class T>
void Node<T>::setNext(Node<T> *pNewNext)
{
	this->pNext = pNewNext;
}