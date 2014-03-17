#include <stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
} SqList;

Status GetElem(SqList sl, int i, ElemType *e) {
	if (i > sl.length || i < 0) {
		return ERROR;
	}
	*e = sl.data[i - 1];
	return OK;
}

Status InsertElem(SqList *sl, int index, ElemType e) {
	if (index < 0 || index > sl->length + 1) {
		return ERROR;
	}

	//TODO: implement dynamic add array length. Just reference: Golang slice.
	if (sl->length == MAXSIZE) {
		return ERROR;	
	}

	int lastIndex = sl->length - 1;

	while (lastIndex >= index) {
		sl->data[lastIndex + 1] = sl->data[lastIndex];
		lastIndex--;
	}

	sl->data[index] = e;
	sl->length++;

	return OK;
}

int main () {
	SqList sl = {{1, 2, 3, 4, 5}, 5};
	ElemType e;
	int index = 2;
	int result = GetElem(sl, index, &e);
	if (result) {
		printf("%i\n", e);
	} else {
		printf("Error: cannot found the %i index in SqList\n", index);
	}

	ElemType newInsertElemType = 6;
	int newIndex = 2;
	result = InsertElem(&sl, newIndex, newInsertElemType);
	GetElem(sl, newIndex, &newInsertElemType);

	if (result) {
		printf("The element[%i]: %i inserted successful, length change to: %i\n", newIndex, newInsertElemType, sl.length);
		for (int i = 0; i < sl.length; i++) {
			printf("The index:%i, value is:%i\n", i, sl.data[i]);
		}
	}
}