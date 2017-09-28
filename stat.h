/*
Name: Stephen Moring
Section: 2
*/
#include<string>
#include<vector>
using namespace std;
class Stat
{
	friend bool operator< (Stat, Stat);		
public:
	Stat(const char&, int);  // for char vector
	Stat(const string&, int); // for words and numbers
	void Update();		// increases counterb by 1
	string getName();
	int getCounter();
	int getEntrance();
	void changeName(const string&);

private:
	string name;
	int counter;
	int entrancelvl;  //represents order of entrance into vector
};
