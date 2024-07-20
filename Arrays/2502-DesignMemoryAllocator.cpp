/*
    You are given an integer n representing the size of a 0-indexed memory array. All memory units are initially free. You have a memory 
    allocator with the following functionalities: Allocate a block of size consecutive free memory units and assign it the id mID.
    Free all memory units with the given id mID.
    Note that:
    Multiple blocks can be allocated to the same mID.
    You should free all the memory units with mID, even if they were allocated in different blocks.
    Implement the Allocator class:
    Allocator(int n) Initializes an Allocator object with a memory array of size n.
    int allocate(int size, int mID) Find the leftmost block of size consecutive free memory units and allocate it with the id mID. Return the 
    block's first index. If such a block does not exist, return -1. int free(int mID) Free all memory units with the id mID. Return the number 
    of memory units you have freed.

    Example 1:

    Input
    ["Allocator", "allocate", "allocate", "allocate", "free", "allocate", "allocate", "allocate", "free", "allocate", "free"]
    [[10], [1, 1], [1, 2], [1, 3], [2], [3, 4], [1, 1], [1, 1], [1], [10, 2], [7]]
    Output
    [null, 0, 1, 2, 1, 3, 1, 6, 3, -1, 0]
*/

#include<bits/stdc++.h>
using namespace std;

class Allocator {
public:
    vector<int> arr;
    Allocator(int n) {
        arr.resize(n, 0);
    }
    
    int allocate(int size, int mID) {
        int curr = 0;
        int idx = -1;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] == 0) {
                if(curr == 0)
                    idx = i;
                curr++;
            } else {
                curr = 0;
                idx = -1;
            }

            if(curr == size)
                break;
        }

        if(idx == -1)
            return -1;
        if(curr < size)
            return -1;

        for(int i = idx; i<idx+size; i++)
            arr[i] = mID;
        
        return idx;
    }
    
    int free(int mID) {
        int cnt = 0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] == mID) {
                arr[i] = 0;
                cnt++;
            }
        }

        return cnt;
    }
};