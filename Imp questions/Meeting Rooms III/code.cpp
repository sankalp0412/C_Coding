#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
typedef pair<int,long> pii;
class Compare{
    public:
        bool operator()(pii &a, pii &b) {
            //same end time, then return the room with smaller number
            if(a.second == b.second) 
                return a.first > b.first;
            return a.second > b.second;
        }
};
class Solution {
public:
	int mostBookedMySolution(int rooms, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(),meetings.end(),[](vector<int> &a, vector<int> &b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        vector<int> freq(n,0);
        queue<pii> waitList;

        priority_queue<int,vector<int> , greater<int> > freeRooms;
        for(int i = 0; i < rooms; i++)
            freeRooms.push(i);
        //{roomOccupied, time getting free}
        priority_queue<pii,vector<pii>, Compare> occupied; 
        int i = 0, t = meetings[0][0];

        while(i < n || !waitList.empty()) {
            //are rooms getting empty at time t 
            //we are checking rooms getting empty first as it's and open interval to the end
            while(!occupied.empty() && occupied.top().second == t) {
                freeRooms.push(occupied.top().first);
                occupied.pop();
            }

            //are there meetings in waitlist that can be started

            while(!waitList.empty() && !freeRooms.empty()) {
                int currRoom = freeRooms.top();
                // cout << waitList.front().first << ',' << waitList.front().second << endl;
                int duration = waitList.front().second - waitList.front().first;

                long endTime = t + duration;

                occupied.push({currRoom,endTime});
                waitList.pop();
                freeRooms.pop();

                freq[currRoom]++;
            }

            //can we start a meeting at time t;

            if(i < n && meetings[i][0] == t) {
                //are there free rooms
                if(!freeRooms.empty()) {
                    int currRoom = freeRooms.top();
                    int duration = meetings[i][1] - meetings[i][0];

                    long endTime = t + duration;

                    occupied.push({currRoom,endTime});
                    // cout << occupied.top().first << "," << occupied.top().second << endl;
                    freeRooms.pop();
                    freq[currRoom]++;
                }
                else 
                    waitList.push(make_pair(meetings[i][0], meetings[i][1]) );
                i++;
            }
            t++;
        }

        int ans = INT_MIN;

        int maxFreq = *max_element(freq.begin(),freq.end());
        for(int i = 0; i < rooms; i++){
            // cout << i << "," << freq[i] << endl;
            if(freq[i] == maxFreq){
                ans = i;
                break;
            }
        }
        return ans;
    }
    int mostBookedBetterSolution(int rooms, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(),meetings.end(),[](vector<int> &a, vector<int> &b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        vector<long> freq(n,0);

        priority_queue<int,vector<int> , greater<int> > freeRooms;
        for(int i = 0; i < rooms; i++)
            freeRooms.push(i);
        //{roomOccupied, time getting free}
        priority_queue<pii,vector<pii>, Compare> occupied; 
        int i = 0, t = meetings[0][0];

        for(auto meeting: meetings) {
            //are rooms getting empty at time t 
            //we are checking rooms getting empty first as it's and open interval to the end
            int start = meeting[0],end = meeting[1];
            while(!occupied.empty() && occupied.top().second <= start) {
                freeRooms.push(occupied.top().first);
                occupied.pop();
            }

           if(!freeRooms.empty()) {
               int currRoom = freeRooms.top();
               freeRooms.pop();
               occupied.push({currRoom,end});
               freq[currRoom]++;
           }
           else {
               auto [room, nextFreeTime] = occupied.top();
               occupied.pop();
               occupied.push({room, nextFreeTime + end - start});
               freq[room]++;
           }

        }

        int maxFreq = *max_element(freq.begin(),freq.end());
        return find(freq.begin(), freq.end(), maxFreq) - freq.begin();
    }
};
int main() {
	init_code();
	vector<vector<int>> meetings = {{1,20},{2,10},{3,5},{4,9},{6,8}};
	int rooms = 3;
	Solution sol;
	cout << sol.mostBookedMySolution(rooms,meetings);
	return 0;


//in better solution we are dynamically updating the new meeting
// instead of creating a separate waitl list 

	