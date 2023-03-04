#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "ptrang"
const int maxn = 6005;

using namespace std;

int n, m, a[maxn], L[maxn];

int main(){
    faster
//    freopen(NunuAndWillump".inp", "r", stdin);
//    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n) L[i] = 1e9;
    fi(i, 1, n){
        int s = 0;
        fid(j, i, 1){
            s += a[j];
            if (s > m) break;
            L[i] = min(L[i], max(L[j-1], m - s));
        }
    }
    cout << L[n];
}
