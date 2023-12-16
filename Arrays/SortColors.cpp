/*
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that 
    objects of the same color are adjacent, with the colors in the order red, white, and blue.
    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    You must solve this problem without using the library's sort function.

    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partition(vector<int>& arr, int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);
    
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quickSort(vector<int>& arr, int low, int high)
    {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
    }
};