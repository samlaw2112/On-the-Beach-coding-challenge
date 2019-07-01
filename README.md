# On-the-Beach-coding-challenge

Browse to CodingChallenge/Debug/CodingChallenge.exe to run the application.

For data entry, enter the job name (single character). If this job has a dependency follow with a > and the dependency (also a single character, that must match one of the job names). E.g: for a depends on b enter "a>b". Spaces may or may not be included, as the program currently takes the first entered character as the job name and the last as the dependency. This means it is important not to type a space before the job name or after the dependency (at the moment the program is not robust to this). Press return after each job entry to enter the next job, and enter an empty line to complete data entry. E.g.:

a  
b > a  
c  
d > c  
