#include <iostream>
#include <climits>
using namespace std;

void prim(int** graph, int V, int* parents, bool* visited, int* weights) {
    int minWeightIndex {};

    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            minWeightIndex = i;
        }
    }
    
    for (int i = 0; i < V; i++) {
        if (weights[i] < weights[minWeightIndex] && visited[i] == false) {
            minWeightIndex = i;
        }
    }
    
    visited[minWeightIndex] = true;
    
    for (int i = 0; i < V; i++) {
        if (graph[minWeightIndex][i] != 0 && visited[i] == false) {
            if (weights[i] > graph[minWeightIndex][i]) {
                weights[i] = graph[minWeightIndex][i];
                parents[i] = minWeightIndex; 
            }
        }
    }
    
    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            prim(graph, V, parents, visited, weights);
        }
    }
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */
    
    int** graph = new int*[V];
    
    for (int i = 0; i < V; i++) {
        graph[i] = new int[V];
        
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }      
    }
    
    for (int i = 0; i < E; i++) {
		int v1;
        int v2;
        int weight;
        
        cin >> v1 >> v2 >> weight;
        
        graph[v1][v2] = weight;
        graph[v2][v1] = weight;
    }

    cout << "graph input completed" << endl;
    
    int* parents = new int[V];
    int* weights = new int[V];
    
    for (int i = 0; i < V; i++) {
        weights[i] = INT_MAX;
    }
    
    bool* visited = new bool[V];
    
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    
    parents[0] = -1;
    weights[0] = 0;
	prim(graph, V, parents, visited, weights);
    
    for (int i = 1; i < V; i++) {
        if (i < parents[i]) {
            cout << i << " " << parents[i] << " ";
        } else {
            cout << parents[i] << " " << i << " ";
        }
        
        cout << weights[i] << endl;
    }
    
  return 0;
}
