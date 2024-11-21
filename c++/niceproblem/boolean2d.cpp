#include <bits/stdc++.h>
#include <vector>
using namespace std;

int maximumOnesRows(vector<vector<int> >&V)
{

   int maxOnes= INT_MIN;
   int maxOnesRow= -1;
   int columns = V[0].size();
   for(int i=0;i<V.size();i++)
   {
    for(int j=0;j<V[i].size();j++)
    {
        if(V[i][j]==1)
        {
            int numberofOnes = columns - j;
            if(numberofOnes> maxOnes)
            {
                maxOnes=numberofOnes;
                maxOnesRow = i;
            }
        }
    }
   }
   return maxOnesRow;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;

    vector<vector<int> > vec(n,vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>vec[i][j];
        }
    }

    int res= maximumOnesRows(vec);
    cout<<res<<endl;
    return 0;  
}    
