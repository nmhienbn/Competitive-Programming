#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "pairnum"
const int maxn = 1e6+5, mod = 1e9;

using namespace std;

int n, k, a[maxn], res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    int j = n;
    fi(i, 1, n-1) if (a[i] + a[n] >= k){
        while (a[i] + a[j] >= k && j > 0){
            j--;
        }
        j++;
        res += n - max(j, i+1) + 1, res %= mod;
    }
    cout << res;
}
