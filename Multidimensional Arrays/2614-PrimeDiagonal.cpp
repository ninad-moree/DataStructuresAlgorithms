/*
    You are given a 0-indexed two-dimensional integer array nums. Return the largest prime number that lies on at least one of the diagonals of nums.
    In case, no prime is present on any of the diagonals, return 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n == 1)
            return false;

        for (int i=2; i*i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        int maxi = 0;

        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums.size(); j++) {
                if(i==j && isPrime(nums[i][j]))
                    maxi = max(maxi, nums[i][j]);
                if(j==nums.size()-i-1 && isPrime(nums[i][j])) 
                    maxi = max(maxi, nums[i][j]);
            }
        }

        return maxi;
    }
};