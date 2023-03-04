#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "salaryinc"
const int maxn = 3e5+5;

using namespace std;

int n, m, par[maxn], a[maxn], cnt[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> a[0];
    fi(i, 1, n){
        cin >> a[i] >> par[i];
        int v = i;
        do {
            v = par[v];
            if (a[i] > a[v]){
                cnt[i]++;
                a[v] = a[i];
            }
            else break;
        } while (v != 0);
    }
    fi(i, 1, n) cout << cnt[i] << '\n';
}
