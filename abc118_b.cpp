#include <stdio.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

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
    // printf("%d ", n);
    // printf("%d\n", m);
    map<int, bool> mp; 
    REP (i, m) {
        mp[i + 1] = true;
    }

    // printf("\n");
    // for (const auto &p : mp) {
    //     std::cout << "m[" << p.first << "] = " << p.second << '\n';
    // }
    // printf("\n");

    REP (i, n) {
        // printf("%s", "======\n");
        int k;
        scanf("%d", &k);
        // printf("%d: ", k);
        map<int, bool> lmp; 
        REP (j, k) {
            int l;
            scanf("%d", &l);
            // printf("%d ", l);
            lmp[l] = true;
        }

        // printf("\n");
        // for (const auto &p : lmp) {
        //     std::cout << "m[" << p.first << "] = " << p.second << '\n';
        // }
        // printf("\n");
        REP (j, m) {
            if ((lmp.find(j + 1) == lmp.end())) {
                // printf("deleted: %d \n", j + 1);
                mp[j + 1] = false;
            }
        }
        // printf("\n");
    }

    // printf("\n");
    int cnt = 0;
    for (const auto &p : mp) {
        if (p.second == true) {
            ++cnt;
        }
    }
    printf("%d", cnt);

    return 0;
}
