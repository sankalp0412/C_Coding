//COMBINATION MATLAB ALL POSSIBLATIES
//HERE UNLIKE THE SUSUAL SCENARIO WHERE WHEN WE PICK THE INDEX WE MOVE TO
//THE NEXT INDEX WHEATHER WE PICK IT OR NOT:
// BUT SINCE WE ARE ALLOWED TO USE THE SAME ONE AGAIN THEN
//WE CAN CALL IT FOR THE SAME INDEX WITH , OUR TARGE WILL REDUCE BY THAT VALUE
// NEW SUM = SUM - NUMS[INDEX]

//IMP - WE WILL ALSO MAKE THIS SUM BACK TO ORIGNIAL AFTER THE RECURSION CALL
// AND REMOVE THIS FROM THE DATA STRUCTURE - line 34
//https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=10


// TIME COMPLEXTIY = 2 KI POWER T*K
//BECAUSE ASSUME THAT THE VALUE IS 1 AND WE ARE TRYING TO REACH THE TARGET VALUE OF 10
// HOW MANY TIMES CAN WE PICK AND NOT PICK : 10 TIMES AS WHEN WE PICK WE STAY AT THE SAME INDEX AT MOST 10 TMES
// IF AVG LENGTH IS K OF (N ELEMENTS) IT WILL TAKE A TC OF K FOR EVEY RECRSION CALL IN BASE CASE TO PUT INTO THE DATA STRUCTURE 
//SC WILL BE VARIABLE AS IT WILL DEPEND ON THE NUMBER OF COMBINATIONS


#include "bits/stdc++.h"
using namespace std;

void findCombinations(int index, vector<vector<int>> &ans,int target, vector<int> &arr, vector<int> temp){
        if(target < 0) return;
	        if(index == arr.size()) {
	            if(target == 0) {
	                ans.push_back(temp);
	            }
	        return;
	        }
        if(arr[index] <= target){
            temp.push_back(arr[index]);
            findCombinations(index,ans,target - arr[index], arr,temp);
            temp.pop_back();
        }
        findCombinations(index+1,ans,target, arr,temp);

    }

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

int main () {
	init_code();
	vector<vector<int>> ans;
	vector<int> temp;
	vector<int> arr = {2,3,6,7};
	int target = 7;
	findCombinations(0,ans,target,arr,temp);
	for(auto vec: ans) {
		for(auto x: vec){
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}