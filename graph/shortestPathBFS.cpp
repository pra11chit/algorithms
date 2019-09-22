#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;

void AddEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void PrintGraph(vector<vector<int>>& adjList) {
    for(int i = 0; i < adjList.size(); ++i) {
        cout << "vertex " << i << endl;
        for(int j = 0; j < adjList[i].size(); ++j) {
            cout << "-->" << adjList[i][j];
        }
    }
}

void IsReachable(vector<vector<int>>& adjList, int s, int d) {
    deque<int> adjacent;
    set<int> explored;
    vector<int> path(adjList.size(), 10000);
    path[s] = 0;
    adjacent.push_back(s);
    explored.insert(s);
    while(adjacent.size() != 0) {
        int vertex = adjacent.front();
        adjacent.pop_front();
        for(vector<int>::iterator itr = adjList[vertex].begin(); 
                itr != adjList[vertex].end(); ++itr) {
            if(explored.count(*itr) == 0) {
                explored.insert(*itr);
                path[*itr] = path[vertex] + 1;
                adjacent.push_back(*itr);
            }
        }
    }
    if(explored.count(d) != 0) {
        cout << d << " is reachable from " << s;
    }
    else
        cout << d << " is not reachable not from " << s;
    
    cout << endl << "distance between " << s << "and " << d << "is " << path[d];

}

int main() {
    vector<vector<int>> adjList(5);
    AddEdge(adjList, 0, 1);
    AddEdge(adjList, 0, 4);
    AddEdge(adjList, 1, 2);
    AddEdge(adjList, 1, 3);
    AddEdge(adjList, 1, 4);
    AddEdge(adjList, 2, 3);
    AddEdge(adjList, 3, 4); 
    PrintGraph(adjList);
    cout << endl;
    IsReachable(adjList, 2, 4);
    return 0;
}
