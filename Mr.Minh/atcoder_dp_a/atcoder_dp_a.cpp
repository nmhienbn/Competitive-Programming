#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "atcoder_dp_a"
const int maxn = 1e5+5;

using namespace std;

int n, k, a[maxn];
ll L[maxn];

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    fi(i, 2, n){
        L[i] = 1e18;
        fi(j, i-k, i-1){
            L[i] = min(L[i], L[j] + abs(a[i]-a[j]));
        }
    }
    cout << L[n];
}
