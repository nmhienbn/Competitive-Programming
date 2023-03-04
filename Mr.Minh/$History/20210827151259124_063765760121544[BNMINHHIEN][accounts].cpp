#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "accounts"
const int maxn = 1e6+5;

using namespace std;

int n, m;
bool kt[maxn];
double a[maxn], b[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, m) cin >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    int j = 1;
    fi(i, 1, n){
        while (b[j] < a[i] && j <= m) j++;
        if (b[j] == a[i]) kt[i] = 1, j++;
    }
    fid(i, n, 1) if (!kt[i]) cout << a[i] << ' ';
}
