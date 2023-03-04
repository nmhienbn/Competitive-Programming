#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "saw"
const int maxn = 1e5+5;

using namespace std;

int n, k, a[maxn];
ll sum[maxn], m;

bool check(int x){
    int d = 1, c = n;
    while (d <= c){
        int g = (d + c) >> 1;
        if (a[g] >= x) c = g-1;
        else d = g+1;
    }
    return sum[n] - sum[d-1] - 1ll*x*(n-d+1) >= m;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    fi(i, 1, n) sum[i] = sum[i-1] + a[i];
    while (k--){
        cin >> m;
        int d = 0, c = a[n];
        while (d <= c){
            int g = ((d + c) >> 1);
            if (check(g)) d = g+1;
            else c = g-1;
        }
        cout << c << '\n';
    }
}
