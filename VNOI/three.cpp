#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "three"
const int maxn = 1e6;
using namespace std;

int n;
ll a;
bool p[maxn + 5];

void Erathosenes(){
    p[0] = p[1] = 1;
    fi(i, 2, 1000) if (!p[i]){
        for (int j = i * i; j <= maxn ; j += i){
            p[j] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    Erathosenes();
    cin >> n;
    fi(rep, 1, n){
        cin >> a;
        int x = sqrt(a);
        if (1ll * x * x == a && !p[x]){
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
}
