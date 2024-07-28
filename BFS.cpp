#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

void BFS(int nV, int nE, int S, vector<int> v[]) {
    vector<bool> visited (nV + 1, false);

    queue<int> q;
    q.push(S);
    visited[S] = true;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        cout << vertex << " ";

        for (auto u : v[vertex]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
    int nV, nE, S;

    ifstream fpIN;
    fpIN.open("data.txt");
    fpIN >> nV >> nE >> S;

    vector<int> v[nV + 1];
    
    for (int i = 0; i < nE; i++) {
        int a, b;
        fpIN >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    fpIN.close();

    BFS(nV, nE, S, v);

    return 0;
}