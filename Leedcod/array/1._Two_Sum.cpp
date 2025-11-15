#include <iostream>
#include <vector>
#include <unordered_map>


class Solution {
public:
    std::vector<int>twoSum(std::vector<int>nums, int target) 
    {
        std::unordered_map<int, int>hash_table;
        int compliment{};
        for (size_t i = 0; i < nums.size(); ++i) 
            {
                compliment = target - nums[i];
                if (hash_table.count(compliment)) 
                {
                    return { hash_table[compliment], static_cast<int>(i)};
                }
                else 
                {
                    hash_table.insert({ nums[i], i });
                }
    }
        return{};
    }
};
int main(){
    return 0;
}