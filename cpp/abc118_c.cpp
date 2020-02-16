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
    int n;
    scanf("%d", &n);
    // printf("%d\n", n);

    vector<int> vn(n, 0);
    REP(i,n) {
        int m;
        scanf("%d", &m);
        vn[i] = m;
    }
    std::sort(vn.begin(),vn.end());
    int min_m;
    while(vn.size() > 1) {
        int nm = vn[1] % vn[0];
        vn.erase(vn.begin() + 1);
        if(nm == 1){
            min_m = 1;
            break;
        } else if (nm > 1) {
            vn.insert(vn.begin(), nm);
        } else if (vn.size() == 1) {
            // printf("last\n");
            min_m = vn[0];
        }
        // cout << nm;
        // cout << vn;
        // printf("\n");
    }
    printf("%d", min_m);
    return 0;
}
