#include "pch.h"
#include "DataProcessor.h"

std::vector<std::string> DataProcessor::GetSortedJobsNames() const { return sortedJobNames; }

InputValidity DataProcessor::CheckInputValidity()
{
	if (RepeatedJobs())
	{
		return InputValidity::Repeated_Jobs;
	} 
	else if (SelfDependency())
	{
		return InputValidity::Self_Dependency;
	}
	else if (NonExistentDependency())
	{
		return InputValidity::Dependency_Doesnt_Exist;
	}
	else if (!SortJobsIfPossible())
	{
		return InputValidity::Circular_Dependency;
	}
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

bool DataProcessor::SelfDependency()
{
	// For each job
	for (int i = 0; i < (int)jobs.size(); i++)
	{
		// If has a dependency
		if (jobs[i].HasDependency())
		{
			// return true if dependency matches job name
			if (jobs[i].GetDependency().compare(jobs[i].GetJobName()) == 0)
			{
				return true;
			}
		}
	}
	// Return false if no self dependencies
	return false;
}

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

bool DataProcessor::SortJobsIfPossible()
{
	// Loop until we finish sorting the list or run into a circular dependency
	bool sortingComplete = false;
	while (!sortingComplete)
	{
		// Loop until we find the next job to go in sorted list, then start again from the top
		bool foundNextJob = false;
		while (!foundNextJob)
		{
			// For each job
			for (int i = 0; i < (int)jobs.size(); i++)
			{
				// If no dependency
				if (!jobs[i].HasDependency())
				{
					// Add to sorted list
					sortedJobNames.push_back(jobs[i].GetJobName());
					jobs.erase(jobs.begin() + i); // Delete sorted job from original jobs list
					foundNextJob = true;
					break;
				}
				else // If dependency
				{
					// Check that dependency job is alright added to the list
					std::string thisDependency = jobs[i].GetDependency();

					for (int j = 0; j < (int)sortedJobNames.size(); j++)
					{
						// If yes add to list
						if (thisDependency.compare(sortedJobNames[j]) == 0)
						{
							sortedJobNames.push_back(jobs[i].GetJobName());
							jobs.erase(jobs.begin() + i); // Delete sorted job from original jobs list
							foundNextJob = true;
							break;
						}
					}  // If no move on to next job
				}
			}
			// If made a complete pass through job list without finding any that can go into sorted list, assume circular dependency
			if (!foundNextJob){ return false; }
		}
		// If moved all jobs over to sorted list then we're done
		if (jobs.empty()) { 
			sortingComplete = true;
			return true; 
		}
	}
	// To stop compiler complaining that not all paths return a value, but we should never get here
	return false;
}