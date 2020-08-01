//https://leetcode.com/problems/angle-between-hands-of-a-clock/
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hours = hour*30 + double(minutes)/2;
        cout << hours;
        minutes = minutes*6;
        double a = hours-minutes;
        if(a<0) a=-a;
        if(a<180) return a;
        else return 360-a;
    }
};
