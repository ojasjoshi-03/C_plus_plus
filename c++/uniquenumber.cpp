#include <iostream>
using namespace std;
int main()
{
    int array[]={3,1,3,2,4,2,4};
    int i;
    int j;
    for(i=0;i<=7;i++)
    {
      for(j=i++;j<=7;j++)
      {
       if(array[i]!=array[j])
       {break;
       } 
      
      } 
    }
    cout<<"unique number is="<<array[i];
}