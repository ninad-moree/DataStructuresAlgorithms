/*
    Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct 
    element. Implement KthLargest class: KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
    int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in 
    the stream.
    
    Example 1:
    Input:
    ["KthLargest", "add", "add", "add", "add", "add"]
    [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
    Output:
    [null, 4, 5, 5, 8, 8]
    Explanation:
    KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
    kthLargest.add(3);   // return 4
    kthLargest.add(5);   // return 5
    kthLargest.add(10);  // return 5
    kthLargest.add(9);   // return 8
    kthLargest.add(4);   // return 8
*/

#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        K = k;

        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > K)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K)
            pq.pop();
        
        return pq.top();
    }
};