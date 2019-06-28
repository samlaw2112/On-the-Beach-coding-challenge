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
	InputValidity CheckInputValidity(); // Not const because job order will be sorted when checking for circular dependencies

	std::vector<std::string> GetJobsList() const;
	std::vector<std::string> GetDependenciesList() const;

private:
	// Will keep track of entered jobs and dependencies
	std::vector <Job> jobs;

	// Checks for repeated job names
	bool RepeatedJobs();

	// Checks dependencies without a matching job
	bool NonExistentDependency();

	// Sorts jobs into correct order if possible and returns true. Returns false if finds a circular dependency.
	bool SortJobsIfPossible();

};