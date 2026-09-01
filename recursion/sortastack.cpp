class Solution {
public:
void insertedsort(stack<int> &st,int x){
if(st.empty()|| x<st.top()){
    st.push(x);
    return;
}
int top=st.top();
st.pop();

    insertedsort(st,x);
    st.push(top);
}



    void sortStack(stack<int> &st) {
        // Your code goes here
        if (st.empty()) {
    return;
}
        int top=st.top();
        st.pop();
        sortStack(st);
        insertedsort(st,top);
    }
};