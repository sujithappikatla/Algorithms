#include <bits/stdc++.h>

using namespace std;
#define INF 99999999

struct NODE
{
    int current_node;
    int edge_weight;
    int previous_node;

    bool operator<(const NODE& o) const
    {
        if(o.current_node == current_node) return edge_weight < o.edge_weight;

        return current_node < o.current_node;
    }
};

void Dijsktra(int Graph[9][9], int source )
{
    priority_queue<NODE, vector<NODE>> PQ;

    vector<int> distances(9, INF);
    distances[source] = 0;

    vector<int> path(9, 0);
    path[source] = source;

    PQ.push({source,0, source});

    while(!PQ.empty())
    {
        NODE p = PQ.top();
        PQ.pop();

        if(p.edge_weight > distances[p.current_node]) continue;

        path[p.current_node] = p.previous_node;

        for(int i=0;i<9;i++)
        {
            if(Graph[p.current_node][i] == 0) continue;

            int dist = distances[p.current_node] + Graph[p.current_node][i];
            if(dist < distances[i])
            {
                distances[i] = dist;
                PQ.push({i, distances[i], p.current_node});
            }

        }
    }

    cout<<"Distances : "<<endl;  
    for(auto x: distances)
    {
        cout<<x<<" ";
    }
    cout<<endl<<endl;

    cout<<"Shortest Path from 0 to 4 node : "<<endl;
    int n = 4;
    cout<<n;
    
    do{
        n = path[n];
        cout<<" <- "<<n;
        
    }while(n != path[n]);
    
    cout<<endl;
}

int main()
{
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    Dijsktra(graph, 0);

    return 0;
}