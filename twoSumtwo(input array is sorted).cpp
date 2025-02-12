class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int left = 0, right = numbers.size() - 1;
            
            while (left < right) {
                int sum = numbers[left] + numbers[right];
                
                if (sum == target)
                    return {left + 1, right + 1}; // Return 1-based indices
                
                if (sum < target)
                    left++;  // Move left pointer to increase the sum
                else
                    right--; // Move right pointer to decrease the sum
            }
            
            return {}; // No solution found
        }
    };
    