#include <iostream>
#include "vector"

using namespace std;
int waterAmount(int h1, int i1, int h2, int i2){
    return (i2-i1) * min(h1,h2);
}
int maxArea(vector<int>& height) {

    int i = 0;
    int j = height.size()-1;
    int area = 0;
    int tempArea;


    while(i < j){
        tempArea = waterAmount(height[i], i, height[j], j);
        if(tempArea > area){area = tempArea;}
        if(height[i] < height[j]){
            i++;
        }else{
            j--;
        };
    }


    return area;

};
int main() {
    vector<int> height = {10,8,6,2,5,4,8,3,7};

    cout<<maxArea(height);

    return 0;
}
