// CodingChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "main.h"

int main()
{
    // Welcome and print instructions for data input
	ShowWelcomeScreen();

	// Accept data input

	// Check data is correct format

	// Collate lists of jobs and their dependencies

	// Figure out correct order of jobs given dependencies
		// Error if circular dependecy

	// Output job list
}

void ShowWelcomeScreen()
{
	std::cout << "Welcome to my solution for the On the Beach coding challenge.\n\n";
	std::cout << "You will be asked to enter each job to be processed one at a time. For each job you will have the option of including a dependency.\n\n";
}

void AcceptValidInput()
{
	// Loop until user has finished entering jobs
		// Enter a job
		// Enter a dependency

	// Check input is valid

	// For each entry
		// Check no repeated entries
		// Check dependencies match a real job
		// Check for simple circular dependencies (e.g. A dependent on B and B dependent on A)
}


