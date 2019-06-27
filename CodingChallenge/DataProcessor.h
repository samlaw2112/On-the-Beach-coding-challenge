#pragma once
#include <string>
#include <vector>

/*
Will collate lists of entered jobs and dependencies, check they are valid, and determine the correct job order for output.
*/

class DataProcessor
{
public:
	// Adds new input to lists
	void AddNewJobAndDependency(std::string job, std::string dependency);

	std::vector<std::string> GetJobsList();
	std::vector<std::string> GetDependenciesList();

private:
	// Will keep track of entered jobs and dependencies
	std::vector <std::string> jobs;
	std::vector <std::string> dependencies;

};