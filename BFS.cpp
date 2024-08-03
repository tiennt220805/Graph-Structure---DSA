#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <sstream>

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

void BFS(vector<vector<int>> list, int src_vertex) {
    vector<bool> visited (list.size(), false);

    queue<int> q;
    q.push(src_vertex);

    while (!q.empty()) {
        int a_vertex = q.front();
        q.pop();

        if (!visited[a_vertex]) {
            cout << a_vertex << " ";

            visited[a_vertex] = true;

            for (int i = 0; i < list[a_vertex].size(); i++) 
                if (!visited[list[a_vertex][i]]) 
                    q.push(list[a_vertex][i]);
        }
    }

    cout << "\n";
}


int main() {
    int src_vertex;
    vector<vector<int>> list = readFileintoList("data.txt", src_vertex);

    BFS(list, src_vertex);
    
    return 0;
}