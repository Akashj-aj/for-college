#include <stdio.h>

#define MAX_TERMS 10

// Define the polynomial term structure
struct poly {
    int cf; // coefficient
    int exp; // exponent
};

// Function to add two polynomials
int add_poly(struct poly p1[], struct poly p2[], struct poly p3[], int t1, int t2) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (p1[i].exp == p2[j].exp) {
            p3[k].cf = p1[i].cf + p2[j].cf;
            p3[k].exp = p1[i].exp;
            i++;
            j++;
            k++;
        } else if (p1[i].exp > p2[j].exp) {
            p3[k].cf = p1[i].cf;
            p3[k].exp = p1[i].exp;
            i++;
            k++;
        } else {
            p3[k].cf = p2[j].cf;
            p3[k].exp = p2[j].exp;
            j++;
            k++;
        }
    }

    // Copy remaining terms from p1
    while (i < t1) {
        p3[k].cf = p1[i].cf;
        p3[k].exp = p1[i].exp;
        i++;
        k++;
    }

    // Copy remaining terms from p2
    while (j < t2) {
        p3[k].cf = p2[j].cf;
        p3[k].exp = p2[j].exp;
        j++;
        k++;
    }

    return k; // Number of terms in the resulting polynomial
}

// Function to print a polynomial
void print_poly(struct poly p[], int t) {
    for (int i = 0; i < t; i++) {
        if (i > 0 && p[i].cf >= 0) {
            printf(" + ");
        }
        printf("%dX^%d", p[i].cf, p[i].exp);
    }
    printf("\n");
}

// Main function
int main() {
    struct poly p1[MAX_TERMS] = {{5, 2}, {3, 1}, {4, 0}}; // Example polynomial 5X^2 + 3X + 4
    struct poly p2[MAX_TERMS] = {{4, 1}, {2, 0}};         // Example polynomial 4X + 2
    struct poly p3[MAX_TERMS]; // Array to store the result

    int t1 = 3; // Number of terms in p1
    int t2 = 2; // Number of terms in p2

    int t3 = add_poly(p1, p2, p3, t1, t2);

    printf("Polynomial 1: ");
    print_poly(p1, t1);

    printf("Polynomial 2: ");
    print_poly(p2, t2);

    printf("Sum of polynomials: ");
    print_poly(p3, t3);

    return 0;
}
