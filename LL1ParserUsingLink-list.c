#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char element;
	struct node *next;
};

//create new nodes
struct node* create_node(){
	struct node *n;
	// allocates new meemory through malloc
	n=(struct node*)malloc(sizeof(struct node)); 	
	return n;
}

// push function used to enter element into the stack
void push(struct node **start,char poss){
	struct node *n;
	n=create_node();	//creates a new node
	n->element=poss;	//saves the new element in new node
	n->next=*start;		//saves the address of the next node in the new one
	*start=n;			// pointer to point the new node(top)
}

//pop function used to remove the top element from stack
void pop(struct node **start){
	struct node *r;
	r=*start;
	*start=r->next;
	free(r);
}


//peek for seeing the top element in stack
char peek(struct node **start){
	return ((*start)->element);
}

void display(struct node **s){
	struct node *current;
	current=*s;
	while((current)!=NULL){
	printf("%c",(current)->element);
	(current)=(current)->next;
	} 
}


main(){
	struct node *stack; //initializing stack
	push(&stack,'$');
	push(&stack,'E');


	char input[10],*point;
	int k=0,i,column_index,row_index,j;
	char parsing_table[6][7][4]={
	{" ","N","+","*","(",")","$"},
	{"E","Te"," "," ","Te"," "," "},
	{"e"," ","+Te"," "," ","#","#"},
	{"T","Ft"," "," ","Ft"," "," "},
	{"t"," ","#","*Ft"," ","#","#"},
	{"F","N"," "," ","(E)"," "," "}
	};


printf("input a string:\n");
scanf("%s", input);
int len=strlen(input);
input[len]='$';
system("CLS");
printf("\n--------------------------------");
		printf("\n\t    INPUT");
printf("\n--------------------------------");
printf("\n\n\t    %s\n",input);
 point=input;

printf("\n--------------------------------");
		printf("\n\t    PROCESS");
		
printf("\n--------------------------------");
printf("\n    ACTION\t    STACK\n");

while(5){


 while(peek(&stack)!=*point ) //to check one char from input
 {

 //finding the possibilty index
 	for(i=1;i<=6;i++)
	{
		
			if(peek(&stack)==parsing_table[i][0][0])
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
		printf("\n-----------------------------------------");
		printf("\n\t    RESULT");
printf("\n-----------------------------------------");
	printf("\n\t  LL1 parssing unsuccesful");
	exit(0);
}

pop(&stack); //removing the topmost item from stack
if(peek(&stack)!=' ')
printf("    %c->%s",parsing_table[column_index][0][0],parsing_table[column_index][row_index]);


if(parsing_table[column_index][row_index][0]!='#'){
for(j=strlen(parsing_table[column_index][row_index])-1; j>=0 ; j--)   //Adding elements in the stack
{
	push(&stack,parsing_table[column_index][row_index][j]);
	//push(stack[20],parsing_table[column_index][row_index][j]);
}
}
if(peek(&stack)!=' '){
printf("\t    ");
display(&stack);
printf("\n");
}

}

	pop(&stack);
	point++;


//printf("%c",peek(&stack));
//display(&stack);
//printf("\n \t");

if(*point=='\0' || peek(&stack)=='$'){
printf("\n--------------------------------");
		printf("\n\t    RESULT");
printf("\n--------------------------------");
	printf("\n    LL1 parssing succesful");
	break;
}
}

}



