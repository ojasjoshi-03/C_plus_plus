#include <iostream>
using namespace std;
int main()
{
    int array[]={3,1,2,4,0,6,5};
    int ts=5;
    int pairs=0;
    int i;
    int j;
    int k;
    for(i=0;i<7;i++)
    {
        for(j=i+1;j<7;j++)
        {
            for(k=j+1;k<7;k++)
            { 
                if(array[i]+array[j]+array[k] == ts)
                {
                  pairs++;
                }

            }
          
           

        }
    }
    cout<<pairs;
    return 0;
}