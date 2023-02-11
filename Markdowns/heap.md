# Heap

## Description
- Tree based data structure
- Complete Binary tree
- Most of times can be implemented with arrays
- Parent node is always greater/lesser than child nodes
- 0th index of array always contains smallest/largest element.

-----

## Approach

### Push 
- Insert element at last index of array
- while child comes befores parent
  - swap child and parent
  - change current child -> parent
  - parent -> (child-1)/2

### Pop
- Remove element from 0th index of array
- Insert last element of array in 0th index, and decrease size of array by 1
- parent -> 0, child = value that comes first among child nodes (2*parent+1 , 2*parent+2)
- while child comes before parent
  - swap child and parent
  - change parent-> child
  - child -> value that comes first among child nodes (2*parent+1 , 2*parent+2)


------

## Complexity

> **Time Complexity**
>
> Push - O(log(n))
>
> Pop - O(log(n))
>
> ---
>
> **Space Complexity** - O(n)