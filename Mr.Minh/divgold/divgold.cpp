#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "divgold"
const int maxn = 255, maxa = 25e4+5, mod = 1e6;

using namespace std;

int n, a[maxn], L[maxa], sum, res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
        sum += a[i];
    }
    L[0] = 1;
    fi(i, 1, n){
        fid(j, sum/2, a[i]){
            L[j] = (L[j] + L[j-a[i]]) % mod;
            if (L[j] > 0) res = max(res, j);
        }
    }
    cout << sum - res*2 << '\n' << L[res];
}
