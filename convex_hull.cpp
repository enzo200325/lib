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

const double eps = 1e-6; 

struct pt {
    double x, y; 
    double cross(const pt& o) { return x * o.y - y * o.x; } 
    double dist2(const pt& o) { return x * o.x + y * o.y; }
    bool operator<(const pt& o) const { return make_pair(x, y) < make_pair(o.x, o.y); }
};  

double cross(const pt& p, const pt& q, const pt& r) {
    pt vq = {q.x - p.x, q.y - p.y}; 
    pt vr = {r.x - p.x, r.y - p.y}; 
    return vq.cross(vr); 
} 

void sort_points(vector<pt>& P) {
    int n = P.size(); 
    sort(P.begin(), P.end()); 
    pt pivot = P[0]; 
    sort(P.begin(), P.end(), [&](const pt& p, const pt& q) {
            pt vp = {p.x - pivot.x, p.y - pivot.y}; pt vq = {q.x - pivot.x, q.y - pivot.y};  
            return vp.cross(vq); 
    });  
} 

vector<pt> convex_hull(vector<pt> P, bool collinear = 0) {
    sort(P.begin(), P.end()); 
    int n = P.size(); 
    vector<pt> upper_hull = {P[0]}; 
    vector<pt> lower_hull = {P[0]}; 
    for (int i = 1; i < n; i++) {
        if (cross(P[0], P[n-1], P[i]) >= 0) {
            while (upper_hull.size() > 1) {
                double cr =cross(upper_hull.end()[-2], upper_hull.end()[-1], P[i]); 
                if (cr > (collinear ? eps : -eps)) {
                    upper_hull.pop_back(); 
                } 
                else break; 
            } 
            upper_hull.emplace_back(P[i]); 
        } 
        else {
            while (lower_hull.size() > 1) {
                double cr = cross(lower_hull.end()[-2], lower_hull.end()[-1], P[i]); 
                if (cr < (collinear ? -eps : eps)) {
                    lower_hull.pop_back(); 
                } 
                else break ;
            } 
            lower_hull.emplace_back(P[i]); 
        } 
    } 
    reverse(lower_hull.begin(), lower_hull.end()); 
    lower_hull.pop_back(); 
    upper_hull.insert(upper_hull.end(), lower_hull.begin(), lower_hull.end()); 
    return upper_hull; 
} 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    vector<pt> P = {{0, 0}, {2, 0}, {2, 2}, {0, 2}, {1, 1}, {1, 0}, {0, 1}};  
    vector<pt> hull = convex_hull(P, 1); 
    for (auto [x, y] : hull) {
        debug(x, y); 
    } 
    cout << hull.size() << endl;
}
















