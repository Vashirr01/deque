#include <stdio.h>
#include <stdlib.h>

typedef struct deque{
	int head;
	int data;
	struct deque *next;
} deque;

int main() {
	printf("hello\n");
}

deque *deque_init(int data){
	deque *q = malloc(sizeof(deque));

	q->head = 0;
	q->data = data;
	q->next = NULL;

	return q;
}
