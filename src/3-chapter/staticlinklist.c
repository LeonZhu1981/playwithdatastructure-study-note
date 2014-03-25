#include <stdio.h>

#define MAXSIZE 1000 
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;


typedef struct 
{
	ElemType data;
	int cur;
}Componet, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList staticLinkList) {
	for (int i = 0; i < MAXSIZE - 1; i++) {
		staticLinkList[i].cur = i + 1;
	}
	staticLinkList[MAXSIZE - 1].cur = 0;
	return OK;
}

int Malloc_Sll(StaticLinkList sl) {
	int i = sl[0].cur;
	printf("i is %i\n", i);

	printf("sl[0].cur is %i\n", sl[0].cur);

	if (sl[0].cur) {
		sl[0].cur = sl[i].cur;
	}
	return i;
}

Status ListInsert(StaticLinkList L, int i, ElemType e) {
	int j,k,l;
	k = MAXSIZE - 1;
	if (i < 1) {
		return ERROR;
	}

	j = Malloc_Sll(L);
	printf("j is %i\n", j);

	if (j) {
		L[j].data = e;
		for (l = 1; l < i - 1; l++) {
			k = L[k].cur;
			L[j].cur = L[k].cur;
			
		}
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}

int main () {
	StaticLinkList list;
	int result = InitList(list);
	if (!result) {
		printf("Init Error\n");
	}
	int insertIndex = 2;
	result = ListInsert(list, insertIndex, 101);
	if (!result) {
		printf("Insert Error\n");
	}

	printf("%i\n", list[insertIndex].data);
	printf("%i\n", list[insertIndex].cur);
}