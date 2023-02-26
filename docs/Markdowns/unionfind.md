{% raw %}
# Disjoint Sets (Union-Find)

## Description

- Union(x,y) -> union between groups that x, y belong to
- Find(x) -> find group that x belongs to.
- Does both of these in almost Constant time.
- Optimizations - Union by Rank, Path Compresssion
- Usaully Implemented with Arrays.
- Used in krushkal Algorithm for findind minimum spanning tree (MST)

-----------

## Approach

### makeSet
- Initialize parent[i] = i
- Initialize rank[i] = 1;

### find
- if parent[x]==x
  - return x;
- else parent[x] = find(parent[x])

### union
- find rootA, rootB of a, b
- if rank[rootA] > rank[rootB]
  - parent[rootB] = rootA
- else if rank[rootA] < rank[rootB]
  - parent[rootA] = rootB
- else
  - parent[rootA] = rootB;
  - rank[rootB]++ 

---------

## Complexity Analysis

> With Optimizations like union by Rank, Path compresssion
> Time Complexity - ~O(1)
>
> Space Complexity - O(n)

---------

## Code

```cpp
#include <bits/stdc++.h>

using namespace std;

int parent[10000];
int _rank[10000];

int makeSet(int n)
{
    for(int i=0;i<=n;i++)
    {
        parent[i] = i;
        _rank[i] = 1;
    }
}

int find(int x)
{
    if(x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

void makeUnion(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);

    if(rootA == rootB) return;

    if(_rank[rootA] > _rank[rootB])
    {
        parent[rootB] = rootA;
    }
    else if(_rank[rootA] < _rank[rootB])
    {
        parent[rootA] = rootB;
    }
    else
    {
        parent[rootA] = rootB;
        _rank[rootB]++;
    }
}

int main()
{
    makeSet(5);

    makeUnion(1, 2);
    makeUnion(2,3);
    makeUnion(4,5);

    cout<<"Are 1 and 3 Related? - "<<(find(1) == find(3)) << endl;
    cout<<"Are 4 and 5 Related? - "<<(find(4) == find(5)) << endl;
    cout<<"Are 2 and 5 Related? - "<<(find(2) == find(5)) << endl;

    return 0;
}


```

```
Output

Are 1 and 3 Related? - 1
Are 4 and 5 Related? - 1
Are 2 and 5 Related? - 0

```
{% endraw %}