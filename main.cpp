#include <iostream>
#include <array>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <thread>


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
    std::thread t1([&arr] {
        std::sort(arr.begin(), arr.begin() + arr.size() / 2);
        for(auto el : arr){
            std::cout << std::setprecision(3) << "THREAD1:" << el << std::endl;
            // для задержки:
            // std::cout << "THREAD1:";
            // std::this_thread::sleep_for(std::chrono::milliseconds(10));
            // std::cout << std::setprecision(3) << el << std::endl;
        }
    });
    std::thread t2([&arr] {
        std::sort(arr.begin() + arr.size() / 2, arr.end());
        for(auto el : arr){
            std::cout << std::setprecision(3) << "THREAD2:" << el << std::endl;
            // для задержки:
            // std::cout << "THREAD2:";
            // std::this_thread::sleep_for(std::chrono::milliseconds(10));
            // std::cout << std::setprecision(3) << el << std::endl;
        }
    });
    std::thread t3([&arr] {
        std::sort(arr.begin(), arr.end());
        for(auto el : arr){
            std::cout << std::setprecision(3) << "THREAD3:" << el << std::endl;
            // для задержки:
            // std::cout << "THREAD3:";
            // std::this_thread::sleep_for(std::chrono::milliseconds(10));
            // std::cout << std::setprecision(3) << el << std::endl;
        }
    });
    t1.join();
    t2.join();
    t3.join();
    std::cout << "Завершили работу";
}
