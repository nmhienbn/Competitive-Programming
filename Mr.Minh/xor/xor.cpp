#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "xor"
const int maxn = 1e5+5, mod = 1e9+7;

using namespace std;

struct node {
    int child[2];
} T[maxn*40];

void add (int x)

int n, k, a[maxn], L[maxn], l[maxn], r[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n){
        cin >> a[i];
        a[i] ^= a[i-1];
    }
    fi(i, 1, k) cin >> l[i] >> r[i];
    L[0] = 1;
    fi(i, 1, k){
        fid(j, n, 0){
            L[j] = 0;
            fi(t, 1, j){
                int ss = a[j]^a[t-1];
                if (l[i] <= ss && ss <= r[i]){
                    L[j] += L[t-1];
                    L[j] %= mod;
                }
            }
        }
    }
    cout << L[n];
}
