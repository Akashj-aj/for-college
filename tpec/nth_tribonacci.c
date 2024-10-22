#include <stdio.h>

int tribonacci(int n) {
	int i;
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    int Tn_3 = 0, Tn_2 = 1, Tn_1 = 1;
    int Tn = 0;

    for (i = 3; i <= n; i++) {
        Tn = Tn_3 + Tn_2 + Tn_1; 
        
        Tn_3 = Tn_2;
        Tn_2 = Tn_1;
        Tn_1 = Tn;
    }

    return Tn;
}

int main() {
    int n1 = 4;
    int n2 = 25;

    printf("T_%d = %d\n", n1, tribonacci(n1));
    printf("T_%d = %d\n", n2, tribonacci(n2));

    return 0;
}
