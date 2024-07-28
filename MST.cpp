#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

typedef pair<int, int> edge; // {weight, vertex}

void MST(int nV, int nE, int S, vector<edge> v[]) {
    vector<int> minWeight (nV + 1, INT_MAX);
    vector<bool> visited (nV + 1, false);

    priority_queue<edge, vector<edge>, greater<edge>> pq;
    
    int sum = 0;

    minWeight[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (visited[node]) 
            continue;
        
        visited[node] = true;
        sum += weight;
        cout << "node: " << node << " - " << "weight: " << weight << "\n";

        for (auto u : v[node]) {
            int nextNode = u.second;
            int nextWeight = u.first;

            if (!visited[nextNode] && nextWeight < minWeight[nextNode]) {
                minWeight[nextNode] = nextWeight;
                pq.push({nextWeight, nextNode});
            }
        }
    }

    cout << sum << "\n";
}

int main() {
    int nV, nE, S;

    ifstream fpIN;
    fpIN.open("data_weight.txt");
    fpIN >> nV >> nE >> S;

    vector<edge> v[nV + 1];
    
    for (int i = 0; i < nE; i++) {
        int a, b, weight;
        fpIN >> a >> b >> weight;
        v[a].push_back({weight, b});
        v[b].push_back({weight, a});
    }

    fpIN.close();

    MST(nV, nE, S, v);

    return 0;
}