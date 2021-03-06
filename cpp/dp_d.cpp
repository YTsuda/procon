
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>

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

int main(void){
    ll n, w;
    scanf("%lld", &n);
    scanf("%lld", &w);

    vector<pair<ll, ll>> items(n, make_pair(0, 0));
    REP(i, n) {
        ll item_weight, item_value;
        scanf("%lld", &item_weight);
        scanf("%lld", &item_value);
        items[i].first = item_weight;
        items[i].second = item_value;
    }
    std::sort(items.begin(), items.end(), [](pair<ll,ll> a, pair<ll, ll> b){ return a.first > b.first; });

    vll dp(w + 1, 0);
    REP(i, n) {
        // cout << "=====" << endl;
        ll weight = items[i].first;
        ll value = items[i].second;
        vll current_dp(w + 1, 0);
        RREP(j, w + 1) {
            ll newWeight;
            ll newValue;
            newWeight = j - weight;
            newValue = dp[j] + value;
            // cout << j << endl;

            if (newWeight >= 0) {
                ll compareValue = dp[newWeight];
                current_dp[newWeight] = max(newValue, compareValue);
            }
            // cout << "---" << endl;
            // cout << weight << "," << value << endl;
            // cout << newWeight << "," << newValue << endl;
        }
        dp = current_dp;
        // cout << dp << endl;
    }
    ll max_value = *max_element(all(dp));

    printf("%lld", max_value);
    return 0;
}
