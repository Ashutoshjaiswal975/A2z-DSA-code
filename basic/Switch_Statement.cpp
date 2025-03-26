// Given an integer choice denoting the choice of the user and a list containing the single value R or two values L and B depending on the choice.
// If the user's choice is 1, calculate the area of the circle having the given radius(R).  
// Else if the choice is 2, calculate the area of the rectangle with the given length(L) and breadth(B).

// Note : A list arr[], containing the single value R or the two values L and B, as input parameters. Return the area of the desired geometrical figure. Use Math.PI for the value of pi.

// Examples :

// Input: choice = 1, R = 5
// Output: 78.53981633974483
// Explaination: The choice is 1. So we have to calculate the area of the circle.
// Input: choice = 2, L = 5, B = 10
// Output: 50
// Explaination: Here we have to calculate the area of the rectangle.


class Solution {
  public:
    double switchCase(int choice, vector<double> &arr) {
        const double pi = 3.14159;  // Define pi with a semicolon and use double for accuracy

        switch(choice) {
            case 1: {
                if (arr.size() > 0) {
                    double R = arr[0];  // Assuming arr[0] is the radius
                    double areaCircle = pi * R * R;
                    return areaCircle;
                }
                break;
            }
            case 2: {
                if (arr.size() > 1) {
                    double L = arr[0];  // Assuming arr[0] is length
                    double B = arr[1];  // Assuming arr[1] is breadth
                    double areaRectangle = L * B;
                    return areaRectangle;
                }
                break;
            }
            default:
                return -1;  // Return -1 for invalid choice
        }
        return -1;  // Return -1 if conditions are not met
    }
};