/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The function returns a sorted array of strings which represents
the directions mouse will take to reach the destination.
You are required to complete the below method. */

//PROBLEM URL: http://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

void checkPath(int m[MAX][MAX], int positionX, int positionY, int n,
    vector<string>* paths, string s) {
    int didGo = 0;
    if((positionX == positionY) && (positionX == (n - 1))) {
        paths->push_back(s);
    } else {
        //Down
        if(((positionY + 1 ) < n)  && m[positionY + 1][positionX] == 1)
        {
            m[positionY + 1][positionX] = 2;
            checkPath(m, positionX, positionY + 1, n, paths, s +'D');
            didGo = 1;
            m[positionY + 1][positionX] = 1;
        }
        //Left
        if(((positionX - 1 ) >= 0) && m[positionY][positionX - 1] == 1)
        {
            m[positionY][positionX - 1] = 2;
            checkPath(m, positionX - 1, positionY, n, paths, s + 'L');
            didGo = 1;
            m[positionY][positionX - 1] = 1;
        }
        //Right
        if(((positionX + 1 ) < n) && m[positionY][positionX + 1] == 1)
        {
            m[positionY][positionX + 1] = 2;
            checkPath(m, positionX + 1, positionY, n, paths, s +'R');
            didGo = 1;
            m[positionY][positionX + 1] = 1;
        }
        //Up
        if(((positionY - 1 ) >= 0)  && m[positionY - 1][positionX] == 1)
        {
            m[positionY - 1][positionX] = 2;
            checkPath(m, positionX, positionY - 1, n, paths, s +'U');
            didGo = 1;
            m[positionY - 1][positionX] = 1;
        }
    }
}
vector<string> printPath(int m[MAX][MAX], int n)
{
    //Gotta check the path
    //Check up down left and right, paint them as 0, 1 and 2
    vector<string>* tempStrings = new vector<string>;
    m[0][0] = 0;
    checkPath(m, 0, 0, n, tempStrings, "");
    return *tempStrings;
}
