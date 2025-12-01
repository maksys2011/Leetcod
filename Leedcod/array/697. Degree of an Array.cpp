#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findShortestSubArray(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, int>first_occurrence;
        std::unordered_map<int, int>last_occurrence;
        std::unordered_map<int, int>frequency_count;
        for(size_t i = 0; i < n; i++){
          if(!first_occurrence.count(nums[i])){
            first_occurrence[nums[i]] = i; 
          }
          last_occurrence[nums[i]] = i;
          frequency_count[nums[i]]++;
        }
        
        int degree = 0;
        for (const auto& pair : frequency_count) {
          if (pair.second > degree) {
              degree = pair.second;
            }
        }
        
        int min_length = n;
        for (const auto& pair : frequency_count) {
            int num = pair.first;
            int count = pair.second;
        if (count == degree) {
            int current_length = last_occurrence[num] - first_occurrence[num] + 1;
            if (current_length < min_length) {
                min_length = current_length;
            }
        }
        }
       return min_length;
    }
};