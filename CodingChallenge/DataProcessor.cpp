#include "pch.h"
#include "DataProcessor.h"

std::vector<std::string> DataProcessor::GetJobsList() { 

	std::vector<std::string> jobList;

	for (int i = 0; i < (int)jobs.size(); i++)
	{
		jobList.push_back(jobs[i].GetJobName());
	}

	return jobList;

};
std::vector<std::string> DataProcessor::GetDependenciesList() { 

	std::vector<std::string> dependencyList;

	for (int i = 0; i < (int)jobs.size(); i++)
	{
		dependencyList.push_back(jobs[i].GetDependency());
	}

	return dependencyList;

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