#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "game3579"
const int maxn = 1e6+5;

using namespace std;

ll n, L[maxn];

int calc(ll n){
    if (n < 3) return 0;
    if (L[n] != -1) return L[n];
    int best = 0;
    for (int i = 3; i <= 9; i += 2) if (!best){
        if (n >= i) best = max(best, 1 - calc(n-i));
    }
    else return L[n] = best;
    return L[n] = best;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    memset(L, -1, sizeof(L));
    while (cin >> n){
        if (n > 1e5){
            n -= ((n-1e5)/1890+1)*1890;
        }
        cout << (calc(n) ? 1 : 2) << '\n';
    }
}
