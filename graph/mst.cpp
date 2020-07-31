#include <iostream>
#include <algorithm>

using namespace std;

class Edge {
    public:
    int v1;
    int v2;
    int weight;

    void set(int to, int from, int w) {
        v1 = to;
        v2 = from;
        weight = w;
    }

    void print() {
        if (v1 < v2) {
            cout << v1 << " " << v2 << " ";
        } else {
            cout << v2 << " " << v1 << " ";
        }

        cout << weight << endl;
    }
};

bool compareEdge(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int main() {
    int V, E;
    cin >> V >> E;

    Edge graph[E];

    for (int i = 0; i < E; i++) {
        int v1;
        int v2;
        int weight;

        cin >> v1 >> v2 >> weight;
        graph[i].set(v1, v2, weight);
    }

    Edge mst[V - 1];

    int* parents = new int[V];

    for (int i = 0; i < V; i++) {
        parents[i] = i;
    }

    sort(graph, graph + E, compareEdge);

    int i {};
    int count {};

    while (count < V - 1) {
        Edge currentEdge = graph[i];
        int v1 = currentEdge.v1;
        int v2 = currentEdge.v2;
        int p1;
        int p2;

        while (parents[v1] != v1) {
            v1 = parents[v1];
        }

        p1 = v1;

        while (parents[v2] != v2) {
            v2 = parents[v2];
        }

        p2 = v2;
        
        if (p2 != p1) {
            mst[count] = currentEdge;
            count++;

            parents[v1] = p2;
        }

        i++;
    }

    for (int i = 0; i < V - 1; i++) {
        mst[i].print();
    }

    return 0;
}