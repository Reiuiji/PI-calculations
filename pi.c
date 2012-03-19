
#include <stdio.h>

#include <stdlib.h>

//define the accuracy
#define MAXDIG 200

int Leibnz();

void PrintArray(int x[],int P);
void DivPIArray(int x[], int Divterm, int Ans[]);
void CopyArray(int x[],int y[]);
void AddSubPIArray(int z[],int y[],int N);



int main()
{
	//set the variables
	int Select;



	//main menu for the pi functions
	printf("+===================================+\n");
	printf("|          Pi calculations          |\n");
	printf("|===================================|\n");
	printf("|  How do you want to calculate Pi  |\n");
	printf("|----+------------------------------|\n");
	printf("|  1 | Gregory- Leibniz series      |\n");
	printf("|  0 | Exit the program             |\n");
	printf("+----+------------------------------+\n");

	//ask the user what calculatiion they want to use
	do	{
	printf("\n\n type of pi calcuation: ");
	scanf("%d",&Select);

	//outputs if the user did not type in the write selection
	if (Select <0 || Select > 1)
	{
		printf("\n+================================+");
		printf("\n|Please type a number between 0-1|");
		printf("\n+================================+\n");
	}

	} while(Select <0 || Select >1);

	//select what funtion you do
	switch(Select)
	{
	case 0:
		{
			printf("\n\n\n||Have a nice Day||");
			exit (0);
		}
	case 1:
		{
			Leibnz();
			break;
		}
	}
	return 0;
}

//Gregory Leibnix series function
int Leibnz()
{
	//variables for pi perimaters
	int Cycles,interval, Screen, Term[MAXDIG]={0},Sum[MAXDIG]={0},Newterm[MAXDIG]={0},d;

	//This will ask the user how many times it will cycle the function
	printf("How many interations do you want to perform: ");
	scanf("%d",&Cycles);

	//this will ask the user how often it will print the value to the screen
	//note the greater the screen time, the faster it will go
	printf("\nHow many times do you want the value to print to the screen: ");
	scanf("%d",&Screen);

	//this will ask the user what is the max digits that the program will hold
	//greater acuracy will take longer to execute
	//printf("\nHow accurate do you want the program (recomend 200): ");
	//scanf("%d",&Maxdig);
	//Now to initalize the arrays since we now know how accurate we need it to be

	//sets the starting sum and term
	Term[0]=4;
	Sum[0]=4;

	//calculate pi
	printf("\n\n");
	for (interval = 1; interval <= Cycles; interval ++)
	{
		DivPIArray(Term,interval,Newterm);
		CopyArray(Term, Newterm);
		AddSubPIArray(Sum,Term,interval);

		//print out to the terminal
		if(interval%Screen == 0)
		{
		printf("N=%3d ------------------------------------------------------------------------\n\n",interval);
		printf("TRM=");PrintArray(Term,70);printf("\n");
		printf("SUM=");PrintArray(Sum,70);printf("\n\n");
		}
	}
	printf("\n===========================================================================\n");
	printf("Calculated pi with %d interations\n", interval-1); //interval is -1 since the for add 1 and closes
	
	//ask if you want to save the data to a txt file
	do {
	printf("do you want to save it to a txt file\n");
	printf("1: yes \n");
	printf("2: no \n");
	scanf("%d",&d);
	if(d != 1 && d != 2)
		printf("I did not get that, please try again\n");
	} while (d != 1 && d != 2);

	if (d == 1)
	{
		int J;
		FILE *FPI;
		char OUT;
		OUT = Sum[0];
		FPI = fopen("pi.txt", "wt");
		fprintf(FPI, "\ncalculated pi with %d iterations\n%d.",interval-1,OUT);
		for (J=1;J<MAXDIG;J++)
		{
			OUT = Sum[J];
			fprintf(FPI, "%d",OUT);
		}
		fflush(FPI);
	}

	return 0;
}



// Divide the Arrays for pi
void DivPIArray(int x[], int Divterm, int Ans[])
{
	int j,t=4, remain=0,B=Divterm*2+1;
for (j=0; j<MAXDIG; j++)
{
	Ans[j]=t/B;
	remain=t%B;
	t=(remain*10);
}
}

//copy one Array to another
void CopyArray(int x[],int y[])
{
	int i;
	for(i=0;i<MAXDIG;i++)
		x[i]=y[i];
}

//add or subtract the answer from the sum
void AddSubPIArray(int z[],int y[],int N)
{
	int Carry=0,t,J,l=N%2;
	if (l==0)
	{
		for (J=MAXDIG-1; J>=0; J--)
		{
			t=z[J]+y[J]+Carry;
			z[J]=t%10;
			Carry=t/10;
		}
	}
	else
		{
		for (J=MAXDIG-1; J>=0; J--)
		{
			z[J]=z[J]-y[J];
			if (z[J]<0)
			{
				z[J-1]--;
				z[J]=z[J]+10;
			}
		}
	}
}
//print the arrays to the terminal
void PrintArray(int x[],int P)
{
	int i;
	printf("%1d.",x[0]);
	for(i=1;i<P;i++)
	{
		printf("%1d",x[i]);
	}
}