#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class company{

 public:
     int id ;
     char name[100];
     char med[100];


void inserte(){
        char ch ;
       company c ;
       int count =0;
        ofstream f ;

        f.open("company.txt" , ios::out | ios::app ) ;
        do {
            cout << "Enter id :  " ;
            cin >> c.id ;

            cout << "Enter name :  " ;
            cin >> c.name ;

                cout<<"enter all medicines" <<endl;
                cin>>c.med;

             f.write((char*) &c , sizeof(c) ) ;
            cout<<"do you want to enter another record?[Y/N]";
            cin >> ch ;
        }while (ch=='y' || ch=='Y') ;
        f.close() ;
    }
void print(){
        ifstream f ;
        company c ;
        f.open("company.txt" , ios::in);
        if(f.is_open())
        {
            while(f.read((char*)&c,sizeof(c)))
            {
                cout<<"ID : "<<c.id<<endl;
                cout<<"Name : "<<c.name<<endl;
                cout<<"medicines : "<<c.med<<endl;

            }
         }
        else
        cout<<"The File Is Not found :("<<endl;
    f.close();
    }

};




class Pharmacy {
    public :
        int id ;
        int Cid;
        char name[100] ;
        int price ;



//input data in file
    void inserte(){
        char ch ;
        Pharmacy s ;
        ofstream f ;
        f.open("Pharmacy.txt" , ios::out | ios::app ) ;
        do {
            cout << "Enter id :  " ;
            cin >> s.id ;
            cout << "Enter Company id :  " ;
            cin>> s.Cid;
            cout << "Enter name :  " ;
            cin >> s.name ;
            cout << "Enter price  :  " ;
            cin >> s.price ;
            f.write((char*) &s , sizeof(s) ) ;
            cout<<"do you want to enter another record?[Y/N]";
            cin >> ch ;
        }while (ch=='y' || ch=='Y') ;
        f.close() ;
    }

//output data from file

    void print(){
        ifstream f ;
        Pharmacy s ;
        f.open("Pharmacy.txt" , ios::in);
        if(f.is_open())
        {
            while(f.read((char*)&s,sizeof(s)))
            {
                cout<<"ID : "<<s.id<<endl;
                cout<<"Company ID : "<<s.Cid<<endl;
                cout<<"Name : "<<s.name<<endl;
                cout<<"price : "<<s.price<<endl;
            }
         }
        else
        cout<<"The File Is Not Open :("<<endl;
    f.close();
    }
//search about data by name in file
    void searchs(){
            Pharmacy s ;
            int flag =0;
            char inp[100] ;
            fstream f;
            f.open("Pharmacy.txt" , ios::in);
            cout<<"Enter the ID : ";
            cin >> inp ;
            while (!f.eof()) {
                f.read( (char*) & s , sizeof(s) ) ;
                if ( strcmp( inp , s.name ) ) {
                    cout << " data is found in id : " << s.id <<" Name "<<s.name<< " with price " << s.price << " Company Id "<< s.Cid << "\n";
                    flag = 1 ;
                    break ;
                }
            }
            if ( flag == 0 ) {
                cout << " data not found \n" ;
            }
            f.close() ;
    }

//Delete by id from file
    void Delete()
    {
        Pharmacy s;
        int rmo;
        ifstream ifile;
        ofstream ofile;
        ifile.open("Pharmacy.txt", ios::in);
        ofile.open("temp.txt", ios::out);
        if(ifile.is_open())
        {
            cout<<"Enter The Id of Pharmacy you wanna delete=> ";
            cin>>rmo;
            while(ifile.read((char*)&s,sizeof(s)))
            {
                if(rmo!=s.id)
                {
                    ofile.write((char*)&s,sizeof(s));
                }
            }
        }
            else
                cout<<"The File Is Not Open :("<<endl;

        ofile.close();
        ifile.close();
        remove("Pharmacy.txt");
        rename("temp.txt","Pharmacy.txt");
    }

// update
    void update()
    {
        Pharmacy s;
        int r;
        ifstream ifile;
        ofstream ofile;

        ifile.open("Pharmacy.txt",ios::in);
        ofile.open("temp.txt",ios::out);
        if(ifile.is_open())
        {
            cout<<"Enter The Id Of Pharmacy You Want to Update=>";
            cin>>r;
            while(ifile.read((char*)&s,sizeof(s)))
            {
                if(r==s.id)
                {
                    cout<<"Enter The New Id: ";
                    cin>>s.id;
                    cout<<"Enter The New Name: ";
                    cin>>s.name;
                    cout<<"Enter the new price: ";
                    cin>>s.price;
                    ofile.write((char*)&s,sizeof(s));
                }
                else
                    ofile.write((char*)&s,sizeof(s));
            }
        }
        else
            cout<<"The File Is Not Open :("<<endl;
        ifile.close();
        ofile.close();
        remove("Pharmacy.txt");
        rename("temp.txt","Pharmacy.txt");
    }

};

int main()
{
    fstream f ;
    Pharmacy s ;
    company c;
    int inf ;
    char ch;
    do{
        cout<<"1- Insert \n2- Display \n3- Delete \n4- Search \n5- Update\n6- insert company\n7- view companies \nQ- Exit\n\nEnter your operation :  ";
        cin>>inf;
        switch(inf){
            case 1:
                 s.inserte();
             break;
            case 2:
                s.print();
             break;
            case 3:
                s.Delete();
              break;
            case 4:
                s.searchs();
              break;
            case 5:
                s.update();
              break;
            case 6:
                c.inserte();
                break;
            case 7:
                c.print();
                break;

            case 'Q'|'q':
                return 0;
            default :
                return 0;
        }
        cout<<"n or N to Exit";
        cin>>ch;

    }while(ch!='n' || ch!='N');

    return 0;
}
