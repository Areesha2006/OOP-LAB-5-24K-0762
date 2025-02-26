#include<iostream>
using namespace std;
class TourGuide{
    string name,spectialization;
    int years_of_experience;
    public:
        void set_details(string n,string spectial,int experience){
            name=n;
            spectialization=spectial;
            years_of_experience=experience;
        }
        void display_details(){
            cout<<"Name: "<<name<<endl<<"Specializatio: "<<spectialization<<endl<<"Years OF Experience: "<<years_of_experience<<endl<<endl;
        }
};
class TravelAgency{
    TourGuide *guide;
    public:
        TravelAgency(int n){
            guide=new TourGuide[n];
        }
        void hire_guide(int i,TourGuide g){
            guide[i]=g;
        }
        void display(int n){
            cout<<"Details of the travel agency is as follows that includes the details of all tour guides working in the agency"<<endl;
            for(int i=0;i<n;i++){
                cout<<"Guide "<<i+1<<endl;
                guide[i].display_details();
            }
        }
        ~TravelAgency(){
            delete[] guide;
        }
};
int main(){
    int n,exp;
    string special,name;
    cout<<"How many tour guides are there: ";
    cin>>n;
    TravelAgency agency(n);
    TourGuide guide[n];
    for(int i=0;i<n;i++){
        cout<<"For Guide "<<i+1<<endl;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter specialization: ";
        cin>>special;
        cout<<"Enter year of experience: ";
        cin>>exp;
        cout<<endl;
        guide[i].set_details(name,special,exp);
        agency.hire_guide(i,guide[i]);
    }
    cout<<"Displaying details of agency and its tour guides"<<endl;
    agency.display(n);
    return 0;
}