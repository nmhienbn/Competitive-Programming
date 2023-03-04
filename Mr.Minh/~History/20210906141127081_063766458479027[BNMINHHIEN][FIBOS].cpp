#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "FIBOS"
const int maxn = 0;

using namespace std;

const int mod = 1e9+7;

struct matran{
    long long a[2][2] = {{1, 1},
                        {1, 0}};
};

matran operator * (matran A, matran B){
    matran C;
    fi(i, 0, 1){
        fi(j, 0, 1){
            C.a[i][j] = 0;
            fi(k, 0, 1)
                C.a[i][j] = (C.a[i][j] + A.a[i][k]*B.a[k][j]) % mod;
        }
    }
    return C;
}

matran binpow(matran A, long long k){
    if (k == 1) return A;
    matran C = binpow(A, k >> 1);
    if (k & 1) return A*C*C;
    else return C*C;
}

int t;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    long long n;
    cin >> n;
    if (n == 0){
        cout << 1;
        return 0;
    }
    if (n == 2){
        cout << 2;
        return 0;
    }
    matran A;
    A = binpow(A, n+3);
    cout << (A.a[1][0] - 1) % mod << '\n';
}
