#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "stchange"
const int maxn = 1005;

using namespace std;

int n, x, f[maxn], L[maxn][40];
string s;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> x >> s;
    n = s.size();
    s = ' ' + s;
    fi(i, 1, n) f[i] = i;

    fi(i, 1, n/2){
        L[i*2][0] = n+1-i;
    }
    fi(i, 1, n-n/2){
        L[i*2-1][0] = i;
    }
    int zz = log2(x);
    fi(j, 1, zz){
        fi(i, 1, n){
            L[i][j] = L[L[i][j-1]][j-1];
        }
    }
    fi(j, 0, zz){
        if ((x >> j) & 1){
            fi(i, 1, n){
                f[i] = L[f[i]][j];
            }
        }
    }
    fi(i, 1, n) cout << s[f[i]];
}
