#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

bool fn(vector<int> &vec, int n,int curr, int sum, int index,vector<int> &temp) {
	if(index == n) {
		//condition sattisfied
		if(curr == sum) {
			for(auto it: temp) cout << it << " ";
				cout << endl;
				return true;
		}
		//not satisfied
		else return false;
	}
	temp.push_back(vec[index]);
	curr += vec[index];
	//take
	if (fn(vec,n,curr,sum,index+1,temp))	
		return true;
	curr -= vec[index];
	temp.pop_back();
	//not take
	if(fn(vec,n,curr,sum,index+1,temp))
		return true;

	return false;
}
int main (){
	init_code();
	vector<int> vec = {1,2,1}, temp;
	int sum = 2, index = 0;
	int n = vec.size();
	fn(vec,n,0,sum,index,temp);
	return 0;

}


//NOW LETS SAY IF WE MODIFY THE QUESTION  AND SAY PRINT ONLY ONE SEQUECEN
// WE NEED TO END THE RECURSION IMMEDIATELY IF WE GET AN ANSWER SUCH A WAY THAT 

//TRICK TO PRINT ONE ANSWER:

//bool F(){
// BASE CASE:
// 	IF CONDITION SATISFIED
// 		RETURN TRUE
// 	ELSE 
// 		RETURN FALSE

// IF(F() == TRUE)
// 	RETURN true;

// F();
//return false
// }