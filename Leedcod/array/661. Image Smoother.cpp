#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img) {
        std::vector<std::vector<int>>matrix(img.size());
        int sum{};
        int counter = 0;
        for(int i = 0; i < img.size(); i++){
            for(int j = 0; j < img[i].size(); j++){
                sum = img[i][j];
                counter = 1;
                if(i + 1 < img.size()){
                    if(j - 1 >= 0){
                        sum += img[i + 1][j - 1];
                        counter++;
                    }
                    sum += img[i + 1][j];
                    counter++;
                    if(j + 1 < img[i].size()){
                        sum += img[i + 1][j + 1];
                        counter++;
                    }
                }
                if(i - 1 >= 0){
                    if(j - 1 >= 0){
                        sum += img[i - 1][j - 1];
                        counter++;
                    }
                    sum += img[i - 1][j];
                    counter++;
                    if(j + 1 < img[i].size()){
                        sum += img[i - 1][j + 1];
                        counter++;
                    }
                }
                if(j - 1 >= 0){
                    sum += img[i][j - 1];
                    counter++;
                }
                if(j + 1 < img[i].size()){
                    sum += img[i][j + 1];
                    counter++;
                }
                matrix[i].push_back(sum / counter);
            }
        }
        return matrix;
        
    }
};
