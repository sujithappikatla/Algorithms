#include <bits/stdc++.h>

using namespace std;


void DFS(vector<vector<pair<int, int>>>& Graph, stack<int>& S , vector<bool>& vis, int node)
{
    vis[node] = true;
    for(auto neighbour : Graph[node])
    {
        if(vis[neighbour.first]) continue;
        DFS(Graph, S, vis, neighbour.first);
    }
    S.push(node);
}

void topological_sort(vector<vector<pair<int, int>>>& Graph, stack<int>& S )
{
    int n = Graph.size();
    vector<bool> visited(n, false);

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            DFS(Graph, S, visited, i);
        }
    }

}


void Single_Source_Shortest_Path_On_Directed_Acyclic_Graph(vector<vector<pair<int, int>>>& Graph, int start_node)
{
    int n = Graph.size();
    stack<int> topology_list;

    topological_sort(Graph, topology_list);

    vector<int> distances(n, INT_MAX );
    distances[start_node] = 0;

    while(!topology_list.empty())
    {
        int node = topology_list.top();
        topology_list.pop();
        
        for(auto neighbour : Graph[node])
        {
            if((unsigned long long)(distances[node] + neighbour.second) < distances[neighbour.first])
            {
                distances[neighbour.first] = distances[node] + neighbour.second;
            }
        }
    }
    
    for(auto dis: distances)
    {
        cout<<dis<<" ";
    }
    cout<<endl;

}


int main()
{
    vector<vector<pair<int, int>>> Graph(6);
    Graph[0] = {{1,5}, {2,3}};
    Graph[1] = {{3,6}, {2,2}};
    Graph[2] = {{4,4}, {5,2}, {3,7}};
    Graph[3] = {{4,-1}};
    Graph[4] = {{5,-2}};

    Single_Source_Shortest_Path_On_Directed_Acyclic_Graph(Graph, 1);

    return 0;
}