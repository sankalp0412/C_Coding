struct Robot{
    int pos;
    int health;
    int i;
    char di;
    Robot(){};
    Robot(int p,int h,int i,char di) {
        this->pos = p;
        this->health = h;
        this->i = i;
        this->di = di;
    }
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int N = positions.size();
        vector<Robot> Rs;
        for(int i = 0; i < N; i++) {
            Rs.emplace_back(positions[i],healths[i],i,directions[i]);
        }
        sort(Rs.begin(),Rs.end(),[&](auto &a, auto &b){
            return a.pos<b.pos;
        });
        vector<Robot> stk;
        for(int i = 0; i < N; i++) {
            if(Rs[i].di == 'L'){
                while(!stk.empty() && stk.back().di == 'R'){
                    if(stk.back().health == Rs[i].health){
                        stk.pop_back();
                        Rs[i].health = 0;
                        break;
                    }
                    else if(stk.back().health < Rs[i].health){
                        stk.pop_back();
                        Rs[i].health--;
                    }
                    else {
                        stk.back().health--;
                        Rs[i].health = 0;
                        break;
                    }
                }
                if(Rs[i].health > 0){
                    stk.push_back(Rs[i]);
                }
            }
            else 
               stk.push_back(Rs[i]); 
        }
        sort(stk.begin(),stk.end(),[&](auto &a, auto &b){
            return a.i < b.i;
        });
        vector<int> ans;
        for(int i = 0; i < stk.size(); i++) {
            ans.push_back(stk[i].health);
        }
        return ans;
    }
};

//understoond the queston, was doing the same thing but didn;t use stack
//this is how you should write code, like use stff like struct whereever possible



mplace_back() vs push_back()

//push_back() copies a string into a vector. First, a new string object will be implicitly created initialized with provided char*. Then push_back will be called which will copy this string into the vector using the move constructor because the original string is a temporary object. Then the temporary object will be destroyed.
//emplace_back() constructs a string in-place, so no temporary string will be created but rather emplace_back() will be called directly with char* argument. It will then create a string to be stored in the vector initialized with this char*. So, in this case, we avoid constructing and destroying an unnecessary temporary string object.

// The time complexity of the survivedRobotsHealths function depends on the number of robots, which is denoted by N. Let's analyze the time complexity of each step

// Creating the Rs vector: This step has a time complexity of O(N) because it involves iterating over the positions and healths vectors.

// Sorting the Rs vector: The sort function used here has a time complexity of O(N log N), where N is the number of elements in the vector.

// Processing the robots using the stack: This step involves iterating over the Rs vector and manipulating the stack. In the worst case, each robot might be processed and compared with the robots in the stack, resulting in a time complexity of O(N).

// Sorting the stk vector: This step also has a time complexity of O(N log N), where N is the number of elements in the vector.

// Creating the ans vector: This step involves iterating over the stk vector, resulting in a time complexity of O(N).

// Overall, the dominant time complexity in this code is

// O(N log N) due to the sorting steps.

// Regarding space complexity:

// The Rs vector requires O(N) space to store the robots.
// The stk vector can have a maximum size of N if all robots survive, so it also requires O(N) space.
// The ans vector will have a size equal to the number of robots that survive, so its space complexity is O(K), where K is the number of surviving robots.
// Therefore, the overall space complexity is O(N) since the space required by the Rs and stk vectors dominates the space usage.