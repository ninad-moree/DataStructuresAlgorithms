/*
    You may recall that an array arr is a mountain array if and only if:
        arr.length >= 3
    There exists some i with 0 < i < arr.length - 1 such that:
        arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
        arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
    Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. 
    If such an index does not exist, return -1.

    You cannot access the mountain array directly. You may only access the array using a MountainArray interface:
        MountainArray.get(k) returns the element of the array at index k (0-indexed).
        MountainArray.length() returns the length of the array.
*/

#include<bits/stdc++.h>
using namespace std;

class MountainArray {
  public:
    int get(int index);
    int length();
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int start = 0; 
        int end = mountainArr.length() - 1;
        int peak = -1;

        // Find the peak
        while(end != start){
           peak = start + (end - start) / 2;
           if(mountainArr.get(peak) < mountainArr.get(peak + 1) ){
              start = peak + 1;
           }
           else end = peak;
        }
        peak = start;

        // Search in ascending sub array
        start = 0, end = peak;
        while(start <= end){
           int targetIndex = start + (end - start) / 2;
           int currentElement = mountainArr.get(targetIndex);
           if(currentElement == target ) return targetIndex;
           else if(currentElement > target){
               end = targetIndex - 1;
           }
           else start = targetIndex + 1;
        }

        // Search in descending sub array
        start = peak, end = mountainArr.length() - 1;
        while(start <= end){
           int targetIndex = start + (end - start) / 2;
           int currentElement = mountainArr.get(targetIndex);
           if(currentElement == target ) return targetIndex;
           else if(currentElement > target){
               start = targetIndex + 1;
           }
           else  end = targetIndex - 1;
        }

        return -1;
    }
};