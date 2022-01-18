// 归并排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*将一个大的无序数组有序，我们可以把大的数组分成两个，然后对这两个数组分别进行排序，之后在把这两个数组合并成一个有序的数组。
由于两个小的数组都是有序的，所以在合并的时候是很快的。
通过递归的方式将大的数组一直分割，直到数组的大小为 1，此时只有一个元素，那么该数组就是有序的了，之后再把两个数组大小为1的合
并成一个大小为2的，再把两个大小为2的合并成4的 … 直到全部小的数组合并起来。

*/

#include <iostream>
#include <vector>
using namespace std;
void mergeSortCore(vector<int>&data,vector<int>&dataTemp,int low,int high)
{
	if (low >= high)return;
	int len = high - low, mid = low + len / 2;
	int start1 = low, end1 = mid, start2 = mid + 1, end2 = high;
	mergeSortCore(data, dataTemp, start1, end1);
	mergeSortCore(data, dataTemp, start2, end2);

	int index = low;
	while (start1 <= end1 && start2 <= end2)
	{
		dataTemp[index++] = data[start1] < data[start2] ? data[start1++] : data[start2++];
	}
	while (start1 <= end1)
	{
		dataTemp[index++] = data[start1++];
	}
	while (start2 <= end2)
	{
		dataTemp[index++] = data[start2++];
	}
	for (index = low; index <= high; ++index) {
		data[index] = dataTemp[index];
	}
}
void mergeSort(vector<int>& data)
{
	int len = data.size();
	vector <int> dataTemp(len, 0);
	mergeSortCore(data, dataTemp, 0, len - 1);
}
int main()
{
	int arr[] = { 12,21,1,2,33,54,5,64,65,66 };
	vector<int> data(arr,arr+10);

	mergeSort(data);
	for (int a : data)
	{
		std::cout << a << std::ends;
	}

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
