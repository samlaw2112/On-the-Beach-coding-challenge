#include "pch.h"
#include "Job.h"

// Getters
char Job::GetJobName() const { return jobName; }
bool Job::HasDependency() const { return hasDependecy; }
char Job::GetDependency() const { return dependency; }

// default constructor
Job::Job()
{
	hasDependecy = false;
}

// Setters
void Job::SetJobName(char input) { jobName = input; }

void Job::SetDependency(char input) { 
	hasDependecy = true;
	dependency = input; 
}