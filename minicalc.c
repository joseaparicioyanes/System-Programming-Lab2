/*
*******************************************************************************************************************************************
 *Purpose/Description: This program is a simple version of a calculator; it takes values accompanied by labels from the command line, 
                       and then it performs calculation depending on the arguments entered by the user. To carry out the operations, 
                       the program uses an array of two dimensions to store the flags corresponding to each mathematical operation and 
                       their corresponding value. There is also a function that validates user input to ensure that the inputs are in 
                       the permitted numerical ranges and that there are no errors due to incompatible data conversion. Besides, there 
                       is a function in which mathematical operations are performed depending on the values of the flags. For a better 
                       understanding, please browse the code as there are comments on almost all lines.
 * Author’s Name: Jose Aparicio
 * Author’s Panther ID: 6186111 
 * Certification: I hereby certify that this work is my own and none of it is the work of any other person.
*********************************************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

#define MIN_VALUE 1           // defining a value to validate the range of user input (-m,-d,-a,and -s has 1 as the lower bound)
#define MAX_VALUE1 5          // defining a value to validate the range of user input (-m,and -d has 5 as the upper bound)
#define MAX_VALUE2 500        // defining a value to validate the range of user input (-a,and -s has 500 as the upper bound)


int validateInput(char arg, int number);                 //Declaring a function to validate user-entered arguments
int getValue(char str[],  char prevArg[]);               //Declaring a function to obtain the numerical value with which all mathematical operations will be performed
void calculate(int argFlags[4][4], int val,int xFlag);   //Declaring a function to perform all mathematical operations.

int main(int argc, char ** argv)    //main function
{
	extern char *optarg;                            //external variable (getopt)
	extern int optind;				//external variable (getopt)
	int op_msg=0, c;                                // variables to be used in the while loop
	int argFlags[4][4] = {{0,0,0,0},{0,0,0,0}};     //2D array to store the flag of each aption abd the value that correspond to each flag // sflag, mflag, dflag, xflag;
	int value=getValue(argv[argc-1], argv[argc-2]); // calling the function getValue to give a numerical value to the variable value
	int calculateFlag=1,xflag=0;                    // decaling variables to be uses as flags to know if all values were entered correctly and if the user wants to calculate power of 2
	static char usage[] = "minicalc [-a num] [-s num] [-m num] [-d num] [x] value\n";  // array to print an example of how to use the program
	
	if(argc < 2){          //if the program has too few arguments, diplay the user a message
		printf("Try running the program with some arguments\n\t%sSomething like:\texample -a 5 -d 3\n\t\texample -m 2 -s 4 file1\n", usage);
		return 0;
	}

		

	while ((c = getopt(argc, argv, "a:s:m:d:xls")) != -1){                        //while loop to iterate through all the arguments
		switch (c) {
			case 'a':
				argFlags[0][0] = 1;                                   //setting the flag for addition
				argFlags[0][1] = atoi(optarg);                        //setting the value to add
				calculateFlag=validateInput('a',argFlags[0][1]);      //Validating that the value entered by the user is in the allowed range
				break;
			case 's':
				argFlags[1][0] = 1;                                   //setting the flag for substraction
				argFlags[1][1] = atoi(optarg);                        //setting the value to substract
				calculateFlag=validateInput('s',argFlags[1][1]);      //Validating that the value entered by the user is in the allowed range
				break;
			case 'm':
				argFlags[2][0] = 1;                                   //setting the flag for multiplication
				argFlags[2][1] = atoi(optarg);                        //setting the value to multiply
				calculateFlag=validateInput('m',argFlags[2][1]);      //Validating that the value entered by the user is in the allowed range
				break;
			case 'd':
                	        argFlags[3][0] = 1;                                   //setting the flag for division
				argFlags[3][1] = atoi(optarg);			      //setting the value to divide
				calculateFlag=validateInput('d',argFlags[3][1]);      //Validating that the value entered by the user is in the allowed range
                       		break;
			case 'x':
                	        xflag = 1;                                            //setting the flag for power of 2
                	        break;
			case '?':
				break;
		}
	}
		
	(calculateFlag==1)?calculate(argFlags,value, xflag):printf("Calculations cannot be made since one or more arguments have out of range values.\n "); /*if all the values are correct then call the function calculate
																				to perform all calculations, if mot, then display a message to 
                                                                                                                                                                the user */

	return 0;
}

int getValue(char str[], char prevArg[])          //function to get the value from the argument
{
	int isDigit = 0;                          // creating a variable to be used as a flag to know if the str is a digit
	int i=0;                                  // creating an variable to be used as a counter inside the while loop
	while(i<strlen(str) && isDigit == 0){     //while loop to iterate through all the indexes of the string  
  		if(isdigit(str[i]))               // if the index in str is a diget then keep the flag as 0
    			isDigit = 0;
  		else                              // if it is not a digit then set the flag as 1
    			isDigit = 1;
  		i++;
	}

	if(isDigit==0 && (prevArg[0]!='-' || strcmp(prevArg,"-x")==0)) // if the string can be conveted to a number, and the previus value is - ar -x, the asign value with the str as integer
	{
		return atoi(str);                                      //returning value
	}
	else
	{
		printf("\n*****INVALID INPUT FOR VALUE!!*****\n\n\n"); // if the condition above is false then display a message to the user and quit the program
		exit(0);

	}
}

int validateInput(char arg, int number)      // function to validate the user entered arguments
{
		switch(arg){
			case 'a':
				if(number>=MIN_VALUE && number<=MAX_VALUE2)                    //If the value is in the allowed range return 1 (true), otherwise return 0 (false)
					return 1;
				else
				{
					printf("Invalid input for -a. -a must be a positive integer between 1 and 500 inclusive.\n");
					return 0;
				}
                                break;
                        case 's':
				if(number>=MIN_VALUE && number<=MAX_VALUE2)                      //If the value is in the allowed range return 1 (true), otherwise return 0 (false)
					return 1;
				else
				{
                                	printf("Invalid input for -s. -s must be a positive integer between 1 and 500 inclusive.\n");
                                	return  0;
				}
				break;
                        case 'm':
				 if(number>=MIN_VALUE && number<=MAX_VALUE1)                      //If the value is in the allowed range return 1 (true), otherwise return 0 (false)
					return 1;
				 else
				 {
					printf("Invalid input for -m. -m must be a positive integer between 1 and 5 inclusive.\n");
					return 0;
				 }
                                 break;
                        case 'd':
				 if(number>=MIN_VALUE && number<=MAX_VALUE1)                       //If the value is in the allowed range return 1 (true), otherwise return 0 (false)
					return 1;
				 else
				 {
					printf("Invalid input for -d. -d must be a positive integer between 1 and 5 inclusive.\n");
					return 0;
				 }
                                  break;
                  }
	return -1;
}

void calculate(int argFlags[4][4], int val,int xFlag)      // function to perform all the calculations
{
	printf("\n\n");
	double value=(double)val;
	if(xFlag==1)                  										//if xFlag ==1 then set value=value*value
	{
		printf("%8.2lf  ^  2 = %8.2lf\n",value,value*value);                                            //displaying the operation and the result
		value*=value;
	}
	if(argFlags[2][0]==1)         										//if the multiplacation flag is equal to 1 then set value= value * the number entered by the user
	{
		 printf("%8.2lf  *%3d = %8.2lf\n",value,argFlags[2][1],value*((double)argFlags[2][1]));         //displaying the operation and the result
		 value*=argFlags[2][1];
	}
	if(argFlags[3][0]==1)          										//if the division flag is equal to 1 then set value= value / the number entered by the user
        {
                 printf("%8.2lf  /%3d = %8.2lf\n",value,argFlags[3][1],(value/((double)argFlags[3][1])));       //displaying the operation and the result
                 value/=argFlags[3][1];
        }
	if(argFlags[0][0]==1)          										//if the add flag is equal to 1 then set value= value + the number entered by the user
        {
                 printf("%8.2lf  +%3d = %8.2lf\n",value,argFlags[0][1],value+((double)argFlags[0][1]));         //displaying the operation and the result
                 value+=argFlags[0][1];
        }
        if(argFlags[1][0]==1)          										//if the substraction flag is equal to 1 then set value= value - the number entered by the user
        {
                 printf("%8.2lf  -%3d = %8.2lf\n",value,argFlags[1][1],value-((double)argFlags[1][1]));         //displaying the operation and the result
                 value-=argFlags[1][1];
        }
	printf("\n***Final Result: %.2lf***\n\n\n",value);                                                      //displaying the total result


}
