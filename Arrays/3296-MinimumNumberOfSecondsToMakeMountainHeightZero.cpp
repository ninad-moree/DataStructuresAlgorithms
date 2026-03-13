/*
    You are given an integer mountainHeight denoting the height of a mountain. You are also given an integer array workerTimes representing the work time of workers in seconds.
    The workers work simultaneously to reduce the height of the mountain. For worker i: To decrease the mountain's height by x, it takes workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x seconds. For example:
    To reduce the height of the mountain by 1, it takes workerTimes[i] seconds. To reduce the height of the mountain by 2, it takes workerTimes[i] + workerTimes[i] * 2 seconds,
    and so on. Return an integer representing the minimum number of seconds required for the workers to make the height of the mountain 0.

    Example 1:
    Input: mountainHeight = 4, workerTimes = [2,1,1]
    Output: 3
    Explanation: One way the height of the mountain can be reduced to 0 is:
    Worker 0 reduces the height by 1, taking workerTimes[0] = 2 seconds. Worker 1 reduces the height by 2, taking workerTimes[1] + workerTimes[1] * 2 = 3 seconds.
    Worker 2 reduces the height by 1, taking workerTimes[2] = 1 second. Since they work simultaneously, the minimum time needed is max(2, 3, 1) = 3 seconds.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(long long mid, long long ht, vector<int>& workerTimes) {
        long long totalHeight = 0;

        for(auto i : workerTimes) {
            long long l = 0;
            long long r = 1e6;

            while(l <= r) {
                long long m = l + (r-l)/2;

                if(i * m * (m+1) / 2 <= mid)
                    l = m+1;
                else
                    r = m-1;
            }

            totalHeight += r;
            if(totalHeight >= ht)
                return true;
        }

        return totalHeight >= ht;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long start = 0;
        long long end = 1e18;
        long long ans = 0;

        while(start <= end) {
            long long mid = start + (end-start)/2;

            if(solve(mid, mountainHeight, workerTimes)) {
                end = mid-1;
                ans = mid;
            } else
                start = mid+1;
        }

        return ans;
    }
};