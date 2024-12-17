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

void deque_push_right(deque *q, int data){
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

void deque_push_left(deque *q, int data){
	deque *node = malloc(sizeof(deque));
	node->data = data;
	node->next = q;
	node->pre = NULL;

	q->pre = node;
}

deque *deque_pop_left(deque *q){
	deque *node = malloc(sizeof(deque));
	node = q;
	q->next->pre = NULL;
	return node;
}

void print_deque(deque *q){
    deque *current = q->head;
    while (current != NULL) {
        printf("data: %d\n", current->data);
        current = current->next;
    }

}

int main() {
	deque *q = deque_init(25);
	print_deque(q);

	deque_push_right(q, 69);
	print_deque(q);
	deque_push_left(q, 687438);
	print_deque(q);

	deque_pop_left(q);
	print_deque(q);
}

