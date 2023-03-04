#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "qbdivseq"
const int maxn = 1e6+5;

using namespace std;

int n, s[maxn], k;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    k = 1;
    cin >> n >> s[1];
    fi(i, 2, n){
        int x, j = k;
        cin >> x;
        while (j > 0 && s[j] <= x) j--;
        if (j == k) k++;
        s[j+1] = x;
    }
    cout << k;
}
