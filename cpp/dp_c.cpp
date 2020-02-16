#include <stdio.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
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
// vector<vi> vn(n, vi(m, 0));

// 多次元配列の dump
// for (vector<int> v : vn) {
//     cout << v;
// }

// printf("%d\n", n);
// printf("%lld\n", n);

int main(void){
    int n;
    scanf("%d", &n);
    // printf("%d\n", n);
    int c = 3;
    vector<vi> funs(n, vi(c, 0));
    vector<vi> dp(n + 1, vi(c, 0));

    REP(i, n) {
        REP(j, c) {
            int fun;
            scanf("%d", &fun);
            funs[i][j] = fun;
        }
        // cout << funs[i];
    }
    // cout << endl;
    RREP(i, n) {
        // cout << "=====" << endl;
        // cout << i << endl;
        REP(j, c) {
            vi next_funs;
            REP(k, c) {
                if (j != k) {
                    next_funs.push_back(dp[i + 1][k]);
                }
            }
            // cout << "next_fun is :" << next_funs << endl;
            int next_max_fun = vmax(next_funs);
            // cout << "max is :" << next_max_fun << endl;
            dp[i][j] = funs[i][j] + next_max_fun;
        }
        // cout << dp[i] << endl;
    }
    // cout << dp[0];
    int max_fun = vmax(dp[0]);
    printf("%d", max_fun);
    return 0;
}
