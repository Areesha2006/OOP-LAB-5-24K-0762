#include<iostream>
using namespace std;
class Movie{
    string title,director;
    int duration;
    public:
        void set_details(string name,string dir,int time){
            title=name;
            director=dir;
            duration=time;
        }
        void display(){
            cout<<"Title: "<<title<<endl<<"Director: "<<director<<endl<<"Duration: "<<duration<<endl<<endl;
        }
};
class CinemaHall{
    Movie movie[100];
    public:
        CinemaHall(Movie m[],int n){
            for(int i=0;i<n;i++){
                movie[i]=m[i];
            }
        }
        void display(int n){
            cout<<"Details of the cinema hall is as follows that includes the details of all the movies screening in the cinema"<<endl;
            for(int i=0;i<n;i++){
                cout<<"Movie "<<i+1<<endl;
                movie[i].display();
            }
        }
};
int main(){
    int n,duration;
    string title,director;
    cout<<"How many movies are there: ";
    cin>>n;
    Movie movie[n];
    for(int i=0;i<n;i++){
        cout<<"For movie "<<i+1<<endl;
        cout<<"Enter title of the movie: ";
        cin>>title;
        cout<<"Enter name of the director of the movie: ";
        cin>>director;
        cout<<"Enter the duration of the movie: ";
        cin>>duration;
        cout<<endl;
        movie[i].set_details(title,director,duration);
    }
    CinemaHall cinema(movie,n);
    cout<<"Displaying details of cinema hall and its movies"<<endl;
    cinema.display(n);
    return 0;
}