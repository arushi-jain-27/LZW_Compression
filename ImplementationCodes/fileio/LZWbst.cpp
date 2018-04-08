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




void LA_encoder ()
{
    dictionary_e d;
    d.initial_d();
    ifstream fin ("given.txt");
    ofstream fout ("compressed.txt");
    char ch;
    fin.get(ch);
    string r(1,ch);

    while (fin.get(ch))
    {
        char c=ch;
        if (d.find_d(r+c)!=-1)
            {
                r=r+c;
            }
        else{
            fout<<d.find_d(r)<<" ";
            w[j++]=d.find_d(r);
            d.insert_d(r+c);
            r=c;
        }

    }
    fout<<d.find_d(r)<<endl;
    w[j++]=d.find_d(r);
    fin.close();
    fout.close();




}

void LA_decoder()
{

    dictionary_d d;
    d.initial_d();
    int x;
    /*
    char* ch;
    int chnum;*/
    ifstream fin ("compressed.txt");
    ofstream fout ("decompressed.txt");
    fin>>x;
    //cout<<"*";
    //chnum=atoi(ch);
    //cout<<"*";
    int old=x;
    fout<<d.a[old];
    string c,s;
    int n;

    while (fin>>x)
    {
     //chnum=atoi(ch);
     n=x;
     if (n>=d.size_d)
     {
         s=d.a[old];
         s=s+c;
     }
     else
     {
         s=d.a[n];
     }
         fout<<s;
         c=s[0];
         d.insert_d(d.a[old]+c);
         old=n;


    }
    fin.close();
    fout.close();
}

int main()
{

    LA_encoder();
    LA_decoder();



    return 0;
}

