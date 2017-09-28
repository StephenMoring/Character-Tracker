/*
Name: Stephen Moring
Section: 02
*/
#include "stat.h"

Stat :: Stat(const char& ch, int x)
{
	name = ch;
	counter = 1;
	entrancelvl = x;
}

Stat :: Stat(const string& s, int x)
{
	name = s;
	counter = 1;
	entrancelvl = x;
}

void Stat :: Update()
{	
	counter++;
}

string Stat :: getName()
{
	return name;
}

int Stat :: getCounter()
{
	return counter;
}

int Stat :: getEntrance()
{
	return entrancelvl;
}

void Stat :: changeName (const string& x)
{
	name = x;
}

// < operator had to be overloaded to allow
// the sort function to poroperly compare
// Stat objects based on the conditions of the assignment
// if counters are equal (same frequency) then the ascii
// value of the name is checked, only works with chars
bool operator< (Stat x, Stat y) 
{
  if (x.counter < y.counter)
	return true; 
  if (x.counter == y.counter)
	{
	  if (x.name > y.name)
		return true;
	  else 
		return false; 
	}

  return false; 
}

