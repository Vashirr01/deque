#include <stdio.h>
#include <stdlib.h>

typedef struct nodes{
	int key;
	int value;
} nodes;

typedef struct deque{
	nodes head;
	nodes next;
} deque;

int main() {
	printf("hello\n");
}

deque *deque_init(int value){

}
