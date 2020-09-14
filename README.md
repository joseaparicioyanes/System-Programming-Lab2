# System-Programming-Lab2
Write a C program that runs on ocelot for a mini calculator using only the command line options. You
must use getopt to parse the command line. The calculator will only do addition, subtraction,
multiplication, division, and a power of 2.
Usage: minicalc [-a num] [-d num] [-m num] [-s num] [-x] value
• The variable value is the starting value.
• Value should be validated to be an integer between 1 and 50 inclusive. Error message and usage
shown if not.
• For the -m option num should be a positive integer between 1 and 5 inclusive.
• For the -d option num should be a positive integer between 1 and 5 inclusive.
• For the -a option num should be a positive integer between 1 and 500 inclusive.
• For the -s option num should be a positive integer between 1 and 500 inclusive.
• -a adds num to value.
• -d divides value by num.
• -s subtracts num from value.
• -m multiplies value by num.
• -x squares value. (Note: no num is needed.)
• Output should have exactly 2 decimal places no matter what the starting values are.
• If -x is included, it is executed first. If -m or -d is included it would be next. The -a and -s would
be executed last.
• There will be at most one of each option, if there are more than one you can use either of the
options in the calculation.
• There should be no user input while the program is running. It runs in full from the command
line.
The source file should have your name & PantherID included in it as well as a program description and it
should have the affirmation of originality from lab 1.
Code should be nicely indented and commented.
Create a simple Makefile to compile your program into an executable called minicalc.
• Test your program with the following command lines and take a screenshot after running the
three lines.
o minicalc -a 5 -m 2 -d 2 -s 1 1
o minicalc -a 4 -m 2 -d 3 -s 1 -x 5
o minicalc -a 3
