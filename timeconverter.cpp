#include<iostream>

using namespace std;

class time {
    public :
        int sec,min,hour;

        void sectohour(){
            hour = sec/3600;
            min = (sec%3600)/60;
            sec = (sec%3600)%60;
            
            cout << hour << ":" << min << ":" << sec ;

        }
        void hourtosec(){
        sec = (hour * 3600) + (min * 60) + sec;

        cout << "total seconds : " << sec << endl;
 
        }
};

int main(){
    int choose;
    time t1;
    cout << "1. for convert seconds to hh:mm:ss" << endl;
    cout << "2. for convert hh:mm:ss to seconds" << endl;
    cout << "enter your choice :";
    cin >> choose;

    
    switch (choose)
    {
    case 1 :
        cout << "enter value in a sec :";
        cin >> t1.sec;
        t1.sectohour();
        break;
    case 2 :
        cout << "enter total hours :";
        cin >> t1.hour;
        cout << "enter total minutes :";
        cin >> t1.min;
        cout << "enter total second :";
        cin >> t1.sec;
        t1.hourtosec();
        break;
    
    default:
      cout << "Invalid choice!" << endl;  
        break;
    }
    return 0;
}