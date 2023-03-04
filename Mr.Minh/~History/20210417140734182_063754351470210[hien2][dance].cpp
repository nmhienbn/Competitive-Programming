#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "dance"
#define maxn 1000005

using namespace std;

int n, a[maxn], b[maxn];
ll res;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    a[0] = 0; b[0] = 0;
    fi(i, 1, n){
        char c;
        cin >> c;
        if (c == 'a') a[i] = a[i-1] + 1;
        else a[i] = a[i-1];
        if (c == 'b') b[i] = b[i-1] + 1;
        else b[i] = b[i-1];
    }
    fi(i, 1, n)
        fi(j, 1, i-1)
            if (a[i] - a[j-1] == b[i] - b[j-1])
                res++;
    cout << res;
}
