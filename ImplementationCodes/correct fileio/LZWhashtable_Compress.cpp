#include <bits/stdc++.h>
#include<unordered_map>

#define max_16 65535
using namespace std;


/// Type used to store and retrieve codes.
using CodeType = std::uint16_t;



//int w[4096];

class dictionary
{
    public:
    unordered_map <string , CodeType> a;
    CodeType size_d;
    CodeType find_d(string s);
    void insert_d (string s);
    void initial_d();
};

void dictionary::initial_d()
{
    for (CodeType i=0;i<256;i++)
        a[string(1,i)]=i;
    
	size_d=256;
}

CodeType dictionary::find_d(string s)
{
        if (a.find(s)!=a.end())
            return a[s];
    return (CodeType)-1;
}

void dictionary:: insert_d(string s)
{
	if(size_d<max_16)
	{
	    a.insert(make_pair(s,size_d));
	    size_d++;
	}
}

////////////////////////////////////////////////////////////////////////////
void compress()
{
    dictionary d;
    d.initial_d();

    ifstream fin ("given.txt");
    ofstream fout ("compressed.txt",std::ios_base::binary);
    if (!fout.is_open())
    {
		cout<<"^^^^";;
    }
    char ch;
    fin.get(ch);
    string r(1,ch);

    while (fin.get(ch))
    {
        char c=ch;

        if (d.find_d(r+c)!=(CodeType)-1)
            {
                r=r+c;
            }

        else{
        	
        	CodeType temp = d.find_d(r);
            fout.write((const char*)&temp,sizeof(CodeType));

//            w[j++]=d.find_d(r);
            
			d.insert_d(r+c);
            r=c;
        }

    }
    
  	CodeType temp = d.find_d(r);
    fout.write((const char*)&temp,sizeof(CodeType));
    
//    w[j++]=d.find_d(r);
    fin.close();
    fout.close();
}


int main()
{
    compress();
    return 0;
}

