#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int maxNumberOfBalloons(std::string text) {
        std::unordered_map<char, int> table = {
                                            {'b', 0},
                                            {'a', 0},
                                            {'l', 0},
                                            {'o', 0},
                                            {'n', 0}};
        std::string str = "balloon";
        for(char ch : text){
            if(table.count(ch)) table[ch]++;
        }
        int result = -1;
        std::string tmp = str;
        while(tmp == str){
            tmp.clear();
            for(const auto it : str){
                char ch = it;
                if(table.count(ch) && table[ch] > 0) {
                   table[ch]--; 
                   tmp += ch;
                }
                else{
                    break;
                }         
        }
        result++;
    }
        return result;
    }
};
