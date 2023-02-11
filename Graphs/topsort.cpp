#include <bits/stdc++.h>

using namespace std;


void DFS(vector<vector<int>>& Graph, vector<int>& ans, vector<bool>& vis , int node, int& a_ind)
{
    for(auto neighbour : Graph[node])
    {
        if(vis[neighbour]) continue;
        vis[neighbour] = true;
        DFS(Graph, ans, vis, neighbour, a_ind);
    }
    ans[a_ind--] = node;
}

void topsort(vector<vector<int>>& Graph )
{
    int n = Graph.size();
    vector<bool> visited(n, false);
    vector<int> topological_list(n,0);
    int t_ind=n-1;

    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            DFS(Graph, topological_list, visited, i, t_ind);   
        }
    }

    for(auto x:topological_list)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}


int main()
{
    cout<<"Topological sorting using TopSort"<<endl<<endl;

    vector<vector<int>> adjacency_list(6, vector<int>());
    adjacency_list[2] = {3};
    adjacency_list[3] = {1};
    adjacency_list[4] = {0,1};
    adjacency_list[5] = {2,0};

    vector<int> topological_list;

    topsort(adjacency_list);

    


    return 0;
}