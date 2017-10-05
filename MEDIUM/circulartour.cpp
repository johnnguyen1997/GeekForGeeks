/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

//PROBLEM URL: http://practice.geeksforgeeks.org/problems/circular-tour/
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/
/*You are required to complete this method*/

//Considering this was under the queue section. Might as well
//make a queue based solution.
int tour(petrolPump p[],int n)
{
   //Keep track of fuel
   int currentFuel = 0;
   
   int startingPoint = 0;
   
   //A trivial solution would be to go through all the possible circles
   
   //Store the data in a queue
   queue<petrolPump> stations;
   int i = 0;
   for(i = 0; i < n; i++) {
       stations.push(p[i]);
   }
   
   //Duplicate the queue so we can 'remember' our starting point
   queue<petrolPump> stationCopy = stations;
   petrolPump currentStation;
   
   //Could have used double while to make things cleaner
   while(startingPoint < n) {
       
       //Track the station
       currentStation = stationCopy.front();
       stationCopy.pop();
       currentFuel += currentStation.petrol;
       if(currentFuel >= currentStation.distance) {
           //We can go again possibly, check
           if(stationCopy.empty()) {
               //We finished a circle
               return startingPoint;
           }
           //Otherwise go to next station, get rid of fuel
           currentFuel -= currentStation.distance;
       } else {
           //No we can't, try again
           startingPoint++;
           
           //Reset variables for next iteration
           currentFuel = 0;
           petrolPump tempPump = stations.front();
           stations.pop();
           stations.push(tempPump);
           stationCopy = stations;
           currentStation = stations.front();
       }
       
   }
   
   
   //No solution at the moment
   return -1;
}
