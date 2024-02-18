#include <iostream>
#include "string"
#include "vector"
using namespace std;

string graphTopology(vector<vector<bool>> boolMatrix);

bool fullyConnected(vector<vector<bool>> boolMatrix);
bool starTopology(vector<vector<bool>> boolMatrix);
bool ringTopology(vector<vector<bool>> boolMatrix);

//Helping Functions
int sumRow(vector<bool> row);

int main() {
    // Test Case 1: Fully Connected Graph
    vector<vector<bool>> test1 = {{false, true, true},
                                  {true, false, true},
                                  {true, true, false}};
    cout << "Test 1: " << graphTopology(test1) << endl;

    // Test Case 2: Star Topology
    vector<vector<bool>> test2 = {{false, true, true},
                                  {true, false, false},
                                  {true, false, false}};
    cout << "Test 2: " << graphTopology(test2) << endl;

    // Test Case 3: Ring Topology
    vector<vector<bool>> test3 = {{false, true, false, true},
                                  {true, false, true, false},
                                  {false, true, false, true},
                                  {true, false, true, false}};
    cout << "Test 3: " << graphTopology(test3) << endl;

    // Test Case 4: No Specific Topology
    vector<vector<bool>> test4 = {{false, true, false},
                                  {true, false, false},
                                  {false, false, false}};
    cout << "Test 4: " << graphTopology(test4) << endl;

    // Test Case 5: Fully Connected Graph
    vector<vector<bool>> test5 = {{false, true, true, true},
                                  {true, false, true, true},
                                  {true, true, false, true},
                                  {true, true, true, false}};
    cout << "Test 5: " << graphTopology(test5) << endl;

    // Test Case 6: No Specific Topology
    vector<vector<bool>> test6 = {{false, false, false, false},
                                  {false, false, false, false},
                                  {false, false, false, false},
                                  {false, false, false, false}};
    cout << "Test 6: " << graphTopology(test6) << endl;


    return 0;
}

string graphTopology(vector<vector<bool>> boolMatrix){

    if(ringTopology(boolMatrix)){
        return "Ring Topology";
    }
    else if(starTopology(boolMatrix)){return "Star Topology";}
    else if(fullyConnected(boolMatrix)){return "Fully Connected";}
    else{return "No Specific Topology";}

}



bool fullyConnected(vector<vector<bool>> boolMatrix){
    int rows = boolMatrix.size();
    int cols = boolMatrix.at(0).size();

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(!boolMatrix.at(i).at(j) && j != i){ //assuming that a node cannot be fiend with itself.
                return false;
            };
        };
    };

    return true;
};

bool ringTopology(vector<vector<bool>> boolMatrix){
    int rows = boolMatrix.size();
    int cols = boolMatrix.at(0).size();

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(i%2 == j%2 && boolMatrix.at(i).at(j) != false){
                return false;
            }else if(i%2 != j%2 && boolMatrix.at(i).at(j) != true){
                return false;
            };
        };
    };

    return true;
}

bool starTopology(vector<vector<bool>> boolMatrix){
    int rows = boolMatrix.size();
    int cols = boolMatrix.at(0).size();

    int starIndex = -1;

    for(int i = 0; i<rows; i++){
        int sum = sumRow(boolMatrix.at(i));
        if(sum == cols-1){ //the sum of the start index should equal to the number of cols - 1
            starIndex = i;
            break;
        }
    }
    if(starIndex == -1){return false;}

    //Now we need to make sure that all nodes are connected with the star node and not connected to other nodes

    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++) {
            if(i!= starIndex && j!= starIndex && boolMatrix.at(i).at(j) == 1){
                return false;
            }
        }
    }

    return true;
};

int sumRow(vector<bool> row)
{
    int sum = 0;
    for(int i = 0; i<row.size(); i++){
        sum+=row.at(i);
    };
    return sum;
}

