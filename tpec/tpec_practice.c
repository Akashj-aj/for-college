#include <stdio.h>
int tribonacci(int n) {
    if (n == 0) return 0;
    if (n < 3) return 1;
    int a = 0, b = 1, c = 1, next;
    for (int i = 3; i <= n; i++) {
        next = a + b + c;
        a = b;
        b = c;
        c = next;
    }
    return c;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", tribonacci(n));
    return 0;
}
