#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "balls"
const int maxn = 2e5+5;

using namespace std;

int cnt[maxn], n, a[maxn];
ll res;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i], cnt[a[i]]++;
    fi(i, 1, n) res += 1ll*cnt[i]*(cnt[i]-1)/2;
    fi(i, 1, n){
        cout << res - cnt[a[i]] + 1 << '\n';
    }

}
