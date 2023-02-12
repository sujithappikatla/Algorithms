{% raw %}
# Dijsktra

## Description
- **Shortest path** from source vertex to all vertices
- Works on **directed** and **undirected** edges
- Only works for **positive edge weights**.
- Best way of Implementation is by using **priority queue** or **indexed heap** along with **adjancency list**. This will result in **O(E*log(V))**

---

## Approach
- Take **Prority Queue**/ Indexed Heap for picking next optimal vertex
- Intilaize **dist** array of size **n** to **INFINITY**
- While priority queue is **not empty**
  - **pop** topmost element u
  - for every adjacent vetex **v** of **u**
    - if **dist[u] + edge_weight(u,v) < dist[v]**
      - **dist[v] = dist[u] + edge_weight(u,v)**
      - push (v, dist[v]) to priority queue


***Note :***  Shortest Path can also be stored by taking an array **'path'** of size **n**, when pushing vertex **v** store vertex **u** too, while poping insert path[v] = u. you can backtrack from destination to source vetex using this array as shown in below code


---

## Complexity

> Time Complexity - O(E * log(V))
>
> Space Complexity - O(V)

----

## Code

### Code for Finding shortest distnace from source vertex to all other vertices


```cpp
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

```

```
Output : 

0 4 12 19 21 11 9 8 14
```


### Code for storing shortest path

```cpp

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

```

```
Output : 

Distances : 
0 4 12 19 21 11 9 8 14 

Shortest Path from 0 to 4 node : 
4 <- 5 <- 6 <- 7 <- 0

```


{% endraw %}