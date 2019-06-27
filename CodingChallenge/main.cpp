// CodingChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "main.h"

int main()
{
    // Welcome and print instructions for data input
	ShowWelcomeScreen();

	// Accept data input
	AcceptValidInput();

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
	bool stillEnteringInput = true;
	int jobCounter = 1; // To keep track of how many jobs have been entered

	while (stillEnteringInput)
	{
		// Enter a job
		std::string jobToEnter;
		std::cout << "Enter " << jobCounter << "th job\n\n"; // TODO change hardcoded th so reads correctly (1st, 2nd, 3rd etc.)
		std::cin >> jobToEnter;
		std::cout << std::endl;

		// Enter a dependency
		std::string dependencyToEnter;
		std::cout << "Enter dependency for " << jobCounter << "th job or press return if there is no dependency\n\n"; // TODO change hardcoded th so reads correctly (1st, 2nd, 3rd etc.)
		std::cin >> dependencyToEnter;
		std::cout << std::endl;

		// Add entered job and dependency to list and ask for next one

		// TODO change this to false after user has finished entering input
		stillEnteringInput = false;
	}
		

	// Check input is valid

	// For each entry
		// Check no repeated entries
		// Check dependencies match a real job
		// Check for simple circular dependencies (e.g. A dependent on B and B dependent on A)
}


