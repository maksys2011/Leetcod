#include <iostream>

void insetionsSort(int *A, int size)
{
    int n = size;
    for(size_t i = 1; i < n; ++i){
        int k = i;
        int key = A[k];
       while(k > 0 && A[k - 1] > key){
            int temp = A[k - 1];
            A[k - 1] = key;
            A[k] = temp;
            k--;
       }
    }
}


int main()
{
    int A[10] = {100, 67, 76, 34, 98, 45, 2, 5, 9, 1};
    for(auto it : A){
        std::cout << it << " " ;
    }
    std::cout << std::endl;
    insetionsSort(A, 10);
    std::cout << "insetions sotr" << std::endl;
    for(auto it : A){
        std::cout << it << " " ;
    }
    std::cout << std::endl;
    return 0;
}
