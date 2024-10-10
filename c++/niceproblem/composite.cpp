#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cout<<"enter n:";
    cin>>n;
     cout<<n;
    bool flag = true ; //true means prime
    for(int i=2;i<=n/2;i++)
    {
        if (n%i==0)
        {
            flag=false;//false means composite
            break;
        }
    }
    if(n==1)
    {
    cout<<"neither prime nor composite";
    }
    else if(flag==true)
    cout<<"prime";
    else
    cout<<"composite";
}