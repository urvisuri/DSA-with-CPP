class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         unordered_set<int> set1;
        vector<int> result;
        
        // Add all elements of nums1 to set1
        for (int num : nums1) {
            set1.insert(num);
        }
        
        // Check for common elements in nums2
        for (int num : nums2) {
            if (set1.find(num) != set1.end()) {
                result.push_back(num);
                set1.erase(num);  // Ensure each element is only added once
            }
        }
        
        return result;
    }
};