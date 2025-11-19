#include <vector>

class Solution {
public:
    int maxCount(int m, int n, std::vector<std::vector<int>>& ops) {
        std::vector<std::vector<int>>matrix(m, std::vector<int>(n, 0)) ;
        if(ops.size() == 0) return m * n;
        int min_a = 0;
        int min_b = 0;
        int i = 0;
        while(i < ops.size()){
            if(min_a == 0) min_a = ops[i][0];
            else{
                min_a = std::min(min_a, ops[i][0]);
            }
            if(min_b == 0) min_b = ops[i][1];
            else{
                min_b = std::min(min_b, ops[i][1]);
            }
            i++;
        }
        return min_a * min_b;
    }
};
