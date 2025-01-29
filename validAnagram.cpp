class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        // Use an unordered_map to store character frequencies
        unordered_map<char, int> charCount;

        // Count characters in the first string
        for (char c : s) {
            charCount[c]++;
        }

        // Decrease counts based on the second string
        for (char c : t) {
            if (charCount.find(c) == charCount.end() || charCount[c] == 0) {
                return false; // Character not found or count mismatch
            }
            charCount[c]--;
        }

        // If all counts are zero, they are anagrams
        return true; 
    }
};