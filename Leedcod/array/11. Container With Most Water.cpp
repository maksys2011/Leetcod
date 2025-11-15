#include <vector>

class Solution {
public:
   int maxArea(std::vector<int>& height) {
        if(height.size() <= 1) return 0;
        int n = height.size();
        int maximum_capacity = 0;
        for(int i = 0, j = n - 1; i < j;){
            int square = (j - i) * std::min(height[i], height[j]);
            if(square > maximum_capacity) {
              maximum_capacity = square;
            }
            if(height[i] > height[j])j--;
            else i++;
    
        }
        return maximum_capacity;
    }
};