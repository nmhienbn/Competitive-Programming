#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define fir first
#define se second
#define bit(i,j) ((i>>j)&1)
#define bit2(i) (1<<(i-1))
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

#define maxn 100005
#define maxm 1000006
#define mod 111539786
#define Seraphine "latgach4"

using namespace std;

struct matrix{
    ll a[2][2] = {{1, 1}, {1, 0}};
};

matrix operator * (matrix a, matrix b){
    matrix c;
    fi(i, 0, 1){
        fi(j, 0, 1){
            c.a[i][j] = 0;
            fi(t, 0, 1) c.a[i][j] += a.a[i][t]*b.a[t][j], c.a[i][j] %= mod;
        }
    }
    return c;
}

matrix binpow(matrix a, int k){
    if (k == 1) return a;
    matrix tg = binpow(a, k/2);
    if (k&1) return tg*tg*a;
    else return tg*tg;
}

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    int t;
    matrix A;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        matrix res = binpow(A, n);
        cout << (res.a[1][0] + res.a[1][1]) % mod << '\n';
    }

}
