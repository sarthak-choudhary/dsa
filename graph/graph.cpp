#include <iostream>
#include <queue>
using namespace std;

// Printing the graph using depth first search
void print(int** edges, int n, int sv, bool* visited) {
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++) {
        if (i == sv) {
            continue;
        }
        if (edges[sv][i] == 1) {
            if (visited[i]) {
                continue;
            }

            print(edges, n, i, visited);
        }
    }
}

//Printing the graph using breadth first search
void bsf_print(int** edges, int n, int sv, bool* visited) {
    queue<int> vertices;
    vertices.push(sv);
    visited[sv] = true;

    while(vertices.size() != 0) {
        cout << vertices.front() << " ";
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }

            if (edges[vertices.front()][i] == 1) {
                vertices.push(i);
                visited[i] = true;
            }
        }

        vertices.pop();
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            bsf_print(edges, n, i, visited);
            break;
        }
    }

}

int main() {
    int n;
    int e;

    cin >> n >> e;

    int** edges = new int*[n];

    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];

        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int f, s;
        cout << "enter the vertices forming an edge" << endl;

        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool* visited = new bool[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    print(edges, n, 0, visited);

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    bsf_print(edges, n, 0, visited);

    delete [] visited;

    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }

    delete [] edges;
}

