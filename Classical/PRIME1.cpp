/*
~ Author    : @tridib_2003
~ Title     : PRIME1 - Prime Generator
~ Link      : https://www.spoj.com/problems/PRIME1/
*/

#include <iostream>
#include<math.h>
using namespace std;

int main() {
	int m,n,t,c,j;
	cin>>t;
	while(t--)
	{
	    cin>>m>>n;
	    for(int i=m;i<n+1;i++)
	    {  if(i==0||i==1)
	        continue;
	        c=0;
	        for(j=2;j<=sqrt(i);j++)
	        {
	            if(i%j==0)
	            {
	                c=1;
	            break;
	            }
	   	    }
	   	    if(c==0)
	   	    cout<<i<<endl;
	    }
	  cout<<endl;
	}
	return 0;
}
