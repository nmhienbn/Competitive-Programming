#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "maxsum"
const int maxn = 1e5+5;

using namespace std;

int n, k, a[maxn];
ll sum, L[maxn];
int q[maxn], d, c;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n+1){
        sum += a[i];
        while (d <= c && q[d] < i-k-1) d++;
        L[i] = L[d] + a[i];
        while (d <= c && L[c] >= L[i]) c--;
        q[++c] = i;
    }
    cout << sum - L[n+1];
}
