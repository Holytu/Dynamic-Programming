#include <iostream>

using namespace std;
int max(int a, int b)
{
	if(a > b)
		return a;
	return b;
}
int CutRod(int arr[], int n)
{
	if( n <= 0)
		return 0;

	int maxNum = 0;

	for(int i = 0; i < n; i++)
	{
		maxNum = max(maxNum, arr[i] + CutRod(arr, n - i -1));
	}
	return maxNum;
}

int main()
{
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};//8
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<CutRod(arr, n);
	return 0;
}