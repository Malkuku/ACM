#define _CRT_SECURE_NO_WARNINGS 1
#include"head.h"
int maxArea(std::vector<int>& height)
{
    int Alen = height.size();
    if (Alen < 2)
        return 0;

    int max = 0;
    for (int i = Alen - 1; i >= 0; i--)
    {
        for (int j = 0; j < Alen - 1 - i; j++)
        {
            int rheight = height[i] < height[j] ? height[i] : height[j];
            int v = (i - j + 1) * rheight;
            max = v > max ? v : max;
        }
    }
    return max;
}