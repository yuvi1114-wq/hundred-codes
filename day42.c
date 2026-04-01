#include <stdio.h>

#define MAX 100

// Queue
int queue[MAX];
int front = 0, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1) return;
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    if (front > rear) return -1;
    return queue[front++];
}

// Push to stack
void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}

// Pop from stack
int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int main() {
    int n, x;
    scanf("%d", &n);

    // Input queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Queue → Stack
    while (front <= rear) {
        push(dequeue());
    }

    // Step 2: Stack → Queue
    front = 0;
    rear = -1;
    while (top != -1) {
        enqueue(pop());
    }

    // Output reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
