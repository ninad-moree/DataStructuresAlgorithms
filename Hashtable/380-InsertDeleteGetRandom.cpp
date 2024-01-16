/*
    Implement the RandomizedSet class:
    RandomizedSet() Initializes the RandomizedSet object.
    bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
    bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
    int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists 
    when this method is called). Each element must have the same probability of being returned.
    You must implement the functions of the class such that each function works in average O(1) time complexity.

    Example 1:
    Input
    ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
    [[], [1], [2], [2], [], [1], [2], []]
    Output
    [null, true, false, true, 2, true, false, 2]
*/

#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> numIndex;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (numIndex.find(val) != numIndex.end()) 
            return false;

        nums.push_back(val);
        numIndex[val] = nums.size() - 1;

        return true;
    }

    bool remove(int val) {
        if (numIndex.find(val) == numIndex.end()) 
            return false;

        int lastElement = nums.back();
        int indexToRemove = numIndex[val];

        nums[indexToRemove] = lastElement;
        numIndex[lastElement] = indexToRemove;

        nums.pop_back();
        numIndex.erase(val);

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};