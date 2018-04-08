#include <bits/stdc++.h>
using namespace std;

int w[4096];

class dictionary
{
    public:
    string a[4096];
    int size;
    int find(string s);
    void insert (string s);
    void initial ();
};
void dictionary::initial()
{
    for (int i=0;i<256;i++)
        a[i]=string(1,i);
    size=256;
}
int dictionary::find(string s)
{
    for (int i=0;i<size;i++)
        if (a[i]==s)
            return i;
    return -1;
}
void dictionary:: insert(string s)
{
    a[size]=s;
    size++;
}
    int j=0;

void LA_encoder (string s)
{
    dictionary d;
    d.initial();
    string r(1,s[0]);
    int i=1;
    while (s[i]!='\0')
    {
        char c=s[i];
        if (d.find(r+c)!=-1)
            {
                r=r+c;
            }
        else{
            cout<<d.find(r)<<" ";
            w[j++]=d.find(r);
            d.insert(r+c);
            r=c;
        }
        i++;
    }
    cout<<d.find(r)<<endl;
    w[j++]=d.find(r);



    for(int i=256;i<d.size;i++)
    {
        cout<<i<<" "<<d.a[i]<<endl;

    }
}
void LA_decoder()
{

    dictionary d;
    d.initial();
    int old=w[0];
    cout<<d.a[old];
    int i=1;
    string c,s;
    int n;
    while (i<j)
    {
     n=w[i];
     if (n>=d.size)
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
         d.insert(d.a[old]+c);
         old=n;
        i++;
    }
}
int main()
{

    LA_encoder("banana_bandana_aaadawdafrsgsrg_rgegerg ");
    LA_decoder();



    return 0;
}

