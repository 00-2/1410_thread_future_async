#include <iostream>
#include <array>
#include <ctime>
#include <iomanip>
#include <algorithm>

#define ARR_SIZE 100
#define n1 20
#define n2 30
#define n3 25
int main() {
    std::array<float,ARR_SIZE> arr ;
    std::srand(std::time(nullptr));
    for (int i = 0; i< ARR_SIZE; ++i){
        arr[i] = std::rand();
    }
    std::sort(arr.begin(), arr.begin()+arr.size()/2);
    std::sort(arr.begin()+arr.size()/2, arr.end());
    return 0;
}
