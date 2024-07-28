#include <iostream>
#include <fstream>
#define MAX_VERTICES 100

using namespace std;

void readFile(string fileName, int &nV, int &nE, int graph[][MAX_VERTICES + 1], int &src_vertex) {
    ifstream fpIN;
    fpIN.open(fileName);

    if (!fpIN) {
        cout << "File does not exits" << "\n";
        return;
    }

    fpIN >> nV >> nE >> src_vertex;

    for (int i = 0; i <= nV; i++)
        for (int j = 0; j <= nV;j ++) 
            graph[i][j] = 0;


    for (int i = 0; i < nE; i++) {
        int a, b, w;
        fpIN >> a >> b >> w;
        graph[a][b] = w;
        graph[b][a] = w;
    }

    fpIN.close();
}

int findMinDist(int nV, int dist[], bool visited[]) {
    int min = INT_MAX;
    int min_index = -1;

    for (int i = 0; i <= nV; i++) {
        if (!visited[i] && dist[i] < min) {
            min_index = i;
            min = dist[i];
        }
    }

    return min_index;
}

void dijkstra(int nV, int nE, int graph[][MAX_VERTICES + 1], int src_vertex) {
    int dist[nV + 1];

    bool visited[nV + 1];

    for (int i = 0; i <= nV; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src_vertex] = 0;

    for (int count = nV; count >= 0; count--) {
        int u = findMinDist(nV, dist, visited);

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v <= nV; v++) {
            if (!visited[v] && graph[u][v]
                && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Display result 
    for (int i = 0; i <= nV; i++)
        if (dist[i] != INT_MAX)
            cout << dist[i] << " ";
        
    cout << "\n";
}

int main() {
    int nV, nE, src_vertex;
    int graph[MAX_VERTICES + 1][MAX_VERTICES + 1];

    readFile("data_weight.txt", nV, nE, graph, src_vertex);

    dijkstra(nV, nE, graph, src_vertex);

    return 0;
}