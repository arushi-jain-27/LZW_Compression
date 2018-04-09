#include <bits/stdc++.h>
#include <string>
#define max_16 65535
using namespace std;

using CodeType = std::uint16_t;


class dictionary
{
    public:
    string a[max_16];
    CodeType size;
    CodeType find(string s);
    void insert (string s);
    void initial ();
};


void dictionary::initial()
{
    for (int i=0;i<256;i++)
        a[i]=string(1,i);
    size=256;
}


CodeType dictionary::find(string s)
{
    for (int i=0;i<size;i++)
        if (a[i]==s)
            return (CodeType)i;
    return (CodeType)-1;
}


void dictionary:: insert(string s)
{
    if(size<max_16)
	{
	
	a[size]=s;
    size++;
	
	}
	
}

void compress()
{
    dictionary d;
    d.initial();
    ifstream fin ("given.txt");
    ofstream fout ("compressed.txt",std::ios_base::binary);
    char ch;
    fin.get(ch);
    string r(1,ch);

    while (fin.get(ch))
    {

        char c=ch;
        if (d.find(r+c)!=(CodeType)-1)
            {
                r=r+c;
            }
        else{
        	
        	
        	CodeType temp = d.find(r);
            fout.write((const char*)&temp,sizeof(CodeType));
            d.insert(r+c);
            r=c;
        }

    }
    
	CodeType temp = d.find(r);
    fout.write((const char*)&temp,sizeof(CodeType));
	fin.close();
    fout.close();

}


int main()
{

    compress();
}

