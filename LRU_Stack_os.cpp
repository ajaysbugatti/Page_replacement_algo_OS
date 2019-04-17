#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int find( vector<int> k,int l)
{
	int c=0;
	for(int i=0;i<k.size();i++)
	{
		if (k[i]==l)
		{
		return i;
		c++;
		}
	}
	if(c==0)
	return -1;
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
	int hit=0;
	int fault =0;
	int frames;
	int n;
	string file_name;
	cout<<"Enter the number of frames"<<endl;
	cin>>frames;
	cout<<"Enter the file name"<<endl;
	cin>>file_name;
	vector<int> v, pages = createData(file_name);
	n = pages.size();
	vector<int>::iterator it;
	auto start = std::chrono::high_resolution_clock::now();
	for(int i=0;i<n;i++)
	{
		a = pages.at(i);
	if(v.empty()==true)
	{
	v.push_back(a);
	fault++;
	}
	else
	{
		 if((find(v,a)==-1)&&(v.size()!=frames))
		{
		v.push_back(a);
		fault++;
		}
		else if(find(v,a)!=-1)
		{
		it=v.begin()+find(v,a);
		v.erase(it);
		v.push_back(a);
        hit++; 
		}
		else if((find(v,a)==-1)&&(v.size()==frames))
		{
			it=v.begin();
			v.erase(it);
			v.push_back(a);
			fault++;
		}
	}
	}


	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout<<"Number of pages "<<n<<endl;
	cout<<"number of page faults are "<<fault<<endl;
	cout<<"number of page hits are "<<hit<<endl;
	cout<<"Elapsed time "<<elapsed.count()<<endl;
	return 0;
}
