#include <unordered_set>
#include <cmath>

class Solution {
public:
    bool isHappy(int n)     
    {   
        std::unordered_set<int>table;
        int sum = 0;
        while(n != 1)
        {
            while(n > 0)
            {
            sum += pow(n % 10, 2);
            n = n / 10;
            }
        if(table.count(sum)){
            return false;
        }else{
            table.insert(sum);
        }
            n = sum;
            sum = 0;
        }
        return true;
    }
};