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
	ShowWelcomeScreen();

	bool goAgain = true;
	while (goAgain)
	{
		// Take input, process and output results
		ProcessInput();

		goAgain = AskToGoAgain();
	}
}

void ShowWelcomeScreen()
{
	std::cout << "Welcome to my solution for the On the Beach coding challenge.\n\n";
}

void ProcessInput()
{
	// Loop until valid input has been entered, so if any errors the user can try again
	bool enteredValidInput = false;
	while (!enteredValidInput)
	{
		// Flush any previously entered data
		dataProcessor.FlushData();

		// Loop until user has finished entering jobs
		bool stillEnteringInput = true;
		int jobCounter = 1; // To keep track of how many jobs have been entered

		// Enter data
		std::cout << "Enter a series of jobs. Each job should be a single character, optionally followed by a dependency. e.g. enter " <<
			" a > b for a depends on b. Press return after each individual entry. To finish data entry press return twice.\n\n";

		while (stillEnteringInput)
		{
			
			std::string input;
			std::getline(std::cin, input);

			// If nothing entered, proceed to process input or ask for input if there wasn't any
			if (input.empty())
			{
				if (jobCounter > 1)
				{
					stillEnteringInput = false;
					break;
				}
				else
				{
					std::cout << "Please enter at least one job.\n\n";
				}
			}
			else
			{
				// Parse input
				char jobToEnter = input.front();
				// Get dependency if one was entered
				char dependencyToEnter;
				if (input.size() > 1)
				{
					dependencyToEnter = input.back();
				}
				else { dependencyToEnter = ' '; } // Empty character being used to signify no dependency, handles situations where user entered a space after job

				// Add entered job and dependency to list and ask for next one
				dataProcessor.AddNewJobAndDependency(jobToEnter, dependencyToEnter);
				jobCounter++;
			}
			
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
			std::vector<char> sortedJobNames = dataProcessor.GetSortedJobsNames();
			std::cout << "Execute jobs in the following order:\n";
			for (int i = 0; i < (int)sortedJobNames.size(); i++)
			{
				std::cout << sortedJobNames[i] << std::endl;
			}
			std::cout << std::endl;
			enteredValidInput = true;
		}
	}

}

bool AskToGoAgain()
{
	std::cout << "Would you like to enter new data? (yes/no)\n";

	std::string response;
	std::getline(std::cin, response);
	std::cout << std::endl;

	return(response[0] == 'y' || response[0] == 'Y');
}


