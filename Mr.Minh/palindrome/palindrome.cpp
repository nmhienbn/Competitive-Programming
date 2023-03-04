#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "palindrome"
const int maxn = 1005, mod = 1e9 + 7;

using namespace std;

int n, L[maxn];
bool kt[maxn][maxn];
string s;

void add(int& x, int y){
    x += y;
    if (x >= mod) x -= mod;
}

void checkPalindrome(){
    fi(i, 1, n)
        kt[i][i] = 1;
    fi(i, 1, n - 1)
        if (s[i] == s[i + 1])
            kt[i][i + 1] = 1;
    fi(j, 2, n - 1){
        fi(i, 1, n - j) if (s[i] == s[i + j]){
            kt[i][i + j] = kt[i + 1][i + j - 1];
        }
    }
}

void CountPal(){
    L[0] = 1;
    fi(j, 1, n){
        fi(i, 1, j){
            if (kt[i][j]){
                add(L[j], L[i-1]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> s;
    s = ' ' + s;
    checkPalindrome();
    CountPal();
    cout << L[n];
}
