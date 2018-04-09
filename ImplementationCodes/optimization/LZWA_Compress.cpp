#include <bits/stdc++.h>
#include<unordered_map>
#define maxlen 1000
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

void compress()
{
	dictionary d;
    d.initial_d();

    ifstream fin ("given.txt");
    ofstream fout ("compressed.txt",std::ios_base::binary);
    
    char ch;	
    string curr,sn="", xsn;
    CodeType xscnt=0;
    
    while (fin.get(ch))
    {
        if (sn=="")
            curr=ch;
        else
            curr=sn+ch;
            
            
        if (d.find_d(curr)!=(CodeType)-1)
        {
            if (xscnt > 1)
            {

                d.insert_d(xsn+ch);
                xsn=xsn+ch;
                xscnt--;
            }
            sn=sn+ch;
        }
        else
        {
        	CodeType temp = d.find_d(sn);
//        	cout<<sn<<" "<<temp<<endl;
            fout.write((const char*)&temp,sizeof(CodeType));
            
			if (d.size_d!=max_16)
            {
                d.insert_d(sn+ch);
                xsn=sn+ch;
                xscnt=maxlen;
            }
            sn=ch;
        }
    }
    
    CodeType temp = d.find_d(sn);
    fout.write((const char*)&temp,sizeof(CodeType));
//    cout<<sn<<" "<<temp<<endl;
    
      fin.close();
    fout.close();
    
}



int main()
{
    compress();
}

