/*
Name: Stephen Moring
Section: 02
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <iomanip>
#include "stat.h"
using namespace std; 

bool Compare (Stat, Stat); // special comparison function to sort word and num vectors
void SortnSum(vector<Stat>&, string); // outputs the summary

int main()
{
  string file;
  while(cin)
	{
	  getline(cin, file, '\0');
	}
// three vectors are created to store appropriate informnation
// as the string is read through 
vector<Stat> words;
vector<Stat> nums;
vector<Stat> chars;
int i = 0;
while (i <= file.length())
	{
	  // first condition checks for a letter, it will then either 
	  // store it as a single letter, or check the next spot to see
	  // if it should store a word

	  if (file[i] >= 65 && file[i] <= 90 || file[i] >= 97 && file[i] <= 122)
		{
		  int j = i;
		  if (!isalpha(file[j+1]))
			{
			  // this same code is written a couple times, its a loop
			  // to check the vector if a Stat object of this "word" exists
			  // probably inefficient

			  Stat x(tolower(file[j]), j);
			  int k;
			  for (k = 0; k < words.size(); k++)
				{
				  if (x.getName() == words[k].getName())
					{
					  // if its in the vectore, update the counter
					  words[k].Update();
					  break;
					}
				}
			  if (k == words.size())
				words.push_back(x);
			}
		  else
			{
			  // if this condition is triggered, a word is present and it stores it as a string
			  // then creates a Stat object out of that string and checks the vector for it

			  string temp;
			  int loopcount = 0; // this keeps track of how many characters the word is so that
					     // i can be set appropriately so it stores words properly

			  while(isalpha(file[j]))
				{
				  if (islower(file[j]))
				  	temp = temp + file[j];
				  else
					{
					  char p = tolower(file[j]);
					  temp = temp + p;
					}
				  j++; 
				  loopcount++;
				}
			  Stat x(temp, j);
		  	  int k; 
			  for (k = 0; k < words.size(); k++)
				{
				  if (x.getName() == words[k].getName())
					{
					  words[k].Update();
					  break;
					}
				}
		  	  if (k == words.size())
				words.push_back(x);

			  i = i + (loopcount-1);
			}
		  
		}
	  else if (file[i] >= 48 && file[i] <= 57)
		{
		  // this is essentially the same code as the code to store words, 
		  // this looks for numbers, and checks for repeats

		  int j = i;
		  if (!isdigit(file[j+1]))
			{
			  Stat x(file[j], j);
			  int k;
			  for (k = 0; k < nums.size(); k++)
				{
				  if (x.getName() == nums[k].getName())
					{
					  nums[k].Update();
					  break;
					}
			
				}
			  if (k == nums.size())
				nums.push_back(x);
			}
		  else
			{ 
			  string temp;
			  int loopcount = 0;
			  while(isdigit(file[j]))
				{
				  temp = temp + file[j];
				  j++; 
				  loopcount++;
				}
			  Stat x(temp, j);
		  	  int k; 
			  for (k = 0; k < nums.size(); k++)
				{
				  if (x.getName() == nums[k].getName())
					{
					  nums[k].Update();
					  break;
					}
				}
		  	  if (k == nums.size())
				nums.push_back(x);

			  i = i + (loopcount-1);
			}
		  
		} 
	  i++;
	}
i = 0;
while(i <= file.length())
	{
	  // kind of lazy but i decided to just run another loop
	  // to count all of the separate characters, similar code to the
	  // functions that gather words and numbers, but it only stores single
	  // chars
	  if (file[i] >= 1 && file[i] <= 127)
		{
		  Stat temp(file[i], i);
		  if ( file[i] == '\n')
			temp.changeName(" \\n");
		  if (file[i] == '\t')
			temp.changeName(" \\t");
		  int j; 
			for (j = 0; j < chars.size(); j++)
				{
				  if (temp.getName() == chars[j].getName())
					{
					  chars[j].Update();
					  //cout << "updating" << endl;
					  break;
					}
				}
		  if (j == chars.size())
			{
			  chars.push_back(temp);
			  //cout << "adding element" << endl;
			}
				
		}		
	  i++;
	}
  std::sort(words.begin(), words.end(), Compare);  // sorts each vector into descending order
  std::reverse(words.begin(), words.end());        // different sort function for words and nums
  						   // becuase they handle ties differently than chars
  std::sort(nums.begin(), nums.end(), Compare);    // according to the project specifications
  std::reverse(nums.begin(), nums.end());

  std::sort(chars.begin(), chars.end());
  std::reverse(chars.begin(), chars.end());

//outputs the summaries properly

SortnSum(chars, "characters"); 
SortnSum(words, "words");
SortnSum(nums, "numbers");
// test3 file takes ~40 seconds to process
	return 0; 
}


bool Compare(Stat x, Stat y) // different form of comparison for words and numbers
{
  if (x.getCounter() < y.getCounter())
	return true;

  if (x.getCounter() == y.getCounter())
	{
	  if (x.getEntrance() < y.getEntrance()) // I added the entrancelvl private member
		return false; 			 // data to handle ties with words and nums
	  else 
		return true; 
	}
  
  return false;
}

void SortnSum(vector<Stat>& chars, string title)
{
	// simply outputs the summaries in proper format

  cout << "Total " << chars.size() << " different " << title;
  if (chars.size() < 10)
	{
	  int limit = chars.size();
	  cout << ", " << limit << " most used " << title << ": " << endl;
	  for (int i = 0; i < limit; i++)
		{
	  	  cout << "No. " << i << ": " << setw(13) <<
		  left << chars[i].getName() << setw(6) <<
		  right << chars[i].getCounter() << endl;
		}
	}
  else
	{
	  cout << ", 10 most used " << title << ": " << endl;
	  for( int i = 0; i < 10; i++)
		{
		  cout << "No. " << i << ": " << setw(13) <<
		  left << chars[i].getName() << setw(6) << 
		  right << chars[i].getCounter() << endl;
		}
	}

  cout << '\n';

}
