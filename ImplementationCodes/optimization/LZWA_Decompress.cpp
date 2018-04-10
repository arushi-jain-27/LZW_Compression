#include <bits/stdc++.h>
#include<unordered_map>
#define maxlen 2
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
//	cout<<"inserting--->"<<size_d<<" "<<s<<endl;
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
    if(currstr=="")
    {
    	if(curr==d.size_d)
			currstr=prevstr + prevstr.substr(0,1);
		else 
			currstr=prevstr + prevstr.substr(0,2);

	}
	
    CodeType k=currstr.length();
      			  
//	cout<<"writing--->"<<curr<<" "<<currstr<<endl;

    fout<<currstr;
	    

			for (l=1;l<=min(k,(CodeType)maxlen);l++)
			{
				d.insert_d(prevstr+currstr.substr(0,l));	
			}
	prevstr=currstr;

    }
    
    fin.close();
    fout.close();
        
}


int main()
{
    decompress();
}

