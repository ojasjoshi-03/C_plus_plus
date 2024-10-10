#include <iostream>
using namespace std;
int main()
{
    int array[]={3,4,6,7,1};
    int ts=7;
    int pairs=0;
    int i;
    int j;
    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
           if(array[i]+array[j] == ts)
           {
              pairs++;
           }
           

        }
    }
    cout<<pairs;
    return 0;
}
