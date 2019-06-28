#pragma once
#include <string>
#include <vector>
#include "Job.h"

/*
Will collate lists of entered jobs and dependencies, check they are valid, and determine the correct job order for output.
*/

class DataProcessor
{
public:
	// Adds new input to lists
	void AddNewJobAndDependency(std::string jobName, std::string dependency);

	std::vector<std::string> GetJobsList();
	std::vector<std::string> GetDependenciesList();

private:
	// Will keep track of entered jobs and dependencies
	std::vector <Job> jobs;

};