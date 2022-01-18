// 希尔排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 就是插入排序的优化版本，实现简单，对于中等规模数据的性能表现还不错
// 不稳定，虽然插入排序是稳定的，但是希尔排序在插入的时候是跳跃性插入的，有可能破坏稳定性
// 每个分组进行插入排序后，各个分组就变成了有序的了（整体不一定有序）
//（从整体上看，小元素大体在前面，大元素大体在后面）
//https://mp.weixin.qq.com/s/4kJdzLB7qO1sES2FEW0Low
#include <iostream>
void insertI(int (&arr)[10],int gap,int i)
{
	int inserted = arr[i];
	int j;
	//对每组进行插入排序，gap为1 的时候就是插入增量为1的插入排序，即普通插入排序
	for ( j = i-gap; j>=0&&inserted < arr[j]; j-=gap)
	{
		arr[j + gap] = arr[j];
	}
	arr[j + gap] = inserted;


}
void shellSort(int (&arr)[10])
{// 12, 21, 1, 2, 33, 54, 5, 64, 65, 66
	int n = 10;
	//分成gep个组，增量为gep
	for (int gap = n/2; gap > 0; gap/=2)
	{
		//分别对每一组进行插入排序
		for (int i = gap; i < n;i++)
		{
			insertI(arr, gap, i);
		}
	}
}
int main()
{
	int arr[] = { 12,21,1,2,33,54,5,64,65,66 };
	shellSort(arr);
	for (int a : arr)
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
