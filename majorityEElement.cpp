class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int candidate = nums[0];
        int count = 1;
        
        // Boyer-Moore Voting Algorithm
        for (int i = 1; i < nums.size(); ++i) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        // Return the majority element (as per the problem, it is guaranteed to exist)
        return candidate;  
    }
};