#include <iostream>
#include <vector>
#include <set>
using namespace std;


void AddEdge(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void dfs(vector<vector<int>> &adjList, set<int> &explored, int s, int v)
{
    explored.insert(s);
    int vertex = s;
    for (vector<int>::iterator iter = adjList[vertex].begin(); iter != adjList[vertex].end(); ++iter)
        {
            if (explored.count(*iter) == 0)
            {
                explored.insert(vertex);
                dfs(adjList, explored, *iter, v);
            }
        }
}

void PrintGraph(vector<vector<int>> &adjList)
{
    for (int i = 0; i < adjList.size(); ++i)
    {
        cout << "Vertex " << i << endl;
        for (int j = 0; j < adjList[i].size(); ++j)
        {
            cout << "-->" << adjList[i][j];
        }
    }
}

int main()
{
    vector<vector<int>> adjList(5);
    AddEdge(adjList, 0, 1);
    AddEdge(adjList, 0, 4);
    AddEdge(adjList, 1, 2);
    AddEdge(adjList, 1, 3);
    AddEdge(adjList, 1, 4);
    AddEdge(adjList, 2, 3);
    AddEdge(adjList, 3, 4);
    PrintGraph(adjList);
    set<int> explored;
    dfs(adjList, explored, 0, 4);
    cout << endl;
    for (set<int>::iterator iter = explored.begin();iter != explored.end(); ++iter)
    {
        cout << *iter << "\t";
    }
    cout << endl;
    return 0;
}
