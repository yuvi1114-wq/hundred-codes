#include <stdio.h>
#include <string.h>

#define MAX 1000

int arr[MAX];
int size = 0;

// Insert element (sorted order)
void insert(int x) {
    int i = size - 1;

    // Shift elements greater than x to right
    while (i >= 0 && arr[i] > x) {
        arr[i + 1] = arr[i];
        i--;
    }

    arr[i + 1] = x;
    size++;
}

// Delete highest priority (smallest element)
int deletePQ() {
    if (size == 0) return -1;

    int val = arr[0];

    // Shift all elements left
    for (int i = 1; i < size; i++) {
        arr[i - 1] = arr[i];
    }

    size--;
    return val;
}

// Peek highest priority
int peek() {
    if (size == 0) return -1;
    return arr[0];
}

int main() {
    int n;
    scanf("%d", &n);

    char op[10];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deletePQ());
        }
        else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}
