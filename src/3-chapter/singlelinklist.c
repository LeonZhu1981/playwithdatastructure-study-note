#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct Node
{
	ElemType data;
	Node *next;
} Node;

typedef struct Node *LinkList;

Status GetElem(LinkList l, int index, ElemType *e) {
	if (index < 0) {
		return ERROR;
	}

	LinkList p = l->next;

	if (!p && index > 0) {
		return ERROR;
	}

	if (index == 0) {
		*e = l->data;
		return OK;
	}

	int initIndex = 1;
	
	//如果p != NULL并且初始index小于获取元素的index, 则继续往后找后续节点.
	while (p && initIndex < index) {
		p = p->next;
		initIndex++;
	}

	//如果第index个节点不存在, 则返回错误.
	if (!p || initIndex > index) {
		return ERROR;
	}

	*e = p->data;
	return OK;
}

Status InsertList(LinkList l, int index, ElemType e) {
	if (index < 0) {
		return ERROR;
	}

	if (index == 0) {
		LinkList t = (LinkList)malloc(sizeof(Node));
		t->data = l->data;
		t->next = l->next;
		l->data = e;
		l->next = t;
		free(t);
		return OK;
	}

	int initIndex = 1;
	LinkList s;

	while (l && initIndex < index) {
		l = l->next;
		initIndex++;
	}

	if (!l || initIndex > index) {
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(Node));

	s->data = e;
	s->next = l->next;
	l->next = s;
	free(s);
	return OK;
}

Status DeleteList(LinkList l, int index) {
	if (index < 0) {
		return ERROR;
	}

	if (index == 0) {
		l->data = l->next->data;
		l->next = l->next->next;
		return OK;
	}

	int initIndex = 1;

	while (l->next && initIndex < index) {
		l = l->next;
		initIndex++;
	}

	if (!(l->next) || initIndex > index) {
		return ERROR;
	}

	LinkList s = l->next;
	l->next = s->next;
	return OK;
}


int main() {
	Node n1, n2, n3;

	n3.data = 3;

	n2.data = 2;
	n2.next = &n3;

	n1.data = 1;
	n1.next = &n2;

	ElemType e;

	int index  = 0;
	int result = ERROR;


	result = GetElem(&n1, index, &e);

     if (result) {
          printf("GetElem: The %i index element is %i\n", index, e);
     } else {
          printf("Error\n");
     }

	ElemType insertElem = 5;
	result = InsertList(&n1, index, insertElem);

	if (!result) { 
		printf("Insert failed\n");
	}

	for (int i = 0; i < 4; i++) {
		result = GetElem(&n1, i, &e);
		if (result) {
			printf("InsertList: The %i index element is %i \n", i, e);
		} else {
			printf("Error\n");
		}
	}

	result = DeleteList(&n1, index);

	if (!result) { 
		printf("Delete failed\n");
	}

	for (int i = 0; i < 3; i++) {
		result = GetElem(&n1, i, &e);
		if (result) {
			printf("DeleteList: The %i index element is %i \n", i, e);
		} else {
			printf("Error\n");
		}
	}
}
