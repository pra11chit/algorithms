//
#include <iostream>
#include <set> //for keeping track of explored/unexplored
#include <vector> //for adjacency list representation
#include <stack>
using namespace std;

void AddEdge(vector<vector<int>> &adjList, int u, int v) {
    adjList[u].push_back(v);
}

void PrintGraph(vector<vector<int>> &adjList) {
    for(int i = 0; i < adjList.size(); ++i) {
        for(vector<int>::iterator itr = adjList[i].begin(); itr != adjList[i].end(); ++itr) {
            cout << (*itr) << "-->";
        }
    }
    cout << endl;
}

void DfsTopo(vector<vector<int>> &adjList, int i, set<int> &explored, stack<int> &order) {
    explored.insert(i);
    for(vector<int>::iterator itr = adjList[i].begin(); itr != adjList[i].end(); ++itr) {
        if(!explored.count(*itr)) {
            DfsTopo(adjList, *itr, explored, order);
        }
    }
    order.push(i);
}

void TopoSort(vector<vector<int>> &adjList) {
    stack<int> order;
    set<int> explored;
    for(int i = 0; i < adjList.size(); ++i) {
        if(!explored.count(i)) {
            DfsTopo(adjList, i, explored, order);
        }
    }
    while(order.empty() == false) {
        cout << order.top() << "->";
        order.pop();
    }
}

int main() {
    vector<vector<int>> adjList(4);
    cout << adjList.size() << endl;
    AddEdge(adjList, 2, 0);
    AddEdge(adjList, 2, 3);
    AddEdge(adjList, 0, 1);
    AddEdge(adjList, 3, 1);
    PrintGraph(adjList);
    TopoSort(adjList);
    return 0;
}
