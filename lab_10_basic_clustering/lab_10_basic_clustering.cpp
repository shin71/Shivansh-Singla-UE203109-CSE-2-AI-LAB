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
#define pii pair<double,double>
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
    vector<double> source(n);
    for(auto &i:source)
    {
        i = rand()%(r - l + 1);
        i+=l;
    }
    cout<<"enter no of seeds"<<endl;
    cin>>seed;
    vector<double> s[seed + 1];
    cout<<"enter the seeds"<<endl;
    for(int i=1;i<=seed;i++)
    {
        double x;cin>>x;s[i].push_back(x);
    }
    cout<<"give number of epochs"<<endl;
    cin>>epochs;
    while(epochs--)
    {
        vector<double> sum(seed + 1,0);
        auto elements_at = sum;
       for(int i=0;i<n;i++)
       {
           pii miny = {INT_MAX,-1};
           for(int j=1;j<=seed;j++)
           {
               miny = min(miny,{abs(s[j].back() - source[i]),j});
           }
           auto [closest,index] = miny;
           sum[index] += source[i];
           elements_at[index]++;
       }
       for(int j=1;j<=seed;j++)
       {
           s[j].push_back((sum[j] + s[j].back())/(1 + elements_at[j]));
       }
    }
    double mean = 0;
    cout<<"\noriginal array"<<endl;
    for(auto i:source){cout<<i<<" ";mean+=i;}
    cout<<"\nmean of original array"<<endl;
    cout<<(mean)/n<<endl;
    cout<<"values of S[i] through all the epochs first element is the seed given"<<endl;
    for(int i=1;i<=seed;i++)
    {
        cout<<"\nS"<<i<<endl;
        for(auto j:s[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
        cout<<"final mean of S"<<i<<endl<<endl;
        cout<<s[i].back()<<endl;
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
