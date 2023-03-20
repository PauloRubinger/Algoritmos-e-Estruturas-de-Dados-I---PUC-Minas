#include <iostream>
using namespace std;

class Time {
    private:
        int hour;
        int minutes;
        int seconds;
    public:
        Time(int hour, int minutes, int seconds){
            this->setHour(hour);
            this->setMinutes(minutes);
            this->setSeconds(seconds);
            cout<<"Object created"<<endl;
        }
        ~Time(){
            cout<<"Object destroyed"<<endl;
        }
        int getHour() {
            return this->hour;
        }
        int getMinutes() {
            return this->minutes;
        }
        int getSeconds() {
            return this->seconds;
        }
        void setHour(int hour) {
            this->hour = hour;
        }
        void setMinutes(int minutes) {
            this->minutes = minutes;
        }
        void setSeconds(int seconds) {
            this->seconds = seconds;
        }
        void print() {
            cout<<this->getHour()<<" hours, "<<this->getMinutes()<<" minutes, "<<this->getSeconds()<<" seconds"<<endl;
        }
        Time difference(Time t) {
            Time time(this->getHour() - t.getHour(), this->getMinutes() - t.getMinutes(), this->getSeconds() - t.getSeconds());
            return time;
        }
};

int main() {

    Time t1(12, 5, 20);
    t1.print();
    Time t2(8, 3, 15);
    t2.print();

    Time h3 = t1.difference(t2);
    cout<<"The difference is: "<<endl;
    h3.print();

    return 0;
}
