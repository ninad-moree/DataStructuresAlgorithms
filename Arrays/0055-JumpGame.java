/*
    You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents 
    your maximum jump length at that position. Return true if you can reach the last index, or false otherwise.

    Example 1:
    Input: nums = [2,3,1,1,4]
    Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;

        if(n<=1)
            return true;
        
        if(nums[0]==0) 
            return false;
        
        int maxReach = nums[0];
        int steps = nums[0];
        
        @SuppressWarnings("unused")
        int jumps = 1;

        for(int i=1;i<n;i++) {
            if (i == n-1) 
                return true;

            maxReach = Math.max(maxReach, i+nums[i]);
            steps--;

            if(steps == 0) {
                jumps++;
                if(i>=maxReach)
                    return false;
                
                steps = maxReach-i;
            }
        }
        return false;
    }
}