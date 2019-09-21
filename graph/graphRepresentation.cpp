#include <iostream>
#include <vector>
using namespace std;

void AddEdge(vector<int> adjList[], int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void PrintGraph(vector<int> adjList[]) {
    for(int i = 0; i < 5; ++i) {
        cout << "Vertex " << i << endl;
        for(int j = 0; j < adjList[i].size(); ++j) {
            cout << "-->" << adjList[i][j];
        }
        cout << endl;
    }
}

int main() {
    vector<int> adjList[5];
    AddEdge(adjList, 0, 1);
    AddEdge(adjList, 0, 4);
    AddEdge(adjList, 1, 2);
    AddEdge(adjList, 1, 3);
    AddEdge(adjList, 1, 4);
    AddEdge(adjList, 2, 3);
    AddEdge(adjList, 3, 4);
    PrintGraph(adjList);
    return 0;
}
