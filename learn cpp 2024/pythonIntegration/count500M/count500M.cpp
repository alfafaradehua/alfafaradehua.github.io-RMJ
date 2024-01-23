#include <iostream>
#include <chrono>

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();

    long long int total = 0;
    for (long long int i = 1; i <= 500000000LL; ++i) {
        total++;
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    std::cout << "Counting to 500 million and incrementing a variable took " << duration.count()
              << " milliseconds. Final value: " << total << std::endl;

    return 0;
}
