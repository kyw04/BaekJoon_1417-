#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void* a, const void* b)
{
	int n1 = *(int*)a;
	int n2 = *(int*)b;
	if (n1 > n2)
		return 1;
	else if (n1 < n2)
		return -1;
	else return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[50];
	int i, N, dasom, max = 0, cnt = 0;
	cin >> N;
	cin >> dasom;
	for (i = 0; i < N - 1; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	qsort(arr, N - 1, sizeof(int), compare);
	i = 0;
	while (max >= dasom)
	{
		if (max < dasom)
			break;
		cnt++;
		dasom++;
		
		for (i = 0; i < N - 1; i++)
		{
			if (max == arr[i])
			{
				arr[i]--;
				break;
			}
		}
		if (i == N - 2)
			max--;
	}
	cout << cnt;
	return 0;
}