/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/
//Problem URL: http://practice.geeksforgeeks.org/problems/replace-all-0-with-5-in-an-input-integer/1

/*you are required to complete this method*/
int convertFive(int n)
{
//Your code here
    std::string inputString = std::to_string(n);
    int i = 0;
    for(i = 0; i < inputString.length(); i++) {
        if(inputString[i] == '0') {
            inputString[i] = '5';
        }
    }
    return std::stoi(inputString);
    
}