#include <iostream>

using namespace std;
bool isSubsetSum(int arr[], int n, int sum)
{
	bool flag = false;

	if(sum == 0)
		return true;

	if(n == 0 && sum > 0)
		return false;
	
	if(arr[n-1] > sum)
		return isSubsetSum(arr, n - 1, sum);
	
	return isSubsetSum(arr, n - 1, sum / 2) || isSubsetSum(arr, n - 1, sum / 2 - arr[n-1]);
}
bool findPartition(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + arr[i];
	}

	if(sum % 2 == 1)
		return false;

	return isSubsetSum(arr, n, sum/2);
}
int main()
{
	int arr[] = {3, 1, 5, 9, 12};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<findPartition(arr, n)<<endl;

	return 0;
}