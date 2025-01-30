class Solution {
public:
    char findTheDifference(string s, string t) {
         char result = 0; // Initialize with 0 since XOR with 0 doesn't change the value
        for (char c : s) {
            result ^= c; // XOR all characters in s
        }   
        for (char c : t) {
            result ^= c; // XOR all characters in t
        }
        return result; 
    }
};