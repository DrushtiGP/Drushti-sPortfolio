#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

// Number of top similar items to maintain
const int K = 5;

// Min-heap to keep Top-K items: (similarity score, item ID)
priority_queue<pair<float, int>, vector<pair<float, int>>, greater<>> topK;

// Function to maintain Top-K most similar items in min-heap
void maintainTopK(float simScore, int itemId) {
    if (topK.size() < K) {
        topK.emplace(simScore, itemId);  // Directly add if under K items
    } else if (simScore > topK.top().first) {
        topK.pop();                      // Remove lowest score
        topK.emplace(simScore, itemId); // Add better one
    }
}

// Utility function to display top-K items
void printTopK() {
    vector<pair<float, int>> result;

    // Copy elements out to display (heap gets emptied in the process)
    while (!topK.empty()) {
        result.push_back(topK.top());
        topK.pop();
    }

    // Optional: Sort by similarity descending for display
    sort(result.rbegin(), result.rend());

    cout << "Top " << K << " similar items:\n";
    for (auto& [score, id] : result) {
        cout << "Item ID: " << id << ", Similarity Score: " << score << "\n";
    }
}

int main() {
    // Example similarities for item 101
    vector<pair<float, int>> candidateSimilarities = {
        {0.92, 201}, {0.85, 202}, {0.78, 203}, {0.81, 204},
        {0.95, 205}, {0.76, 206}, {0.88, 207}, {0.83, 208}
    };

    // Maintain top-K for item 101
    for (auto& [score, itemId] : candidateSimilarities) {
        maintainTopK(score, itemId);
    }

    printTopK();

    return 0;
}
