#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
int nt, n, ans[maxn];
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> nt >> s;
    n = s.size();
    s = ' ' + s;
    for (int j = n >> 1; j >= 1; j--)
    {
        int cnt = 0;
        for (int i = 1; i <= j; i++)
            cnt += (s[i] != s[i + j]);
        ans[j] = cnt;
        for (int i = j + 1; i <= n - j; i++)
        {
            cnt += (s[i] != s[i + j]) - (s[i - j] != s[i]);
            if (ans[j] > cnt)
            {
                ans[j] = cnt;
            }
        }
    }
    n >>= 1;
    while (nt--)
    {
        int k;
        cin >> k;
        for (int i = n; i >= 0; i--)
        {
            if (ans[i] <= k)
            {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
