#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>>table;
        std::vector<std::vector<std::string>>result;

        for(const std::string s : strs){
            std::string key = s;
            std::sort(key.begin(), key.end());
            table[key].push_back(s);
        }

        for(const auto& pair : table){
            result.push_back(pair.second);
        }
        return result;
    }
};

