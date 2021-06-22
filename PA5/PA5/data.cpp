#include "data.h"

Data::Data(int customerNumber, int serviceTime, int totalTime)
{
	this->customerNumber = customerNumber;
	this->serviceTime = serviceTime;
	this->totalTime = totalTime;
}
int Data::getCustomerNumber()
{
	return customerNumber;
}
int Data::getServiceTime()
{
	return serviceTime;
}
int Data::getTotalTime()
{
	return totalTime;
}
void Data::setCustomerNumber(int num)
{
	customerNumber = num;
}
void Data::setServiceTime(int time)
{
	serviceTime = time;
}
void Data::setTotalTime(int time)
{
	totalTime = time;
}
Data::~Data()
{

}