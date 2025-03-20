#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>

#ifdef TEST
��ɢ����Ӧ��

��Ŀ��
�ٶ���һ�����޳������ᣬ�����ϸ������ϵ�������0��
���ڣ��������Ƚ���n�β�����ÿ�β�����ĳһλ��x�ϵ�����c��
������������m��ѯ�ʣ�ÿ��ѯ�ʰ�����������l��r, ��Ҫ���������r]֮����������ĺ͡�

�����ʽ��
��һ�а�����������n��m
������n�У�ÿ�а�����������x��c
�ٽ�����m�У��а�����������r��l

�����ʽ��
��m�У�ÿ�����һ��ѯ������������������ֺ͡�
#endif

const int N = 3 * 1e5 + 10;
int a[N]; //�����Ӧ��������ֵ
int s[N];//a��ǰ׺��
std::vector<int> alls;//�������������ص���������
std::vector<std::pair<int, int>> add, query;

int find(int x)//���ֲ���
{
	int l = 0;
	int r = alls.size() - 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (alls[mid] == x)return mid + 1;//S��1��ʼ��ӳ��λ��ǰ��һλ
		else if (alls[mid] < x)
		{
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return -1;
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)//���������n
	{
		int x, c;
		std::cin >> x >> c;//������xλ�õ�ֵ+c
		add.push_back({ x, c });//��¼+������λ��
		alls.push_back(x);//��¼λ��
	}

	for (int i = 0; i < m; i++)//��ѯ�Ĵ���m
	{
		int l, r;
		std::cin >> l >> r;//��Χ
		query.push_back({ l, r });//��¼��Χ[l, r]
		alls.push_back(l);
		alls.push_back(r);//Ҳ�Ž�alls?
	}

	std::sort(alls.begin(), alls.end());//����
	alls.erase(unique(alls.begin(), alls.end()), alls.end());//ɾ��

	for (auto& item : add)
	{
		int x = find(item.first);//��alls���ҵ���Ӧ��xλ��
		a[x] += item.second;//��¼x��Ӧ����+C
	}

	for (int i = 1; i <= alls.size(); i++) 
		s[i] = s[i - 1] + a[i];//ǰ׺��

	for (auto& item : query)
	{
		int l = find(item.first);//��alls�ҵ�l
		int r = find(item.second);
		std::cout << s[r] - s[l - 1] << std::endl;
	}

	return 0;
}
