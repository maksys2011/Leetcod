#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int prev = 0;
        int last = nums.size() - 1;
        while(last >= prev){
            int middle = prev + (last - prev) / 2;
            if(nums[middle] > target) {
                last = middle - 1;}
            if(nums[middle] < target) {
                prev = middle + 1;}
            if(nums[middle] == target) {
                return middle;}
        }
        return - 1;   
    }
};
