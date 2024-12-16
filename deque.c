#include <stdio.h>
#include <stdlib.h>

typedef struct deque{
	struct deque *head;
	int data;
	struct deque *next;
	struct deque *pre;
} deque;

deque *deque_init(int data){
	deque *q = malloc(sizeof(deque));

	q->head = q;
	q->data = data;
	q->next = NULL;
	q->pre = NULL;

	return q;
}

void deque_add(deque *q, int data){
	deque *node = malloc(sizeof(deque));
	node->data = data;
	node->next = NULL;

	//TODO fix check to q != NULL
	while (q->next != NULL) {
		q = q->next;
	}

	q->next = node;
	q->next->pre = q;
}

int main() {
	deque *q = deque_init(25);
	deque_add(q, 69);
	deque_add(q, 829);
	deque_add(q, 687438);

	//TODO use do-while?
	while (q->next != NULL){
	printf("data: %d\n", q->data);
		q = q->next;
	}

	while (q != NULL) {
	printf("data: %d\n", q->data);
		q = q->pre;
	}
}

