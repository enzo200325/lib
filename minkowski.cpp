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

#define all(x) begin(x), end(x)
const double eps = 1e-6; 

struct pt {
    double x, y; 
    double cross(const pt& o) { return x * o.y - y * o.x; } 
    double dist2(const pt& o) { return x * o.x + y * o.y; }
    bool operator<(const pt& o) const { return make_pair(x, y) < make_pair(o.x, o.y); }
    pt operator+(const pt& o) { return pt(x + o.x, y + o.y); } 
    pt operator-(const pt& o) { return pt(x - o.x, y - o.y); }
    pt operator-() { return pt(-x, -y); }

};  

vector<pt> minkowski(vector<pt> P, vector<pt> Q) {
    // assumes P and Q are convex 
    rotate(min_element(all(P)), all(P)); 
    rotate(min_element(all(Q)), all(Q)); 

    vector<pt> ret = {P[0] + Q[0]}; 

    int i = 0, j = 0; 
    while (i < (int)P.size()-1 || j < (int)Q.size()-1) {
        if (i == (int)P.size() - 1) j++; 
        else if (j == (int)Q.size() - 1) i++; 
        else {
            pt vi = P[i+1] - P[i]; 
            pt vj = Q[j+1] - Q[j]; 
            if (vi.cross(vj) > 0) i++; 
            else j++; 
        } 
        ret.emplace_back(P[i] + P[j]); 
    } 

    ret.emplace_back(P[i] + P[j]); // ???? need this? 
    return ret; 
} 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    vector<pt> P = {{2, 0}, {2, 2}, {0, 2}, {1, 1}, {1, 0}, {0, 1}, {0, 0}};  
}
















