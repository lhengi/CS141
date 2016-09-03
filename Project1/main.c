//
//  main.c
//  Project1
//
//  Created by Heng Li on 9/1/16.
//  Copyright © 2016 Heng Li. All rights reserved.
//
/* ------------------------------------------------
 * Program 1, Twenty Four
 *
 * Class: CS 141, Fall 2016
 * System: OSX 10.11.6 , Xcode
 * Author: Heng Li
 * Version: 2.7
 *
 * Game of TwentyFour.  Using each of the four numbers shown
 * below exactly once, combining them somehow with the basic mathematical
 * operators (+,-,*,/) to yield the value twenty-four.\n
 * -------------------------------------------------
 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/*
 Doing basic calculations
 take two integers and one operator
 do simple calculation and return the answer
 @parameter:
    int num1
    int num2
    char op
 @return
    double answer
 */
double basicCalc(double num1,int num2, char op)
{
    double answer;
    //switch statement to determine which operator to use
    switch (op)
    {
        case '+':
            answer = num1 *1.0 + num2;
            break;
        case '-':
            answer = num1 *1.0 - num2;
            break;
        case '*':
            answer = num1 *1.0 * num2;
            break;
        case '/':
            answer = num1 *1.0 / num2;
        default:
            break;
    }
    return answer;
}//end basicCalc

/*
 simpleSwitch Function
 To simplfy multiple switch statements
 @parameter
    int num
 @return
    char returnVar
 */
char simpleSwitch(int num)
{
    //switch statement, determine the sign
    char returnVar = '+';
    switch (num)
    {
        case 0:
            returnVar = '+';
            break;
        case 1:
            returnVar = '-';
            break;
        case 2:
            returnVar = '*';
            break;
        case 3:
            returnVar = '/';
            break;
            
        default:
            break;
    }//end switch
    
    return returnVar;
    
}//end simpleSwitch

/*
 do mutiple calculation, and display the result
 return the answer
 @parameter
    int num1
    int num2
    int num3
    int num4
    char op1
    char op2
    char op3
 */
void calcDisplay(int num1, int num2, int num3, int num4, char op1, char op2, char op3)
{
    double firstAnswer;
    double secondAnswer;
    double finalAnswer;
    firstAnswer = basicCalc(num1*1.0, num2, op1);
    secondAnswer = basicCalc(firstAnswer, num3, op2);
    finalAnswer = basicCalc(secondAnswer, num4, op3);
    printf("%d %c %d = %2.1lf\n",num1,op1,num2,firstAnswer);
    printf("%2.1lf %c %d = %2.1lf\n",firstAnswer,op2,num3,secondAnswer);
    printf("%2.1lf %c %d = %2.1lf\n",secondAnswer,op3,num4,finalAnswer);
    
    //out put for answers that user inputed
    if(finalAnswer == 24)
    {
        printf("Well Done! Geniues!\n");
    }
    else
    {
        printf("Sorry, your answers are wrong\n");
    }
    
    return;
}//end calcDisplay

/*
 deBugDisplay Function
 generates, and display all the combinations
 pull out a specific puzzle
 @parameter
    int numPuzzle
    int outPutOption
    char userOp1
    char userOp2
    char userOp3
 */
void deBugDisplay(int numPuzzle, int outPutOption,char userOp1,char userOp2, char userOp3)
{
    int numberCount = 0;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    double firstAnswer;
    double secondAnswer;
    double finalAnswer;
    int op1;
    int op2;
    int op3;
    char operator1;
    char operator2;
    char operator3;
    
    // 7 nested for loops, generate all possible combinations
    for(num1 = 1; num1 < 10; num1++)
    {
        for(num2 = 1; num2 < 10; num2++)
        {
            for(num3 = 1;num3 < 10; num3++)
            {
                for(num4 = 1; num4 < 10; num4++)
                {
                    for(op1 = 0; op1 < 4; op1++)
                    {
                        for(op2 = 0; op2 < 4; op2++)
                        {
                            for(op3 = 0; op3 < 4; op3++)
                            {
                                //call simpleSwitch to get the combination of operators
                                operator1 = simpleSwitch(op1);
                                operator2 = simpleSwitch(op2);
                                operator3 = simpleSwitch(op3);
                                
                                // use basicCal to break down the math
                                firstAnswer = basicCalc(num1*1.0, num2, operator1);
                                secondAnswer = basicCalc(firstAnswer, num3, operator2);
                                finalAnswer = basicCalc(secondAnswer, num4, operator3);
                                
                                // check if the answer == 24
                                if(finalAnswer == 24)
                                {
                                    numberCount++;
                                }
                                
                                // determine different output options
                                if(outPutOption == -1)//print out all 3185 puzzles
                                {
                                    if(finalAnswer == 24)
                                    {
                                        printf("%d: %d %c %d %c %d %c %d = %2.1lf\n",numberCount,num1,operator1,num2,operator2,num3,operator3,num4,finalAnswer);
                                    }
                                }// end if outPutOption == 1
                                else if(outPutOption == 0)//print out a specific puzzle(deBug)
                                {
                                    if(numPuzzle == numberCount && finalAnswer == 24)
                                    {
                                        printf("Puzzle selected. Puzzle number: ");
                                        printf("%d: %d %c %d %c %d %c %d = %2.1lf\n",numberCount,num1,operator1,num2,operator2,num3,operator3,num4,finalAnswer);
                                        
                                    }// end if numPuzzle == numberCount
                                }// end else if outPutOption == 0
                                else if(outPutOption == -2 && numPuzzle == numberCount && finalAnswer == 24)//print out the puzzle(only numbers)
                                {
                                    printf("The numbers to use are: %d , %d , %d , %d\n",num1,num2,num3,num4);
                                }//end else if outPutOption == -2
                                else//print out the steps
                                {
                                    if(numPuzzle == numberCount && finalAnswer == 24)
                                    {
                                        calcDisplay(num1, num2, num3, num4, userOp1, userOp2, userOp3);
                                    }//end if

                                }//end else
                                
                            }//end for(op3)
                        }//end for(op2)
                    }//end for(op1)
                    
                }// end for(num4)
            }//end for(num3)
        }//end for(num2)
    }// end for(num1)
    
    return;
}//end deBugDisplay

/*
 main function of the program: Twenty Four
 display puzzels
 prompt user
 */
int main()
{
    srand(time(NULL));
    //print the instructions
    
    printf("Author: Heng Li\n");
    printf("Program: #1, TwentyFour\n");
    printf("Aug 31, 2016\n\n");
    
    printf("Welcome to the game of TwentyFour.  Using each of the four numbers shown\n");
    printf("below exactly once, combining them somehow with the basic mathematical\n");
    printf("operators (+,-,*,/) to yield the value twenty-four.\n");
    
    const int SHOW_DEBUG = 1;//change to 1 if you want to be displayed
    
    int choice;
    int validEntre = 0;
    
    //initialize all input vars to ' '
    char userOp1;
    char userOp2 = '\n';
    char userOp3 = '\n';
    char fourthChar = '\n';
    
    int runCount = 0;
    
    //while loop prompt user to play again
    char again = 'Y';
    while (again == 'Y')
    {
        // DeBugDisplay
        choice = (rand()%3185) + 1;
        if(SHOW_DEBUG == 1)
        {
            //display all 3185 puzzels
            deBugDisplay(0, -1, '+', '+', '+');
            
            //choose one puzzle randomly, and display with answer to test
            deBugDisplay(choice, 0, '+', '+', '+');
            printf("***END DEBUG DISPLAY***\n\n\n");
        }
        
        //print out the puzzle(only the numbers)
        deBugDisplay(choice, -2, '+', '+', '+');
        
        
        
        
        //do while loop, check if user's input is valid or not
        do{
        
            printf("Enter the three operators to be used (+ , - , * , /)");
            
            //let user input
            //deal with if user input less than 3 charater
            scanf("%c",&userOp1);
            if(userOp1 != '\n')
            {
                scanf("%c",&userOp2);
                if(userOp2 != '\n')
                {
                    scanf("%c",&userOp3);
                    if(userOp3 != '\n')
                    {
                        scanf("%c",&fourthChar);
                    }//end if userOp3
                }//end if userOp2
            }//end if userOp1
            
            printf("\n");
            
            //set runCount to another value, so do not need to prompt user to carrage return
            runCount++;
            //reset validEntre
            validEntre = 0;
            
            
            //check if user type in the right charaters
            if(((userOp1 == '+') ||(userOp1 == '-') || userOp1 == ('*') || (userOp1 == '/') ) && fourthChar == '\n')
            {
                validEntre++;
            }
            if(((userOp2 == '+') || (userOp2 == '-') || (userOp2 == '*') || (userOp2 == '/') )&& fourthChar == '\n')
            {
                validEntre++;
            }
            if(((userOp3 == '+') || (userOp3 == '-') || (userOp3 == '*') || (userOp3 == '/') )&& fourthChar == '\n')
            {
                validEntre++;
            }
            
            //if correct length but incorrect charater && less length
            if(validEntre != 3 && fourthChar == '\n')
            {
                if((userOp3 == '\n') || (userOp2 == '\n') || (userOp1 == '\n'))
                {
                    printf("*** Sorry, that input is the wrong length.  Please retry. ***\n");
                    continue;
                }
                printf("*** Sorry, invalid characters in input.  Please retry. ***\n");
                continue;
            }
            
            //detects long inputs that are more than 3 characters
            //Read all the extra input, then start again
            while(validEntre != 3 && fourthChar != '\n')
            {
                validEntre = 0;
                scanf("%c",&fourthChar);
                
                if(fourthChar == '\n')
                {
                    printf("*** Sorry, that input is the wrong length.  Please retry. ***\n");
                    break;
                }//end if fourthChar == '\n'
            }// end while fourthChar != \n++

        }while(validEntre != 3);
             
        
        //print the arithmetic
        deBugDisplay(choice, 1,userOp1, userOp2, userOp3);
        
        //ask user to play again
        printf("Would you like to play again? (Y/N): ");
        //catch the carrage return when user type in Y/N
        char catchCarage;
        scanf(" %c%c",&again,&catchCarage);
        printf("\n");
    }
    printf("Thanks for playing.  Exiting program...\n");
    return 0;
}//end main
