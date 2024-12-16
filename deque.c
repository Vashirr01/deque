#include <stdio.h>
#include <stdlib.h>

typedef struct deque{
	int head;
	int data;
	struct deque *next;
} deque;

deque *deque_init(int data){
	deque *q = malloc(sizeof(deque));

	q->head = 0;
	q->data = data;
	q->next = NULL;

	return q;
}

void deque_add(deque *q, int data){
	int head = 1;
	deque *node = malloc(sizeof(deque));
	node->data = data;
	node->next = NULL;

	while (q->next != NULL) {
		q = q->next;
		head++;
	}

	q->next = node;
	q->next->head = head;
}

int main() {
	deque *q = deque_init(25);
	deque_add(q, 69);
	deque_add(q, 829);
	deque_add(q, 687438);

	do{
	printf("head: %d, data: %d\n", q->head, q->data);
		q = q->next;
	}while (q != NULL) ;
}

