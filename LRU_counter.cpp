#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int find( vector<int> p,int l)
{
	int d=-1;
	for(int i=0;i<p.size();i++)
	{
		if (p[i]==l)
		{
		return i;
		break;
		d++;
		}
	}
	if(d==-1)
	return -1;
}
int mincount(vector<int> k)
{
    int min=k[0];
    int l;
    for(int i=0;i<k.size();i++)
    {
        if(k[i]<=min)
        {
            min=k[i];
            l=i;
        }
        
    }
    return l;
}

vector<int> createData(string file_name) {
char ch;
vector<int>pages;
fstream fin(file_name.c_str(), fstream::in);
while (fin  >> ch) {
    int num = int(ch) - int('0'); 
    if(num>0 && num<10) {
    	pages.push_back(num);
	}
}
return pages;
}

int main()
{
   
   int a;
	int fault =0;
	int hit=0;
	int frames;
	int n;
	string file_name;
	cout<<"Enter the number of frames"<<endl;
	cin>>frames;
	cout<<"Enter the file name"<<endl;
	cin>>file_name;
	vector<int> v, pages = createData(file_name);
	n = pages.size();
	cout<<"Number of pages "<<n<<endl;
	vector<int> counter;
	int c=1;
	auto start = std::chrono::high_resolution_clock::now();
	for(int i=0;i<n;i++)
	{
	   a = pages.at(i);
	   if(v.empty())
	   {
	       v.push_back(a);
	       counter.push_back(c);
	       fault++;
	   }
	   else
	   {
	     if((find(v,a)==-1)&&(v.size()!=frames)) 
	     {
	         v.push_back(a);
	         fault++;
	         counter.push_back(c);
	     }
	     else if((find(v,a)==-1)&&(v.size()==frames))
	     {
	        
	         v[mincount(counter)]=a;
	         counter[mincount(counter)]=c;
	         fault++;
	         
	     }
	      else if(find(v,a)!=-1)
	     {
	         hit++;
	         counter[find(v,a)]=c;
	     }
	     
	   }
	   
	   c++;
	}

	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout<<"number of page faults are "<<fault<<endl;
	cout<<"number of page hits are "<<hit<<endl;
	cout<<"Elapsed time "<<elapsed.count()<<endl;
	   
	return 0;
}
