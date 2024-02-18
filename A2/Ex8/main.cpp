#include <iostream>
#include <vector>

using namespace std;

// We will assume the following in the Grade statistics Problem
/* --> The grades are out of 20.
 * --> The index in the vector will serve as an id for the student. Starts from student 0 to student n-1
 */

struct pairGradeSum20{
    int student1Id;
    int student2Id;
};

double task1(vector<double> grades);
double task2(vector<double> grades);
double task3(vector<double> grades);
vector<pairGradeSum20> task4(vector<double> grades);

int partition(vector<double>& arr, int start, int end);
void quickSort(vector<double>& arr, int start, int end);


int main() {

    // Test data
    vector<double> grades = {15, 18, 5, 10, 17, 20, 19, 10, 5, 14};

    // Task 1: Compute the difference between the minimum and maximum grade
    cout << "Task 1: Difference between min and max grade: " << task1(grades) << endl;

    // Task 2: Compute the average grade
    cout << "Task 2: Average grade: " << task2(grades) << endl;

    // Task 3: Compute the median grade
    cout << "Task 3: Median grade: " << task3(grades) << endl;

    // Task 4: Check if any two students have a total grade that is equal to 20
    cout << "Task 4: Students with total grade equal to 20:";
    vector<pairGradeSum20> result = task4(grades);
    if(result.size() == 0){
        cout<<" None"<<endl;
    }
    else{
        for (const auto& pair : result) {
            cout << " Student " << pair.student1Id << " and Student " << pair.student2Id << endl;
        };
    }





    return 0;
}

// Compute the difference between the minimum and maximum grade
double task1(vector<double> grades){
    double min = grades.at(0);
    double max = grades.at(0);

    for(int i = 0; i < grades.size(); i++){
        if(grades.at(i) > max){
            max = grades.at(i);
        };

        if(grades.at(i) < min){
            min = grades.at(i);
        };
    };

    return max - min;
};

// Compute the average grade.
double task2(vector<double> grades){

    double sum;
    for(int i=0; i<grades.size(); i++){
        sum+=grades.at(i);
    };

    return sum / grades.size();
};

// Compute the median grade
double task3(vector<double> grades){
    int size = grades.size();

    quickSort(grades, 0, size-1); //now grades is sorted
    if (size%2 == 1){
        int indexMean = size / 2;
        return grades.at(indexMean);
    }else{
        int index1 = size / 2;
        int index2 = (size / 2) - 1;
        return (grades.at(index1) + grades.at(index2)) / 2;
    };
};

// Check if any two students have a total grade that is equal to 20
vector<pairGradeSum20> task4(vector<double> grades){
    vector<pairGradeSum20> result;

    for(int i = 0; i<grades.size(); i++){
        for(int j = i+1; j<grades.size(); j++){
            if(grades.at(i) + grades.at(j) == 20.0){
                pairGradeSum20 couple;
                couple.student1Id = i;
                couple.student2Id = j;
                result.push_back(couple);
            }
        }
    }

    return result;
};


//code for quick sort
int partition(vector<double>& arr, int start, int end)
{

    int pivot = arr.at(start);

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr.at(i) <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr.at(pivotIndex), arr.at(start));

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr.at(i) <= pivot) {
            i++;
        }

        while (arr.at(j) > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr.at(i++), arr.at(j--));
        }
    }

    return pivotIndex;
}

void quickSort(vector<double>& arr, int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

