#include <unordered_map>
#include <string>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) 
    {
      if (s.size() != t.size()) return false;
      std::unordered_map<char, char> st, ts;
      for(size_t i = 0; i < s.size(); i++){
        char a = s[i];
        char b = t[i];
        if(st.count(a) && st[a] != b) return false;
        if(ts.count(b) && ts[b] != a) return false;

        st[a] = b;
        ts[b] = a;
      }
      return true;
    }
};