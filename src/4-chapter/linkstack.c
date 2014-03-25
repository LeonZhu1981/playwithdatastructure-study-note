#include "../greatest/greatest.h"

#define OK 1
#define ERROR 0

typedef int SElemType;
typedef int Status;


typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
} StackNode;

typedef StackNode *LinkStackPtr;

typedef struct 
{
	LinkStackPtr top;
	int count;
} LinkStack;

int IsEmpty(LinkStack s) {
	return s.top->next == NULL;
}

void CreateEmptyStack(LinkStack *s) {
	s->top = NULL;
	s->count = 0;
}

void Push(LinkStack *s, SElemType e) {
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->count++;
}

Status Pop(LinkStack *s, SElemType *e) {
	if (IsEmpty(*s)) {
		return ERROR;
	}

	*e = s->top->data;
	LinkStackPtr p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return OK;
}

TEST linkstack_push_pop_test() { 
	LinkStack testcase;
	CreateEmptyStack(&testcase);
	Push(&testcase, 1);
	Push(&testcase, 2);
	Push(&testcase, 3);

	int popElement = 0;
	int result = Pop(&testcase, &popElement);
	ASSERT(result);
	ASSERT_EQ(3, popElement);
	ASSERT_EQ(2, testcase.count);

	result = Pop(&testcase, &popElement);
	ASSERT(result);
	ASSERT_EQ(2, popElement);
	ASSERT_EQ(1, testcase.count);
	
	PASS();
}

SUITE(the_suite) {
	RUN_TEST(linkstack_push_pop_test);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(the_suite);
	GREATEST_MAIN_END();
}