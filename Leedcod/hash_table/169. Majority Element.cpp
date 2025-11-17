#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate = nums[0];
        int counter = 1;
        size_t size = nums.size();
    for (int i = 1; i < size; i++) {
        if (nums[i] == candidate) counter++;
        else counter--;
        
        if (counter == 0){
            candidate = nums[i];
            counter++;
            }
    }
    int target = size / 2 + 1;
    int examination = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] == candidate) examination++;
    }
    if (examination >= target) return candidate;
    else return -1;
    }
};