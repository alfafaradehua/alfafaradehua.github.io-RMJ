// #include <iostream>

// int main() {
//     std::cout << "Hello, World!" << std::endl;
//     return 0;

// }

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::queue<std::string> messageQueue;
std::mutex mutexQueue;
std::condition_variable condVar;

void producer() {
    for (int i = 0; i < 5; ++i) {
        std::string message = "Message " + std::to_string(i);
        
        {
            std::unique_lock<std::mutex> lock(mutexQueue);
            messageQueue.push(message);
        }

        condVar.notify_one();  // Notify consumer that a new message is available
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::thread producerThread(producer);

    while (true) {
        std::unique_lock<std::mutex> lock(mutexQueue);

        condVar.wait(lock, []{ return !messageQueue.empty(); });

        std::string message = messageQueue.front();
        messageQueue.pop();

        lock.unlock();  // Unlock before processing to allow producer to push more messages

        // Send the message to Python program
        std::cout << message << std::endl;
    }

    producerThread.join();

    return 0;
}
