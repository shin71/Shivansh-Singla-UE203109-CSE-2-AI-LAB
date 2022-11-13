/* Shivansh Singla
    UE203109
    CSE 2*/
#include <iostream>
#include <vector>
#include <cstdlib>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define output(a) cout<<a<<endl;
#define outputv(arr) for(auto i:arr){cout<<i<<" ";}cout<<endl;
#define outputp(a) cout<<a.first<<" "<<a.second<<endl;
#define all(v) v.begin(), v.end()
#define yes cout<<"YES"<<endl;return;
#define no cout<<"NO"<<endl;return;
#define pii pair<int,int>
using ll = long long;
const ll MOD = 1e9 + 7;
using namespace std;
void soln()
{
    int l,r,n,epochs,seed;
    cout<<"give range of values format l r"<<endl;
    cin>>l>>r;
    cout<<"give size of series"<<endl;
    cin>>n;
    cout<<"give seed value"<<endl;
    cin>>seed;
    vector<int> source(n);
    srand(seed);
    for(auto &i:source)
    {
        i = rand()%(r - l + 1);
        i+=l;
    }
    vector<int> s[5];
    cout<<"give number of epochs"<<endl;
    cin>>epochs;
    while(epochs--)
    {
        bool first = false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=4;j++)
            {
                if(!first)
                {
                    s[j].push_back(source[rand()%100]);
                }
                else
                {
                    s[j][s[j].size() - 1]  = (s[j][s[j].size() - 1] + source[rand()%100])/2;
                }

            }
            first = true;
        }

    }
    int mean = 0;
    cout<<"\noriginal array"<<endl;
    for(auto i:source){cout<<i<<" ";mean+=i;}
    cout<<"\nmean of original array"<<endl;
    cout<<(mean)/n<<endl;

    for(int i=1;i<=4;i++)
    {
        cout<<"\nS"<<i<<endl;
        for(auto j:s[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

signed main() {
#ifdef LOCAL_PROJECT
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 freopen("error.txt", "w", stderr);
#endif
IOS
ll t;
cout<<"enter number of test cases"<<endl;
t=1;
cin>>t;
int x = t;  
while(t--)  
{
 soln();
 cout<<"test case "<<x - t<<" complete"<<endl;  
}
return 0;
}
