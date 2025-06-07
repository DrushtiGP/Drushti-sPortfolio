#include <iostream>
#include <deque>

using namespace std;

class SlidingWindow {
private:
    deque<int> window;
    int windowSize;
    int runningSum;

public:
    SlidingWindow(int size) {
        windowSize = size;
        runningSum = 0;
    }

    // Insert new data point
    void insert(int value) {
        window.push_back(value);
        runningSum += value;

        // If window exceeds size, remove oldest
        if (window.size() > windowSize) {
            runningSum -= window.front();
            window.pop_front();
        }
    }

    // Get sum of current window
    int getSum() {
        return runningSum;
    }

    // Get average of current window
    double getAverage() {
        if (window.empty()) return 0.0;
        return static_cast<double>(runningSum) / window.size();
    }

    // Optional: Get current window contents
    void printWindow() {
        cout << "Window: ";
        for (int val : window) cout << val << " ";
        cout << endl;
    }
};

int main() {
    SlidingWindow tracker(5); // Window of size 5

    tracker.insert(2);
    tracker.insert(4);
    tracker.insert(1);
    tracker.insert(3);
    tracker.insert(5);
    tracker.printWindow();
    cout << "Sum: " << tracker.getSum() << endl;
    cout << "Average: " << tracker.getAverage() << endl;

    tracker.insert(6); // This will remove 2
    tracker.printWindow();
    cout << "Sum: " << tracker.getSum() << endl;
    cout << "Average: " << tracker.getAverage() << endl;

    return 0;
}
