#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "sort3"
const int maxn = 1e4+5;
using namespace std;

int a[3][maxn], d[3], n, b[maxn], sl;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int x;
        cin >> x;
        a[x%3][++d[x%3]] = x;
    }
    if (d[0] > d[1] + d[2] + 1 || (!d[0] && d[1] && d[2])){
        cout << "impossible";
        exit(0);
    }
    fi(i, 1, d[0]){
        b[++sl] = a[0][i];
        if (d[1]) b[++sl] = a[1][d[1]--];
        else if (d[2]) b[++sl] = a[2][d[2]--];
    }
    while (d[2]) cout << a[2][d[2]--] << ' ';
    fi(i, 1, sl) cout << b[i] << ' ';
    while (d[1]) cout << a[1][d[1]--] << ' ';
}
