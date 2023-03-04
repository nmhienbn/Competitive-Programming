#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "delcol"
const int maxn = 300005;

using namespace std;

int n;
bool kt[maxn];
ll res;
pii a[maxn], b[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].first >> b[i].first;
        a[i].second = b[i].second = i;
    }
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    int j = n;
    fid(i, n, 1){
        if (!kt[a[i].second]){
            res += a[i].first, kt[a[i].second] = 1;
            while (kt[b[j].second] && j > 0) j--;
            if (!kt[b[j].second]) res -= b[j].first, kt[b[j].second] = 1;
        }
    }
    cout << res;
}
