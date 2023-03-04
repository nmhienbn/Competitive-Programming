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
pii a[maxn];

bool cmp(pii a, pii b){
    return a.first + a.second > b.first + b.second;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1, a+n+1);
    fi(i, 1, n){
        if (i&1) res += a[i].first;
        else res -= a[i].second;
    }
    cout << res;
}
