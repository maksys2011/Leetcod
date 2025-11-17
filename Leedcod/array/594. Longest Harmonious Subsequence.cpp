#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        int n = nums.size();
        if(!std::is_sorted(nums.begin(), nums.end()))
        {
          std::sort(nums.begin(), nums.end());
        }
        int harmonic_array{0};
        int left{0};
        for(int right = 0; right < n; right++){
            while(nums[right] - nums[left] > 1){
                left++;
            }
            if(nums[right] - nums[left] == 1){
                if(right - left + 1 > harmonic_array) harmonic_array = right - left + 1;
            }

        }
       return harmonic_array;
    }
};



