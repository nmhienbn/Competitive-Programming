#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "nkdeg"
const int maxn = 0;

using namespace std;

int n, k, c, a[15], b[15], res, now;

void backtrack(int i){
    fi(j, 0, 9){
        if (now == 0 || abs(now%10 - j) % k == 0){
            now = now*10 + j;
        }
        else continue;
        if (i == c){
            if (now <= n) res++;
        }
        else backtrack(i+1);
        now /= 10;
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    c = log10(n) + 1;
    backtrack(1);
    cout << res;
}
