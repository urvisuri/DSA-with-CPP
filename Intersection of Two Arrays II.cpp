class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int, int> countMap;
        vector<int> result;

        // Count the occurrences of elements in nums1
        for (int num : nums1) {
            countMap[num]++;
        }

        // Check for intersections in nums2
        for (int num : nums2) {
            if (countMap[num] > 0) {
                result.push_back(num);
                countMap[num]--; // Decrease the count for matched elements
            }
        }

        return result; 
    }
};