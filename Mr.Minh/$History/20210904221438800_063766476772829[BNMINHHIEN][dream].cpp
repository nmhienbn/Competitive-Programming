#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "dream"
const int maxn = 105;
const int mod = 1e9+7;

using namespace std;

struct matran{
    long long a[maxn][maxn] = {};
};

matran operator * (matran A, matran B){
    matran C;
    fi(i, 0, 100)
        fi(j, 0, 100){
            C.a[i][j] = 0;
            fi(k, 0, 100)
                C.a[i][j] = (C.a[i][j] + A.a[i][k]*B.a[k][j]) % mod;
        }
    return C;
}

long long n, k;
long long b[maxn], d[maxn], s[maxn], res;
matran A, ans;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n){
        int u;
        cin >> u;
        d[u]++;
    }
//------------------------------------------------
    b[0] = s[0] = 1;
    fi(i, 1, 100){
        fi(j, 1, i){
            b[i] = (b[i] + b[i-j]*d[j]) % mod;
        }
        s[i] = (s[i-1] + b[i]) % mod;
    }
//------------------------------------------------
    fi(i, 1, 100){
        ans.a[100][i] = A.a[100][i] = d[101-i];
        ans.a[i-1][i] = A.a[i-1][i] = 1;
    }
    A.a[0][1] = ans.a[0][1] = 0;
    A.a[0][0] = A.a[100][0] = ans.a[0][0] = ans.a[100][0] = 1;
    k++;
    int u = log(k), v = 2;
    fid(i, u-1, 0){
        ans = ans*ans;
        //v *= 2;
        if ((k >> i) & 1){
            //v++;
            ans = ans*A;
        }
    }
    fi(i, 0, 100){
        res = (res + ans.a[1][i] * s[i]) % mod;
    }
    cout << res;
}
