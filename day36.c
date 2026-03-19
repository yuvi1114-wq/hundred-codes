#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int arr[n];

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &m);

    int front = 0;
    int rear = n - 1;

    // Perform m dequeues
    for (int i = 0; i < m; i++) {
        if (n == 0) break;
        front = (front + 1) % n;
    }

    // Print elements from front to rear circularly
    int count = n;
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[(front + i) % n]);
    }

    return 0;
}
