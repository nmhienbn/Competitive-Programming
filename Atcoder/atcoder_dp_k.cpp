#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "atcoder_dp_k"
const int maxn = 1e5+5;

using namespace std;

int n, k, L[maxn], a[105];

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    fi(i, a[1], k){
        int best = 0;
        fi(j, 1, n){
            if (i >= a[j]){
                best = max(best, L[i-a[j]]^1);
            }
        }
        L[i] = best;
    }
    cout << (L[k] ? "First" : "Second");
}
