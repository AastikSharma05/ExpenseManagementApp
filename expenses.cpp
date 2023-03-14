//Header files
#include<iostream>                          
#include<cstring>
#include<fstream>
#include<windows.h>                               
                                      
using namespace std;

//Functions
void setup();                                       
void input();
void displayall();
void display();
void searchprice();
void searchname();

static boolean initialsized;
static boolean initialsizeddisplay;

int main()                                //Main function
{   int choice;
    system("cls");
        if(!initialsized)
            {
                setup();                   // Calling setup function only in the beginning
                initialsized=true;
            }
    system("cls");
    cout<<"1. Enter new expenses"<<endl;
    cout<<"2. Display the expenses"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Enter your choice:  ";
    cin>>choice;
    cout<<endl;
        switch (choice)
        {
        case 1:
            input();
            break;
        case 2:
            display();
            break;
        
        default:
            exit(0);
            break;
        }
    return 0;
}

void setup()                       //Function for initial page
{  
    string s={"WELCOME TO THE EXPENSE MANAGEMENT APP"};
    int i;   
    cout<<endl;
        for(i=0;i<50;i++)
        cout<<' ';    
    cout<<s<<endl;
    Sleep(2500);
}

void input()                     //Function for taking input
{
    string expenseName;
    system("cls");
    int expensePrice;
    char ans;
        do{
            ofstream expensefile("expensefile.txt",ios::app);
            cout<<endl<<"Enter the Name of the expense: ";
            cin>>expenseName;            
            cout<<"Enter the price in Rs (Do not type 'Rs' or use commas): ";
            cin>>expensePrice;
            cout<<endl;
            expensefile<<expenseName<<' '<<expensePrice<<endl;
            expensefile.close();
            cout<<"Do you want to enter more";cout<<endl;
            cout<<"Press Y for yes and N for no: ";
            cin>>ans;cout<<endl;

        }while(ans=='y'||ans=='Y');
     main();                                                                  //Calling back main function
}

void display()                                 //To dispaly the input
{
    int choice;
        if(!initialsizeddisplay)
        {
            system("cls");                              //To clear the screen only in the beginning so that the data remains on screen afterwards
            initialsizeddisplay=true;
        }
    cout<<"1. Show the total amount spent"<<endl;
    cout<<"2. Search by Price"<<endl;
    cout<<"3. Search by Name"<<endl;
    cout<<"4. Go back"<<endl;
    cout<<"Enter your Choice: ";
    cin>>choice;
    cout<<endl;
        switch (choice)
        {
        case 1:
            displayall();
            break;
        case 2:
            searchprice();
            break;
        case 3:
            searchname();
            break;
        case 4:
            main();
            break;
        
        default:
            exit(0);
            break;
        }
}

void displayall()                                    //Function to dispaly all the data
{
    ifstream expensefile("expensefile.txt");
    string expenseName;
    int expensePrice,total=0;
    cout<<"Expenses"<<' '<<" Prices"<<endl;
    cout<<"-----------------"<<endl;
        while(expensefile>>expenseName>>expensePrice)
        {
            cout<<expenseName<<' '<<' '<<' '<<' '<<"Rs "<<expensePrice<<endl;
            total=total+expensePrice;
        }
    cout<<"Total amount spent is:  Rs ";
    
    cout<<total<<endl<<endl;
    expensefile.close();
    display();

}

void searchprice()                                      // Function to search by price value
{
    ifstream expensefile("expensefile.txt");
    string expenseName;
    int expensePrice,searchPrice,i=0;
    cout<<endl<<"Enter the price above which you want to see you expenditure"<<endl;
    cout<<"Enter the Search price: ";
    cin>>searchPrice;
    cout<<endl;
    cout<<"Expenses"<<' '<<" Prices"<<endl;
    cout<<"-----------------"<<endl;
        while(expensefile>>expenseName>>expensePrice)
        {   
            if(expensePrice>=searchPrice)
            {           
                cout<<expenseName<<' '<<' '<<' '<<' '<<expensePrice<<endl;
                i=1;
            }
            
        }
    cout<<endl;
        if(i==0)
        cout<<"There are no expenses above Rs "<<searchPrice<<endl<<endl;
    expensefile.close();
     display();
}

void searchname()                                             //Function to search by name
{
    ifstream expensefile("expensefile.txt");
    string expenseName,searchName;
    int expensePrice,i=0;
    cout<<endl<<"Enter the name of the expense: ";
    cin>>searchName;
    cout<<endl;
    cout<<"Expenses"<<' '<<" Price"<<endl;
        cout<<"-----------------"<<endl;
        while(expensefile>>expenseName>>expensePrice)
        { 
            if(expenseName==searchName)
            {            
                cout<<expenseName<<' '<<' '<<' '<<' '<<expensePrice<<endl;
                i=1;
            }
            
        }
    cout<<endl;
        if(i==0)
        cout<<"There are no expenses for "<<searchName<<endl<<endl;
    expensefile.close();
     display();
}