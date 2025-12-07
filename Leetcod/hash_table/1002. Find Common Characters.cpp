#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
// {"cool","lock","cook"};
class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        std::unordered_map<char, int>table;
        std::unordered_map<char, int>table2;
        int n = words.size();
        for(char ch : words[0]) table[ch]++;
        for(auto it : table){
            std::cout << it.first << " " << it.second << std::endl;
        }
        std::cout << std::endl;

        // table:
        // c -> 1
        // o -> 2
        // l -> 1

        for(size_t i = 1; i < words.size(); i++){
            for(size_t j = 0; j < words[i].size(); j++){
                table2[words[i][j]]++;
            }
            for(auto it = table.begin(); it != table.end();){
                if(!table2.count(it->first)){
                    it = table.erase(it);
                }else{
                    if(it->second > table2[it->first]){
                        table[it->first] = table2[it->first];
                    }
                    it++;
                }
            }
            table2.clear();
        }
        std::vector<std::string>result;
        for(auto it : table){
            int j = it.second;
            while(j > 0){
                std::string str;
                str.push_back(it.first);
                result.push_back(str);
                j--;
            }
        }
        

        return result;
    }
};

int main()
{
    std::vector<std::string>words{"bbddabab","cbcddbdd","bbcadcab","dabcacad","cddcacbc","ccbdbcba","cbddaccc","accdcdbb"};
    Solution s;
    std::vector<std::string> nums = s.commonChars(words);
    for(auto it : nums){
        std::cout << it << " ";
    }

    return 0;
}

