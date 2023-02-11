# Topological Sorting


## Description
- Linear Ordering of vertices, such that for every directed edge (u, v) -> u comes before V in ordering 
- Graph needs to be DAG(Directed Acyclic Graph)

-----

## Approach
- Create Stack to store nodes
- Maintain visited array of length **n** nodes, initialized to **false**
- Iterate all nodes, if node not visited
  - Call Recursive function to perform following 
    - Mark node as visited
    - For every directed edge going out from this node, if not visited, call recursive function
    - Push current node to Stack
- Print all nodes in Stack

***Note*** - A vertex added to stack only when all of its adjacent vertices are in Stack.

-----

## Complexity Analysis


>Time Complexity - O(V+E)
>
>Space Complexity - O(V)