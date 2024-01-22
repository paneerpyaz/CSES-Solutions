#include <bits/stdc++.h>
#define TimeTravel                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define ld long double
#define vll vector<ll int>
#define vpll vector<pair<ll int, ll int>>
#define bs binary_search
#define make_pair mp
#define m 1e9 + 7
#define vsort sort(v.begin(), v.end());
#define vsortd sort(v.begin(), v.end(), greater<int>());
#define it(i, n) for (ll int i = 0; i < n; i++)
#define pb push_back
using namespace std;
int main()
{
    TimeTravel
    ll int n;
    cin >> n;
    ll int a[n];
    it(i, n)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << 0;
    }
    else if (n == 2)
    {
        if (a[1] < a[0])
        {
            cout << a[0] - a[1];
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        ll int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i -1])
            {
                cnt += (a[i-1] - a[i]);
                a[i]=a[i-1];
                
            }
        }
        cout << cnt;
    }
    return 0;
}
