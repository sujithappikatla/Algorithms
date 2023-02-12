#include <bits/stdc++.h>

using namespace std;
#define INF 99999999

void Dijsktra(int Graph[9][9], int source )
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

    vector<int> distances(9, INF);
    distances[source] = 0;

    PQ.push({source,0});

    while(!PQ.empty())
    {
        pair<int, int> p = PQ.top();
        PQ.pop();

        if(p.second > distances[p.first]) continue;

        for(int i=0;i<9;i++)
        {
            if(Graph[p.first][i] == 0) continue;

            int dist = distances[p.first] + Graph[p.first][i];
            if(dist < distances[i])
            {
                distances[i] = dist;
                PQ.push({i, distances[i]});
            }

        }
    }

    
    for(auto x: distances)
    {
        cout<<x<<" ";
    }
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