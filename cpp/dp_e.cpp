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
// for (auto v : my_vector) {
//     cout << v;
// }

ll MAX_VALUE = 10;

ll N, W;
vector<vll> I;
vector<ll> DP;

auto solve() {
    cin >> N >> W;
    I.resize(N);
    DP.resize(N * MAX_VALUE);
    REP(i, N) {
        ll weight, value;
        cin >> weight >> value;
        I[i] = vll{weight, value};
    }
    cout << DP << endl;
    REP(i, N) {
        cout << "===" << endl;
        ll item_weight = I[i][0];
        ll item_value = I[i][1];
        cout << item_weight << ", " << item_value << endl;
        REP(j, N * MAX_VALUE) {
            cout << "---" << endl;
            // item i を拾わない場合
            // 価値 j を実現するための weight はDPの j である
            ll passing_weight = DP[j];

            // item i を拾う場合
            // j の価値を実現するための weight は ( iの重さ + DP[j - item_value] ) である
            ll base_value = j - item_value;
            ll base_weight = DP[base_value];
            ll taking_weight = base_weight + item_weight;
            cout << base_value << "," << base_weight << endl;
            cout << passing_weight << "," << taking_weight << endl;
            DP[j] = min(passing_weight, taking_weight);
        }
    }
    cout << DP << endl;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    // cout << solve();
}