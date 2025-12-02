#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) 
   {
        if (nums.empty()) return -1;
        int first = 0;
        int last = nums.size() - 1;
        while (first <= last) {
            int middle = first + (last - first) / 2;
            if (nums[middle] == target) return middle;
            if (nums[middle] > target) last = middle - 1;
            else first = middle + 1;
            middle = first + (last - first) / 2;
        }
        return first;
    }
};