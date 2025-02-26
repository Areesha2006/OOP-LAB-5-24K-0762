#include<iostream>
using namespace std;
class Professor{
    string name,department;
    public:
        void set_details(string name,string dept){
            this->name=name;
            department=dept;
        }
        void display_professors(Professor p[],int n){
            if(n==0){
                cout<<"No proffessors found"<<endl;
            }
            else{
                for(int i=0;i<n;i++){
                    cout<<"Professor "<<i+1<<endl<<"Name: "<<p[i].name<<endl<<"Department: "<<p[i].department<<endl<<endl;
                }
            }
        }
};
class University{
    Professor *prof=NULL;
    public:
        void add_professor(Professor *p,int *total,int new_total){
            Professor *new_prof=new Professor[new_total];
            for (int i = 0; i < *total; i++){
                new_prof[i]=prof[i];
            }   
            new_prof[*total]=*p;
            if(prof!=NULL){
                delete[] prof;
            }    
            prof=new_prof;
            *total=new_total;
            cout<<"Professor added successfully"<<endl;
        }
        void display(int n){
            cout<<"Details of university are as follows which includes the details of all the professors working"<<endl;
            cout<<"University Name: FAST University"<<endl;
            if(n!=0){
                prof->display_professors(prof,n);
            }
            else{
                cout<<"No professor found"<<endl;
            }
        }
        
        ~University(){
            delete[] prof;
        }
};
int main(){
    int c,total=0,new_total;
    Professor *prof=NULL;
    University uni;
    string dept,name;
    while(1){
        cout<<"Enter the appropriate key according to the function you want to perform\n1.Add a professor\n2.Display university details\nAny other key to exit\nEnter: ";
        cin>>c;
        switch(c){
            case 1:
                new_total=total+1;
                Professor *new_prof;
                new_prof=new Professor[new_total];
                for (int i = 0; i < total; i++){
                    new_prof[i]=prof[i];
                }
                cout<<"Enter name: ";
                cin>>name;
                cout<<"Enter department: ";
                cin>>dept;
                new_prof[total].set_details(name,dept);    
                if(prof!=NULL){
                    delete[] prof;
                }    
                prof=new_prof;   
                uni.add_professor(&prof[total],&total,total+1);
                total=new_total;
                break;
            case 2:
                uni.display(total);                
                break;
            default:
                cout<<"Exited successfully";
                delete[] new_prof,prof;
                return 0;
                break;
        }
        cout<<endl;
    } 
}