/*
	PSA!!!!!!!!

	I APOLOGIZE IN ADVANCE FOR THE CODE. THERE ARE A LOT OF VARIABLES THAT I DIDN'T END UP USING AND I WAS RUNNING OUT OF TIME TO SUBMIT THIS PROJECT
	SO I WASNT ABLE TO GET RID OF THOSE UNUSED VARIABLES! I'M SORRY AGAIN!
*/


#include "queue.h"
#include "cstdlib"
using std::cout;
using std::endl;
using std::rand;
Queue::Queue()
{
	this->pHead = nullptr;
	this->pTail = nullptr;
}
Queue::~Queue()
{

}
bool Queue::enqueue(Data &pData)
{
	// I create and allocate memory for a new node with the data passed in
	QueueNode *pMem = new QueueNode(pData);
	bool success = false;
	if (pMem != nullptr) // check to make sure pMem memory was actually allocated
	{
		success = true;
		if (this->pHead == nullptr) // if queue is originally empty i set both the head and tail to the node
		{
			this->pHead = pMem;
			this->pTail = pMem;
		}
		else
		{
			this->pTail->setNext(pMem);
			this->pTail = pMem;
		}
	}
	return success;
}
Data *Queue::dequeue()
{
	Data *value;
	QueueNode *pTemp = nullptr;
	if (this->pHead == this->pTail) // check to see if there is one one thing in the queue
	{
		/*
			Set both pointers to null because there is only 1 node in the queue
		*/
		pTemp = this->pHead;
		this->pHead = nullptr;
		this->pTail = nullptr;
		value = pTemp->getData(); // set value to pTemps value
		delete pTemp; // deallocate memory for pTemp
	}
	else
	{
		/*
			otherwise i set the head pointer to its next pointer and deallocate memory for the head to remove the item from the queue
		*/
		pTemp = this->pHead;
		this->pHead = this->pHead->getNext();
		value = pTemp->getData();
		delete pTemp;
	}
	return value;
}
Data *Queue::peek()
{
	if (this->pHead != nullptr) // i make sure to checm to see that that the list is not empty and if it is i return a nullptr
	{
		/*
			returns the data from the head pointer without removing the node
		*/
		Data *value;
		QueueNode *pTemp = nullptr;
		pTemp = this->pHead;
		value = pTemp->getData();
		return value;
	}
	return nullptr;
}
int Queue::size()
{
	int items = 0;
	QueueNode *pTemp = nullptr;
	pTemp = this->pHead;
	while (pTemp != nullptr)
	{
		items++;
		pTemp = pTemp->getNext();
	}
	return items;
}
void Queue::print()
{
	QueueNode *pTemp = nullptr;
	pTemp = this->pHead;
	while (pTemp != nullptr)
	{
		cout << "Customer Number: " << pTemp->getData()->getCustomerNumber();
		cout << " Service Time: " << pTemp->getData()->getServiceTime();
		cout << " Total Time: " << pTemp->getData()->getTotalTime() << endl;
		pTemp = pTemp->getNext();
	}
}
void runApp(int min)
{
	Queue express, normal; // define two queues, one for express lane and one for the normal lane
	int totalTime = 1, uniqueIdentifier = 1, curExpressServiceTime = 0, curNormalServiceTime = 0, curCustomerExpressTime = 0, curCustomerNormalTime = 0, arrival1 = 0, arrival2 = 0, expressWaitTime = -1, normalWaitTime = -1;

	arrival1 = rand() % 5 + 1; // time for the first arrival in the express lane
	arrival2 = rand() % 8 + 3; // time for th first arrival in the normal lane
	int tempServiceTime = 0;
	int nextCustomerArrival = 0;
	int nextCustomerArrivalTracker = 0;
	int expresssizetracker = 0;
	int normalsizetracker = 0;
	while (totalTime <= min) // the program runs until min which is the ammount of minutes the user inputs
	{
		if (totalTime == arrival1) 
		{
			/*
				Checks to see if the arrival time of the first express lane customer is equal to the current min
				if it is, then i create a new Data object and enqueue it into the express queue
				afterwards i generate the arrival time for the next customer and then increase the unique identifier so every
				customer is unique
			*/
			int serviceTime = rand() % 5 + 1;
			curCustomerExpressTime = serviceTime;
			expressWaitTime = curCustomerExpressTime;
			Data *pTemp1 = new Data(uniqueIdentifier, serviceTime, serviceTime + curExpressServiceTime);
			curExpressServiceTime = curExpressServiceTime + serviceTime;
			cout << "Customer has arrived in Express Lane. Customer Arrival Time: " << totalTime << " Customer Number: " << uniqueIdentifier << endl;
			express.enqueue(*pTemp1);
			nextCustomerArrival = rand() % 5 + 1;
			nextCustomerArrivalTracker = nextCustomerArrival;
			uniqueIdentifier++;
		}
		if (totalTime == arrival2)
		{
			/*
			Checks to see if the arrival time of the first normal lane customer is equal to the current min
			if it is, then i create a new Data object and enqueue it into the express queue
			afterwards i generate the arrival time for the next customer and then increase the unique identifier so every
			customer is unique
			*/
			int serviceTime = rand() % 8 + 3;
			curCustomerNormalTime = serviceTime;
			normalWaitTime = curCustomerNormalTime;
			Data *pTemp1 = new Data(uniqueIdentifier, tempServiceTime, tempServiceTime + curNormalServiceTime);
			curNormalServiceTime = curNormalServiceTime + tempServiceTime;
			cout << "Customer has arrived in Normal Lane. Customer Arrival Time: " << totalTime << " Customer Number: " << uniqueIdentifier << endl;
			normal.enqueue(*pTemp1);
			nextCustomerArrival = rand() % 8 + 3;
			nextCustomerArrivalTracker = nextCustomerArrival;
			uniqueIdentifier++;
		}


		if (nextCustomerArrival == 0) // checks to see if the customer arrival time has been reached and if so it generates a new customer
		{

			tempServiceTime = rand() % 8 + 1; // randomyl selects a service time between 1 and 8

			if (tempServiceTime < 3) // if the service time is less than 3 then a new customer is created and added to express queue
			{
				curCustomerExpressTime = tempServiceTime;
				Data *pTemp1 = new Data(uniqueIdentifier, tempServiceTime, tempServiceTime + curExpressServiceTime);
				curExpressServiceTime = curExpressServiceTime + tempServiceTime;
				cout << "Customer has arrived in Express Lane. Customer Arrival Time: " << totalTime << " Customer Number: " << uniqueIdentifier << endl;
				express.enqueue(*pTemp1);
				nextCustomerArrival = rand() % 5 + 1;
				nextCustomerArrivalTracker = nextCustomerArrival;
				uniqueIdentifier++;
			}
			else if (tempServiceTime > 5) // if the service time is greater than 5 then a new customer is created and added to normal queue
			{
				curCustomerNormalTime = tempServiceTime;

				Data *pTemp1 = new Data(uniqueIdentifier, tempServiceTime, tempServiceTime + curNormalServiceTime);
				curNormalServiceTime = curNormalServiceTime + tempServiceTime;
				cout << "Customer has arrived in Normal Lane. Customer Arrival Time: " << totalTime << " Customer Number: " << uniqueIdentifier << endl;
				normal.enqueue(*pTemp1);
				nextCustomerArrival = rand() % 8 + 3;
				nextCustomerArrivalTracker = nextCustomerArrival;
				uniqueIdentifier++;
			}
			else // otherwise, the service time is either between 3 and 5 which means they can go in either express lane or normal lane
			{
				int randomLaneSelection = rand() % 2 + 1; // randomly choose between 1 and 2
				if (randomLaneSelection == 1) // if the number randomly chosen is 1 then it adds a new customer to the express queue
				{
					curCustomerExpressTime = tempServiceTime;

					Data *pTemp1 = new Data(uniqueIdentifier, tempServiceTime, tempServiceTime + curExpressServiceTime);
					curExpressServiceTime = curExpressServiceTime + tempServiceTime;
					cout << "Customer has arrived in Express Lane. Customer Arrival Time: " << totalTime << " Customer Number: " << uniqueIdentifier << endl;
					express.enqueue(*pTemp1);
					nextCustomerArrival = rand() % 5 + 1;
					nextCustomerArrivalTracker = nextCustomerArrival;
					uniqueIdentifier++;
				}
				else // if the number randomly chosen is not 1, then a new customer is added to the normal queue
				{
					curCustomerNormalTime = tempServiceTime;

					Data *pTemp1 = new Data(uniqueIdentifier, tempServiceTime, tempServiceTime + curNormalServiceTime);
					curNormalServiceTime = curNormalServiceTime + tempServiceTime;
					cout << "Customer has arrived in Normal Lane. Customer Arrival Time: " << totalTime << " Customer Number: " << uniqueIdentifier << endl;
					normal.enqueue(*pTemp1);
					nextCustomerArrival = rand() % 8 + 3;
					nextCustomerArrivalTracker = nextCustomerArrival;
					uniqueIdentifier++;
				}
			}
		}
		if (express.size() == 1 && expresssizetracker == 1) // checks to see if there is one node in the queue and if the tracker is 1
		{
			// if there is only one node and the tracker is equal to 1, then it means a node was added however the wait time wasn't updated
			// sets the express wait time to service time of the head node and changes the tracker so it doesn't get into this check unless wait time wasn't updated
			expressWaitTime = express.peek()->getServiceTime();
			expresssizetracker = 0;
		}
		if (normal.size() == 1 && normalsizetracker == 1)
		{
			//same as above check except for the normal queue
			normalWaitTime = normal.peek()->getServiceTime();
			normalsizetracker = 0;
		}
		if (expressWaitTime == 0)
		{
			/*
				If the wait time is 0, then it means the customer at the head of the queue is finished so it dequeus that object and sets the new wait time to the new head
				in the queue. if the size is 0 then it sets the tracker to 1 so it can get into the above checks because otherwise the wait time won't be updated
			*/
			Data *pTemp = express.dequeue();
			cout << "Customer has exited Express Lane. Customer Number: " << pTemp->getCustomerNumber() << " Total Customer Time: " << pTemp->getTotalTime() << endl;
			if (express.peek() != nullptr)
			{
				expressWaitTime = express.peek()->getServiceTime();
			}
			if (express.size() == 0)
			{
				expresssizetracker = 1;
			}
		}
		if (normalWaitTime == 0)
		{
			// same as above except for the normal queue
			Data *pTemp = normal.dequeue();
			cout << "Customer has exited Normal Lane. Customer Number: " << pTemp->getCustomerNumber() << " Total Customer Time: " << pTemp->getTotalTime() << endl;
			if (normal.peek() != nullptr)
			{
				normalWaitTime = normal.peek()->getServiceTime();
			}
			if (normalsizetracker = 0)
			{
				normalsizetracker = 1;
			}
		}
		if (totalTime % 10 == 0) // prints out both queues every ten minutes
		{
			cout << "Current Line in Express Lane" << endl;
			express.print();
			cout << endl;
			cout << "Curren Line in Normal Lane" << endl;
			normal.print();
			cout << endl;
		}
		if (totalTime % 1440 == 0) // resets the identifiers every 24 hours
		{
			uniqueIdentifier = 1;
		}
		nextCustomerArrival--; 
		totalTime++; // increases the minutes
		expressWaitTime--; // decreases current wait time for the customer in the express lane so when it hits 0, the customer at the front is finished and removed
		normalWaitTime--; // decereases current wait time for the customer in the normal lane so when it hits 0, the customer at the front is finished and removed
	}
}