#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "atcoder_dp_m"
const int maxn = 105, maxk = 1e5+5, mod = 1e9+7;

using namespace std;

int n, k;
ll L[maxk], M[maxk];

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> k;
    L[0] = 1;
    fi(i, 1, n){
        int a;
        cin >> a;
        M[0] = L[0];
        fi(j, 1, k){
            M[j] = (M[j-1] + L[j]) % mod;
        }
        fi(j, 1, k){
            if (j-a > 0) L[j] = (M[j] - M[j-a-1] + mod) % mod;
            else L[j] = M[j];
        }
    }
    cout << L[k];
}
