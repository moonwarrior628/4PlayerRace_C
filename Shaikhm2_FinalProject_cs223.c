/* -----------------------------------------------
  	 Submitted By: <Your Name>
  	 Homework Number: <whichever homework you are doing>
   	 Credit to:
  		     <StackOverflow(http://stackoverflow.com),Z. D.,P. D.>

  	 Submitted On: <6/22/2016>

By submitting this program with my name,
I affirm that the creation and modification
of this program is primarily my own work.
 --------------------------------------------------------------------------- */
 /*
    a.	Total time spent in reading and understanding the requirements :20
    b.	Total time spent in Design :20
    c.	Total time spent implementing design (code) :20
    d.	Total time spent testing code :15
    e.	Total of the Above  (How much total time to do this project) :90
------------------------------------------------------------------------------*/
/* This program is a text based game made possible by using various functions in C language.
It asks user for a password to begin the game has two modes that a user can select.One mode
is a computerized(automatic) game of four players and the other involves two players(manual).
The racer profiles are stored in a txt file that are read stored in a structure of array.The
results of the race are created in a new file. */


#include <stdlib.h>     /*includes */
#include <stdio.h>      /*includes */
#include <conio.h>      /*includes */
#include <string.h>     /*includes */
#include <time.h>       /*includes */
#include <unistd.h>     /*includes */
#define LIMIT 90        /*includes */

void password();    /*prototype for password function*/
void selectracemode();  /*prototype for selecting race mode function*/
void selectCar ();  /*prototype for selecting car function*/
int autorace ();    /*prototype for auto race function*/
int manualrace(int,int);    /*prototype for manual race function*/
void starbar();     /*prototype for star-bar function*/
int readcarprofile();   /*prototype for reading car profile function*/
void bubbleSort();  /*prototype for bubble-sort function*/
void raceresults(int,int);  /*prototype for race results function*/


struct Racerprofile /*Structure array declaration*/
{
    char Username[10]; /*Stores the username of racers in this array*/
    char Carname[15]; /*Stores the Car name of racers in this array*/
    int Carnum; /*Stores the Car number */
    char CarColor[10]; /*Stores Car color*/


};

struct Racerprofile record[10]; /**/

struct sum
{
    int
};
struct sum spacesum[5];

int main (void)
{
    printf("...........................................................");
    printf("\n\t\t\tMehvesh Shaikh\n");/*Prints the name on screen*/
    printf("...........................................................");

    password(); /*Calls password function*/
}
void password()/* A function that checks the password */
{
    /*Declares strings for storing user's input and the given password*/
    char password[20]="Racer101";
    char Userpassword[20];


    printf("\n\nPlease input the password to proceed with the game:");/*Asks user for the password*/
    gets(Userpassword); /*Gets password from the user*/

    if (strcmp(password,Userpassword)==0) /*compares the user password to the given password and executes the if condition*/
    {
        printf("\nPassword is correct. Enjoy the Race!\n");/*If password is correct, it prints the message*/
        system("cls"); /*Clears the screen*/
        selectracemode(); /*Calls the function that deals with selecting the race mode*/
    }
    else /*Executes the following message when password entered by the user is wrong*/
    {
        printf("\nIncorrect Password.See you later\n"); /*Prints the message when user's password is wrong.*/
    }
}

void selectracemode()/*A function that deals with selection of race mode*/
{
    /*Declares variables*/
    int Auto,menu;

    readcarprofile();/*Calls for a function that reads text from file*/

    printf("\n\nWhich mode do you want to race?"); /*Asks user for choice of race mode*/
    printf("\n\n 1= Auto (game of Four Players)"); /*Prints Auto*/
    printf("\n 2= Manual(game of Two Players"); /*Prints Manual*/

    printf("\n\nPlease select the number corresponding to the mode you wish to race:\n"); /*Asks user to choose number*/
    scanf("%d",&menu);/*scans user input*/

    switch (menu) /*switch statement gives choice of two modes*/
    {
        case 1:
                Auto = autorace();/*Calls for auto race function*/
                break;

        case 2:
                selectCar(); /*Calls to a function that deals with selecting car*/
                break;

        default:
        printf("Invalid input");/*Prints message when user input is not among the choice given above*/
    }
}

int autorace ()/* A function that manages the auto race of four players*/
{
    /*Declare variables */
    int x,i,k;
    int sum[4];
    sum [0]=0;
    sum [1]=0;
    sum [2]=0;
    sum [3]=0;

    while((sum[0]<=90)&&(sum[1]<=90)&&(sum[2]<=90)&&(sum[3]<=90))/*Loop makes sure the sum of spaces of each car does not increase more than 90 spaces*/
    {
        system("cls");/*Clears screen*/

        for (k=0;k<4;k++) /*for loop generates the race for four cars*/
        {
            srand(time(NULL)); /*seed time to null*/
            x = (rand() %10)+1; /*generates random numbers from 1-10*/
            sum[k]=sum[k]+x; /*adds sum of random numbers for each car */

            printf("\n#%d ",record[k].Carnum); /*display the car number*/

            starbar(sum[k]);/*calls function that displays stars on screen*/
            usleep(500000); /*adds delay to avoid same value of random numbers for each car*/
        }
     }

     bubbleSort( sum, 4); /* calls function that sorts the sum of spaces of each car and passes the array to this function */

}
int manualrace (int Player1,int Player2)/*Function that generates the manual race of two players and takes value from selectcar function*/
 {
    /*Declare variables*/
    int x,i;
    int sum[2];
    sum [0]= 0;
    sum [1]= 0;
    char Carname[4];
    char enter;


    while((sum[0]<=90)&&(sum[1]<=90))/*while loop makes sure the sum of spaces of each car don't increase more than 90*/
    {
        enter = 0;/*initializes enter as 0*/
        system("cls");/*clears screen*/

        printf("\nPlayer 1: Press enter for next move.\n");/*Prompts player 1 to press enter to make their move*/
        enter = getchar();/*gets user command*/

        while (enter != '\r' && enter != '\n')/*loop */
        {
            enter = getchar();/* gets the command enter from user*/
        }
        printf("#%d ",Player1);/*displays car number*/

        srand(time(NULL));/*seeds time*/
        x = (rand() %10)+1;/*generate number from 1-10*/
        sum[0]=sum[0]+x;/*adds spaces of random number of player 1*/
        starbar(sum[0]);/*calls function starbar*/
        usleep(300000);/*adds  a delay*/
//-----------------------------------------------------------------------------------------------------------------------------------------------
        enter =0;
        printf("\nPlayer 2: Press enter for next move.\n");
        enter = getchar();
        while (enter != '\r' && enter != '\n')
        {
            enter = getchar();
        }

        printf("\n#%d ",Player2);

        srand(time(NULL));
        x = (rand() %10)+1;
        sum[1]=sum[1]+x;
        starbar(sum[1]);
        usleep(300000);/*adds a delay*/
    }
    if (sum[0]>sum[1])/*checks if sum of spaces of player 1 is greater and executes the message below*/
    {
        printf("Player 1 has won the race\n");
    }
    else if (sum[1]>sum[0])/*checks if sum of spaces of player 2 is greater and executes the message below*/
    {
        printf("Player 2 has won the race\n");
    }
 }

int readcarprofile()/*Function that reads information from txt file and stores it in a structure of array*/
{
    FILE *Fpointin;/*creates a pointer*/
    Fpointin = fopen ("car.txt","r"); /* opens the file and reads the file from car.txt*/

    if (Fpointin == NULL) /*checks if file exists*/
    {
        printf ("File does not exist.\n");
    }
    else
    {
        /*declare variables*/
        int i =0;

        do/*scans the information from text file and stores it in a structure of array*/
        {
            fscanf(Fpointin, "%s %s %d %s",&record[i].Username, &record[i].Carname, &record[i].Carnum, &record[i].CarColor);
            i++;

        }while(feof(Fpointin)==0);/*ends the loop after it reaches the end of file*/

    }

fclose(Fpointin);/*Closes the file*/
return 0;
}

void starbar(int x)/*function responsible for displaying stars on screen*/
{
    /*Declare variables*/
    int iCount; /*star counter*/
    int c;

    for (c=0;c<x;c++)/*for loop displays stars on screen for each player*/
    {
        putchar('*');
    }

    putchar('\n');
}

 void selectCar ()/*Function that deals with selecting the car*/
 {
    int i,Player1,Player2;
    int SelectedCar;

        for (i=0;i<4;i++)/*for loop prints the stored information in the structure and displays it on screen*/
        {
            printf("\t%s %s %d %s\n",record[i].Username, record[i].Carname, record[i].Carnum, record[i].CarColor);
        }

        printf("\nPlayer 1: Choose a car you wish to race with by entering the number:\n");
        scanf("%d",&Player1);

        while ((Player1<record[0].Carnum) && (Player1 > record[4].Carnum))/*// while loop makes sure PLayer 1's input lies in the same range of car numbers given in txt file(car.txt)*/
        {
            printf("\nPlayer 1 has input an incorrect car number.Please try a car number from the given options");
            scanf("%d",&Player1);
        }

        printf("\nPlayer 2: Choose a car you wish to race with by entering the number:\n");
        scanf("%d",&Player2);

        while ((Player2<record[0].Carnum)&& (Player2>record[4].Carnum))/*While loop makes sure PLayer 2's input lies in the same range of car numbers given in txt file(car.txt)*/
        {
            printf("\nPlayer 2 has input an incorrect car number.Please try a car number from the given options");
            scanf("%d",&Player2);
        }

        while (Player1==Player2)/*while loop makes sure Player 1 and Player 2's input are not the same.*/
        {
            printf("\nPlayer 1 and Player 2 have chosen the same car.This is not possible.\nPlease enter a different car number:");
            scanf("%d",&Player2);
        }

         while ((Player2<record[0].Carnum)&& (Player2>record[4].Carnum))/*while loop prompts the Player 2 to change their value after they select the same value as Player 1.*/
        {
            printf("Player 2 has input an incorrect car number.Please try a car number from the given options");
            scanf("%d",&Player2);
        }
    manualrace(Player1,Player2); /* It passes Player 1 and Player 2 values to manualrace function.*/
 }
 void bubbleSort( int * array, int size )
{
    void swap (int *element1Ptr, int *element2Ptr ); /* prototype of swap function */

    int pass; /* pass counter */
    int j,i,l;
    int Users[4];
    Users [0]= array[0];
    Users [1]=array[1];
    Users[2]=array[2];
    Users[3]=array[3];

     /* loop to control passes */
     for ( pass = 0; pass < size - 1; pass++ )
     {
         /* loop to control comparisons during each pass */
         for ( j = 0; j < size - 1; j++ )
         {
             /* swap adjacent elements if they are out of order */
             if ( array[ j ] > array[ j + 1 ] )
             {
                swap( &array[ j ], &array[ j + 1 ] );
             } /* end if */
         } /* end inner for */
     } /* end outer for */

    /* loop through array a */
    printf("\nThe results of the race are given as below\n");

    int q,p;
    for (q=0;q<4;q++)
    {
        for (p=0;p<4;p++)
        {
            if (array[q]==Users[p])/*compares the sum of spaces taken from auto race function with user's score*/
            {
                if(q==0)
                {
                    printf("%s has won the 4th place\n",record[p].Username);/*displays the player with 4th position*/
                }
                if(q==1)
                {
                    printf("%s has won the 3rd place\n",record[p].Username);/*displays the player with 3rd position*/
                }
                if(q==2)
                {
                    printf("%s has won the 2nd place\n",record[p].Username);/*displays the player with 2nd position*/
                }
                if(q==3)
                {
                    printf("%s has won the 1st place\n",record[p].Username);/*displays the player with 1st position*/
                }
            }
        }
    }
raceresults(p,q);/*calls for raceresults function*/
/* end for */
} /* end function bubbleSort */

void swap( int *element1Ptr, int *element2Ptr )/* swap values at memory locations to which element1Ptr and element2Ptr point */
{
     int hold = *element1Ptr;
     *element1Ptr = *element2Ptr; /*swaps value of element1 with element 2*/
     *element2Ptr = hold;
} /* end function swap */

void raceresults( int p,int q)
{
    FILE *Fpointout;

    Fpointout = fopen ("raceresult.txt","w");/*opens file*/
    int t,w;



        while(feof(Fpointout)==0);
        {
            fopen("raceresults.txt","w");

            fprintf(Fpointout,"%s #%d",record[t].Username,w);
        }


fclose(Fpointout);

}
