#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<int>> readFileintoList(string fileName, int &src_vertex) {
    ifstream fpIN;
    fpIN.open(fileName);

    if (!fpIN) {
        cout << "File does not exits";
        fpIN.close();
        return {};
    }

    int n;
    fpIN >> n >> src_vertex;
    fpIN.ignore();

    vector<vector<int>> list (n);

    string line_info;
    int cnt = 0;

    while (getline(fpIN, line_info)) {
        stringstream ss(line_info);

        if (line_info == "")
            break;

        int vertex;
        while (ss >> vertex) 
            list[cnt].push_back(vertex);
        
        ++cnt;
    }

    fpIN.close();

    return list;
}

void DFS(vector<vector<int>> list, int src_vertex) {
    vector<bool> visited (list.size(), false);

    stack<int> st;
    st.push(src_vertex);

    while (!st.empty()) {
        int a_vertex = st.top();
        st.pop();

        if (!visited[a_vertex]) {
            visited[a_vertex] = true;

            cout << a_vertex << " ";

            for (int i = list[a_vertex].size() - 1; i >= 0; i--) 
                if (!visited[list[a_vertex][i]]) 
                    st.push(list[a_vertex][i]);
        }
    }

    cout << "\n";
}

int main() {
    int src_vertex = 0;
    vector<vector<int>> list = readFileintoList("data.txt", src_vertex);
    
    DFS(list, src_vertex);

    return 0;
}