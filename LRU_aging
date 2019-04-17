#include <bits/stdc++.h>
#include<chrono>
using namespace std;
class NFUCache {
    private:
    	int frame_size, page_faults, page_hits;
    	int *arr;
    	int *frequency;
    	void replaceAndUpdate(int page) {
    		page_faults++;
    		// find least frequently used page //
    		int min = frequency[0], min_pointer = 0;
    		for(int i=0;i<frame_size; i++) {
    			if(min > frequency[i]){
				 min = frequency[i];
				 min_pointer = i;
				}
			}

    		// replace least frequently used page //
    		int lfu_page = min_pointer;
    		arr[lfu_page] = page;
    		frequency[lfu_page] = 1;
    	}
    	void updateFrequencies(int frame) {
    		for(int i=0;i <frame_size; i++) {
    			 frequency[i] >> 1 ; //exponential decay
    			 if(i == frame) frequency[i] += 1 << 14; //Since range is 2^15
			}
		}

    public:
    	NFUCache(int size){
    		// initialize cache //
    		page_faults=0;
    		page_hits=0;
    		frame_size=size;
    		arr = (int*)calloc(sizeof(int), frame_size);
    		frequency = (int*)calloc(sizeof(int), frame_size);
    		for(int i=0; i<frame_size; i++){
    			frequency[i] = 0;
    		}
    		for(int i=0; i<frame_size; i++){
    			arr[i]=0;
    		}
    	}

    	void findAndUpdate(int page) {
    		bool found = false;
    		for(int i=0; i<frame_size; i++){
    			if(arr[i] == page){
    				frequency[i] = frequency[i] + 1;
    				found = true;
    				page_hits++;
    				updateFrequencies(i);
    				break;
    			}
    		}
    		// if cache is full find and replace the least frequently used page // 
    		if(found == false){
    			replaceAndUpdate(page);
    			updateFrequencies(-1);
    		}
    		
    		
    	}

    	void printData() {
    		cout <<"Number of hits : "<<page_hits<<endl;
    		cout <<"Number of faults : "<<page_faults<<endl;
    	}

};

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

int main() {
	clock_t t;
	int frame_size;
	vector<int> pages;
	string file_name;
	cout<<"Enter name of file"<<endl;
	cin>>file_name;
	cout<<"Enter number of frames"<<endl;
	cin>>frame_size;
	pages = createData(file_name);
	NFUCache cache(frame_size);
	auto start = std::chrono::high_resolution_clock::now();
	for(int i=0; i<pages.size(); i++){
		cache.findAndUpdate(pages.at(i));
	}
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout<<"Number of pages "<<pages.size()<<endl;
	cout<<"Elapsed time "<<elapsed.count()<<endl;
	cache.printData();
}
