#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

const int size = 4;
vector<pair<int, int>> adj[size];
vector<bool> marked(size, false);
set<int> X;
vector<int> spd(size);

bool iswholemarked() {
    for (bool i : marked) {
        if (i == false) {
            return true;
        }
    }
    return false;
}

void AddEdge(int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
}

void dijkstra(int s) {
    set<int>::iterator iter;
    X.insert(s);
    spd[s] = 0;
    marked[s] = true;
    int mindist = 10001, dist = 0; //taking random large value 
    int minu = 0, minv = 0;
    while (iswholemarked()) {
        for (iter = X.begin(); iter != X.end(); ++iter) {
            for (int j = 0; j < adj[*iter].size(); ++j) {
                if (marked[(adj[*iter][j]).first] == false) {
                    dist = spd[*iter] + (adj[*iter][j]).second;
                    if (dist < mindist) {
                        mindist = dist;
                        minu = *iter;
                        minv = (adj[*iter][j]).first;
                    }
                }
            }
        }
        X.insert(minv);
        marked[minv] = true;
        spd[minv] = mindist;
        mindist = 10001;
    }
}

int main() {
    
    AddEdge(1, 0, 4);
    AddEdge(1, 2, 1);
    AddEdge(2, 0, 2);
    AddEdge(2, 3, 6);
    AddEdge(0, 3, 3);   
    
    //print the graph
    for(int i = 0; i < 4; ++i) {
        cout << "Vertex " << i << endl;
        for(int j = 0; j < adj[i].size(); ++j) {
            cout << "-->" << (adj[i][j]).first << "[weight: " << (adj[i][j]).second << " ]";
        }
        cout << endl;
    }

    int s;
    cin >> s;
    dijkstra(s);

    for (int i : spd) {
        cout << i << " ";
    }

    return 0;
}