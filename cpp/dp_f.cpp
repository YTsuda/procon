#include <stdio.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

#define REP(var, n)  for (decltype(n) var = 0; var < (n); var++)
#define RREP(var, n)  for (auto var = n - 1; var != static_cast<decltype(var)>(-1); var--)
#define FOR(var, a, b)  for (auto var = (a); var < (b); var++)
#define RFOR(var, a, b)  for (auto var = b - 1; var != a; var--)
#define all(c) begin(c),end(c)
#define vmax(c) *max_element(all(c))
#define vmin(c) *min_element(all(c))
 
template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &p) {
    out << "[" << p.first << ", " << p.second << "]";
    return out;
}

template<typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::map<T1, T2>& map)
{
    for (typename std::map<T1, T2>::const_iterator it = map.begin();
         it != map.end();
         ++it)
    {
        out << (*it);
    }
    return out;
}

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9; 

// 2次元配列を作る
// vector<vi> my_vector(n, vi(m, 0));

// 多次元配列の dump
// for (auto v : DP) {
//     cout << v << endl;
// }

ll MAX_VALUE = 10;

string A, B;

auto solve() {
    cin >> A >> B;
    cout << A << A.size() << endl;
    cout << B << B.size() << endl;
    vector<vll> DP(A.size(), vll(B.size(), 0));
    for (auto v : DP) {
        cout << v << endl;
    }

    REP (i, A.size()) {
        cout << "==== " << A.substr(0, i + 1) << endl;

        REP (j, B.size()) {
            cout << B.substr(0, j + 1) << endl;
        }
    }

}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    // cout << solve();
}