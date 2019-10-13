#include <iostream>
#include <set>
#include <vector>
#include <stack>
using namespace std;

int numScc;

void AddEdge(vector<vector<int>> &adjList, vector<vector<int>> &adjListRev, int u, int v) {
    adjList[u].push_back(v);
    adjListRev[v].push_back(u);
}

void PrintGraph(vector<vector<int>> &adjList) {
    for(int i = 0; i < adjList.size(); ++i) {
        cout << i << ":";
        for(vector<int>::iterator itr = adjList[i].begin(); itr != adjList[i].end(); ++itr) {
            cout << (*itr) << "->";
        }
        cout << endl;
    }
}

void DfsTopo(auto adjListRev, int i, set<int> &exploredRev, stack<int> &order) {
    exploredRev.insert(i);
    vector<int>::iterator itr;
    for(itr = adjListRev[i].begin(); itr != adjListRev[i].end(); ++itr) {
        if(!exploredRev.count(*itr)) {
            DfsTopo(adjListRev, *itr, exploredRev, order);
        }
    }
    order.push(i);
}

void TopoSort(auto adjListRev, set<int> &exploredRev, stack<int> &order) {
    for(int i = 0; i < adjListRev.size(); ++i) {
        if(!exploredRev.count(i)) {
            DfsTopo(adjListRev, i, exploredRev, order);
        }
    }
}
void DfsScc(auto &adjList, int i, auto &explored, auto &scc, int numScc) {
    explored.insert(i);
    scc[i] = numScc;
    for(int j = 0; j < adjList[i].size(); ++j) {
        if(!explored.count(adjList[i][j])) {
                DfsScc(adjList, adjList[i][j], explored, scc, numScc);
        }
    }
}

void Kosaraju(auto adjList, auto adjListRev) {
    set<int> exploredRev; 
    set<int> explored;
    stack<int> order;
    vector<int> scc(adjList.size());
    TopoSort(adjListRev, exploredRev, order);
    numScc = 0;
    cout << endl << "Topological Ordering :" << endl;
    while(!order.empty()) {
        int top = order.top();
        cout << top << "-";
        order.pop();
        if(!explored.count(top)) {
            numScc = numScc + 1;
            DfsScc(adjList,top, explored, scc, numScc);
        }
    }
    cout << endl << "SCCs" << endl;
    for(int j = 0; j < scc.size(); ++j) {
        cout << scc[j] << "-";
    }
}

int main() {
    vector<vector<int> > adjList(4);
    vector<vector<int> > adjListRev(4);
    AddEdge(adjList, adjListRev, 2, 3);
    AddEdge(adjList, adjListRev, 2, 0);
    AddEdge(adjList, adjListRev, 3, 1);
    AddEdge(adjList, adjListRev, 0, 1);
    PrintGraph(adjList);
    cout << "Rev" << endl;
    PrintGraph(adjListRev);
    cout << endl;
    Kosaraju(adjList, adjListRev);
    cout << endl;
    return 0;
}
