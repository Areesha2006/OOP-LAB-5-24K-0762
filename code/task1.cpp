#include<iostream>
using namespace std;
class Car{
    int reg_num;
    static int counter;
    string owner_name,model;
    public:
        Car(string name,string model){
            owner_name=name;
            reg_num=counter;
            counter++;
            this->model=model;
        }
        Car(string name,Car &obj){
            reg_num=obj.reg_num;
            owner_name=name;
            model=obj.model;
        }
        void display(){
            cout<<"Registration number: "<<reg_num<<endl<<"Name: "<<owner_name<<endl<<"Model: "<<model<<endl;
        }
};
int Car::counter=1;
int main(){
    string owner_name,model;
    cout<<"Enter the owner name of car c1: ";
    cin>>owner_name;
    cout<<"Enter the model of car c1: ";
    cin>>model;
    Car c1(owner_name,model);
    cout<<"Enter the owner name of car c2: ";
    cin>>owner_name;
    Car c2(owner_name,c1);
    cout<<"Details of car c1"<<endl;
    c1.display();
    cout<<endl<<"Details of car c2 copied from c1"<<endl;
    c2.display();
    return 0;
}