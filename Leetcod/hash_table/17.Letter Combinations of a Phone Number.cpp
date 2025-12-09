#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// "ad","ae","af","bd","be","bf","cd","ce","cf"

class Solution {
public:
  std::vector<std::string> letterCombinations(std::string &digits) {
    std::vector<int>nums = conversion_from_string_to_number(digits);
    std::vector<std::string>table(10, "");
    int n = nums.size();
    table[2] = "abc";
    table[3] = "def";
    table[4] = "ghi";
    table[5] = "jkl";
    table[6] = "mno";
    table[7] = "pqrs";
    table[8] = "tuv";
    table[9] = "wxyz";
    std::vector<std::string>result;
    int i = 0;
    std::string str;
    for(char ch : table[nums[i]])
    {
      str += ch;
      if(i + 1 < n){
        i++;
        for(char ch : table[nums[i]]){
          str += ch;
          if(i + 1 < n)
          {
            i++;
            for(char ch : table[nums[i]]){
              str += ch;
              if(i + 1 < n){
                i++;
                for(char ch : table[nums[i]]){
                  str += ch;
                  result.push_back(str);
                  str.pop_back();
                }
                i--;
              }else{
                result.push_back(str);}
              str.pop_back();
            }
            i--;
          }else{
            result.push_back(str);}
          str.pop_back();
        }
        i--;
      }else{
        result.push_back(str);}
      str.pop_back();
    }
    return result;
  }
private:
  std::vector<int> conversion_from_string_to_number(const std::string str){
    int number;
    std::stringstream ss(str);
    while(ss >> number){}
    std::vector<int>nums;
    while(number > 0){
      nums.push_back(number % 10);
      number = number / 10;
    }
    std::reverse(nums.begin(), nums.end());
    return nums;
  }
};

int main()
{
  Solution s;
  std::string str = "5678";
  std::vector<std::string> words = s.letterCombinations(str);
  for(auto it : words){
    std::cout << it << std::endl;
  }
  return 0;
}