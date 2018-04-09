#include <bits/stdc++.h>
#include<unordered_map>
#define maxlen 1000
#define max_16 65535

using namespace std;
using CodeType = std::uint16_t;


class dictionary
{
    public:
    unordered_map <CodeType , string> a;
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

    CodeType prev,curr,l;
    
    
	ifstream fin ("compressed.txt",std::ios_base::binary);
    ofstream fout ("decompressed.txt");
    
    fin.read((char*)(&prev),sizeof(CodeType));
    
    fout<<d.find_d(prev);
    string currstr,prevstr;
    prevstr=d.find_d(prev);

    while (fin.read((char*)(&curr),sizeof(CodeType)))
    {
    currstr=d.find_d(curr);
    CodeType k=currstr.length();
    fout<<currstr;
	    

			for (l=1;l<=min(k,(CodeType)maxlen);l++)
			{
				d.insert_d(prevstr+currstr.substr(0,l));	
			}
	prevstr=currstr;

    }
    
    fin.close();
    fout.close();
        
    for (int i=0;i<d.size_d;i++)
        cout<<i<<" "<<d.find_d(i)<<endl;
}


int main()
{
    decompress();
}

