// 快速排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
void quickSort(int *arr,int low,int high)
{
	if (low < high)
	{
		int i = low;
		int j = high;
		int paivt = arr[low];
		while (i < j)
		{
			while (i < j && arr[j] >= paivt)
			{
				j--;
			}
			arr[i] = arr[j];
			while (i < j && arr[i] < paivt)
			{
				i++;
			}
			arr[j] = arr[i];
		}
		arr[i] = paivt;

		quickSort(arr, low, i - 1);
		quickSort(arr, i + 1, high);
	}
	
  
}

int main()
{
    int arr[10] = { 12,21,1,2,33,54,5,64,65,66 };
	
	
    quickSort(arr, 0, 9);
	for (int a : arr)
	{
		std::cout << a << ends;
	}
	_CrtDumpMemoryLeaks();

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
