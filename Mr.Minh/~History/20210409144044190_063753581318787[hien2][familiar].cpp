#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define maxn 300005

using namespace std;

int n;
set<int> a;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    f(i, 1, n) {int t; cin >> t; a.insert(t);}
    cout << a.size();
}
