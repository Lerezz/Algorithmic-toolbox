#include<iostream>
#include<vector>
using namespace std;

long long merge(vector<int> &numbers, vector<int> &sorted, int left, int mid, int right)
{
	int i=left,j=mid,k=left;
	long long count=0;
	while(i<mid && j<right)
	{
		if(numbers[i]<=numbers[j])
		{
			sorted[k++]=numbers[i++];
		}
		else
		{
			sorted[k++]=numbers[j++];
			count+=mid-i;
		}
	}
	while(i<mid) sorted[k++]=numbers[i++];
	while(j<right) sorted[k++]=numbers[j++];
	for(int l=left;l<right;l++)
	{
		numbers[l]=sorted[l];
	}
	return count;
}

long long number_inversion(vector<int> &numbers, vector<int> &sorted, int left, int right)
{
	long long count=0;
	if(left+1>=right) return count;
	int mid=(left+right)/2;
	count+=number_inversion(numbers, sorted, left, mid);
	count+=number_inversion(numbers, sorted, mid, right);
	count+=merge(numbers, sorted, left, mid, right);
	return count;
}

int main()
{
	int n;
	cin>>n;
	vector<int> numbers(n);
	vector<int> sorted(n);
	for(int i=0;i<n;i++) 
	{
		cin>>numbers[i];
	}
	long long res=number_inversion(numbers, sorted, 0, n);
	cout<<res;
}
