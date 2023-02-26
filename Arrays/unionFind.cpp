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