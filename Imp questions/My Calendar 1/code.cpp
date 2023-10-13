#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

class MyCalendar {
private:
    set<pair<int, int>> calendar;

public:
    bool book(int start, int end) {
        const pair<int, int> event{start, end};
        const auto nextEvent = calendar.lower_bound(event);
        if (nextEvent != calendar.end() && nextEvent->first < end) {
            return false;
        }

        if (nextEvent != calendar.begin()) {
            const auto prevEvent = prev(nextEvent);
            if (prevEvent->second > start) {
                return false;
            }
        }

        calendar.insert(event);
        return true;
    }
};
int main() {
	init_code();
	MyCalendar mc;
	cout << mc.book(10,20) << endl;
	cout << mc.book(15,25) << endl;
	cout << mc.book(20,30) << endl;
	cout << mc.book(40,50) << endl;
	return 0;
}


//(10,20) (20,30) , (30,40) (40,50) , (55,60) (60,67) (70,80);

//now if we are trying to insert lets say 57,61
//the lower bound will give me the fist element that is not less 
// than 57,60
//ie 60,70
//now agar mera jo end time (61) hai new event ka that is greater than
// 60 then its overlapping
//as iske aage ke events will be definately greater than 67 (as no overlapping)
//

//if thats not the case and we are inserting something like 
//57,59

//then my end time is not overalapping after this
///now if we check the prev event if/
// uska jo en time hai (60) if that is greater than my end time(59)

//then again overlapping

//now if we trying to insert (53,55)
//then lower boun will be 55,60
// 55 is not less than 55
//so check prev
//53 > 50

//so insert