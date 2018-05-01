#include<iostream>
using namespace std;

long long int sum[60];

long long int compute(long long int n,long long int m)
{
	long long int val=1;
	
	if(m==0)
	{
		return 0;
	}
	
	if(n==1 || m==1)
	{
		return 1;
	}
	
	long long int n1=(val<<(n-1))-1;
	
	if(m<=n1)
	{
		return compute(n-1,m);
	}
	else if(m==(n1+1))
	{
		return sum[n-1]+n;
	}
	else 
	{
		return sum[n-1]+n+compute(n-1,(m-(n1+1)));
	}
	
}

int main()
{
	long long int i,j,k,t,n,l,r,d,q;
	
	sum[1]=1;
	
	for(i=2;i<=50;i++)
	{
		sum[i]=sum[i-1]*2+i;
	}
	
	cin>>n>>q;
	
	while(q--)
	{
		cin>>l>>r;
		
		d=compute(n,r)-compute(n,l-1);
		
		cout<<d<<endl;
	}
	
}
