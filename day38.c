#include <stdio.h>
#define MAX 100

int arr[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return front == -1;
}

// Check full
int full() {
    return (rear + 1) % MAX == front;
}

// Push front
void push_front(int x) {
    if (full()) {
        printf("Deque is full\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    arr[front] = x;
}

// Push back
void push_back(int x) {
    if (full()) {
        printf("Deque is full\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    arr[rear] = x;
}

// Pop front
int pop_front() {
    if (empty()) return -1;

    int val = arr[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    return val;
}

// Pop back
int pop_back() {
    if (empty()) return -1;

    int val = arr[rear];

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }

    return val;
}

// Front element
int get_front() {
    if (empty()) return -1;
    return arr[front];
}

// Rear element
int get_back() {
    if (empty()) return -1;
    return arr[rear];
}

// Size
int size() {
    if (empty()) return 0;
    return (rear - front + MAX) % MAX + 1;
}

// Display deque
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", arr[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
