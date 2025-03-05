class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        
        int n = haystack.size(), m = needle.size();
        if (m > n) return -1; // If needle is longer than haystack, return -1

        
        for (int i = 0; i <= n - m; ++i) {
            // Compare the substring with the needle
            if (haystack.substr(i, m) == needle) {
                return i; // Found the first occurrence, return the index
            }
        }

        
        return -1;
    }
};