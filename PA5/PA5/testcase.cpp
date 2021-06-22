#include "testcase.h"
using std::cout;
using std::endl;
void test::testEnqueueOnEmptyQueue(void)
{
	Queue q;
	Data *pTemp1 = new Data(5, 60, 54);
	q.enqueue(*pTemp1);
}
void test::testEnqueueOnOneNodeQueue(void)
{
	Queue q;
	Data *pTemp1 = new Data(5, 60, 54);
	q.enqueue(*pTemp1);
	Data *pTemp2 = new Data(11, 24, 77);
	q.enqueue(*pTemp2);
}
void test::testDequeueOnOneNode(void)
{
	Queue q;
	Data *pTemp1 = new Data(5, 60, 54);
	q.enqueue(*pTemp1);
	Data *pTemp3 = q.dequeue();
	cout << "Customer Number: " << pTemp3->getCustomerNumber() << " Service Time: " << pTemp3->getServiceTime() << " Total Time: " << pTemp3->getTotalTime() << endl;
}
void test::testDequeueOnTwoNodes(void)
{
	Queue q;
	Data *pTemp1 = new Data(5,60,54);
	q.enqueue(*pTemp1);
	Data *pTemp2 = new Data(11,24,77);
	q.enqueue(*pTemp2);
	Data *pTemp3 = q.dequeue();
	Data *pTemp4 = q.dequeue();
	cout << "Customer Number: " << pTemp3->getCustomerNumber() << " Service Time: " << pTemp3->getServiceTime() << " Total Time: " << pTemp3->getTotalTime() << endl;
	cout << "Customer Number: " << pTemp4->getCustomerNumber() << " Service Time: " << pTemp4->getServiceTime() << " Total Time: " << pTemp4->getTotalTime() << endl;
}
void test::testProgram24Hours(void)
{
	runApp(1440);
}