#include <stdio.h>

int a[10][10], s[10], n;

void bfs(int u) {
    int f = 0, r = -1, q[10], v;
    printf("\nThe nodes reachable from %d:", u);
    q[++r] = u;
    s[u] = 1;
    printf("%d\t", u);
    while (f <= r) {
        u = q[f++];
        for (v = 0; v < n; v++) {
            if (a[u][v] == 1 && s[v] == 0) {
                printf("%d\t", v);
                s[v] = 1;
                q[++r] = v;
            }
        }
    }
}

void read_AM() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void print_AM() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}

void dfs(int u) {
    s[u] = 1;
    printf("%d\t", u);
    for (int v = 0; v < n; v++) {
        if (a[u][v] == 1 && s[v] == 0)
            dfs(v);
    }
}

int main() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    read_AM();
    printf("The adjacency matrix for the given graph:\n");
    print_AM();
    
    printf("\nBFS\n");
    for (int source = 0; source < n; source++) {
        for (int i = 0; i < n; i++) s[i] = 0;  // Reset visited nodes
        bfs(source);
    }
    
    printf("\nDFS\n");
    for (int source = 0; source < n; source++) {
        for (int i = 0; i < n; i++) s[i] = 0;  // Reset visited nodes
        printf("\nThe nodes reachable from %d:", source);
        dfs(source);
    }
    
    return 0;
}
