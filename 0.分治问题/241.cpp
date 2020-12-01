#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
	public:
		vector<int> diffWaysToCompute(string input) {
			vector<int> res;
			for(int i = 0;i < input.length();++i){
				if((input[i] == '+') || (input[i] == '-') || (input[i] == '*')){
					vector<int> left = diffWaysToCompute(input.substr(0,i));
					vector<int> right = diffWaysToCompute(input.substr(i+1));

					for(auto l : left){
						for(auto r:right){
							if(input[i] == '+'){
								res.push_back(l+r);
							}
							else if(input[i] == '-'){
								res.push_back(l-r);
							}
							else{
								res.push_back(l*r);
							}
						}
					}
				}
			}
			if(res.empty()){
				return {stoi(input)};
			}
			return res;
		}
};

int main(){

	class Solution solu;
	string input1 = "2-1-1";
	string input2 = "2*3-4*5";
	
	vector<int> res1 = solu.diffWaysToCompute(input1);
	cout<<"str1 : ";
	for(auto a = res1.begin();a != res1.end();++a){
		cout<<*a<<" ";
	}
	cout<<endl;
	vector<int> res2 = solu.diffWaysToCompute(input2);
	
	cout<<"str2 : ";
	for(auto a = res2.begin();a != res2.end();++a){
	    cout<<*a<<" ";
	}
	cout<<endl; 
	return 0;
}
