#include <stdlib.h>
#include <stdio.h>

#define EMPTY -1
#define SUCCESS_VALUE 1
#define ERROR_VALUE -1

typedef struct Stack {
    unsigned int capacity;
	int* items;
    int top;
} Stack;

Stack* create(unsigned int capacity) {
    Stack* new_stack = malloc(sizeof(Stack));
    if (!new_stack) {
        return NULL;
    }
    new_stack->capacity = capacity;
    new_stack->top = EMPTY;
    new_stack->items = malloc(capacity * sizeof(int));
    return new_stack;
}

void delete(Stack* s) {
    free(s->items);
    free(s);
}

int is_empty(Stack* s) {
    if (s->top == EMPTY) {
        return 1;
    } else {
        return 0;
    }
}

int is_full(Stack* s) {
    if (s->top == s->capacity - 1) {
        return 1;
    } else {
        return 0;
    }
}

int get_capacity(Stack* s) {
    return s->capacity;
}

int num_items(Stack* s) {
    return s->top + 1;
}

int push(Stack* s, int value) {
    if (is_full(s)) {
        printf("Error: cannot push item %d to the stack: stack full\n", value);
        return ERROR_VALUE;
    } else {
        s->top++;
        s->items[s->top] = value;
        return SUCCESS_VALUE;
    }
}

int pop(Stack* s) {
    if (is_empty(s)) {
        printf("Error: cannot pop from the stack: stack empty\n");
        return ERROR_VALUE;
    } else {
        s->top--;
        return s->items[s->top + 1];
    }
}

int peek(Stack* s) {
    if (is_empty(s)) {
        printf("Error: cannot peek from the stack: stack empty\n");
        return ERROR_VALUE;
    } else {
        return s->items[s->top];
    }
}

void print(Stack* s) {
    if (num_items(s) > 0) {
        printf("(top) -> ");
        for (int i = num_items(s) - 1; i >= 0; i--) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    } else {
        printf("(stack is empty)\n");
    }
}

int is_equal(Stack* s1, Stack* s2) {
    int is_equal = 0;
    if (num_items(s1) == num_items(s2)) {
        is_equal = 1;
        for (int i = 0; i < num_items(s1); i++) {
            if (s1->items[i] != s2->items[i]) {
                is_equal = 0;
                break;
            }
        }
    }
    return is_equal;
}

void reverse(Stack* s) {
    int n = num_items(s);
    for (int i = 0; i < n/2; i++) {
        int temp = s->items[i];
        s->items[i] = s->items[n - i - 1];
        s->items[n - i - 1] = temp;
    }
}

int main() {

    Stack* s1 = create(6);
    Stack* s2 = create(6);
    push(s1, 1);
    push(s1, 3);
    push(s1, 5);
    push(s1, 7);
    push(s1, 42);
    push(s1, 17);
    print(s1);
    print(s2);
    printf("Check whether s1 is full: %d\n", is_full(s1));
    printf("Check whether s2 is full: %d\n", is_full(s2));
    printf("Number of elements in s1: %d\n", num_items(s1));
    printf("Number of elements in s2: %d\n", num_items(s2));
    printf("Overflow test... ");
    push(s1, 99);
    printf("Element popped from s1: %d\n", pop(s1));
    printf("Element popped from s1: %d\n", pop(s1));
    printf("Element peeked from s1: %d\n", peek(s1));
    for (int i = 0; i < 4; i++) {
        push(s2, i + i + 1);
    }
    print(s1);
    print(s2);
    printf("Comparison of s1 with s2: %d\n", is_equal(s1, s2));
    printf("Element popped from s2: %d\n", pop(s2));
    printf("Comparison of s1 with s2: %d\n", is_equal(s1, s2));
    for (int i = 0; i < 4; i++) {
        pop(s1);
    }
    print(s1);
    print(s2);
    printf("Check whether s1 is empty: %d\n", is_empty(s1));
    printf("Check whether s2 is empty: %d\n", is_empty(s2));
    printf("Underflow test... ");
    pop(s1);
    printf("Underflow test... ");
    peek(s1);
    push(s2, 9);
    push(s2, 8);
    push(s2, 2);
    print(s2);
    reverse(s2);
    print(s2);
    delete(s1);
    delete(s2);
    return 0;
}
