/*
    The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, 
    and the median is the mean of the two middle values.
    For example, for arr = [2,3,4], the median is 3.
    For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
    Implement the MedianFinder class:
        MedianFinder() initializes the MedianFinder object.
        void addNum(int num) adds the integer num from the data stream to the data structure.
        double findMedian() returns the median of all elements so far. 
    Answers within 10-5 of the actual answer will be accepted.
    
    Example 1:
    Input
        ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
        [[], [1], [2], [], [3], []]
    Output
        [null, null, null, 1.5, null, 2.0]
    Explanation
        MedianFinder medianFinder = new MedianFinder();
        medianFinder.addNum(1);    // arr = [1]
        medianFinder.addNum(2);    // arr = [1, 2]
        medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
        medianFinder.addNum(3);    // arr[1, 2, 3]
        medianFinder.findMedian(); // return 2.0
*/

#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    double median = 0;
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    MedianFinder() {}

    int signum(int a, int b) {
        if(a==b)     
            return 0;
        else if(a>b) 
            return 1;
        else         
            return -1;
    }
    
    void addNum(int num) {
        switch( signum(maxi.size(), mini.size())) {
            case 0:
                if(num > median) {
                    mini.push(num);
                    median = mini.top();
                }
                else {
                    maxi.push(num);
                    median = maxi.top();
                }
                break;
            
            case 1:
                if(num > median) {
                    mini.push(num);
                    median = ( mini.top() + maxi.top() ) /2.0;
                }
                else {
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(num);
                    median = ( mini.top() + maxi.top() ) /2.0;
                }
                break;

            case -1:
                if(num > median) {
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(num);
                    median = ( mini.top() + maxi.top() ) /2.0;
                }
                else {
                    maxi.push(num);
                    median = ( mini.top() + maxi.top() ) /2.0;
                }
                break;
        }
    }
    
    double findMedian() {
        return median;
    }
};
