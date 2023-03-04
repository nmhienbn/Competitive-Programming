#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "coin34"
const int maxn = 132000;

using namespace std;

int a[40], L[maxn], M[maxn], f[maxn], id, n;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> x;
    a[1] = 2;
    a[2] = 3;
    a[3] = 5;
    fi(i, 4, 34) a[i] = a[i-1] + a[i-2] + a[i-3];
    n = (1 << 17) - 1;

    fi(x, 1, n){
        fi(i, 0, 16){
            if ((x >> i) & 1){
                f[x] = f[x - (1 << i)] + 1;
                L[x] = L[x - (1 << i)] + a[i+1];
                break;
            }
        }
    }
    fi(x, 1, n){
        fi(i, 0, 16){
            if ((x >> i) & 1){
                M[x] = M[x - (1 << i)] + a[i+18];
                break;
            }
        }
    }
    sort(L, L+n+1);
    sort(M, M+n+1);


}
