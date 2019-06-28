#include "pch.h"
#include "DataProcessor.h"

std::vector<std::string> DataProcessor::GetJobsList() const{ 

	std::vector<std::string> jobList;

	for (int i = 0; i < (int)jobs.size(); i++)
	{
		jobList.push_back(jobs[i].GetJobName());
	}

	return jobList;

};
std::vector<std::string> DataProcessor::GetDependenciesList() const{ 

	std::vector<std::string> dependencyList;

	for (int i = 0; i < (int)jobs.size(); i++)
	{
		dependencyList.push_back(jobs[i].GetDependency());
	}

	return dependencyList;

};

InputValidity DataProcessor::CheckInputValidity() const
{
	// if find repeated jobs
		// return Repeated_Jobs

	// if find a dependency without matching job
		// return Dependency_Doesnt_Exist

	// if can't find an order that fulfills dependencies
		// return Circular_Dependency

	// else return Valid
};

// Instantiate new job
void DataProcessor::AddNewJobAndDependency(std::string jobName, std::string dependency)
{
	// Instantiate new job
	Job newJob;
	newJob.SetJobName(jobName);
	
	// Add dependency if the user didn't enter na for no dependency
	if (dependency.compare("na") != 0)
	{
		newJob.SetDependency(dependency);
	}

	// Add to list of all jobs
	jobs.push_back(newJob);
}