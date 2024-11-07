class Solution {
public:
    bool wordPattern(string pattern, string s) {
       istringstream iss(s);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }

        // Step 2: If the sizes don't match, return false
        if (words.size() != pattern.size()) return false;

        // Step 3: Use two hash maps to track correspondence
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        // Step 4: Iterate through the pattern and words simultaneously
        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string w = words[i];

            // Check if c -> w mapping exists and matches
            if (charToWord.count(c) && charToWord[c] != w) return false;

            // Check if w -> c mapping exists and matches
            if (wordToChar.count(w) && wordToChar[w] != c) return false;

            // Add to both maps
            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true; 
    }
};class Solution {
public:
    bool wordPattern(string pattern, string s) {
       istringstream iss(s);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }

        // Step 2: If the sizes don't match, return false
        if (words.size() != pattern.size()) return false;

        // Step 3: Use two hash maps to track correspondence
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        // Step 4: Iterate through the pattern and words simultaneously
        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string w = words[i];

            // Check if c -> w mapping exists and matches
            if (charToWord.count(c) && charToWord[c] != w) return false;

            // Check if w -> c mapping exists and matches
            if (wordToChar.count(w) && wordToChar[w] != c) return false;

            // Add to both maps
            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true; 
    }
};