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

void decompress()
{

    dictionary d;
    d.initial();
    
    
    ifstream fin ("compressed.txt",std::ios_base::binary);
    ofstream fout ("decompressed.txt");
    
	CodeType n;
	
    fin.read((char*)(&n),sizeof(CodeType));
    
	CodeType old=n;
    fout<<d.a[old];
    CodeType i=1;
    string c,s;
    
    while (fin.read((char*)(&n),sizeof(CodeType)))
    {
    	
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

    decompress();
}

