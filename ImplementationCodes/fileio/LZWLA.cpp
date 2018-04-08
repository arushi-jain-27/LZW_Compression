#include <bits/stdc++.h>
#include <string>
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

void LA_encoder ()
{
    dictionary d;
    d.initial();
    ifstream fin ("given.txt");
    ofstream fout ("compressed.txt");
    char ch;
    fin.get(ch);
    string r(1,ch);

    while (fin.get(ch))
    {

        char c=ch;
        if (d.find(r+c)!=-1)
            {
                r=r+c;
            }
        else{
            fout<<d.find(r)<<" ";
            w[j++]=d.find(r);
            d.insert(r+c);
            r=c;
        }

    }
    fin.close();
    fout<<d.find(r)<<endl;
    w[j++]=d.find(r);
    fout.close();

/*
    for(int i=256;i<d.size;i++)
    {
        cout<<i<<" "<<d.a[i]<<endl;

    }*/
}
void LA_decoder()
{

    dictionary d;
    d.initial();
    char* ch;
    int chnum;
    ifstream fin ("compressed.txt");
    ofstream fout ("decompressed.txt");
    fin>>ch;
    chnum=atoi(ch);
    int old=chnum;
    fout<<d.a[old];
    int i=1;
    string c,s;
    int n;
    while (fin>>ch)
    {

     chnum=atoi(ch);
     n=chnum;
     if (n>=d.size)
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
         d.insert(d.a[old]+c);
         old=n;
        i++;
    }
}
int main()
{

    LA_encoder();
    LA_decoder();



    return 0;
}

