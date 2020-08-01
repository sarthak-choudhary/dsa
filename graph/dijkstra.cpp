#include <iostream>
#include <climits>

using namespace std;

void dijkstra(int** graph, int V, int* distance, bool* visited) {
    int minDistanceVertex = -1;

    for (int i = 0; i < V; i++) {
        if ((minDistanceVertex == -1 || distance[i] < distance[minDistanceVertex]) && visited[i] == false) {
            minDistanceVertex = i;
        }
    }

    visited[minDistanceVertex] = true;

    for (int i = 0; i < V; i++) {
        if (graph[minDistanceVertex][i] != 0 && visited[i] == false) {
            int totalDistance = distance[minDistanceVertex] + graph[minDistanceVertex][i];

            if (totalDistance < distance[i]) {
                distance[i] = totalDistance;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            dijkstra(graph, V, distance, visited);
        }
    }
}

int main() {
    int V, E;

    cin >> V >> E;

    int** graph = new int*[V];

    for (int i = 0; i < V; i++) {
        graph[i] = new int[V];

        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++) {
        int v1, v2, weight;

        cin >> v1 >> v2 >> weight;
        graph[v1][v2] = weight;
        graph[v2][v1] = weight;
    }

    int* distance = new int[V];
    bool* visited = new bool[V];

    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[0] = 0;

    dijkstra(graph, V, distance, visited);
    
    for (int i = 0; i < V; i++) {
        cout << i << " "<< distance[i] << endl;
    }

}