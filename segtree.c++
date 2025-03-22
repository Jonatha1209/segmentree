#include <bits/stdc++.h>

using namespace std;

vector<long long> arr, seg;

void init(long long start, long long end, long long node) {
    if (start == end) {
        seg[node] = arr[start];
        return;
    }
    long long mid = (start + end) / 2;
    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

void update(long long start, long long end, long long tar, long long node) {
    if (start > tar || end < tar) return;
    if (start == end) {
        seg[node] = arr[tar];
        return;
    }
    long long mid = (start + end) / 2;
    if (tar <= mid) update(start, mid, tar, node * 2);
    else update(mid + 1, end, tar, node * 2 + 1);
    
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

long long query(long long start, long long end, long long ts, long long te, long long node) {
    if (start > te || end < ts) return 0;
    if (ts <= start && end <= te) return seg[node];
    
    long long mid = (start + end) / 2;
    long long a = query(start, mid, ts, te, node * 2);
    long long b = query(mid + 1, end, ts, te, node * 2 + 1);
    return a + b;
}
