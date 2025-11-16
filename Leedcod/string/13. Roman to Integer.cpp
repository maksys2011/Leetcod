#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) 
    {
    std::unordered_map<char, int>hash_table;
    hash_table['I'] = 1;      // IV = 4;
    hash_table['V'] = 5;      // IX = 9;
    hash_table['X'] = 10;     // XL = 40;
    hash_table['L'] = 50;     // XC = 90;
    hash_table['C'] = 100;    // CD = 400;
    hash_table['D'] = 500;    // CM = 900;
    hash_table['M'] = 1000;
    int sum{};
    for(size_t i = 0; i < s.size(); ++i){
        if(hash_table[s[i]] < hash_table[s[i+1]] && (i + 1) < s.size())
    {
      int res = hash_table[s[i+1]] - hash_table[s[i]];
      sum += res;
      i++;
    }else{
      sum += hash_table[s[i]];
    }
  }
  return sum;
}
};