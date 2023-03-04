#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "balance"
const int maxn = 15, maxk = 60000;

using namespace std;

int h[maxn], m, n, a[maxn], b[maxn], L[maxk], M[maxk], k;
ll res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    h[0] = 1;
    fi(i, 1, 10) h[i] = h[i-1] * 3;
    cin >> n >> k;
    m = n - n/2;
    n /= 2;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, m) cin >> b[i];

    int u = h[n]-1, v = h[m]-1;
    fi(x, 0, u){
        int y = x;
        fi(i, 1, n){
            L[x] += (y%3-1)*a[i];
            y /= 3;
        }
    }
    fi(x, 0, v){
        int y = x;
        fi(i, 1, m){
            M[x] += (y%3-1)*b[i];
            y /= 3;
        }
    }
    sort(L, L+u+1);
    sort(M, M+v+1);
    int j = v, luu = 0;
    fi(i, 0, u){
        if (i > 0 && L[i] == L[i-1]){
            res += luu;
            continue;
        }
        luu = 0;
        while (L[i] + M[j] > k && j > 0) j--;
        while (L[i] + M[j] == k && j > 0) j--, luu++;
        res += luu;
    }
    cout << res;
}
