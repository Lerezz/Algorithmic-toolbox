#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;

vector<int> order_arr;

int binary_search(int begin, int end, int num)
{
	if (order_arr[begin] == num) return begin;
	if (order_arr[end] == num) return end;
	if (order_arr[begin] > num) return -1;
	if (order_arr[end] < num)	return -1;
	if (order_arr[begin]<num && order_arr[end]>num)
	{
		if (begin == end - 1)	return -1;
		if (order_arr[(begin + end) / 2] > num)
			return binary_search(begin, (begin + end) / 2, num);
		else
			return binary_search((begin + end) / 2, end, num);
	}
}


int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int num;
		cin>>num;
		order_arr.push_back(num);
	}

	int m;
	cin>>m;
	vector<int> search_arr;
	while(m--)
	{
		int num;
		cin>>num;
		search_arr.push_back(num);
	}

	int begin=0;
	int end=order_arr.size() - 1;

	vector<int> result;
	for(int i=0;i<search_arr.size();i++)
	{
		result.push_back(binary_search(begin, end, search_arr[i]));
	}
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i]<<" ";
	}
	system("pause");
}

/*
int main()
{
	order_arr.push_back(1);
	order_arr.push_back(2);
	order_arr.push_back(5);
	order_arr.push_back(12);
	order_arr.push_back(13);
	int num;
	cout << binary_search(0, 4, 5);
	system("pause");
}
*/
