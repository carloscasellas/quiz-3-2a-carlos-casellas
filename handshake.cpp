#include <iostream>
#include <thread>
#include <mutex>
// include additional necessary headers

using namespace std;

mutex m;

void query(int curr) {

    m.lock();
    cout << "[" << curr << "] SYN ... ";
    m.unlock();
}

void response() {

    m.lock();
    cout << "ACK" << endl;
    m.unlock();

}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: ./handshake <count>\n");
        exit(1);
    }

    /**
     * Steps to follow:
     * 1. Get the "count" from cmd args
     * 2. Create necessary synchronization primitive(s)
     * 3. Create two threads, one for "SYN" and the other for "ACK"
     * 4. Provide the threads with necessary args
     * 5. Update the "query" and "response" functions to synchronize the output
    */

    int count = std::stoi(argv[1]);

    for(int i = 0; i < count; ++i) {

        thread t1(query, i);
        thread t2(response);

        t1.join();
        t2.join();

    }


   
    return 0;
}