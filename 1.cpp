#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


class Car {
public:
    string brand;
    string model;
    int year;
    long double price;

    Car(string b, string m, int y, long double p)
        : brand(b), model(m), year(y), price(p) {}

    void display() const {
        cout << brand << " " << model << " (" << year << ") - Rs. " <<fixed<<setprecision(0)<< price << endl;
    }
    int get_price()
    {
        return price;
    }
};

class CarManagementSystem {
private:
    vector<Car> carsForSale;
    vector<Car> carsForRent;

public:
    CarManagementSystem() {
        // Initial dummy data
        carsForSale.push_back(Car("Toyota", "Camry", 2020, 1707262));
        carsForSale.push_back(Car("Honda", "Civic", 2021, 1877988.20));
        carsForSale.push_back(Car("Hyundai", "Elantra", 2021, 1535500));
        carsForSale.push_back(Car("Kia", "Sorento", 2022, 2439370));
        carsForSale.push_back(Car("BMW", "3 Series", 2022, 3569000));
        
        carsForRent.push_back(Car("Maruti", "Swift", 2020, 500));
        carsForRent.push_back(Car("Maruti", "Ertiga", 2021, 850));
        carsForRent.push_back(Car("Tata", "Hexa", 2019, 950));
        carsForRent.push_back(Car("Honda", "City", 2020, 700));
        carsForRent.push_back(Car("Hyundai", "i20", 2019, 600));
    }
    void displayCarsForSale() {
        cout << "\n-- Cars for Sale --\n";
        if (carsForSale.empty()) {
            cout << "No cars available for sale.\n";
            return;
        }

        for (size_t i = 0; i < carsForSale.size(); ++i) {
            cout << i + 1 << ". ";
            carsForSale[i].display();
        }
    }
    void buyCar() {
       
        string s1,s2;
        int color;
        if (carsForSale.empty()) return;
     while(1)
     {
         displayCarsForSale();
        int choice;
        cout <<endl<< "Enter the number of the car to buy: ";
        cin >> choice;

        if (choice >= 1 && choice <= (int)carsForSale.size()) {
            // cout << "You bought: ";
            // carsForSale[choice - 1].display();
            
            cout<<endl<<"which color?\n";
            cout<<"1. Black\n";
            cout<<"2. White\n";
            cout<<"3. Grey\n";
            cout<<"4. Blue\n";
            
            cout<<endl<<"Enter your choice : ";
            cin>>color;
            switch(color)
            {
                case 1:s1="Black";break;
                case 2:s1="White";break;
                case 3:s1="Grey";break;
                case 4:s1="Blue";break;
                default:cout<<"Not available";
            }
            
        cout<<endl<<"this is the car you have selected\n";
            carsForSale[choice - 1].display();
            cout<<s1<<endl;
            
            cout<<endl<<"You want to make any changes?\n";
            cout<<"1.Yes\t\t2.No\n";
            cout<<endl;
            int a;
            cin>>a;
            
            switch(a)
            {
                case 1:continue;
                case 2:
                {
                    carsForSale.erase(carsForSale.begin() + (choice - 1));
                    cout<<endl<<"You bought: \n";
                    carsForSale[choice - 1].display();
                    cout<<s1<<endl;
                }
            }
            break;
            
        } else {
            cout << "Invalid selection.\n";
        }
    }
    }
    void displayCarsForRent() {
        cout << "\n-- Cars for Rent --\n";
        if (carsForRent.empty()) {
            cout << "No cars available for rent.\n";
            return;
        }
        

        for (int i = 0; i < carsForRent.size(); i++) {
            cout << i + 1 << ". ";
            carsForRent[i].display();
        }
    }
    void rentCar() {
        
        if (carsForRent.empty()) return;
        while(1){
            displayCarsForRent();
        int choice;
        cout << "Enter the number of the car for rent: ";
        cin >> choice;

        if (choice >= 1 && choice <= (int)carsForRent.size()) {
            
            cout<<endl<<"For how much time(in hours)?\n";
            int a;
            cin>>a;
            
            double rent;
            for(int i=0;i<carsForRent.size();i++)
            {
                if((choice-1)==i)
                rent=a*carsForRent[i].price;
            }
            cout<<endl<<"Your rent is : Rs. "<<rent;
            cout <<endl<<endl<< "Your choice for rent a car : ";
            carsForRent[choice - 1].display();
            cout<<"Time duration : "<<a<<" hour";
            cout<<"\nRent is : Rs. "<<rent;
            
            cout<<endl<<endl<<"You want to make any changes?";
            cout<<"\n1.Yes\t\t2.No   ";
            
            int b;
            cin>>b;
            switch(b)
            {
                case 1:continue;
                case 2:{
                    carsForRent.erase(carsForRent.begin() + (choice - 1));
                    cout<<endl<<"You rented : ";
                    carsForRent[choice - 1].display();
                    cout<<"\nTime duration : "<<a<<" hour";
                    cout<<"\nRent is : "<<rent;
                    cout<<endl<<endl;
                }
            }
            break;
            
        } else {
            cout << "Invalid selection.\n";
        }
        }
    }
    void call()
    {
        cout << "\n=== Car Delership ===\n";
    cout<<"\n1.Customer\t\t2.Service provider  ";
    cout<<"\nEnter your choice : ";
    int p;
    cin>>p;
    switch(p)
    {
        case 1: customer();
        case 2: service();
        default:cout<<"Invalid";break;
    }
    }
    void customer()
    {
        int choice;
        do {
            cout << "\n=== Car Delership ===\n";
            cout << "1. View Cars for Sale\n";
            cout << "2. Buy a Car\n";
            cout << "3. View Cars for Rent\n";
            cout << "4. Rent a Car\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch(choice)
            {
                case 1:{
                    displayCarsForSale();
                    call();}
                     break;
                case 2:
                {
                    // cmt.displayCarsForSale();
                    buyCar();
                    call();
                    break;
                }
                case 3:{
                    displayCarsForRent();
                    call();
                }
                    continue;
                case 4:
                {
                    rentCar();
                    call();
                };break;
                default: cout << "Invalid choice. Try again.\n";break;
                
                
            }
        } while (choice != 5);
    }
    void service()
    {
        cout<<endl<<"1.Add car models\n";
        cout<<"2.Remove car models\n";
        
        int a;
        cout<<"\nEnter your choice : ";
        cin>>a;
        switch(a)
        {
            case 1:
            {
                cout<<endl<<"1.From buyer stock\t\t2.From rental stock\n";
        cout<<"Enter your choice : ";
        int q;
        cin>>q;
        switch(q)
        {
            case 1:
            {
                string s1,s2;
                int r,t;
                double p;
                cout<<endl<<"How many cars do you want to add? : \n";
                cin>>t;
                for(int i=1;i<=t;i++)
                {
                    //cin>>s1>>s2>>r>>p;
                    cout<<endl<<"Enter the brand : ";
                    cin>>s1;
                    cout<<"Enter the model : ";
                    cin>>s2;
                    cout<<"Enter year : ";
                    cin>>r;
                    cout<<"Enter the price : ";
                    cin>>p;
                    carsForSale.push_back(Car(s1,s2,r,p));
                }
                call();
            };break;
            case 2:
            {
                string s1,s2;
                int r,t;
                double p;
                cout<<endl<<"How many cars do you want to add? : \n";
                cin>>t;
                for(int i=1;i<=t;i++)
                {
                    cin>>s1>>s2>>r>>p;
                    carsForRent.push_back(Car(s1,s2,r,p));
                }
                call();
            };break;
            
        };break;
        case 2: 
        {
            cout<<endl<<"1.From buyer stock\t\t2.From rental stock\n";
        cout<<"Enter your choice : ";
        int q;
        cin>>q;
        switch(q)
        {
            int u,t;
            case 1:
            {
                cout<<endl<<"How many cars do you want to remove? : \n";
                cin>>t;
                displayCarsForSale();
                for(int i=1;i<=t;i++)
                {
                    cin>>u;
                    carsForSale.erase(carsForSale.begin() + (u - 1));
                }
                call();
            };break;
            case 2:
            {
                cout<<endl<<"How many cars do you want to remove? : \n";
                cin>>t;
                displayCarsForRent();
                for(int i=1;i<=t;i++)
                {
                    cin>>u;
                    carsForRent.erase(carsForRent.begin() + (u - 1));
                }
                call();
            };break;
            
        }
       
        };break;
        
            }
        }
        
    }
};



int main()
{
    CarManagementSystem cmt;
    cmt.call();
    
    return 0;
}