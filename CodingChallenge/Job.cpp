#include "pch.h"
#include "Job.h"

// Getters
std::string Job::GetJobName() const { return jobName; }
bool Job::HasDependency() const { return hasDependecy; }
std::string Job::GetDependency() const { return dependency; }

// default constructor
Job::Job()
{
	hasDependecy = false;
}

// Setters
void Job::SetJobName(std::string input) { jobName = input; }

void Job::SetDependency(std::string input) { 
	hasDependecy = true;
	dependency = input; 
}