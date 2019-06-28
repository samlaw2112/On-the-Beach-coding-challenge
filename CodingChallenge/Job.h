#pragma once
#include <string>

/*
This class will be responible for an individual job - job name, whether it has a dependency, what the dependency is.
Making each job an instance of this class for encapsulation - so e.g. can't confuse dependency 4 with job 2.
*/

class Job
{
public:
	
	// Default constructor
	Job();

	// Setters
	void SetJobName(std::string);
	void SetDependency(std::string);

	// Getters
	std::string GetJobName() const;
	bool HasDependency() const;
	std::string GetDependency() const;


private:
	std::string jobName;
	bool hasDependecy;
	std::string dependency;
};