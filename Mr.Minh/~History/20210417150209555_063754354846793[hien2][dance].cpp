#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "dance"
#define maxn 1000005

using namespace std;

int n, chenh = n, dem[2*maxn];
ll res;
char c;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    
    dem[chenh] = 1;
    fi(i, 1, n){
        cin >> c;
        if (c == 'a') chenh++; else chenh--;
        res += dem[chenh];
	dem[chenh]++;
    }
    cout << res;
}
