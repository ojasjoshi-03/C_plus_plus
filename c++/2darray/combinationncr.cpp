#include <iostream>
using namespace std;
int fact (int x)
{
    int f=1;
    for(int i=1;i<=x;i++)
    {
        f *= i;

    }
    return f;
}
int ncr(int n, int r)
{
    return fact(n)/(fact(r)*fact(n-r));

}
int main()
{
    int n,r;
    cout<<"enter n"<<endl<<"enter r"<<endl;
    cin>>n>>r;
    cout<<ncr(n,r);
}