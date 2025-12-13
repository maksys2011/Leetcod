#include <vector>
#include <unordered_map>

/*Example 1:
Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]

key = 1 + 2 = 3.push_back(2 + 1, 2,1);

Output: 1
Example 2:
Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
Output: 3*/

class Solution {
public:
    int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes) {
        int result = 0;
        std::unordered_map<int, std::vector<std::vector<int>>>table;
        for(auto it : dominoes){
            int key = 0;
            for(auto s : it){
                key += s;
            }
            table[key].push_back(it);
        }
        for(auto it : table){
            if(it.second.size() > 1){
                int n = it.second.size();
                result += (n * (n - 1)) / 2;
            }   
        }
        return result;
    }
};
