/*逸 1.14*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<algorithm>
//#include<string>
//
////排0 //排1
//const int N = 1e5+10;
//int n;
//char arr[N];
//int res = 0;
//
//int main()
//{
//	scanf("%d", &n);
//	scanf("%s", arr);
//	//排1
//	int res1 = 0;
//	int num = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] == '1')
//		{
//			res1 += i - num;
//			num++;
//		}
//	}
//	int res2 = 0;
//	num = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] == '0')
//		{
//			res2 += i - num;
//			num++;
//		}
//	}
//	res = std::min(res1, res2);
//	printf("%d", res);
//
//	return 0;
//}
//
//
//#include<algorithm>
//#include<iostream>
//
//int main()
//{
//
//	return 0;
//}

/*测试数组的初始化*/
//#include<iostream>
//int main()
//{
//	int arr[10];
//	for (auto i : arr) printf("%d ", i);
//	printf("\n");
//	arr[0] = 618;
//	for (auto i : arr) printf("%d ", i);
//	printf("\n");
//	memset(arr, 0x3f, sizeof arr);
//	for (auto i : arr) printf("%d ", i);
//	printf("\n");
//
//	//奇怪的初始化
//	int arr2[10] = { 0x3f3f3f3f };
//	for (auto i : arr2) printf("%d ", i);
//	printf("\n");
//	const int N = 1e4 + 10;
//	int dp[N] = { INT_MAX };//初始化？？？？ 
//	for (auto i : dp) printf("%d ", i);
//	printf("\n");
//
//	return 0;
//}


/*kmp next数组*/
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main()
//{
//    string s = "cbbd";
//    int res = 0;
//    //KMP next
//    int next[1010] = { 0 };
//    int n = s.size();
//    int j = 0;//目前的next数组长度
//    int i = 1;
//
//    while (i < n)
//    {
//        if (s[i] == s[j])
//        {
//            j++;
//            next[i] = j;
//            res = max(res, next[i]);
//            i++;
//        }
//        else
//        {
//            if (j == 0) next[i++] = 0;
//            else j = next[j - 1];
//        }
//    }
//    printf("%d ", res);
//
//    return 0;
//}