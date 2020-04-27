#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int lbinary_search(vector<int> begin, int point)
{
	int left = 0;
	int right = begin.size() - 1;
	int mid = 0;
	if (begin[right] <= point) return begin.size();
	if (begin[left] > point) return 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (begin[mid] > point) right = mid - 1;
		else if (begin[mid] < point) left = mid + 1;
		else
		{
			while (begin[mid] == point) mid++;
			return mid;
		}
	}
	if (begin[mid] < point) return mid + 1;
	else return mid;
}

int rbinary_search(vector<int> end, int point)
{
	int left = 0;
	int right = end.size() - 1;
	int mid = 0;
	if (end[right] < point) return 0;
	if (end[left] >= point) return end.size();
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (end[mid] > point) right = mid - 1;
		else if (end[mid] < point) left = mid + 1;
		else
		{
			while (end[mid] == point) mid--;
			return end.size() - mid - 1;
		}
	}
	if (end[mid] < point) return end.size() - mid - 1;
	else return end.size() - mid;
}

int get_result(vector<int> &p_begin, vector<int> &p_end, int point)
{
	int l = lbinary_search(p_begin, point);
	int r = rbinary_search(p_end, point);
	return l + r - p_begin.size();
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> p_begin(n);
	vector<int> p_end(n);
	for (int i = 0; i < n; i++)
	{
		cin >> p_begin[i] >> p_end[i];
	}
	vector<int> points(m);
	for (int i = 0; i < m; i++)
	{
		cin >> points[i];
	}
	sort(p_begin.begin(), p_begin.end());
	sort(p_end.begin(), p_end.end());
	for (int i = 0; i < points.size(); i++)
	{
		cout << get_result(p_begin, p_end, points[i])<<" ";
	}
}
