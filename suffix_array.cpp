#include <bits/stdc++.h>
using namespace std;

// Build suffix array in O(n log n)
vector<int> buildSuffixArray(const string& text) {
    int n = text.length();
    vector<int> suffixArr(n), ranks(n), tempRanks(n);

    // Initial rank (based on ASCII values)
    for (int i = 0; i < n; i++) {
        suffixArr[i] = i;
        ranks[i] = text[i];
    }

    for (int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int a, int b) {
            if (ranks[a] != ranks[b])
                return ranks[a] < ranks[b];
            int ra = (a + k < n) ? ranks[a + k] : -1;
            int rb = (b + k < n) ? ranks[b + k] : -1;
            return ra < rb;
        };

        sort(suffixArr.begin(), suffixArr.end(), cmp);

        tempRanks[suffixArr[0]] = 0;
        for (int i = 1; i < n; i++) {
            tempRanks[suffixArr[i]] = tempRanks[suffixArr[i - 1]] + cmp(suffixArr[i - 1], suffixArr[i]);
        }
        ranks = tempRanks;
    }

    return suffixArr;
}

// Binary search substring using suffix array
bool substringSearch(const string& text, const vector<int>& suffixArr, const string& pattern) {
    int left = 0, right = suffixArr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        string suffix = text.substr(suffixArr[mid]);
        int cmp = suffix.compare(0, pattern.size(), pattern);
        if (cmp == 0)
            return true;
        else if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

// Example usage
int main() {
    string text = "wireless";
    vector<int> suffixArr = buildSuffixArray(text);

    vector<string> queries = {"less", "wire", "eless", "irel", "phone"};
    for (const string& q : queries) {
        cout << "Searching for '" << q << "' => "
             << (substringSearch(text, suffixArr, q) ? "Found" : "Not Found") << endl;
    }

    return 0;
}
