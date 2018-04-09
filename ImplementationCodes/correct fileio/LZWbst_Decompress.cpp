#include <bits/stdc++.h>
#include<map>
#define max_16 65535

using namespace std;

//int w[4096];
using CodeType = std::uint16_t;


class dictionary
{
    public:
    map <CodeType , string> a;
    CodeType size_d;
    string find_d(CodeType s);
    void insert_d (string s);
    void initial_d();
};

void dictionary::initial_d()
{
    for (int i=0;i<256;i++)
        a[i]=string(1,i);
    size_d=256;
}

string dictionary::find_d(CodeType i)
{
        if (a.find(i)!=a.end())
            return a[i];
     return "";
}

void dictionary:: insert_d(string s)
{
	if(size_d<max_16)
	{
	   a.insert(make_pair(size_d,s));
    	size_d++;
	}
 
}


void decompress()
{

    dictionary d;
    d.initial_d();
    CodeType x;
    /*
    char* ch;
    int chnum;*/
    
	ifstream fin ("compressed.txt",std::ios_base::binary);
    ofstream fout ("decompressed.txt");
    
    fin.read((char*)(&x),sizeof(CodeType));
    
	//cout<<"*";
    //chnum=atoi(ch);
    //cout<<"*";
    
	CodeType old=x;
    fout<<d.a[old];
    string c,s;
    CodeType n;

    while (fin.read((char*)(&x),sizeof(CodeType)))
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
    decompress();
}

