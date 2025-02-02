class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

        // Group anagrams using sorted string as key
        for (const std::string& str : strs) {
            std::string sortedStr = str;
            std::sort(sortedStr.begin(), sortedStr.end()); // Sort to get unique key
            anagramGroups[sortedStr].push_back(str);
        }

        // Convert map values to a vector of vectors
        std::vector<std::vector<std::string>> result;
        for (const auto& group : anagramGroups) {
            result.push_back(group.second);
        }

        return result;
    }
};