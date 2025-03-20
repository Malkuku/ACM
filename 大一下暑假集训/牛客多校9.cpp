#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
int a[N];
string l_low,l_high,r_low,r_high;
string add(string str1, string str2){
    string str;
    int len1 = str1.length();
    int len2 = str2.length();
    if (len1 < len2){
        for (int i = 1; i <= len2 - len1; i++)
            str1 = "0" + str1;
    }
    else{
        for (int i = 1; i <= len1 - len2; i++)
            str2 = "0" + str2;
    }
    len1 = str1.length();
    int cf = 0;
    int temp;
    for (int i = len1 - 1; i >= 0; i--){
        temp = str1[i] - '0' + str2[i] - '0' + cf;
        cf = temp / 10;
        temp %= 10;
        str = char(temp + '0') + str;
    }
    if (cf != 0)  str = char(cf + '0') + str;
    return str;
}

string mul(string str1,string str2){
    string str;
    int len1=str1.length();
    int len2=str2.length();
    string tempstr;
    for(int i=len2-1;i>=0;i--){
        tempstr="";
        int temp=str2[i]-'0';
        int t=0;
        int cf=0;
        if(temp!=0){
            for(int j=1;j<=len2-1-i;j++)
              tempstr+="0";
            for(int j=len1-1;j>=0;j--){
                t=(temp*(str1[j]-'0')+cf)%10;
                cf=(temp*(str1[j]-'0')+cf)/10;
                tempstr=char(t+'0')+tempstr;
            }
            if(cf!=0) tempstr=char(cf+'0')+tempstr;
        }
        str=add(str,tempstr);
    }
    str.erase(0,str.find_first_not_of('0'));
    return str;
}
bool cmp1(string s1,string s2){
      if(s1.size() < s2.size()) return 0;
      else
      if(s1.size() > s2.size()) return 1;
      for(int i = 0; i < s1.size(); i++){
        if(s1[i] - '0' > s2[i] - '0') return 1;
        if(s1[i] - '0' < s2[i] - '0') return 0;
      }
      return 1;
}
bool cmp2(string s1,string s2){
      if(s1.size() > s2.size()) return 0;
      else
      if(s1.size() < s2.size()) return 1;
      for(int i = 0; i < s1.size(); i++){
        if(s1[i] - '0' < s2[i] - '0') return 1;
        if(s1[i] - '0' > s2[i] - '0') return 0;
      }
      return 0;
}
ll check_low(string x){ //l_low /r_low--10^len_high
    ll l = 0,r = 1e16;
    while(l + 1 != r){
        ll mid = (l+r) >> 1;
        string mid2 = to_string(mid); // >= x fist
        if(cmp1(mul(mid2,mid2),x)) r = mid;
        else l = mid; 
    }
    return r;
}
ll check_high(string x){ //r_high / 10^len_low
    ll l = 0,r = 1e16;
    while(l + 1 != r){
        ll mid = (l+r) >> 1;
        string mid2 = to_string(mid);
        if(cmp2(mul(mid2,mid2),x)) l = mid; //>
        else r = mid; 
    }
    return l;
}
ll get_num(int arr[],int len){
    ll ans = 0;
    for(int i = 1; i <= len; i++){
        ans *= 10;
        ans += arr[i];
    }
    //cout << ans << "\n";
    return ans;
}
void test1(int arr[],int len){
    cout << len << "\n";
    for(int i = 1; i <= len; i++) cout << arr[i] <<  " ";
    cout << "\n";
}
string dpow(int len2){
    string ans = "1";
    for(int i = 1;  i <= len2 ; i++){
        ans += "0";
    }
    return ans;
}
string zero(string x){
    string res;
    int lk = 0;
    while(x[lk] == '0' && lk < x.size()) lk++;
    for(int i = lk; i < x.size(); i++) res += x[i];
    if(res.size() == 0) res += "0";
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    int n;cin >> n;
    string L,R;cin >> L >> R;
    int low = (n+1)/2;
    int high = n - low;
    int len_low = 0;
    int len_high = 0;
    for(int i = 0; i < n; i++){
        if(i+1 <= high){  
            l_high += L[i]; 
            r_high += R[i];
            len_high++;
        } 
        else{
            l_low += L[i];
            r_low += R[i];
            len_low++;
        }
    }
    //test1(l_low,len_low);
    //test1(r_high,len_high);
    
    ll cnt_low = 0,cnt_high = 0;
    string l_low_num = zero(l_low);
    string l_high_num = zero(l_high);
    string r_low_num = zero(r_low);
    string r_high_num = zero(r_high);
    cout << l_low_num << " " << l_high_num << " " << r_low_num << " " << r_high_num << "\n";
    cnt_low = (check_high(l_high_num) - check_low(l_low_num)+1);
    cnt_high = (check_high(r_high_num) - check_low(r_low_num)+1);
    cout <<  check_high(r_high_num) << " " <<check_low(r_low_num) << "\n";
    cout << check_high(l_high_num) << " " << check_low(l_low_num) << "\n";
   // cout << cnt_high << " " << cnt_low << "\n";
    cout << cnt_high * cnt_low << "\n";
    return 0;
}
