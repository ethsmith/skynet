// Skynet.cpp : Aerial drone program

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// seed random number generator
	srand(static_cast<unsigned int>(time(0)));

	// keeps the loop from being endless
	bool found = false;
	// the random enemy location on an 8 x 8 grid (1-64)
	int enemyPos = rand() % 64 + 1;
	// lowest number that the enemy can be found
	int searchGridLowNumber = 1;
	// highest number that the enemy can be found
	int searchGridHighNumber = 64;
	// amount of predictions the software made
	int pings = 0;

	// intro text
	cout << "Generating random enemy location on 8 x 8 grid...\n";
	cout << "The enemy is located at location #" << enemyPos << " on 8 x 8 grid with 1-64 sectors.\n";
	cout << "Skynet HK-Aerial Initializing Search Software...\n";

	cout << "================================================================================\n";

	// loop endlessly until the enemy is found
	while(!found) 
	{

		cout << "Skynet HK-Aerial Radar sending out ping #" << pings << endl;

		// guess grid number
		int searchedPos = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

		// executes if the guess is equal to the enemy location
		if(searchedPos == enemyPos) 
		{
			// set found to true so that the loop stops executing
			found = true;
			
			cout << "Enemy was hiding at location #" << enemyPos << endl;
			cout << "Target was found at location #" << enemyPos << endl;
			cout << "Skynet HK-Aerial Software took " << pings << " predictions to find the enemy location on a grid size of 8 x 8 (64)" << endl;
		}
		// executes if the guess is too low
		else if(searchedPos < enemyPos)
		{
			// increases the prediction count by 1
			pings++;
			// increases the minimum grid number that the enemy can be found
			searchGridLowNumber = searchedPos + 1;
			
			cout << "The target location prediction of " << searchedPos << " was lower than the actual enemy location of " << enemyPos << endl;
			cout << "The new search grid low is " << searchGridLowNumber << endl;
		}
		else
		{
			// increases the prediction count by 1
			pings++;
			// decrease the highest grid number that the enemy can be found
			searchGridHighNumber = searchedPos - 1;

			cout << "The target location prediction of " << searchedPos << " was higher than the actual enemy location of " << enemyPos << endl;
			cout << "The new search grid high is " << searchGridHighNumber << endl;
		}
		cout << "================================================================================\n";
	}

	// keeps the console from closing
	system("pause");

    return 0;
}

