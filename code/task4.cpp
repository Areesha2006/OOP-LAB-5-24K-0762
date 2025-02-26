#include<iostream>
using namespace std;
class Battery{
    float capacity;
    public:
        Battery(float c){
            capacity=c;
        }
        void display(){
            cout<<"Capacity: "<<capacity<<endl;
        }
};
class Smartphone{
    Battery b;
    public:
        Smartphone(float c) :b(c){}
        void display(){
            cout<<"Details of the smartphone"<<endl<<"The battery of this smart phone is non-removable and can exist seperately without the smartphone"<<endl;
            b.display();
        }
};
int main(){
    float c;
    cout<<"Enter the capacity of the battery of the smart phone 1: ";
    cin>>c;
    Smartphone phone1(c);
    cout<<"Enter the capacity of the battery of the smart phone 2: ";
    cin>>c;
    Smartphone phone2(c);
    cout<<"Enter the capacity of the battery of the smart phone 3: ";
    cin>>c;
    Smartphone phone3(c);
    cout<<endl<<"Details about the smartphone 1"<<endl;
    phone1.display();
    cout<<endl<<"Details about the smartphone 2"<<endl;
    phone2.display();
    cout<<endl<<"Details about the smartphone 3"<<endl;
    phone3.display();
    return 0;
}