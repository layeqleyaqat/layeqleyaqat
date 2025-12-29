#include <iostream>
#include <string> 
using namespace std;


class MyQueue {
public:
    static const int nSize = 5;
    int arr[nSize];
    int head = 0;
    int tail = -1;

    bool isEmpty() {
        return (tail < 0);
    }

    bool isFull() {
        return (tail == nSize - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full" << std::endl;
        } else {
            arr[++tail] = value;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is Empty" << std::endl;
            return -9999;
        } else {
            int value = arr[head];
            moveArray();
            return value;
        }
    }

    int front() {
        if (isEmpty()) {
            std::cout << "Queue is Empty" << std::endl;
            return -9999;
        } else {
            return arr[head];
        }
    }

    int size() {
        return (tail + 1);
    }

private:
    void moveArray() {
        for (int i = 0; i < tail; i++) {
            arr[i] = arr[i + 1]; // Each element shifts to fill the gap
        }
        tail--;
    }
};

int main() {
    MyQueue rippleQueue;
    rippleQueue.enqueue(1); 
    rippleQueue.enqueue(2);
    rippleQueue.enqueue(3);

    std::cout << "Initial size of ripple: " << rippleQueue.size() << std::endl;
    std::cout << "Front of the ripple: " << rippleQueue.front() << std::endl;

    
    std::cout << "Processing: " << rippleQueue.dequeue() << " (Restoration begins)" << std::endl;
    std::cout << "New front after shift: " << rippleQueue.front() << std::endl;

    return 0;
}
