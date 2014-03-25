#include "../greatest/greatest.h"

#define MAXSIZE 1000
#define OK 1
#define ERROR 0

typedef int SElemType;
typedef int Status;

typedef struct {
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

Status Push(SqDoubleStack *s, SElemType e, int stackNumber) {
	if (s->top1 + 1 == s->top2) {
		return ERROR;
	}

	if (stackNumber == 1) {
		s->top1++;
		s->data[s->top1] = e;
		return OK;
	} else if (stackNumber == 2) {
		s->top2--;
		s->data[s->top2] = e;
		return OK; 
	} else {
		return ERROR;
	}

}

Status Pop(SqDoubleStack *s, int stackNumber, SElemType *e) {
	if (stackNumber == 1) {
		if (s->top1 == 0) {
			return ERROR;
		}
		*e = s->data[s->top1];
		s->top1--;
		return OK;
	} else if (stackNumber == 2) {
		if (s->top2 == MAXSIZE - 1) {
			return ERROR;
		}
		*e = s->data[s->top2];
		s->top2++;
		return OK;
	} else {
		return ERROR;
	}
}

TEST doublestack_push_pop_test() {
	SqDoubleStack testcase = {{1, 2, 3, 4}, 0, MAXSIZE - 1};
	int result = Push(&testcase, 5, 1);
	int popElement = 0;
	ASSERT(result);
	result = Pop(&testcase, 1, &popElement);
	ASSERT(result);
	ASSERT_EQ(5, popElement);

	result = Push(&testcase, 1, 2);
	ASSERT(result);
	result = Pop(&testcase, 2, &popElement);
	ASSERT(result);
	ASSERT_EQ(1, popElement);
	PASS();
}

TEST doublestack_push_pop_failed_test() {
	SqDoubleStack testcase = {{1, 2, 3, 4}, 0, MAXSIZE - 1};
	int result = Push(&testcase, 5, 0); 
	ASSERT(!result);
	result = Pop(&testcase, 5, 0); 
	ASSERT(!result);
	PASS();
}

SUITE(the_suite) {
    RUN_TEST(doublestack_push_pop_test);
    RUN_TEST(doublestack_push_pop_failed_test);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
	GREATEST_MAIN_BEGIN();      /* command-line arguments, initialization. */
    RUN_SUITE(the_suite);
    GREATEST_MAIN_END();        /* display results */
}

