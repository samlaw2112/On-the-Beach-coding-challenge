#pragma once

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
	void SetJobName(char);
	void SetDependency(char);

	// Getters
	char GetJobName() const;
	bool HasDependency() const;
	char GetDependency() const;


private:
	char jobName;
	bool hasDependecy;
	char dependency;
};