#define _CRT_SECURE_NO_WARNINGS 1

/*NC16679 [NOIP2003]������*/ //������Ȩͼ //��������
/*2024.2.20 �ڽӱ�*/
//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<queue>
//using namespace std;
//const int N = 210;
//struct gra {
//	int to, w;//���ӵ����Ȩ
//};
//vector<gra> arr[N];
//int c[N];
//int u[N]; //��ǰ״̬
//int in[N]; //��Ӧ��ŵ�����;
//
//int main() {
//	ios::sync_with_stdio(0);
//	int n, p;
//	cin >> n >> p;
//	for (int i = 1; i <= n; i++) {
//		cin >> c[i] >> u[i];
//		if (c[i] == 0) c[i] = -u[i];
//	}
//	for (int i = 0; i < p; i++) {
//		int from,to, w;
//		cin >> from >> to >> w;
//		arr[from].push_back({ to,w });
//		in[to]++;
//	}
//	queue<int> q;
//	for (int i = 1; i <= n; i++) {
//		if (in[i] == 0) {
//			q.push(i);
//		}
//	}
//	while (q.size()) {
//		int pos = q.front();
//		q.pop();
//		bool flag = 0;
//		if (c[pos] <= 0)continue;
//		for (auto t : arr[pos]) {
//			flag = 1;
//			int to = t.to;
//			int w = t.w;
//			c[to] += w * c[pos];
//			in[to]--;
//			if (in[to] == 0) q.push(to);
//		}
//		if (flag) c[pos] = 0;
//	}
//	vector<gra> ans;
//	for (int i = 1; i <= n; i++) {
//		if (c[i] > 0) ans.push_back({i, c[i]});
//	}
//	if (ans.size() == 0) cout << "NULL\n";
//	else {
//		for (auto t : ans) {
//			cout << t.to << " " << t.w << "\n";
//		}
//	}
//	return 0;
//}
/*2024.2.20 ��ʽǰ����*/
////WA:���Ǹ�head����ֵ-1
//#include <bits/stdc++.h>
//using namespace std;
//int n, p;
//struct {
//    int to;
//    int next;
//    int w;
//}edge[20002];
//struct {
//    int u;
//    int c;
//}node[210];
//int head[210];int cnt = 1;
//int in[210];
//
//int main() {
//    memset(head, -1, sizeof head);
//    ios::sync_with_stdio(0);
//    cin >> n >> p;
//    for (int i = 1; i <= n; i++) {
//        cin >> node[i].c >> node[i].u;
//        if (node[i].c == 0) node[i].c = -node[i].u;
//    }
//    for (int i = 0; i < p; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        edge[cnt].to = v;
//        edge[cnt].next = head[u];
//        edge[cnt].w = w;
//        in[v]++;
//        head[u] = cnt++;
//    }
//    //tuopu
//    queue<int> q;
//    for (int i = 1; i <= n; i++) {
//        if (in[i] == 0) {
//            q.push(i);
//        }
//    }
//    while (q.size()) {
//        int pos = q.front();
//        q.pop();
//        bool flag = 0;
//        if (node[pos].c <= 0) continue;
//        for (int i = head[pos]; i != -1; i = edge[i].next) {
//            int to = edge[i].to;
//            int w = edge[i].w;
//            int c = node[pos].c;
//            node[to].c += w * c;
//            in[to]--;
//            if (in[to] == 0) q.push(to);
//            flag = 1;
//        }
//        if (flag) node[pos].c = 0;
//    }
//    vector<pair<int, int>> ans;
//    for (int i = 1; i <= n; i++) {
//        if (node[i].c > 0) ans.push_back({ i,node[i].c });
//    }
//    if (ans.size() == 0) cout << "NULL\n";
//    else {
//        sort(ans.begin(), ans.end(), [](auto x, auto y) {
//            return x.first < y.first;
//        });
//        for (auto t : ans) {
//            cout << t.first << " " << t.second << "\n";
//        }
//    }
//    return 0;
//}
/*2024.2.20  ��� ���� ��ʽǰ����*/
////��������ķ�ʽ���������һ�����״̬��Ȼ��һ�����Ƶ����¸��㡣һֱ�����
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int maxn = 202;
////ʹ����ʽǰ����ȥ�洢ͼ��������
////Ϊʲô������ʽǰ���ǣ�//��Ϊhead��i����������iΪ�ڵ����������ߵĹ�ϵ
//struct sy {
//    int to;
//    int next;
//    int w;
//}edge[20002];
//struct Node {
//    int u;
//    int c;
//} node[maxn];
//int head[maxn];
//int in[maxn], to[maxn], to_cnt = 0;
//vector<pair<int, int> > pr;
//int cnt = 0;
//int n, p;
//
////��ʽǰ���Ǽӱ�
//void add_edge(int x, int y, int w)
//{
//    edge[++cnt].next = head[x]; //head��¼�˱��
//    edge[cnt].to = y;
//    edge[cnt].w = w;
//    head[x] = cnt;
//}
//
//bool comp(pair<int, int> p1, pair<int, int> p2)
//{
//    return p1.first < p2.first;
//}
//
//void topu()
//{
//    queue<int> q;
//    //��һ�����еĽڵ㣬�����Ϊ0�Ľڵ������������档
//    for (int i = 1;i <= n;i++)
//    {
//        //         cout<<"i="<<i<<" in[i]="<<in[i]<<endl;
//        if (in[i] == 0)
//        {
//            q.push(i);
//            //             cout<<"i="<<i<<endl;
//        }
//    }
//    while (q.size())
//    {
//        bool flag = false;
//        int pos = q.front();
//        //         cout<<"pos="<<pos<<endl;
//        q.pop();
//        if (node[pos].c <= 0) continue;//��û�м���
//        for (int i = head[pos];i != -1;i = edge[i].next) //����һ������-1�������û�г��ȵĵ㣩
//        {
//            int next = edge[i].to;//��������ӵ���һ����
//            int w = edge[i].w;
//            int c = node[pos].c;
//            node[next].c += w * c;
//            in[next]--;//ȡ�˵㣬��һ�������Ⱦ�-1
//            if (in[next] == 0)
//            {
//                q.push(next);
//            }
//            flag = true;
//        }
//        if (flag) node[pos].c = 0;//����������Ѿ���������
//    }
//}
//
//signed main()
//{
//    memset(head, -1, sizeof(head));
//    int x, y, w;
//    cin >> n >> p;
//    for (int i = 1;i <= n;i++) //node��¼ÿ����ĳ�ʼ��ֵ
//    {
//        cin >> node[i].c;
//        cin >> node[i].u;
//        if (node[i].c == 0)//û�м����ĵ�ĳ�ʼֱ�Ӽ�����ֵ
//        {
//            node[i].c -= node[i].u;
//        }
//    }
//    for (int i = 1;i <= p;i++)
//    {
//        cin >> x >> y >> w;
//        in[y]++; //y�����
//        add_edge(x, y, w);//��ʽǰ���ǣ�û����
//    }
//    topu();
//    //д�������
//    for (int i = 1;i <= n;i++)
//    {
//        if (node[i].c > 0)
//        {
//            pr.push_back({ i, node[i].c });
//        }
//    }
//    sort(pr.begin(), pr.end(), comp);//���ݹ�������
//    if (pr.size() == 0)
//    {
//        cout << "NULL" << endl;
//        return 0;
//    }
//    //���
//    vector<pair<int, int> >::iterator it;
//    for (it = pr.begin();it != pr.end();it++)
//    {
//        cout << (*it).first << " " << (*it).second << endl;
//    }
//    return 0;
//}

/*NC20115 [HNOI2015]��������������*/ //���򽨱�
/*2024.2.20 �ڽӱ�*/
////���� x->y
////ͬ��ȵĵ��н�����С��
////���򽨱ߣ�������������������������ֻ�ܰ�����ʼ�ĵ�ȥѰ��������С���ַ����У�
////��������Ŀ����Ҫ�����ȳԵ������ߵĲ��ȣ���ô��͹�ϵ���յ��ˡ�
////�������ǿ��Բ��÷��򽨱ߵķ�ʽ��ȥ��һ���ַ��������ģ�������ʵ���˾����ȳԵ������ߵĲ��ȡ�
////Ҳ�������ǰ�ԭ�����յ㻻������㣨������������һ��ʼ������յ㣩
////���򽨱�+��Ѷ���������𰸵��ǣ�ԭ���յ㣬����������������������������ƻ���Ϊ��Ѷ������
////WA: �ã�nodeû��ɾ�
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 100000 + 10;
//int in[N];
//int d,n,m;
////int to[N];
//vector<int> node[N];
//vector<int> ans;
//map<pair<int, int>, bool> g;
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> d;
//	while (d--) {
//		memset(in, 0, sizeof in);
//		ans.clear();
//		g.clear();
//		cin >> n >> m;
//		for (int i = 1; i <= n; i++)node[i].clear();
//		for (int i = 1; i <= m; i++) {
//			int x, y;
//			cin >> x >> y;
//			if (g[{x, y}]) continue;
//			node[y].push_back(x); //����ͼ???
//			in[x]++;
//			g[{x, y}] = 1;
//		}
//		priority_queue<int, vector<int>,less<int>> q;
//		for (int i = 1; i <= n; i++) {
//			if (in[i] == 0) q.push(i);
//		}
//		while (q.size()) {
//			int pos = q.top();
//			q.pop();
//			ans.push_back(pos);
//			for (int t : node[pos]) {
//				in[t]--;
//				if (in[t] == 0) q.push(t);
//			}
//		}
//		if (ans.size() != n) cout << "Impossible!\n";
//		else {
//			for (int i = n-1; i >= 0; i--) {
//				cout << ans[i] << " ";
//			}cout << "\n";
//		}
//	}
//	return 0;
//}
/*2024.2.20 ��� ��ʽǰ����*/
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
////ʹ����ʽǰ���Ǵ洢��
//const int maxn = 100000 + 10;
//struct sy {
//    int to;
//    int next;
//} edge[maxn];
//map<pair<int, int>, int> mp;
//struct comp {
//    bool operator () (const int& x, const int& y) const {
//        return x < y;
//    }
//};
//int in[maxn];
//int head[maxn];
//priority_queue<int, vector<int>, comp> pq;
//int cnt = 0;
//
//void add_edge(int x, int y)
//{
//    edge[++cnt].next = head[x];
//    edge[cnt].to = y;
//    head[x] = cnt;
//}
//
//void solve()
//{
//    while (pq.size()) pq.pop();
//    memset(in, 0, sizeof(in));
//    memset(head, -1, sizeof(head));
//    mp.clear();
//    for (int i = 0;i < maxn;i++) edge[i].next = 0, edge[i].to = 0;
//    cnt = 0;
//    int n, m;
//    int x, y;
//    vector<int> ans;
//    cin >> n >> m;
//    for (int i = 1;i <= m;i++)
//    {
//        cin >> x >> y;
//        if (mp[{x, y}] == 0)
//        {
//            //             cout<<"x="<<x<<" y="<<y<<endl;
//            mp[{x, y}] = 1;
//            add_edge(y, x);
//            in[x]++;
//        }
//    }
//    //����һ��ڵ㣬ѡ���ܹ�ѡ�����ĵ�һ���˽������ȶ�������
//    for (int i = 1;i <= n;i++)
//    {
//        if (in[i] == 0) pq.push(i);
//    }
//    while (pq.size())
//    {
//        int number = pq.top();
//        //         cout<<"number="<<number<<endl;
//        pq.pop();
//        ans.push_back(number);
//        for (int i = head[number];i != -1;i = edge[i].next)
//        {
//            //             cout<<"i="<<i<<endl;
//            in[edge[i].to]--;
//            if (in[edge[i].to] == 0)
//                pq.push(edge[i].to);
//        }
//    }
//    if (ans.size() != n) cout << "Impossible!";
//    else
//        for (int i = n - 1;i >= 0;i--)
//        {
//            cout << ans[i] << ' ';
//        }
//    cout << "\n";
//}
//
//signed main()
//{
//    int D;
//    cin >> D;
//    while (D--)
//    {
//        solve();
//    }
//    return 0;
//}
/*2024.2.23 ��ʽǰ����*/
////WA:����ûŪ��
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<algorithm>
//#include<queue>
//#include<map>
//using namespace std;
//const int N = 1e5 + 10;
//int in[N];
//struct {
//	int to;
//	int next;
//}edge[N];
//int head[N];
//int cnt = 1;
//map<pair<int, int>, bool> g;
//int main() {
//	int d;cin >> d;
//	while (d--) {
//		int n, m;
//		cin >> n >> m;
//		cnt = 1;
//		memset(head, -1, sizeof head);
//		memset(in, 0, sizeof in);
//		g.clear();
//		for (int i = 1; i <= m; i++) {
//			int x, y;
//			cin >> x >> y;
//			if (g[{x, y}]) continue;
//			edge[cnt].to = x;
//			edge[cnt].next = head[y];
//			head[y] = cnt++;
//			in[x]++;
//			g[{x, y}] = 1;
//		}
//		priority_queue<int> pq;
//		for (int i = 1; i <= n; i++) {
//			if (in[i] == 0) pq.push(i);
//		}
//		vector<int> ans;
//		while (pq.size()) {
//			int pos = pq.top();
//			pq.pop();
//			ans.push_back(pos);
//			for (int i = head[pos]; i != -1; i = edge[i].next) {
//				int to = edge[i].to;
//				in[to]--;
//				if (in[to] == 0) pq.push(to);
//			}
//		}
//		if (ans.size() != n) {
//			cout << "Impossible!\n";
//			continue;
//		}
//		for (int i = ans.size() - 1; i >= 0;i--) {
//			cout << ans[i] << " ";
//		}cout << "\n";
//	}
//	return 0;
//}

/*NC236175 ������*/
/*2024.2.22 ��ʽǰ����*/
////WA����ʽǰ���ǵı���д����
////����Ҫ�����ϰ //��סedge����Ǳ�
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<queue>
//#include<vector>
//#include<map>
//#include<stack>
//using namespace std;
//int n, m;
//const int N = 3e5 + 10;
//int in[N];
//int cost[N];
//int zao[N];
//int late[N];
//int head[N];
//int cnt = 1;
//struct Edge {
//	int to;
//	int next;
//	int w;
//}edge[N];
//map<pair<int, int>, bool> g;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m;
//	memset(head, 0, sizeof head);
//	memset(late, 0x3f, sizeof late);
//	for (int i = 1; i <= n; i++) {
//		cin >> cost[i];
//		zao[i] = cost[i];
//	}
//	for (int i = 1; i <= m; i++) {
//		int u, v;cin >> u >> v;
//		if (g[{u, v}]) continue;
//		g[{u, v}] = 1;
//		edge[cnt].to = v;
//		edge[cnt].next = head[u];
//		in[v]++;
//		head[u] = cnt++;
//	}
//	queue<int> q;
//	stack<int> st;
//	int tim = 0;
//	for (int i = 1; i <= n; i++) {
//		if (in[i] == 0)q.push(i);
//	}
//	while (q.size()) {
//		int pos = q.front();
//		q.pop();
//		st.push(pos);
//		tim = max(tim, zao[pos]);
//		for (int i = head[pos]; i != 0; i = edge[i].next) {//�������next��0
//			int to = edge[i].to;
//			in[to]--;
//			zao[to] = max(zao[to], zao[pos] + cost[to]);
//			if (in[to] == 0) q.push(to);
//		}
//	}
//	if (st.size() != n) {
//		cout << -1 << "\n";
//		return 0;
//	}
//	while (st.size()) {
//		int pos = st.top();
//		st.pop();
//		late[pos] = tim;
//		for (int i = head[pos]; i != 0; i = edge[i].next) {
//			int to = edge[i].to;
//			late[pos] = min(late[pos], late[to] - cost[to]);
//		}
//	}
//	vector<int> ans;
//	for (int i = 1; i <= n; i++) {
//		if (late[i] > zao[i]) ans.push_back(i);
//	}
//	cout << ans.size() << "\n";
//	for (int i : ans) {
//		cout << i << " ";
//	}cout << "\n";
//	return 0;
//}
/*2024.2.21 �ڽӱ�*/
////��ô֪��ʲôʱ��������ӣ�
////�������ҵ��������ʱ�䣬��¼����
////�������򣬷����������������ʱ��
////WA: ����Ƿ�Ϊ�ظ�·������
////WA: Ҳ��������ֵ�������
////WA: ��ʵ��ؼ��Ĵ�����û�д���ò����κε�������ӵĹ�����
////ps�����������һ�£�ǰ����WA�²ⶼ���ᵼ��WA��������С��Ϊ��~
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<queue>
//#include<vector>
//#include<algorithm>
//#include<map>
//using namespace std;
//int n, m;
//const int N = 3e5 + 10;
//struct Node {
//	int late = 0x3f3f3f3f;
//	int zao;
//	int cost;
//	int in = 0;
//}node[N];
//
//vector<int> arr[N];
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> node[i].cost;
//		node[i].zao = node[i].cost;
//	}
//	map<pair<int, int>, bool> g;
//	for (int i = 1; i <= m; i++) {
//		int u, v;
//		cin >> u >> v;
//		if (g[{u, v}]) continue;
//		g[{u, v}] = 1;
//		arr[u].push_back(v);
//		node[v].in++;
//	}
//	queue<int> q;
//	//priority_queue<int> pq;
//	vector<int> qq;
//	for (int i = 1; i <= n; i++) {
//		if (node[i].in == 0) {
//			q.push(i);
//		}
//	}
//	int tim = 0;
//	while (q.size()) {
//		int pos = q.front();
//		q.pop();
//		qq.push_back(pos);//��ʵ�ǰ����鵱ջ������
//		tim = max(tim, node[pos].zao);//�ҳ���������ʱ��
//		for (int i = 0; i < arr[pos].size(); i++) {
//			int x = arr[pos][i];
//			node[x].in--;
//			node[x].zao = max(node[x].zao, node[x].cost + node[pos].zao);//�������ʱ��
//			if (node[x].in == 0) {
//				q.push(x);
//			}
//		}
//	}
//	if (qq.size() != n) {
//		cout << -1 << "\n";
//		return 0;
//	}
//	for (int i = n-1; i >= 0; i--) {
//		int pos = qq[i];
//		node[pos].late = tim;//����������û���ȵĵ�
//		for (int i = 0; i < arr[pos].size(); i++) {
//			int to = arr[pos][i];
//			int cost = node[to].cost;
//			node[pos].late = min(node[to].late - cost, node[pos].late);
//		}
//	}
//	vector<int> ans;
//	for (int i = 1; i <= n; i++) {
//		if (node[i].late > node[i].zao) ans.push_back(i);
//	}
//	sort(ans.begin(), ans.end());
//	cout << ans.size() << "\n";
//	for (int i : ans) {
//		cout << i << " ";
//	}cout << "\n";
//	return 0;
//}
/*2024.2.22 ��� ��ʽǰ����*/
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int maxn = 3e5 + 10;
//const int maxnn = 1e5 + 10;
//struct sy {
//    int to;
//    int next;
//    int w;
//}edge[maxn];
//struct Node {
//    int first;
//    int late = 0x3f3f;
//    int cost;
//} node[maxnn];
//int head[maxnn];
//map<int, int> mp;
//int cnt = 0;
//int n, m, rt;
////��¼��ȵĸ���
//int in[maxnn];
//stack<int> st;
//
////������ʽǰ����
//void add_edge(int u, int v, int w)
//{
//    edge[++cnt].next = head[u];
//    edge[cnt].to = v;
//    edge[cnt].w = w;
//    head[u] = cnt;
//}
////��ʼ���е�һ����������
//bool tuopu()
//{
//    queue<int> q;
//    int num = 0;
//    for (int i = 1;i <= n;i++)
//    {
//        if (in[i] == 0)
//        {
//            q.push(i);
//            mp[i] = 1;
//        }
//    }
//    while (q.size())
//    {
//        int pos = q.front();
//        q.pop();
//        num++;
//        st.push(pos);//��ջ
//        rt = max(rt, node[pos].first + node[pos].cost);//������Ҫ���ѵ�ʱ��
//        for (int i = head[pos];i;i = edge[i].next)
//        {
//            int next = edge[i].to;
//            int w = edge[i].w;
//            node[next].first = max(node[next].first, node[pos].first + w);//�������翪ʼʱ��
//            in[next]--;
//            if (in[next] == 0) q.push(next);
//        }
//    }
//    if (num != n) return false;
//    return true;
//}
//
//void fanxiang()
//{
//    while (st.size())
//    {
//        int pos = st.top();//ջ�����Ƚ��ĺ����ȡ������ֵ
//        //         cout<<"pos="<<pos<<endl;
//        st.pop();
//        node[pos].late = rt - node[pos].cost;//����Ĭ���������ʼʱ��
//        for (int i = head[pos];i;i = edge[i].next)//����������ӵ�
//        {
//            int next = edge[i].to;
//            int late = node[next].late;
//            int w = edge[i].w;
//            node[pos].late = min(node[pos].late, late - w);//����ʼʱ�䣬���������ӵĵ㷴��
//        }
//    }
//}
//
//signed main()
//{
//    int t, u, v;
//    cin >> n >> m;
//    for (int i = 1;i <= n;i++) cin >> node[i].cost;
//    for (int i = 1;i <= m;i++)
//    {
//        cin >> u >> v;
//        in[v]++;
//        add_edge(u, v, node[u].cost);
//    }
//    bool isok = tuopu();
//    if (!isok)
//    {
//        cout << -1;
//        return 0;
//    }
//    //     cout<<"rt="<<rt<<endl;
//    fanxiang();
//    vector<int> vt;
//    for (int i = 1;i <= n;i++)
//    {
//        //         cout<<node[i].first<<" "<<node[i].late<<endl;
//        if (node[i].late > node[i].first)
//        {
//            vt.push_back(i);
//        }
//    }
//    cout << vt.size() << endl;
//    vector<int>::iterator it = vt.begin();
//    for (it;it != vt.end();it++)
//    {
//        cout << (*it) << ' ';
//    }
//    return 0;
//}
