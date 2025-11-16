#include <string>
#include <stack>
#include <vector>

class Solution {
public:
    bool isValid(std::string s) {
    std::stack<char, std::vector<char>>str; 
    for (char ch : s) {
    if (ch == '(' || ch == '[' || ch == '{'){
        str.push(ch);
        continue;
    }
    else if (str.empty()){
        return false;
    }
    if (str.top() == '(' && ch == ')'){
        str.pop();
    }
    else if (str.top() == '{' && ch == '}') {
        str.pop();
    }
    else if (str.top() == '[' && ch == ']') {str.pop();
    }
    else return false;
    }
    if (str.empty()) return true;
       
    return false; 
}
};