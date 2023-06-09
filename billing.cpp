#include<bits/stdc++.h>
#include<string.h>
using namespace std;



class shopping{

    private :
    int pcode;
    string pname;
    float dis;
    float price;

    public :

    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void reciept();

};

void shopping :: administrator(){

    m :
    int choice ;
    cout<<"\n\n \t administrator menu :";
    cout<<"\n\t |___ 1) add product";
    cout<<"\n\t |___ 2) modify product";
    cout<<"\n\t |___ 3) delete product";
    cout<<"\n\t |___ 4) back to main menu";
    cout<<"\n\t Please Enter choice : ";
    cin>>choice;
    switch(choice){
        case 1:
                add();
                break;
        case 2 :
                edit();
                break;
        case 3 : 
                rem();
                break;
        case 4 : 
                menu();
                break;
        default :
                cout<<"Invalid choice" ;

    }
    goto m;
}


void shopping :: menu(){

    int choice;
    string email;
    string password;
    m :
    cout<<"\t\t\t\t____________________________\t\n";
    cout<<"\t\t\t\t    Super Market Main Menu  \n";
    cout<<"\t\t\t\t     1) Administrator  |\n";
    cout<<"\t\t\t\t     2) Buyer          | \n";
    cout<<"\t\t\t\t     3) Exit           |\n";
    cout<<"\t\t\t\t     Please Enter : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"\t\t\t Please login"<<endl;
            cout<<"\t\t\t Please Enter Email : ";
            cin>>email;
            cout<<"\t\t\t \nPlease Enter password : ";
            cin>>password;

            if(email == "saket@gmail.com" && password == "12345")
            {
                administrator();
            }
            else 
            {
                cout<<"Credential Error "<<endl;
            }
            break;
        case 2:
            buyer();
            break;
        case 3: 
                exit(0);
            break;
        case 4 : cout<<"\t\t\t\t Please Enter Valid Input \n";
            
    }
    goto m;
}

void shopping :: buyer(){

    m :
    int choice ;
    cout<<"\t\t\t Buyer  \n";
    cout<<"_______________\n";
    cout<<"\t\t\t\n 1) Buy the product :";
    cout<<"\t\t\t\n 2) Go back : ";
    cout<<"\n Enter the choice : ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        reciept();
        break;
    case 2: 
        menu();
        break;
    default:
        cout<<"Invalid Choice";
    
    }

    goto m;
}

void shopping :: add(){

    m :
    fstream data;
    int c;
    int token =0;
    float p;
    float d;
    string n;

    cout<<"\n\n \t Add new product ";
    cout<<"\n Product Code of the product : ";
    cin >> pcode;   
    cout<<"\n \t Name of the product : ";
    cout<<"\n \t Price of product : ";
    cin>>price;
    cout<<"\n \t Discount of product :";
    cin>>dis;

    data.open("databse.txt", ios ::in);

    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname <<" "<<dis<<"\n";
        data.close();
    }
    else 
    {
        data>>c>>n>>p>>d;

        while(!data.eof()){

            if(c == pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    

        if( token == 1)
            goto m;

        else  
        {
            data.open("database.txt", ios:: app | ios::out);
            data <<" "<<pcode <<" "<<pname<<" "<<price<<" "<<dis<<endl;
            data.close();     
        }
    }

    cout<<"\t\t \n Data inserted :";


}

void shopping :: edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record"<<endl;
    cout<<"\n\t\t\t enter product code :";
    cin>>pkey;

    data.open("database.txt", ios::in);

    if( !data){
        cout<<"\n\n Data is not exists "<<endl;
    }
    else 
    {
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;

        while(!data.eof())
        {
            if(pkey == pcode)
            {
                cout<<"\n\t\t Procduct new code : ";
                cin>>c;
                cout<<"\n\t\t Name of product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t\t Record has edited : ";
                token++;
            }
            else 
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if( token == 0)
        cout<<"\n\t\t\t record has not found"<<endl;

    }

}

void shopping :: rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;

    cout<<"\n\n \t Dalete Product ";
    cout<<"\n\t Enter product code :";
    cin>>pkey;

    data.open("database.txt", ios::in);

    if( !data)
    {
        cout<<"\nFile does not exist ";

    }
    else 
    {
        data1.open("database.txt", ios:: app | ios::out);
        data>>pcode>>pname>>price>>dis;
        while( !data.eof())
        {
            if( pkey == pcode )
            {
                cout <<"\n\t\t Product Deleted successfully";
                token++;
            }
            else 
            {
                data1<<" "<<pcode<<" "<<pname <<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }

        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if( token == 0)
        {
            cout<<"\n\n Record is not found";
        }

    }
    
}

int main()
{
     shopping s;


     s.menu();
    //cout<<"saket\n";
    return 0;
}