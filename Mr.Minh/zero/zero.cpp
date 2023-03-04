#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "zero"
const int maxn = 1e6+5;
using namespace std;

int nt, st, L[maxn];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    fi(i, 2, 1e6) L[i] = 1e9;
    L[1] = 1;
    fi(i, 2, 1e6){
        L[i] = min(L[i], L[i-1]+1);
        for (int j = 2; j*i <= 1e6 && j <= i; j++){
            L[i*j] = min(L[i*j], L[i]+1);
        }
    }
    fi(i, 1, nt){
        cin >> st;
        cout << L[st] << '\n';
    }
}
