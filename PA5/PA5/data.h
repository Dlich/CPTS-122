#include <iostream>


class Data
{
public:
	Data(int customerNumber = 0, int serviceTime = 0, int totalTime = 0);
	~Data();
	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();
	void setCustomerNumber(int num);
	void setServiceTime(int time);
	void setTotalTime(int time);
private:
	int customerNumber;
	int serviceTime;
	int totalTime;
}; 