#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define file freopen(Ahri".inp", "r", stdin); freopen(Ahri".out", "w", stdout);
#define Ahri "zero"
const int maxn = 1e6+5;

using namespace std;

int a[maxn];

void Era(){
    fi(i, 1, 1e6) a[i] = 1e9;
    fi(i, 1, 1e6){
        a[i] = min(a[i], a[i-1]+1);
        for (int j = 2; j <= i && j*i <= 1e6; j++){
            a[j*i] = min(a[j*i], a[i] + 1);
        }
    }
}

int main(){
    faster file
    Era();
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << a[n] << '\n';
    }
}
