//https://www.codingninjas.com/studio/problems/day-25-queue-using-stack_8230722?challengeSlug=striver-sde-challenge&leftPanelTab=1

class Queue { 
    stack<int>in,out; 
    public: 
    Queue() { 
        // Initialize your data structure here.
   } 
   void enQueue(int val) { 
       in.push(val); 
    } 
    int deQueue() { 
        if(out.empty()){ 
            while(!in.empty()) { 
                int val = in.top(); 
                in.pop(); 
                out.push(val); 
            } 
        } 
        if(out.empty())return -1; 
        int x = out.top(); 
        out.pop(); 
        return x; 
    } 
    int peek() { 
        if(out.empty()){
             while(!in.empty()) { 
                 int val = in.top(); 
                 in.pop(); 
                 out.push(val); 
                } 
            } 
            if(out.empty())
            return -1; 
            int x = out.top(); 
            return x;
         } 
         bool isEmpty() { 
             return in.empty() && out.empty();
         }
     };