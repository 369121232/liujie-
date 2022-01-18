// 插入排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 稳定的，http://mp.weixin.qq.com/s?__biz=MzU1MDE4MzUxNA==&mid=2247483924&idx=1&sn=936546a8b0d20ff8cc0b851311517e7f&chksm=fba53521ccd2bc373e9ddcfaae201f276f41bdd8f0ca57278fc231ce272470fb8c014c7ae698&scene=21#wechat_redirect

#include <iostream>
void mysort(int(&arr)[10],int i)
{
    int temp = arr[i];//把要排序的数存起来，因为后续移动会覆盖。
    int j = i - 1;//认为第一个元素为已经排好序的序列
    while ( arr[j] > temp && j >=0)//如果前一个数大于这个要插入的数，就把他往后移动，直到该数小于等于temp，或者前面没有数（说明已经是最小的数）。
    {
		arr[i] = arr[i - 1];

        j--;
    }
    arr[j+1] = temp;//插入到比temp小或等于的（稳定的原因）后面。

   
}
void insertSort(int (&arr)[10])
{
    for (int i = 1; i < 10; i++)
    {
        mysort(arr,i);
    }
}
int main()
{
    int arr[] = { 12,21,1,2,33,54,5,64,65,66 };
    insertSort(arr);
    for (int a:arr)
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
