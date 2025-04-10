#include <bits/stdc++.h>
using namespace std;

class Car {
    public:
        string name;
        string color;
        int *milage;


    Car (string name, string color){
        this->name = name;
        this->color = color;
        milage = new int; // dynamic memory allocation
        *milage = 12;
    }

    // deep copy
    Car (Car &orginal){
        cout<<"copying orginal to new"<<endl;
        name = orginal.name;
        color = orginal.color;
        milage = new int; // new memory allocation
        *milage = *orginal.milage;
    }

    /// destructor
    ~Car(){
        cout<<"deleting object.."<<endl;

        if(milage != NULL){
            delete milage;
            milage = NULL;
        }
    }
};

int main(){
    Car c1("maruti 800", "white");
    Car c2(c1); // custom copy constractor
    cout<<c2.name << endl;
    cout<<c2.color << endl;
    cout<<*c2.milage << endl;

    *c2.milage = 10;
    cout<<*c1.milage<<endl;
    return 0;
}