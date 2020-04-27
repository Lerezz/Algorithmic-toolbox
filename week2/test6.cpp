#include<iostream>
using namespace std;

int fab(long long n)
{
	int front=0,rear=1;
	int tmp;
	int sum=front+rear;
	if(n<2) return n;
	for(int i=2;i<=n;i++)
	{
		tmp=(front+rear)%10;
		front=rear%10;
		rear=tmp%10;
		sum=(sum+tmp)%10;
	}
	return sum;
} 

int periodic()
{
	int a=0,b=1;
	int c=(a+b)%10;
	for(int i=1;;i++)
	{
		c=(a+b)%10;
		a=b%10;
		b=c%10;
		if(a==0 && b==1)
			return i;
	}
}

int periodic_sum()
{
	int a=0,b=1;
	int sum=1;
	int c=0;
	for(int i=2;i<60;i++)
	{
		c=(a+b)%10;
		a=b%10;
		b=c%10;
		sum=(sum+c)%10;
	}
	return sum;
}

int main()
{
	long long n;
	cin>>n;
	int p=periodic();
	n=n%p;
	int sum=periodic_sum();
	int div=(n/p)*sum%10;
	int res=fab(n);
	cout<<(div+res)%10;
}

