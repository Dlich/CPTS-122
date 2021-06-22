#include "queue.h"
#include <ctime>
#include <cstdlib>
using std::cout;
using std::endl;
using std::cin;
using std::rand;
void main(void)
{
	int n = 0;
	srand(time(NULL)); // used so i can call rand() and get actual random numbers
	cout << "How many minutes do you want to run this program for?" << endl;
	cin >> n;
	runApp(n);
	
}