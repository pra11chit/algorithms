#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

void AddEdge(auto &adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void PrintGraph(auto &adjList) {
    for(int i = 0; i < adjList.size(); ++i) {
        cout << i << endl;
        for(int j = 0; j < adjList[i].size(); ++j) {
            cout << "->" << adjList[i][j]; 
        }
        cout << endl;
    }
}

void BfsShortestPath(auto &adjList, int s) {
    set<int> explored;
    explored.insert(s);
    queue<int> adjacent;
    vector<int> dist(4);
    adjacent.push(s);
    dist[s] = 0;
    int vertex;
    vector<int>::iterator itr;
    while(!adjacent.empty()) {
        vertex = adjacent.front();
        adjacent.pop();
        for(itr = adjList[vertex].begin(); itr != adjList[vertex].end(); ++itr) {
            if(!explored.count(*itr)) {
                dist[*itr] = dist[vertex] + 1;
                adjacent.push(*itr);
                explored.insert(*itr);
            }
        }
    }
    cout << endl;
    for(int j = 0; j < 4; ++j) {
        cout << "Shortest Distance of Vertex " << j << " is " << dist[j];
        cout << endl;
    }
}


int main() {
    vector<vector<int>> adjList(4);
    AddEdge(adjList, 0, 1);
    AddEdge(adjList, 0, 2);
    AddEdge(adjList, 1, 3);
    AddEdge(adjList, 2, 3);
    PrintGraph(adjList);
    BfsShortestPath(adjList, 0);
    return 0;
}
