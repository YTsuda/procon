#include <stdio.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iterator>

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

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9; 

// 多次元配列を作る
// vector<vi> my_vector(n, vi(m, 0));

// 多次元配列の dump
// for (vi v : my_vector) {
//     cout << v;
// }

auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<vll> bs(m, vll(2, 0));
    vector<vll> groups(n + 1, vll(n + 1, 0));
    ll group_i = 0;

    ll cost = n * (n - 1) / 2;
    REP(i, m){
        ll a, b;
        cin >> a >> b;
        bs[i][0] = a;
        bs[i][1] = b;
    }
    for (vll b : bs) {
        cout << "====" << endl;
        ll ia = b[0];
        ll ib = b[1];
        cout << "island: " << ia << ", " << ib << endl;
        ll a_group = groups[ia][ib];
        ll b_group = groups[ib][ia];
        cout << "group : " << a_group << ", " << b_group << endl;
        if (a_group == 0 && b_group == 0) {
            groups[ia][ib] = group_i;
            groups[ib][ia] = group_i;
            ++group_i;
        } else {

        }

        for (vll v : groups) {
            cout << v << endl;
        }
    }
    cout << endl;
    cout << cost;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
