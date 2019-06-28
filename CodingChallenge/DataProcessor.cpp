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

}


InputValidity DataProcessor::CheckInputValidity()
{
	if (RepeatedJobs())
	{
		return InputValidity::Repeated_Jobs;
	}
	else if (NonExistentDependency())
	{
		return InputValidity::Dependency_Doesnt_Exist;
	}

	// if can't find an order that fulfills dependencies
		// return Circular_Dependency

	else { return InputValidity::Valid; }
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
};

bool DataProcessor::RepeatedJobs()
{
	// Gather list of job names
	std::vector<std::string> jobNames;
	for (int i = 0; i < (int)jobs.size(); i++)
	{
		jobNames.push_back(jobs[i].GetJobName());
	}

	// For each job name
	for (int i = 0; i < (int)jobNames.size() - 1; i++) // Size - 1 because we don't need to check the last entry
	{
		// Remove current job name from the list so we can check against remaining names
		std::string thisJobName = jobNames.front();
		jobNames.erase(jobNames.begin());

		// For each remaining job name
		for (int j = 0; j < (int)jobNames.size(); j++)
		{
			// Compare names
			if (thisJobName.compare(jobNames[j]) == 0)
			{
				return true;
			}
		}
	}
	// Return false if we made it to the end without finding any repeats
	return false;
};

bool DataProcessor::NonExistentDependency()
{
	// Gather list of job names
	std::vector<std::string> jobNames;
	for (int i = 0; i < (int)jobs.size(); i++)
	{
		jobNames.push_back(jobs[i].GetJobName());
	}

	// For each job
	for (int i = 0; i < (int)jobs.size(); i++)
	{
		// If it has a dependency
		if (jobs[i].HasDependency())
		{
			// Check it matches one of the job names
			std::string thisDependency = jobs[i].GetDependency();
			bool foundMatch = false;

			for (int j = 0; j < (int)jobNames.size(); j++)
			{
				if (thisDependency.compare(jobNames[j]) == 0)
				{
					foundMatch = true;
				}
			}
			// If no matches return true
			if (!foundMatch) { return true; }
		}
	}
	// Return false if we made it to the end without finding a non-existent dependency
	return false;				
};