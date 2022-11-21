/* Shivansh Singla
    UE203109
    CSE 2*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n\n"
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
vector<float> series;
double moving_average(int ind,double b,auto &temp)
{
    if(ind == 0)
    {
        temp.push_back(series[ind]);
        return series[ind];
    }
    double z = b*series[ind] + (1-b)*moving_average(ind - 1,b,temp);
    temp.push_back(z);
    return z;
}
void soln()
{
    series = {0,2,1,22,2,1,3,5,9,15,8,10,10,11,10,14,20,25,
            27,58,78,69,94,74,86,73,153,136,120,187,309,424,
            486,560,579,609,484,573,565,813,871,854,758,1243,
            1031,886,1061,922,1371,1580,1239,1537,1292,1667,
            1408,1835,1607,1568,1902,1705,1801,2391};
    double avg = 0,variance = 0,std_dev = 0;
    int n = series.size();
    for(auto i:series){avg+=i;}
    avg/=n;
    for(auto i:series){variance+=(i - avg)*(i - avg);}
    variance/=double(n);
    std_dev = sqrt(variance); 
    cout<<"average ,variance, standard_deviation"<<endl;
    cout<<to_string(avg) + " " + to_string(variance) + " " + to_string(std_dev) + " "<<endl;
    vector<double> grad,lap;
    for(int i=1;i<n;i++)
    {
        grad.push_back(series[i] - series[i-1]);
    }
    for(int i=1;i<grad.size();i++)
    {
        lap.push_back(grad[i] - grad[i-1]);
    }
    cout<<"gradient"<<endl;
    for(auto i:grad){cout<<i<<" ";}
    cout<<endl<<"laplace"<<endl;
    for(auto i:lap){cout<<i<<" ";}
    cout<<endl;
    vector<double> filter = {5,3,1,3,5};
    int limit  = filter.size()/2;
    auto series_smooth = series;
    for(int i=0;i<n;i++)
    {
        double val = 0;
        for(int j = i - limit;j<=i+limit;j++)
        {
            int ind = j - i + limit;
            if(ind<0){ind=0;}
            else if(ind>=n){ind = n-1;}
            val += filter[ind]*series[j];
        }
        series_smooth[i] = val/double(filter.size());
    }
    cout<<"series if we apply smoothening filter"<<endl;
    for(auto i:series_smooth){cout<<i<<" ";}
    cout<<endl;
    cout<<"moving averages for different betas"<<endl;
    for(double beta = 0.1;beta<=0.6;beta+=0.1)
    {
        vector<double> temp;
        moving_average(n-1,beta,temp);
        cout<<"\nBeta:" + to_string(beta)<<endl;
        for(auto i:temp){cout<<i<<" ";}
        cout<<endl;
    }
    cout<<endl;
    cout<<"normalized series"<<endl;
    double maxy = *max_element(all(series));
    double miny = *min_element(all(series));
    for(int i=0;i<n;i++)
    {
        cout<<abs(series[i] - avg)/(maxy - miny)<<" ";
    }
    cout<<endl;
    cout<<"adam optimized series"<<endl;
    double epsilon = 0.5,alpha = 0.01;
    for(int i=0;i<n;i++)
    {
        double dx2dt2,dxdt;
        if(i<=0){dxdt = 0;}
        else{dxdt = grad[i-1];}
        if(i<=1){dx2dt2 = 0;}
        else{dx2dt2 = lap[i-2];}
        cout<<series[i] - (alpha*abs(dxdt))/(sqrt(dx2dt2) + epsilon)<<" ";
    }
    cout<<endl;
}

signed main() {
#ifdef LOCAL_PROJECT
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 freopen("error.txt", "w", stderr);
#endif
IOS
ll t;
t=1;
//cin>>t;  
while(t--)  
{
 soln();  
}
return 0;
}
