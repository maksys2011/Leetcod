#include <string>
#include <unordered_set>

class Solution {
public:
    std::string reverseVowels(std::string s) { // "leetcode"
        int n = s.size();
        std::string result(n, ' ');
        std::unordered_set<char>table{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int begin = 0;
        int end = n - 1;
        while(begin <= n && end != begin){ 
            if(table.count(s[begin])){
                if(table.count(s[end])){
                    result[begin] = s[end];
                    result[end] = s[begin];
                    begin++;
                    end--;
                }else {
                    result[end] = s[end];
                    end--;}
            }else{
                result[begin] = s[begin]; 
                begin++;}  
                if(begin == end) result[begin] = s[begin];
        }
        return result;
    }
};
