#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct deque{
	int data;
	struct deque *next;
	struct deque *pre;
} deque;

deque *deque_init(int data){
	deque *q = malloc(sizeof(deque));

	q->data = data;
	q->next = NULL;
	q->pre = NULL;

	return q;
}

void deque_push_right(deque *q, int data){
	deque *node = malloc(sizeof(deque));
	node->data = data;
	node->next = NULL;

	while (q->next != NULL) {
		q = q->next;
	}

	q->next = node;
	q->next->pre = q;
}

void deque_push_left(deque **q, int data){
	deque *node = malloc(sizeof(deque));
	node->data = data;
	node->next = *q;
	node->pre = NULL;

	if(*q != NULL){
	(*q)->pre = node;
	}
	(*q) = node;
}

deque *deque_pop_left(deque **q){
	deque *node = *q;
	*q = (*q)->next;

	if (*q != NULL) {
		(*q)->pre = NULL;
	}

	node->next = NULL;
	return node;
}

deque *deque_pop_right(deque *q){
	while (q->next != NULL) {
		q = q->next;
	}
	if(q->pre != NULL){
		q->pre->next = NULL;
		q->pre = NULL;
	}
	deque *node = q;
	return node;
}

void print_deque(deque *q){
    deque *current = q;
    while (current != NULL) {
        printf("data: %d\n", current->data);
        current = current->next;
    }
        printf("------\n");

}

int main() {
	deque *q = deque_init(25);
	print_deque(q);

	deque_push_right(q, 69);
	print_deque(q);
	deque_push_left(&q, 687438);
	print_deque(q);

	deque *n = deque_pop_left(&q);
	printf("popped node data: %d\n", n->data);
	print_deque(q);
	n = deque_pop_right(q);
	printf("popped node data: %d\n", n->data);
	print_deque(q);
}

