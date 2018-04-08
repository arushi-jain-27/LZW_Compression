#include <bits/stdc++.h>
#include<unordered_map>
#define maxlen 4
using namespace std;

int w[4096];

class dictionary_e
{
    public:
    unordered_map <string , int> a;
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

    dictionary_e e;

    e.initial_d();
    string curr,sn="", xsn;
    int i=0, xscnt=0;
    while (s[i]!='\0')
    {
        string ch(1,s[i]);
        if (sn=="")
            curr=ch;
        else
            curr=sn+ch;
        if (e.find_d(curr)!=-1)
        {
            if (xscnt > 1)
            {

                e.insert_d(xsn+ch);
                xsn=xsn+ch;
                xscnt--;
            }
            sn=sn+ch;
        }
        else
        {
            cout<<e.find_d(sn)<<" ";
            w[j++]=e.find_d(sn);
            if (e.size_d!=4096)
            {

                e.insert_d(sn+ch);
                xsn=sn+ch;
                xscnt=maxlen;
            }
            sn=ch;
        }

         i++;
    }
    cout<<e.find_d(sn)<<endl;
    w[j++]=e.find_d(sn);


}

void LA_decoder()
{

    dictionary_d d;
    d.initial_d();

    int prev=w[0],curr,i=1,l;
    cout<<d.find_d(prev);
    string currstr;

    while (i<j)
    {
    curr=w[i];
    currstr=d.find_d(curr);
    int k=currstr.length();
    cout<<d.find_d(curr);
    for (l=1;l<= min(k,maxlen);l++)
        d.insert_d(d.find_d(prev)+currstr.substr(0,l));
    prev=curr;
    i++;

    }
    cout<<endl;
    for (int i=0;i<d.size_d;i++)
        cout<<i<<" "<<d.find_d(i)<<endl;
}

int main()
{

    LA_encoder("shdgakhgf ff shdgakhgf shdgakhgf ff shdgakhgf ff shdgakhgf");
    LA_decoder();



    return 0;
}

