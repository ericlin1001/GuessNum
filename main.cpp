/*
 * Problem:
 * Choose two numbers(1~20), tell A the sum of them, tell B the product of them, then A says I don't know what they are, B says I don't know either. At this time, A says I know, and B says I know, too.
 * The question is what's the two numbers?
 */
#include<iostream>
#include<vector>
#define Trace(m) cout<<#m"="<<(m)<<endl;
using namespace std;
void printArr(const vector<int>&a){
	cout<<"[";
	for(int i=0;i<a.size();i++){
		if(i!=0)cout<<",";
		cout<<a[i];
	}
	cout<<"]";
	cout<<endl;
}
class A{
	public:
		vector<int> guessA(int b){
			vector<int>res;
			for(int i=1;i*i<=b;i++){
				if(b%i==0){
					int j=b/i;
					int a=i+j;
					res.push_back(a);
				}
			}
			return res;
		}
		vector<int> guessB(int a){
			vector<int>res;
			for(int i=1;i<=a/2;i++){
				int j=a-i;
				int b=i*j;
				res.push_back(b);
			}
			return res;
		}

		int test(int a,int b){
			//A1
			if(guessB(a).size()<=1)return 1;
			//B1
			if(guessA(b).size()<=1)return 2;
			//A2
			vector<int>gb=guessB(a);
			int numa=0;
			for(int i=0;i<gb.size();i++){
				if(guessA(gb[i]).size()>=2){
					numa++;
				}
			}
			if(numa>=2)return 3;//if numa<=1 means A knows B.
			//B2
			//
			vector<int>ga=guessA(b);
			int numb=0;
			for(int i=0;i<ga.size();i++){
				vector<int>ggb=guessB(ga[i]);
				numa=0;
				for(int j=0;j<ggb.size();j++){
					if(guessA(ggb[j]).size()>=2){
						numa++;
					}
				}
				if(numa<=1){
					numb++;
				}
			}
			if(numb>=2)return 4;
			return 0;

		}
#define Trace(m) cout<<#m"="<<(m)<<endl;
		void guess(){
			for(int i=1;i<=20;i++){
				for(int j=i;j<=20;j++){
					int a=i+j;
					int b=i*j;
					//2<=a<=40 1<=b<=400
					if(test(a,b)==0){
						Trace(i);
						Trace(j);

					}
				}
			}
		}
		int newtest(int i,int j){
			return test(i+j,i*j);
		}
};
class B{
	public:
		vector<int> guessA(int b){
			vector<int>res;
			for(int i=1;i*i<=b;i++){
				if(b%i==0){
					int j=b/i;
					if(i!=j){
						int a=i+j;
						res.push_back(a);
					}
				}
			}
			return res;
		}
		vector<int> guessB(int a){
			vector<int>res;
			for(int i=1;i<=a/2;i++){
				int j=a-i;
				if(i!=j){
					int b=i*j;
					res.push_back(b);
				}
			}
			return res;
		}

		int test(int a,int b){
			//A1
			if(guessB(a).size()<=1)return 1;
			//B1
			if(guessA(b).size()<=1)return 2;
			//A2
			vector<int>gb=guessB(a);
			int numa=0;
			for(int i=0;i<gb.size();i++){
				if(guessA(gb[i]).size()>=2){
					numa++;
				}
			}
			if(numa>=2)return 3;//if numa<=1 means A knows B.
			//B2
			//
			vector<int>ga=guessA(b);
			int numb=0;
			for(int i=0;i<ga.size();i++){
				vector<int>ggb=guessB(ga[i]);
				numa=0;
				for(int j=0;j<ggb.size();j++){
					if(guessA(ggb[j]).size()>=2){
						numa++;
					}
				}
				if(numa<=1){
					numb++;
				}
			}
			if(numb>=2)return 4;
			return 0;

		}
#define Trace(m) cout<<#m"="<<(m)<<endl;
		void guess(){
			for(int i=1;i<=20;i++){
				for(int j=i;j<=20;j++){
					if(i!=j){
						int a=i+j;
						int b=i*j;
						//2<=a<=40 1<=b<=400
						if(test(a,b)==0){
							//Trace(a);
							//Trace(b);
							Trace(i);
							Trace(j);
							cout<<endl;

						}
					}
				}
			}
		}
		int newtest(int i,int j){
			return test(i+j,i*j);
		}
};
int main(){
	//	Trace(test(9+20,9*20));
	//	Trace(newtest(2,3));
	A a;
	B b;
	cout<<"Allow duplicate"<<endl;
	a.guess();
	cout<<"Not allow duplicate"<<endl;
	b.guess();
	cout<<"end of result."<<endl;
	return 0;
}
