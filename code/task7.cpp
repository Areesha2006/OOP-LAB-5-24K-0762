#include<iostream>
using namespace std;
class Product{
    static int counter;
    string name;
    int price,id;
    public:
        void set_details(string name,int p){
            this->name=name;
            price=p;
            id=counter++;
        }
        void serach_product(Product prod[],int n){
            string prod_name;
            int found=0;
            cout<<"Enter the name of the product: ";
            cin>>prod_name;
            for(int i=0;i<n;i++){
                if(prod_name==prod[i].name){
                    found=1;
                    cout<<"Product Found"<<endl;
                    cout<<"Product ID: "<<prod[i].id<<endl;
                    cout<<"Name: "<<prod[i].name<<endl;
                    cout<<"Price: "<<prod[i].price<<endl;
                }
            }
            if(!found){
                cout<<prod_name<<" not found"<<endl;
            }
        }
        void sort_products_asc(Product prod[],int n){
            cout<<"Displaying all products before sorting in ascending order"<<endl;
            for(int i=0;i<n;i++){
                cout<<"Product "<<i+1<<endl;
                cout<<"Product ID: "<<prod[i].id<<endl;
                cout<<"Name: "<<prod[i].name<<endl;
                cout<<"Price: "<<prod[i].price<<endl;
                cout<<endl;
            }
            for(int i=0;i<n;i++){
                for(int j=i;j<n-1-i;j++){
                    if(prod[j].price>prod[j+1].price){
                        Product temp;
                        temp=prod[j];
                        prod[j]=prod[j+1];
                        prod[j+1]=temp;
                    }
                }
            }
            cout<<"Displaying all products after sorting in ascending order"<<endl;
            for(int i=0;i<n;i++){
                cout<<"Product "<<i+1<<endl;
                cout<<"Product ID: "<<prod[i].id<<endl;
                cout<<"Name: "<<prod[i].name<<endl;
                cout<<"Price: "<<prod[i].price<<endl;
                cout<<endl;
            }
        }
};
int Product::counter=1;
int main(){
    int n,price,c;
    string name;
    cout<<"How many products are there: ";
    cin>>n;
    Product p[n];
    for(int i=0;i<n;i++){
        cout<<"For Product "<<i+1<<endl;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter price: ";
        cin>>price;
        p[i].set_details(name,price);
        cout<<endl;
    }
    while(1){
        cout<<"Enter the appropriate key according to the operation you want to perform\n1.Search a product\n2.Sort all products in ascending order with respect to the price\nAny other key to exit\nEnter: ";
        cin>>c;
        switch(c){
            case 1:
                p->serach_product(p,n);
                break;
            case 2:
                p->sort_products_asc(p,n);
                break;
            default:
                cout<<"Exited successfully";
                return 0;
        }
        cout<<endl;
    }
}