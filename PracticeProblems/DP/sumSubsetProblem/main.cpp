#include <iostream>
#include "vector"
using namespace std;

struct node{
    int end;
    int value;
    bool res;
};


bool sumSubsetNODP(vector<int> w, int end, int value);
bool sumSubsetMemo(vector<int> w, int end, int value, vector<node> history);

//Helper Functions
int findInVector(vector<node> history, node d);

int main() {
    vector<int> w = {10,20,30};
    int e = w.size()-1;
    int v = 30;

    vector<node> history;
    bool r = sumSubsetMemo(w, e, v, history);
    if(r) {cout<<"Subset with sum "<<v<<" does exist!"<<endl;}
    else{cout<<"Subset with sum "<<v<<" does not exist!"<<endl;}

    return 0;
}

bool sumSubsetNODP(vector<int> w, int end, int value){

    if(end ==0){
        return (value == w[end]);
    }else{
        if(sumSubsetNODP(w, end-1, value)) {
            return true;}
       else if(value-w[end] >= 0){
           return sumSubsetNODP(w, end, value-w[end]);}
       else{
            return false;
       }
    }
};

bool sumSubsetMemo(vector<int> w, int end, int value, vector<node> history){

    if(end ==0){
        return (value == w[end]);
    }else{
        node temp;
        temp.value = value;
        temp.end = end-1;
        int index = findInVector(history, temp);
        if(index == -1){
            temp.res = sumSubsetNODP(w, end-1, value);
            history.push_back(temp);
            index = history.size()-1;
        }else{
            temp.res = history.at(index).res;
        }

        if(temp.res) {
            return true;}
        else if(value-w[end] >= 0){
            node temp2;
            temp2.value = value-w[end];
            temp2.end = end;
            int index2 = findInVector(history, temp2);
            if(index2== -1) {
                temp2.res = sumSubsetNODP(w, end, value - w[end]);
                history.push_back(temp2);
                index2 = history.size() - 1;
            }else{
                temp2.res = history.at(index2).res;
            }
        }
        else{
            return false;
        }
    }
}


int findInVector(vector<node> history, node d){

    for(int i = 0; i<history.size(); i++){
        if(history[i].end == d.end && history[i].value == d.value){
            return i;
        }
    }
    return -1;
}