#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <climits> 
using namespace std; 
#define endl '\n'

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// ============================================================================================== // 

typedef long long ll; 

// Sum segment tree by default
// be aware of long long
struct Seg {
    Seg() {} 
    vector<int> seg, lazy; 
    int n; 

    const int neutral = 0; 
    int merge(int a, int b) { return a + b; } 

    void build_aux(int p, int l, int r, vector<int>& a) {
        if (l == r) {
            seg[p] = a[l]; 
            return; 
        } 

        int mid = l + r >> 1; 
        build_aux(p<<1, l, mid, a); 
        build_aux(p<<1|1, mid+1, r, a); 
        seg[p] = merge(seg[p<<1], seg[p<<1|1]); 
    } 
    void build(int _n) {
        n = _n; 
        seg.assign(4*n, neutral); 
        lazy.assign(4*n, neutral); 

        vector<int> a(n, neutral); 
        build_aux(1, 0, n-1, a); 
    } 
    void build(vector<int>& a) {
        n = a.size(); 
        seg.assign(4*n, neutral); 
        lazy.assign(4*n, neutral); 

        build_aux(1, 0, n-1, a); 
    } 

    void push(int p, int l, int r) {
        seg[p] += (r - l + 1) * lazy[p]; 
        if (l != r) {
            lazy[p<<1] += lazy[p]; 
            lazy[p<<1|1] += lazy[p]; 
        } 
        lazy[p] = neutral; 
    } 

    void update(int p, int l, int r, int L, int R, int v) {
        push(p, l, r); 
        if (l > R || r < L) return; 
        if (l >= L && r <= R) {
            lazy[p] += v; 
            push(p, l, r); 
            return; 
        } 
        int mid = l + r >> 1; 
        update(p<<1, l, mid, L, R, v);  
        update(p<<1|1, mid+1, r, L, R, v); 
        seg[p] = merge(seg[p<<1], seg[p<<1|1]); 
    } 
    void update(int l, int r, int v) { update(1, 0, n-1, l, r, v); } 

    int query(int p, int l, int r, int L, int R) {
        push(p, l, r); 
        if (l > R || r < L) return neutral; 
        if (l >= L && r <= R) return seg[p]; 
        int mid = l + r >> 1; 
        int q1 = query(p<<1, l, mid, L, R); 
        int q2 = query(p<<1|1, mid+1, r, L, R); 
        return merge(q1, q2); 
    } 
    int query(int l, int r) { return query(1, 0, n-1, l, r); } 
};  

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

}
















