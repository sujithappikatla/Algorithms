#include <bits/stdc++.h>

using namespace std;

struct COMP
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
    {
        if(a.first == b.first) a.second > b.second;
        return a.first < b.first;
    }
};

template <class T, class CMP>
class HEAP
{
public:
    T arr[10000];
    int ind=0;
    CMP comparator;
    void up( )
    {
        T temp =  arr[ind];
        int child = ind;
        int parent = (ind-1)/2;
        while(child)
        {
            if(comparator(arr[parent], temp) ) break;
            
            arr[child] = arr[parent];
            child = parent;
            parent = (child-1)/2;
        }
        arr[child] = temp; 
    }

    void down()
    {
        T temp = arr[0];
        int parent = 0;
        int child = 2*parent+1;
        while(child < ind)
        {
            if(child+1 < ind && comparator(arr[child+1], arr[child])) child++;
            if(comparator(temp, arr[child])) break;

            arr[parent] = arr[child];
            parent = child;
            child = 2*parent+1;

        } 
        arr[parent] = temp;
    }

    void push(T value)
    {
        arr[ind] = value;
        up();
        ind++;
    }
    T pop()
    {
        T temp = arr[0];
        arr[0] = arr[--ind];
        down();
        return temp;
    }
    bool empty()
    {
        if(ind<=0) return true;
        return false;
    }
    void reset()
    {
        ind=0;
    }
};


int main()
{
    //depending on comparator min heap/max heap is decided
    HEAP<pair<int, int>, COMP> hp;
    hp.push({2,7});
    hp.push({2,5});
    hp.push({1,2});
    hp.push({5,4});
    hp.push({0,4});

    while(!hp.empty())
    {
        auto val = hp.pop();
        cout<<val.first<<" "<<val.second<<endl;
    }
    cout<<endl;

    return 0;
}