#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    void update(int idx, int start, int end, int pos, int val) {
        if (start == end) {
            tree[idx] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (pos <= mid) update(2*idx, start, mid, pos, val);
        else update(2*idx+1, mid+1, end, pos, val);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }

    int query(int idx, int start, int end, int l, int r) {
        if (r < start || l > end) return 0;
        if (l <= start && end <= r) return tree[idx];
        int mid = (start + end) / 2;
        return query(2*idx, start, mid, l, r) + query(2*idx+1, mid+1, end, l, r);
    }
};

int main() {
    int zones = 8;
    SegmentTree segTree(zones);

    // Mark congestion at zone 3
    segTree.update(1, 0, zones-1, 3, 1);

    // Query congestion in zones 2 to 5
    cout << "Congestion count in zones 2-5: " << segTree.query(1, 0, zones-1, 2, 5) << endl;

    return 0;
}
