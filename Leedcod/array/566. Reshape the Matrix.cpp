#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
        int counter{0};
        for(auto i : mat){
            for(auto j : i){
                counter++;
            }
        }
        if(counter != r * c) return mat;
        std::vector<std::vector<int>>new_matrix(r);
        int a{0},b{0},g{0},d{0};
        while(a < mat.size() && g < r){
            while(b < mat[a].size() && d < c){
                new_matrix[g].push_back(mat[a][b]);
                b++;
                d++;
            }
            if(b == mat[a].size()) 
            {
                b = 0;
                a++;
            }
            if(d == c)
            {
                d = 0;
                g++;
            }
        }      
        return new_matrix;
    }
};