#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
double calculate_area(triangle tr) {
    double s = (tr.a + tr.b + tr.c) / 2.0;
    return sqrt(s * (s - tr.a) * (s - tr.b) * (s - tr.c));
}

int compare_areas(const void *a, const void *b) {
    double area1 = calculate_area(*(triangle *)a);
    double area2 = calculate_area(*(triangle *)b);

    if (area1 < area2) return -1;
    else if (area1 > area2) return 1;
    return 0;
}
void sort_by_area(triangle* tr, int n) 
{
    qsort(tr, n, sizeof(triangle), compare_areas);
    
    
	
}

int main()
{
	int n;
	int i;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}

