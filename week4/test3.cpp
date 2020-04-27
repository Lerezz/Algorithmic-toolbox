#include<iostream>
#define MAX_LEN 10000
#include<vector>
using namespace std;

int repeat[MAX_LEN] = { 0 };

void swap(int &i, int &j)
{
	int temp = i;
	i = j;
	j = temp;
}

void quick_sort(vector<int> &unsort, int left, int right)
{
	if (left > right) return;
	int lindex = left;
	int rindex = right + 1;
	int i = left + 1;
	int j = right;
	int value = unsort[left];
	while (i < rindex)
	{
		if (unsort[i] < value)
		{
			swap(unsort[i], unsort[lindex + 1]);
			lindex++;
			i++;
		}
		else if (unsort[i] > value)
		{
			swap(unsort[i], unsort[rindex - 1]);
			rindex--;
		}
		else
		{
			i++;
		}
	}
	swap(unsort[left], unsort[lindex]);
	quick_sort(unsort, left, lindex - 1);
	quick_sort(unsort, rindex, right);
}

int main()
{
	int n;
	cin >> n;
	vector<int> unsort;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		unsort.push_back(num);
	}
	quick_sort(unsort, 0, unsort.size() - 1);
	for (int i = 0; i < unsort.size(); i++)
	{
		cout << unsort[i] << " ";
	}
}
