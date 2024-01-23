#include <iostream>
#include <chrono>

int main() {
    long long int increment;
    std::cin >> increment;  // Read the increment value from Python

    auto start_time = std::chrono::high_resolution_clock::now();

    long long int total = 0;
    for (long long int i = 1; i <= increment; ++i ) {
        total ++;
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    // Output execution time and final count to Python
    std::cout << duration.count() << " " << total << std::endl;
    std::cin.ignore();
    return 0;
}
