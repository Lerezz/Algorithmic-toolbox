#include <iostream>
#include <vector>
using namespace std;

int compute_min_refills(int dist, int tank, vector<int> stops)
{
	int times = 0;
	for (int i = 0; i < stops.size(); i++)
	{
		if (stops[i] > tank && stops[i-1] == 0) return -1;
		if (stops[i] > tank)
		{
			i = i - 1;
			int temp = stops[i];
			for (int j = i; j < stops.size(); j++)
			{
				stops[j] -= temp;
			}
			times += 1;
		}
	}
	return times;
}


int main()
{
	int d, m, n;
	cin >> d >> m >> n;	// distance,capacity,number of stops

	vector<int> stops;
	stops.push_back(0);
	int num;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		stops.push_back(num);
	}		
	stops.push_back(d);
	cout << compute_min_refills(d, m, stops) << "\n";
	return 0;
}
