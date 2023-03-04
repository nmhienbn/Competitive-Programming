#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "cutseq"
const int maxn = 205;

using namespace std;

int n, a[maxn], L[maxn][maxn][maxn];

int calc(int i, int j, int k){
    if (L[i][j][k]) return L[i][j][k];
    if (i > j) return 0;
    int now = (k+1)*(k+1) + calc(i+1, j, 0);
    fi(t, i+1, j){
        if (a[i] == a[t]){
            now = max(now, calc(t, j, k+1) + calc(i+1, t-1, 0));
        }
    }
    return L[i][j][k] = now;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    cout << calc(1, n, 0);
}
