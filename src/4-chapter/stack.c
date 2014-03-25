#include <stdio.h>

#define MAXSIZE 1000 
#define OK 1
#define ERROR 0

typedef int SElemType;
typedef int Status;

typedef struct
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;

Status Push(SqStack *s, SElemType e) {
	if (s->top == MAXSIZE - 1) {
		return ERROR;
	}
	s->top++;
	s->data[s->top] = e;
	return OK;
}

Status Pop(SqStack *s, SElemType *e) {
	if (s->top == 0) {
		return ERROR;
	}
	*e = s->data[s->top];
	s->top--;
	return OK;
}


int main() {
	SqStack sqs = {{1, 2, 3}, 2};
	int result = Push(&sqs, 4);
	if (!result) {
		printf("Push failed!\n");
	}

	for (int i = 3; i >= 0; i--) {
		printf("After pushed: %i\n", sqs.data[i]);
	}

	SElemType e;
	result = Pop(&sqs, &e);
	if (!result) {
		printf("Pop failed!\n");
	}

	printf("Poped element is: %i\n", e);

	for (int i = 2; i >= 0; i--) {
		printf("After 1 Poped: %i\n", sqs.data[i]);
	}

	result = Pop(&sqs, &e);
	if (!result) {
		printf("Pop failed!\n");
	}

	printf("Poped element is: %i\n", e);

	for (int i = 1; i >= 0; i--) {
		printf("After 2 Poped: %i\n", sqs.data[i]);
	}
}