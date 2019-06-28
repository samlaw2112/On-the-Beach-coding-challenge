// CodingChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "main.h"
#include "DataProcessor.h"
#include <vector>

// Instantiate data processor
DataProcessor dataProcessor;

int main()
{
    // Welcome and print instructions for data input
	ShowWelcomeScreen();

	// Take input, process and output results
	ProcessInput();
}

void ShowWelcomeScreen()
{
	std::cout << "Welcome to my solution for the On the Beach coding challenge.\n\n";
	std::cout << "You will be asked to enter each job to be processed one at a time. For each job you will have the option of including a dependency.\n\n";
}

void ProcessInput()
{
	// Loop until user has finished entering jobs
	bool stillEnteringInput = true;
	int jobCounter = 1; // To keep track of how many jobs have been entered

	while (stillEnteringInput)
	{
		// Enter a job
		std::string jobToEnter;
		std::cout << "Enter " << jobCounter << "th job or type fin if you have finished entering jobs\n"; // TODO change hardcoded th so reads correctly (1st, 2nd, 3rd etc.)
		std::cin >> jobToEnter;
		std::cout << std::endl;

		// Quit if user typed fin
		if (jobToEnter.compare("fin") == 0) { stillEnteringInput = false; break; }

		// Enter a dependency
		std::string dependencyToEnter;
		std::cout << "Enter dependency for " << jobCounter << "th job or na if there is no dependency\n"; // TODO change hardcoded th so reads correctly (1st, 2nd, 3rd etc.)
		std::cin >> dependencyToEnter;
		std::cout << std::endl;

		// Add entered job and dependency to list and ask for next one
		dataProcessor.AddNewJobAndDependency(jobToEnter, dependencyToEnter);
		jobCounter++;
	}

	// Check input is valid
	InputValidity inputValidity = dataProcessor.CheckInputValidity();

	// Print output depending on input validity
	switch (inputValidity)
	{
	case InputValidity::Repeated_Jobs:
		std::cout << "Error: Cannot enter the same job name more than once.\n\n";
		break;
	case InputValidity::Self_Dependency:
		std::cout << "Error: Jobs cannot depend on themselves.\n\n";
		break;
	case InputValidity::Dependency_Doesnt_Exist:
		std::cout << "Error: Cannot enter a dependency that does not match an existing job name.\n\n";
		break;
	case InputValidity::Circular_Dependency:
		std::cout << "Error: Found circular dependency. Cannot sort jobs.\n\n";
		break;
	case InputValidity::Valid:
		// For valid input print the sorted list
		std::vector<std::string> sortedJobNames = dataProcessor.GetSortedJobsNames();
		std::cout << "Execute jobs in the following order:\n";
		for (int i = 0; i < (int)sortedJobNames.size(); i++)
		{
			std::cout << sortedJobNames[i] << std::endl;
		}
	}

}


