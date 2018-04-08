#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int w[4096];

class dictionary_e
{
    public:
    map <string , int> a;
    int size_d;
    int find_d(string s);
    void insert_d (string s);
    void initial_d();
};
void dictionary_e::initial_d()
{
    for (int i=0;i<256;i++)
        a[string(1,i)]=i;;
    size_d=256;
}
int dictionary_e::find_d(string s)
{
        if (a.find(s)!=a.end())
            return a[s];
    return -1;
}
void dictionary_e:: insert_d(string s)
{
    a.insert(make_pair(s,size_d));
    size_d++;
}
    int j=0;

////////////////////////////////////////////////////////////////////////////


class dictionary_d
{
    public:
    map <int , string> a;
    int size_d;
    string find_d(int s);
    void insert_d (string s);
    void initial_d();
};
void dictionary_d::initial_d()
{
    for (int i=0;i<256;i++)
        a[i]=string(1,i);
    size_d=256;
}
string dictionary_d::find_d(int i)
{
        if (a.find(i)!=a.end())
            return a[i];
    return "";
}
void dictionary_d:: insert_d(string s)
{
    a.insert(make_pair(size_d,s));
    size_d++;
}
////////////////////////////////////////////////////////////////////////////////////




void LA_encoder (string s)
{
    dictionary_e d;
    d.initial_d();
    string r(1,s[0]);
    int i=1;
    while (s[i]!='\0')
    {
        char c=s[i];
        if (d.find_d(r+c)!=-1)
            {
                r=r+c;
            }
        else{
            cout<<d.find_d(r)<<" ";
            w[j++]=d.find_d(r);
            d.insert_d(r+c);
            r=c;
        }
        i++;
    }
    cout<<d.find_d(r)<<endl;
    w[j++]=d.find_d(r);



    for(int i=256;i<d.size_d;i++)
    {
       // cout<<i<<" "<<d.a[i]<<endl;

    }
}

void LA_decoder()
{

    dictionary_d d;
    d.initial_d();
    int old=w[0];
    cout<<d.a[old];
    int i=1;
    string c,s;
    int n;

    while (i<j)
    {
     n=w[i];
     if (n>=d.size_d)
     {
         s=d.a[old];
         s=s+c;
     }
     else
     {
         s=d.a[n];
     }
         cout<<s;
         c=s[0];
         d.insert_d(d.a[old]+c);
         old=n;

        i++;
    }
}

int main()
{

    LA_encoder("banana_bandana_aaadawdafrsgsrg_rgegerg  rgegergerged rg drgdrgd rgdrg y j yu jk yu jyikyukyuikjr tg sergwerfsdcfwef qe fwefwrferge tghrtyjyukyujt6hrtergerg e tet g");
    LA_decoder();



    return 0;
}

