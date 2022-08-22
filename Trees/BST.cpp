#include<iostream>

using namespace std;

struct NODE
{
  int val;
  NODE* left;
  NODE* right;
};

NODE pool[10000];
int pool_ind=0;


NODE* newNode(int val)
{
  NODE* n = &pool[pool_ind++];
  n->val = val;
  n->left = nullptr;
  n->right = nullptr;
  return n;
}



NODE* insert(NODE* ptr, NODE* val)
{
  if(ptr==nullptr) return val;
  if(ptr->val > val->val)
  {
    ptr->left = insert(ptr->left, val);
  }
  else
  {
    ptr->right = insert(ptr->right, val);
  }
  return ptr;
}

bool search(NODE* ptr, int val)
{
  if(ptr == nullptr) return false;
  if(val == ptr->val) return true;
  else if(ptr->val > val) return search(ptr->left, val);
  else 
    return search(ptr->right, val);
}

NODE* minNode(NODE* ptr)
{
  NODE* temp = ptr;
  while(temp && temp->left) temp = temp->left;
  return temp;
}

NODE* remove(NODE* ptr, int val)
{
  if(ptr==nullptr) return nullptr;

  if(ptr->val > val) ptr->left = remove(ptr->left, val);
  else if(ptr->val < val) ptr->right = remove(ptr->right, val);
  else
  {
    if(ptr->left == nullptr)
    {
      return ptr->right;
    }else if(ptr->right == nullptr)
    {
      return ptr->left;
    }else
    {
      NODE* temp = minNode(ptr->right);
      ptr->val = temp->val;
      ptr->right = remove(ptr->right, temp->val);
    }
  }
  return ptr;
}


void init()
{
  pool_ind = 0;
}

int main()
{
  NODE* root = nullptr;
  int nums[5] = {99,55,3,778,1};
  for(int i=0;i<5;i++)
    {
      NODE* n = newNode(nums[i]);
      root = insert(root, n);
    }
  cout<<search(root, 1)<<endl;
  cout<<search(root, 99)<<endl;
  cout<<search(root, 3)<<endl;
  cout<<search(root, 779)<<endl;

  root = remove(root, 1);
  root = remove(root, 99);
  root = remove(root, 3);
  root = remove(root, 55);
  root = remove(root, 778);
  cout<<search(root, 1)<<endl;
  cout<<search(root, 99)<<endl;
  cout<<search(root, 778)<<endl;
  cout<<search(root, 779)<<endl;

  
  return 0;
}