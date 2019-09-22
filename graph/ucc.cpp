//undirected connected components
//finding the no of connected components
//if two vertices have same cc value then they are in same component
//
//input
//0 4
//2 4
//6 4
//8 4
//1 3
//5 7
//5 9
//b


#include <iostream>
#include <vector>
#include <set>
#include <deque>
using namespace std;

void AddEdge(vector<vector<int> >& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void PrintGraph(vector<vector<int> >& adjList) {
    for(int i = 0; i < adjList.size(); ++i) {
        cout << "Vertex " << i << endl;
        for(int j = 0; j < adjList[i].size(); ++j) {
            cout << "-->" << adjList[i][j];
        }
        cout << endl;
    }
}

void Ucc(vector<vector<int> >& adjList, int s, int d) {
    set<int> explored;
    deque<int> adjacent;
    vector<int> cc(10);
    int numCc = 0;
    for(int i = 0; i < 10; ++i) {
        if(!explored.count(i)) {
            numCc += 1;
            explored.insert(i);
            adjacent.push_back(i);
        }
        while(adjacent.size() != 0) {
            int vertex = adjacent.front();
            adjacent.pop_front();
            for(vector<int>::iterator itr = adjList[vertex].begin();
                    itr != adjList[vertex].end(); ++itr) {
                cc[*itr] = numCc;
                if(explored.count(*itr) == 0) {
                    adjacent.push_back(*itr);
                    explored.insert(*itr);
                }
            }
        }
    }
    cout << "no of connected components :" << numCc << endl;
    if(cc[d] == cc[s])
        cout << "both are in same connected component" << endl;
    else
        cout << "both are not" << endl;
}

int main() {
    vector<vector<int> > adjList(10);
    int u,v;
    while(cin >> u && cin >>v) {
        AddEdge(adjList, u, v);
    }
    PrintGraph(adjList);
    Ucc(adjList, 2, 0);
    
    return 0;
}
