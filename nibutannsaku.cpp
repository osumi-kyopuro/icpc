#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int a[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int s;
	cin >> s;

	int left = 0, right = 9;

	while (left < right)
	{
		//printf("a");
		int mid = (left + right) / 2;
		cout << mid << endl;
		if (s == a[mid])
		{
			printf("%dは%d番目\n", s, mid);
			break;
		}
		else if (s > a[mid]) {
			printf("真ん中より大きい\n");
			left = mid;
		}
		else if (s < a[mid]) {
			right = mid;
			printf("真ん中より小さい\n");
		}
	}
}