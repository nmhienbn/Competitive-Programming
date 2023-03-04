#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "loco"
const int maxn = 0;

using namespace std;

int mod;

struct matran{
    long long a[3][3] = {{1, 1, 1},
                        {1, 0, 0},
                        {0, 1, 0}};
};

matran operator * (matran A, matran B){
    matran C;
    fi(i, 0, 2){
        fi(j, 0, 2){
            C.a[i][j] = 0;
            fi(k, 0, 2)
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
    cin >> n >> mod;
    if (n == 1){
        cout << 1 % mod << '\n';
        return 0;
    }
    else if (n == 2){
        cout << 2 % mod << '\n';
        return 0;
    }
    else if (n == 3){
        cout << 4 % mod << '\n';
        return 0;
    }
    matran A;
    A = binpow(A, n-1);
    cout << (4*A.a[2][0] + 2*A.a[2][1] + A.a[2][2]) % mod << '\n';
}
