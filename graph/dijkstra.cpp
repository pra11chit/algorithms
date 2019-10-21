//Input:- directed graph G with adjacency list representation, vertex s, length of each edge
//Post-Condition:-shortest path dist of every vertex
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <limits.h>
using namespace std;

void AddEdge(auto &adjList, int u, int v) {
    adjList[u].push_back(v);
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

void dijkstra(auto &adjList, int s, auto &len) {
    set<int> explored;
    explored.insert(s);
    vector<int> dist(4, INT_MAX);
    dist[s] = 0;
    set<int>::iterator set_itr;
    int min = 0;
    int d_value;
    int vstar, wstar;
    while(explored.size() != adjList.size()) { 
        for(set_itr = explored.begin(); set_itr != explored.end(); ++set_itr) {
            for(int i = 0; i < adjList[(*set_itr)].size(); ++i) {
                if(!explored.count(adjList[*set_itr][i])) {
                    if(i == 0 && set_itr == explored.begin()) {
                        min = dist[0] + len[adjList[0][0]];
                    }
                    d_value = dist[*set_itr] + len[adjList[*set_itr][i]];
                    if(d_value <= min) {
                        min = d_value;
                        vstar = *set_itr;
                        wstar = adjList[*set_itr][i];
                    }
                }
            }
        }
    explored.insert(wstar);
    dist[wstar] = d_value;

    }
    cout << endl;
    for(int j = 0; j < adjList.size(); ++j) {
        cout << j << "-" << dist[j];
    }
}

int main() {
    vector<vector<int>> adjList(4);
    AddEdge(adjList, 0, 1);
    AddEdge(adjList, 0, 2);
    AddEdge(adjList, 1, 3);
    AddEdge(adjList, 2, 3);
    PrintGraph(adjList);
    vector<int> len = {5, 10, 15, 20};
    dijkstra(adjList, 0, len);
    return 0;
}
