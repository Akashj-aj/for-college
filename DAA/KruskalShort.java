import java.util.*;

class KruskalShort {

    static class Edge implements Comparable<Edge> {
        int u, v, w;
        Edge(int u, int v, int w) { this.u = u; this.v = v; this.w = w; }
        public int compareTo(Edge e) { return this.w - e.w; }
    }

    static int find(int[] parent, int i) {
        if (parent[i] != i)
            parent[i] = find(parent, parent[i]); // Path compression
        return parent[i];
    }

    static void union(int[] parent, int[] rank, int x, int y) {
        int xRoot = find(parent, x), yRoot = find(parent, y);
        if (rank[xRoot] < rank[yRoot]) parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot]) parent[yRoot] = xRoot;
        else { parent[yRoot] = xRoot; rank[xRoot]++; }
    }

    public static void main(String[] args) {
        int V = 4;
        List<Edge> edges = Arrays.asList(
            new Edge(0, 1, 10),
            new Edge(0, 2, 6),
            new Edge(0, 3, 5),
            new Edge(1, 3, 15),
            new Edge(2, 3, 4)
        );

        Collections.sort(edges);
        int[] parent = new int[V], rank = new int[V];
        for (int i = 0; i < V; i++) parent[i] = i;

        int mstWeight = 0;
        System.out.println("Edges in MST:");
        for (Edge e : edges) {
            int x = find(parent, e.u), y = find(parent, e.v);
            if (x != y) {
                System.out.println(e.u + " -- " + e.v + " == " + e.w);
                mstWeight += e.w;
                union(parent, rank, x, y);
            }
        }
        System.out.println("Total weight: " + mstWeight);
    }
}