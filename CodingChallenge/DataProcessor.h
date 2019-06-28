#pragma once
#include <string>
#include <vector>
#include "Job.h"

/*
Will collate lists of entered jobs and dependencies, check they are valid, and determine the correct job order for output.
*/

// Different possibile options for input validity
enum class InputValidity
{
	Valid,
	Repeated_Jobs,
	Dependency_Doesnt_Exist,
	Circular_Dependency,
};

class DataProcessor
{
public:
	// Adds new input to lists
	void AddNewJobAndDependency(std::string jobName, std::string dependency);

	// Check whether input is valid
	InputValidity CheckInputValidity(); // Making this const causes an error - probably it shouldn't

	std::vector<std::string> GetJobsList() const;
	std::vector<std::string> GetDependenciesList() const;

private:
	// Will keep track of entered jobs and dependencies
	std::vector <Job> jobs;

	// Checks for repeated job names
	bool RepeatedJobs();

};