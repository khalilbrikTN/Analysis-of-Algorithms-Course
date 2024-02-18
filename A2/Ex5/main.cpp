#include <iostream>
#include "string"
#include "vector"
using namespace std;

string graphTopology(vector<vector<bool>> boolMatrix);

int main() {
    vector<vector<bool>> test1 = {{false, false, true},
                                  {true, false, true},
                                  {true, true, false}};

    cout<<graphTopology(test1);
    return 0;
}

string graphTopology(vector<vector<bool>> boolMatrix){

    int rows = boolMatrix.size();
    int cols = boolMatrix.at(0).size();

    //Check for Fully Connected
    bool fullyConnected = true;
    int i = 0;

    while(i<rows && fullyConnected){
        int j = 0;
        while (j<cols && fullyConnected){
            if(!boolMatrix.at(i).at(j) && j != i){ //assuming that a node cannot be fiend with itself.
                fullyConnected = false;
            }
            j++;
        }
        i++;
    }
    if(fullyConnected){return "Fully Connected";};

    //Check for Star Topology
    bool startTopology = true;
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols;j++){
            if(boolMatrix.at(i).at(j) == true){ //if a node is connected to another node

            }
        }
    }

    //Check for Ring Topology
    bool ringTopology = true;
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(i%2 == j%2 && boolMatrix.at(i).at(j) != false){
                ringTopology = false;
                break;
            }else if(boolMatrix.at(i).at(j) != true){
                ringTopology = false;
                break;
            };
        };
        if(!ringTopology){break;};
    };
    if(ringTopology){return "Ring Topology";};

    return "mo";

}