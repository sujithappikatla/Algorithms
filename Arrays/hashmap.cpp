#include <bits/stdc++.h>

using namespace std;

#define HASHMAP_SIZE 100000
#define HASHMAP_MOD 10000

template <typename K, typename V, typename H>
class HASHMAP
{
public:
    struct NODE
    {
        K key;
        V value;
        bool deleted;
        int hnext;
    };

    NODE pool[HASHMAP_SIZE];
    int pool_ind=1;

    H hashCalculator;

    int hashmap[HASHMAP_MOD];

    HASHMAP(){reset();}

    void add(K k, V v)
    {
        int hash = hashCalculator(k, HASHMAP_MOD);
        
        pool[pool_ind] = {k, v,false, 0};
        pool[pool_ind].hnext = hashmap[hash];
        hashmap[hash] = pool_ind++;
    }
    bool exist(K k)
    {
        int hash = hashCalculator(k, HASHMAP_MOD);
        int id = hashmap[hash];
        while(id && !(pool[id].key == k && !pool[id].deleted)) id= pool[id].hnext;

        return (id!=0);
    }
    V get(K k)
    {
        int hash = hashCalculator(k, HASHMAP_MOD);
        int id = hashmap[hash];
        while(id && !(pool[id].key == k && !pool[id].deleted)) id= pool[id].hnext;

        return pool[id].value;
    }
    void erase(K k)
    {
        int hash = hashCalculator(k, HASHMAP_MOD);
        int id = hashmap[hash];
        while(id && !(pool[id].key == k && !pool[id].deleted)) id= pool[id].hnext;

        pool[id].deleted = true;
    }
    void reset()
    {
        pool_ind = 0;
        for(int i=0;i<HASHMAP_MOD;i++) hashmap[i]=0;
    }

};


struct NODE
{
    int val1;
    int val2;
};

NODE pool[5];
int pool_ind = 0;


struct HASH_FUNC
{
    int operator()(string str, int mod )
    {
        int ii=0;
        int ret = 0;
        while(str[ii] != '\0')
        {
            ret = ret + str[ii++];
        }
        return ret%mod;
    }
};

int main()
{
    HASHMAP<string, NODE*, HASH_FUNC> hm;
    
    pool[pool_ind] = {5,55};
    hm.add("five", &pool[pool_ind++]);
    pool[pool_ind] = {88,8888};
    hm.add("eightyeight", &pool[pool_ind++]);
    pool[pool_ind] = {2,22};
    hm.add("two", &pool[pool_ind++]);

    cout<<"Is one exists : "<<hm.exist("one")<<endl;
    cout<<"Is two exists : "<<hm.exist("two")<<endl;
    cout<<"Is wot exists : "<<hm.exist("wot")<<endl;
    hm.erase("two");
    cout<<"Is two exists after erase : "<<hm.exist("two")<<endl;

    cout<<"five : "<<hm.get("five")->val2<<endl;
    cout<<"eightyeight : "<<hm.get("eightyeight")->val2<<endl;

    return 0;
}