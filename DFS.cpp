#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

void DFS(int nV, int nE, int S, vector<int> v[]) {
    stack<int> st;
    vector<bool> visited(nV + 1, false); 

    st.push(S);

    while (!st.empty()) {
        int a_vertex = st.top();
        st.pop();

        if (!visited[a_vertex]) {
            cout << a_vertex << " ";
        
            visited[a_vertex] = true;

            for (auto u = v[a_vertex].rbegin(); u != v[a_vertex].rend(); ++u) {
                if (!visited[*u])
                    st.push(*u);
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

    DFS(nV, nE, S, v);
    
    return 0;
}