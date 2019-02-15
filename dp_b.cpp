#include <stdio.h>
#include <math.h>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long int ll;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9; 
 
int main(void){
    int n,k;
    scanf("%d", &n);
    scanf("%d", &k);

    ll h[n];
    ll costs[n];
    costs[n - 1] = 0;

    for( int i = 0; i < n; ++i ){
        ll height;
        scanf("%lld", &height);
        h[i] = height;
    }
    for( int i = n - 2; i >= 0; --i ){
        ll c = INF;

        for (int a = 1; a <= k && a < n - i; ++a) {
            int jump_to = i + a;
            ll jump_cost = abs(h[jump_to] - h[i]) + costs[jump_to];
            c = (c > jump_cost) ? jump_cost : c;
        }
        costs[i] = c;
    }
    printf("%lld", costs[0]);
    return 0;
}
