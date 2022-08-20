#include <stdio.h>
#include<stdlib.h>
#include <string.h>
int top=1;
main(){
	char input[10]="N+N*N$",*point;
	char stack[20]="$E";
	int k=0,i,column_index,row_index,j;
	char parsing_table[6][7][3]={
	{" ","N","+","*","(",")","$"},
	{"E","Te"," "," ","Te"," "," "},
	{"e"," ","+Te"," "," ","#","#"},
	{"T","Ft"," "," ","Ft"," "," "},
	{"t"," ","#","*Ft"," ","#","#"},
	{"F","N"," "," ","(E)"," "," "}
	};
//printf("input a string");
//scanf("%s", input);
 point=input;
 
 
while(stack[top] != '$')  // End tak chalane ke liye 
{

 while(stack[top]!=*point ) //to check one char from input
 {
 //finding the possibilty index 
	for(i=1;i<=6;i++)
	{
		
			if(stack[top]==parsing_table[i][0][0])
			{
				column_index=i;
				
			}
			if(*point==parsing_table[0][i][0]  )
			{
				row_index=i;
			}
	}
	//checking for error
if(parsing_table[column_index][row_index][0] == ' ')
{
	printf("Unsuccessfull");
	exit(0);
}

//removing the topmost item from stack
	stack[top]='\0';
	top--;
	//inserting elements to topmost in stack ulta
if(parsing_table[column_index][row_index][0]!='#'){
for(j=strlen(parsing_table[column_index][row_index])-1; j>=0 ; j--)   //Adding elements in the stack
{
	top++;
	stack[top]=parsing_table[column_index][row_index][j];
	//push(stack[20],parsing_table[column_index][row_index][j]);

}
}

printf("%s\n",stack);
}
//when stack top and input char are equal, removing topmost from stack and increment pointer by 1
stack[top]='\0';
top--;
point++;

printf("%s\n",stack);
}
printf("hello");
}


