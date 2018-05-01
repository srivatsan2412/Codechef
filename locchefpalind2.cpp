#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int p=1000000007;

long long int powers(long long int x,long long int y,long long int m)
{
	long long int res=1;
	x=x%m;
	
	while(y>0)
	{
		if(y&1)
		res=(res*x)%m;
		
		y=y>>1;
		x=(x*x)%m;
	}
	
	return res;
	
}

long long int modinverse(long long int x,long long int y)
{
	return powers(x,p-2,p);
}

int main()
{
	long long int i,j,k,t,n,m,alp=26,sum1=0,a1,r1,n1,x,b,denm;
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		sum1=0;
		
		x=ceil(n/2);
		
		b=powers(alp,x,p);
		
		if(n%2==0)
		{
			sum1=powers(alp,x-1,p)-1;
			sum1=(sum1*alp)%p;
			sum1=(sum1*2)%p;
			denm=modinverse(alp-1,p)%p;	
			sum1=(sum1%p)*(denm%p)%p;
		
			sum1++;
			sum1=(sum1+b)%p;
			b=modinverse(b,p)%p;
			sum1=(sum1%p)*(b%p)%p;
			
		}
		else
		{
			sum1=powers(alp,x-1,p)-1;
			sum1=(sum1*alp)%p;
			sum1=(sum1*2)%p;
			denm=modinverse(alp-1,p)%p;	
			sum1=(sum1%p)*(denm%p)%p;
		
			sum1+=2;
			sum1=(sum1+b)%p;
			
			b=modinverse(b,p)%p;
			sum1=(sum1%p)*(b%p)%p;
	
		}
		
		
		cout<<sum1<<endl;
	
		
	}
}
