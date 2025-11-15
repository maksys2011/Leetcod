#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) 
    {
        if (strs.empty()) return " ";
        std::string prefix = strs[0];
        for (const auto& it : strs) {
            int i = 0;
            if (prefix[i] != it[i]) return "";
            while (prefix[i] == it[i] && i < it.size()) {
                i++;
            }
            prefix = prefix.substr(0,i);
        }
        return prefix;
    }
};