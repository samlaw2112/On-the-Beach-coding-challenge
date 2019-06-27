#include "pch.h"
#include "DataProcessor.h"

std::vector<std::string> DataProcessor::GetJobsList() { return jobs; };
std::vector<std::string> DataProcessor::GetDependenciesList() { return dependencies; };

void DataProcessor::AddNewJobAndDependency(std::string job, std::string dependency)
{
	jobs.push_back(job);
	dependencies.push_back(dependency);
}