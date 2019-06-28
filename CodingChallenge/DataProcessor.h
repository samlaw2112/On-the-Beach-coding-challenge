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
	Self_Dependency,
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

	// To access sorted job names
	std::vector<std::string> GetSortedJobsNames() const;

private:
	// Will keep track of entered jobs and dependencies
	std::vector <Job> jobs;

	// Sorted job names will be put here
	std::vector <std::string> sortedJobNames;

	// Checks for repeated job names
	bool RepeatedJobs();

	// Checks for jobs that depend on themselves
	bool SelfDependency();

	// Checks for dependencies without a matching job
	bool NonExistentDependency();

	// Sorts jobs into correct order if possible and returns true. Returns false if finds a circular dependency.
	bool SortJobsIfPossible();

};