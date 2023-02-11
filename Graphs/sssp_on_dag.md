# Single Source Shortest Path On DAG

## Description
- To find Shortest Distance from source vertex to all other vertices
- Faster when compared to Djikstra and Bellman-Ford
- Works only For Directed Acyclic Graphs(DAG)
- Works for both positive and negative edge weights
- Depends on topological ordering

----

## Approach
- Intialize **dist** array of size **n** to **INFINITY** and dist[s]=0, where **s** is source vertex
- For every vertex **u** in topological order
    - Do following for every **adjacent** vertex **v** of **u**
      - if dist[u] + weight(u,v) < dist[v]
        - dist[v] = dist[u] + weight(u, v)
- Print **dist** array for minimum distances from source **s**

```
Note - Longest Distance from Source vertex can also be found, if we multiply all edges weights with -1 and Apply above algorithm and finally multiply all distances with -1
```
----

## Complexity

> Time Complexity - O(V+E)
>
> Space Complexity - O(V)