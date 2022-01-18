// 冒泡排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 原理：从后往前（或从前往后）两两比较相邻元素的值，若为逆序（即A【i-1】>A【i】），则交换它们，直到序
// 列比较完。称这样过程为“一趟”冒泡排序。每一趟排序能确定一个最大的数。
// flag = false 一次都没交换 说明已经排好顺序了， 提前结束趟数。

#include <iostream>

using namespace std;
void maopaoSort(int (&arr)[10])
{

    for (int i = 0; i < sizeof(arr)/sizeof(int);++i)
    {
        bool flag = false;
        for (int j = 0; j < sizeof(arr) / sizeof(int)-i-1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;
            }
         
        }
        if (flag == false) 
        {
            //提前结束
            return;
        }
    }
}
int main()
{
    int arr[] = {12,21,1,2,33,54,5,64,65,66};
    maopaoSort(arr);
    for (int a : arr)
    {
        std::cout << a <<ends;
    }
  
}

