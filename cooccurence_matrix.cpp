#include <unordered_map>
using namespace std;

// Nested hash map for sparse co-occurrence matrix
unordered_map<int, unordered_map<int, int>> co_occur;

// Function to update co-occurrence counts
void updateCoOccurrence(int itemA, int itemB) {
    if (itemA == itemB) return; // Skip self-pairing if not needed
    co_occur[itemA][itemB]++;
    co_occur[itemB][itemA]++; // Maintain symmetry
}