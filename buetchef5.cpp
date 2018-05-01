#include<iostream>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

long int a[7000001],arr[7000001];

void pgenerate()
{
	long int i,j;
	
		for(i=1;i<=7000001;i++)
			{
				for(j=i;j<=7000001;j+=i)
				{
					a[j]++;		
				}
			}
}

int main()
{
	
	long int i,j,k,t,n,m,up;
	
	memset(a,0,sizeof a);
	
	cin>>t;
	
	pgenerate();
	
	arr[0]=0;
	
	for(i=1;i<=7000001;i++)
	{
		arr[i]=a[i]+arr[i-1];

	}
	
	while(t--)
	{
		cin>>k;
		
		up=lower_bound(arr,arr+7000001,k)-arr ;
		
		cout<<up<<endl;
		
	}
	
}
