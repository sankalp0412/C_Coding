#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

int fn(vector<int> &vec, int n,int curr, int sum, int index,vector<int> &temp) {
	if(index == n) {
		//condition sattisfied
		if(curr == sum) 
			return 1;
		//not satisfied
		else 
			return 0;
	}
	temp.push_back(vec[index]);
	curr += vec[index];
	//take
	int l = fn(vec,n,curr,sum,index+1,temp);	

	curr -= vec[index];
	temp.pop_back();
	//not take
	int r = (fn(vec,n,curr,sum,index+1,temp));

	return l+r;
}
int main (){
	init_code();
	vector<int> vec = {1,2,1}, temp;
	int sum = 2, index = 0;
	int n = vec.size();
	int ans = fn(vec,n,0,sum,index,temp);
	cout << ans;
	return 0;

}


//NOW LETS SAY IF WE MODIFY THE QUESTION  AND SAY PRINT ONLY ONE SEQUECEN
// WE NEED TO END THE RECURSION IMMEDIATELY IF WE GET AN ANSWER SUCH A WAY THAT 

//TRICK TO PRINT ONE ANSWER:

//FUNCTION WILL RETURN A BOOL

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


///////////////////////////////////////

//NOW LETS MODIFY THIS FURTHER AND NOW WE ONLY WANT THE COUNT OF NUMBER SUBSEQUCNE WHOSE SUM IS SUM
//INT F(){
// BASE CASE:
// 	IF CONDITION SATISFIED
// 		RETURN 1
// 	ELSE 
// 		RETURN 0

//if there are two ercursion calls:
//l =  F();
//r = f();
// if there are multiple recusion calls then we can run a for loop and so on

// return l+r
// }
