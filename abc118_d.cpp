#include <stdio.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>

using namespace std;

#define REP(var, n)  for (decltype(n) var = 0; var < (n); var++)
#define RREP(var, n)  for (auto var = n - 1; var != static_cast<decltype(var)>(-1); var--)
#define FOR(var, a, b)  for (auto var = (a); var < (b); var++)
#define RFOR(var, a, b)  for (auto var = b - 1; var != a; var--)
#define all(c) begin(c),end(c)
 
template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9; 

// 多次元配列を作る
// vector<vector<int>> vn(n, vector<int>(3, 0));

// 多次元配列の dump
// for (vector<int> v : vn) {
//     cout << v;
// }

// printf("%d\n", n);
// printf("%lld\n", n);

int main(void){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    printf("%d\n", n);
    printf("%d\n", m);

    vector<int> costs{2,5,5,4,5,6,3,7,6};
    vector<pair<int, int>> vn(m);
    REP(i, m){
        int t;
        scanf("%d", &t);
        vn[i] = make_pair(t, costs[t - 1]);
    }
    std::sort(vn.begin(), vn.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });
    for (pair<int, int> p : vn) {
        cout << p.first << " : " << p.second << endl;
    }
    vector<pair<int, int>> smalls;
    return 0;
    

}
