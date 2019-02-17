
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
std::ostream &operator<<(std::ostream &stream, const std::map<T1, T2>& map)
{
    for (typename std::map<T1, T2>::const_iterator it = map.begin();
         it != map.end();
         ++it)
    {
        stream << (*it);
    }
    return stream;
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
    int n, w;
    scanf("%d", &n);
    scanf("%d", &w);
    printf("%d\n", n);
    printf("%d\n", w);

    vector<pair<int, int>> items(n, make_pair(0, 0));
    REP(i, n) {
        int item_weight, item_value;
        scanf("%d", &item_weight);
        scanf("%d", &item_value);
        items[i].first = item_weight;
        items[i].second = item_value;
        cout << items[i];
    }

    map<int,int> dp{
        {w, 0},
    };
    REP(i, n) {
        int weight = items[i].first;
        int value = items[i].second;

        dp
    }

    cout << endl << "map" << endl;
    cout << dp;
    return 0;
}
