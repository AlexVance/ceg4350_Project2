/*
Alex Vance
Logic for stack
*/
#include "stack.h"

#define MAXSTACK 20
#define EMPTYSTACK -1
int top = EMPTYSTACK;
char items[MAXSTACK];

//push on to stack
void push(char c){
	items[++top] = c;
}

//remove from stack
char pop() {
	return items[top--];
}

//is the stack full
int full(){
	return top+1 == MAXSTACK;
}

//is the stack empty
int empty() {
	return top == EMPTYSTACK;
}