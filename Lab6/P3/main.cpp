#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // Include the <algorithm> header for the sort function
#include <limits>

/* Recursive relation used:
    T(n) = 2T(n/2) + O(n)
    where n is the number of points.

    Time Complexity Analysis:
    The time complexity of the closest pair algorithm using the divide and conquer approach is O(n log n).
    The recursive relation T(n) = 2T(n/2) + O(n) can be solved using the Master Theorem, and it results in O(n log n) time complexity.
*/






using namespace std;

// Structure to represent a point in 2D plane
struct Point {
    int x, y;
};

// Custom comparison function for sorting Points based on x-coordinate
bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

// Custom comparison function for sorting Points based on y-coordinate
bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

// Function to calculate the Euclidean distance between two points
double dist(const Point& p1, const Point& p2) {
    double result = sqrt(pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2));
    return result;
}

// Function to find the closest pair of points among a strip of points
double stripClosest(vector<Point> strip, double d) {
    double minDist = d;

    // Sort the strip based on y-coordinate
    sort(strip.begin(), strip.end(), compareY);

    // Iterate through each point in the strip
    for (size_t i = 0; i < strip.size(); ++i) {
        // Compare each point with its neighbors within a distance of d
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            // Update minDist if a closer pair is found
            minDist = min(minDist, dist(strip[i], strip[j]));
        }
    }

    return minDist;
}


// Function to find the closest pair of points using a divide and conquer approach
double closestUtil(const vector<Point>& points, int left, int right) {
    // Base case: If there are 2 or 3 points, use brute force method
    if (right - left <= 3) {
        double minDist = numeric_limits<double>::max();
        for (int i = left; i <= right; ++i) {
            for (int j = i + 1; j <= right; ++j) {
                minDist = min(minDist, dist(points[i], points[j]));
            }
        }
        return minDist;
    }

    // Find the middle point
    int mid = (left + right) / 2;
    Point midPoint = points[mid];

    // Recursively find the closest pair in left and right halves
    double dl = closestUtil(points, left, mid);
    double dr = closestUtil(points, mid + 1, right);

    // Find the minimum of dl and dr = d
    double d = min(dl, dr);

    // Create a strip containing points within d distance of the middle line
    vector<Point> strip;
    for (int i = left; i <= right; i++) {
        if (abs(points[i].x - midPoint.x) < d) {
            strip.push_back(points[i]);
        }
    }

    // Find the closest pair in the strip and return the minimum distance
    return min(d, stripClosest(strip, d));
}

// Function to find the closest pair of points
double closestPair(const vector<Point>& points) {
    // Sort points based on x-coordinate
    vector<Point> sortedPoints = points;
    sort(sortedPoints.begin(), sortedPoints.end(), compareX);

    // Call the recursive function to find the closest pair
    return closestUtil(sortedPoints, 0, sortedPoints.size() - 1);
}

int main() {
    // Example usage
    vector<Point> points1 = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};  //min dist bet. (2,3),(3,4)
    cout << "Minimum distance between two points: " << closestPair(points1) << endl;// Expected output: 1.41421

    vector<Point> points2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}}; //The points are arranged diagonally, so the minimum distance is between any two consecutive points.
    cout << "Minimum distance between two points: " << closestPair(points2) << endl;// Expected output: 1.41421

    vector<Point> points3 = {{100, 200}, {300, 400}, {500, 600}, {700, 800}, {900, 1000}, {1100, 1200}}; //The points are arranged diagonally with a consistent difference of 200 in both x and y coordinates
    cout << "Minimum distance between two points: " << closestPair(points3) << endl; // Expected output: 282.843

    vector<Point> points4 = {{-10, -10}, {10, 10}, {-20, -20}, {20, 20}, {-30, -30}, {30, 30}}; //The points are arranged diagonally
    cout << "Minimum distance between two points: " << closestPair(points4) << endl; // Expected output: 14.1421 */

    vector<Point> points5 = {{-10, 10}, {10, 1}, {-2, -20}, {25, 10}, {-30, -10}, {32, 3}}; //The points are arranged randomly
    cout << "Minimum distance between two points: " << closestPair(points5) << endl; // Expected output: 9.89949 //min dist bet. (25,10),(32,3)

    return 0;
}
