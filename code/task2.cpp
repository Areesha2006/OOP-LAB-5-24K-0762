#include <iostream>
using namespace std;
class Patient{
    int id;
    static int counter;
    string name,*test_results;
    public:
        Patient(string name, string result[], int n){
            this->name=name;
            id=counter;
            counter++;
            test_results = new string[n];
            for(int i=0;i<n;i++){
                test_results[i]=result[i];
            }
        }
        Patient(const Patient &obj, int n){
            test_results=new string[n];
            for(int i=0;i<n;i++){
                test_results[i]=obj.test_results[i];
            }
            name=obj.name;
            id=obj.id;
        }
        void display(int n){
            cout<<"Patient ID: "<<id<<endl<<"Name: "<<name<<endl<< "Test results" << endl;
            for(int i=0;i<n;i++){
                cout<<"Test "<<i+1<<": "<<test_results[i]<<endl;
            }
        }
};
int Patient::counter = 1;
int main(){
    int n;
    string name;
    cout<<"Enter the name of the patient: ";
    cin>>name;
    cout<<"How many tests are there: ";
    cin>>n;
    string result[n];
    for(int i=0;i<n;i++){
        cout<<"Result of test "<<i+1<<": ";
        cin>>result[i];
    }
    Patient p1(name,result,n);
    Patient analiyze_p1(p1,n);
    cout<<"Details for patient p1"<<endl;
    p1.display(n);
    cout<<endl<<"Analyize p1 details copied from p1 for the analysis of patient p1"<<endl;
    analiyze_p1.display(n);
    return 0;
}