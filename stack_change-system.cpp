/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
																				Using stack to achieve changing system(decimal to others)
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include<iostream>
#include<stdlib.h>
using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct 
{
	int *top;
	int *base;
	int stacksize;
}SqStack;


//Initiate the stack
int InitStack(SqStack &S)
{
	S.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
	if (!S.base)
		exit(-1);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;

	return 1;
}


//Free the stack
int DestroyStack(SqStack *S)
{
	free(S->base);                                                          //!!why S->base isn't an array?
	S->base = S->top = NULL;
	S->stacksize = 0;

	return 1;
}

//clear the stack
int ClearStack(SqStack &S)
{
	S.top = S.base;
	return 1;
}

//Get the top of the stack
int GetTop(SqStack S,int &e)
{
	if (S.top!=S.base)
		e=*S.top;
	return 1;
}

//Push an element into the stack
int Push(SqStack &S,int e)
{
	if (S.top-S.base>=STACK_INIT_SIZE)		//if the stack is full
	{
		S.base=(int *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(int));
		if (!S.base)
			return -1;
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}				
	*(++S.top)=e;

	return 1;
}

//Pop an element from the stack
int Pop(SqStack &S,int &e)
{
	if (S.top!=S.base)
		e=*S.top;
		S.top--;
	return 1;
}

//Change the system
void conversion(int num,int size)
{
	int e;
	SqStack S;

	InitStack(S);
	while (num)
	{
		Push(S,num%size);
		num/=size;
	}
	

	while (S.top!=S.base)
	{
		Pop(S,e);
		cout<<e;
	}
	DestroyStack(&S);
}

int main(void)
{
	int num,size;
	cout<<"Please input the number and the size you want to change to:"<<endl;
	cin>>num>>size;
	conversion(num,size);
	//LineEdit();
}
