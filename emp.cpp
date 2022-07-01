#include <bits/stdc++.h>

using namespace std;

inline string indent()
{
    return "\t\t\t";
}

class Employee;
vector<Employee> employees;

struct Employee
{
public:
    string id,name,contact;
};

string name, pass;

namespace loggin_{

        void login(){ 
        system("CLS");

        cout << "\n\n"
            << indent() << "Employee Data Managment System" << endl;
        cout << "\n\n"
            << indent() << "Sign In" << endl;
        string a, b;
        cout << "\n"
            << indent() << "Enter your username: ";
        cin >> a;
        cout << "\n"
            << indent() << "Enter your password: ";
            cin >> b;
            if (a != name or b != pass)
            {
                cout << "\n\n"
                     << indent() << "\aUsername or Password is incorrect!";
                _sleep(4000);
                loggin_::login();
            }
        }
}

namespace emp{
    void insert_data()
    {
        system("CLS");
        int add;
        cout << "\n\n"
             << indent() << "Enter number of employees data you want to insert: ";
        cin >> add;
        if(add<1){
            cout<<"\n\n"<<indent()<<"Invalid option!";
            return;
        }
        int g = employees.size();
        Employee e;
        for (int i = g; i < (g + add); i++)
        {
            cout << "\n\n"
                 << indent() << "Enter the data of " << i + 1 << " employee:" << endl;
            cout << "\n"<<indent()<<"Id: ";
            cin>>e.id;
            cout << "\n"
                 << indent() <<"Name : ";
            cin >>
                e.name;
            cout<<"\n"<<indent()<<"Contact: ";
            cin>>e.contact; 
            employees.push_back(e);
        }
    }

    void show_data1(){
        string a;
        if (employees.empty())
        {
            cout <<"\n\n"<< indent() << "Record is empty!";
            return;
        }
        cout<<"\n\n"<<indent()<<"Enter the id of the employee: ";
        cin>>a;
        int i = -1;
        for(int j = 0;j<employees.size();j++){
            if(employees[j].id == a){
                i = j;
                break;
            }
        }
        if(i == -1){
            
            cout<<"\n"<<indent()<<"No such record found!";
            return;
        }
        vector<string> attribute = {"Id", "Name", "Contact"};
        int g = 10+max(employees[i].id.size(),attribute[0].size())+max(employees[i].name.size(),attribute[1].size())+max(employees[i].contact.size(),attribute[2].size());
        vector<bool> vb(g);
        vb[0] = true;
        vb[1 + max(employees[i].id.size(), attribute[0].size()) + 2] = true;
        vb[1 + max(employees[i].id.size(), attribute[0].size()) + 2 + 1 + max(employees[i].name.size(), attribute[1].size())+2] = true;
        vb[1 + max(employees[i].id.size(), attribute[0].size()) + 2 + 1 + max(employees[i].name.size(), attribute[1].size()) + 2 + 1 + max(employees[i].contact.size(),attribute[2].size()) + 2] = true;
        int column = 0;
        int count = 0;
        vector<string> record = {employees[i].id,employees[i].name,employees[i].contact};
        int row = 0;
        
        cout<<endl;
        
        while(row<5){
            column = 0;
            count = 0;
            bool ok = false;
            cout<<indent();
            if(!(row&1)){
                while(column<g){
                    cout<<'-';
                    column++;
                }
                cout<<endl;
                row++;
                continue;
                
            } 
            else if(row == 1){
                while (column < g)
                {
                    if (vb[column])
                    {
                        cout << '|';
                        column++;
                    }
                    else if ((vb[column - 1] == true and column > 0))
                    {
                        cout << ' ';
                        column++;
                        ok = true;
                    }
                    else if (ok)
                    {
                        cout << attribute[count];
                        column += attribute[count].size();
                        count++;
                        ok = false;
                    }
                    else
                    {
                        cout << ' ';
                        column++;
                    }
                }
                cout<<endl;
                row++;
                continue;
            }
           
            while(column<g){
                if(vb[column]){
                    cout<<'|';
                    column++;
                }
                else if((vb[column-1] == true and column>0)){
                    cout<<' ';
                    column++;
                    ok = true;
                }
                else if(ok){
                    cout<<record[count];
                    column+=record[count].size();
                    count++;
                    ok = false;
                }
                else{
                    cout<<' ';
                    column++;
                }
            }
            cout<<endl;
            row++;
        }
    }

    void show_data2(){
        if (employees.empty())
        {
            cout <<"\n"<< indent() << "Record is empty!";
            return;
        }
        vector<string> attribute = {"Id", "Name", "Contact"};
        int a = 0,b = 0,c = 0;
        int i = 0;
        while(i<3){
            for(int j = 0;j<employees.size();j++){
                if(i == 0){
                    a = max(a,(int)employees[j].id.size());
                }
                else if(i==1){
                    b = max(b,(int)employees[j].name.size());
                }
                else{
                    c = max(c,(int)employees[j].contact.size());
                }
            }
            i++;
        }
        a= max(a,2);
        b = max(b,4);
        c = max(c,7);
        int g = 10+a+b+c;
        int row = 0;
        vector<bool> vb(g);
        vb[0] = true;
        vb[1 + a + 2] = true;
        vb[1 +a + 2 + 1 + b + 2] = true;
        vb[1 + a + 2 + 1 + b + 2 + 1 + c + 2] = true;
        int column=0;
        int count = 0;
        int y = 0;
        vector<string> record;
        while(row<2*employees.size()+3){
            column = 0;
            count = 0;
            bool ok = false;
            cout << indent();
            if (!(row & 1))
            {
                while (column < g)
                {
                    cout << '-';
                    column++;
                }
                cout << endl;
                row++;
                continue;
            }
            else if (row == 1)
            {
                while (column < g)
                {
                    if (vb[column])
                    {
                        cout << '|';
                        column++;
                    }
                    else if ((vb[column - 1] == true and column > 0))
                    {
                        cout << ' ';
                        column++;
                        ok = true;
                    }
                    else if (ok)
                    {
                        cout << attribute[count];
                        column += attribute[count].size();
                        count++;
                        ok = false;
                    }
                    else
                    {
                        cout << ' ';
                        column++;
                    }
                }
                cout << endl;
                row++;
                continue;
            }
            
            record = {employees[y].id, employees[y].name, employees[y].contact};
            while (column < g)
            {
                if (vb[column])
                {
                    cout << '|';
                    column++;
                }
                else if ((vb[column - 1] == true and column > 0))
                {
                    cout << ' ';
                    column++;
                    ok = true;
                }
                else if (ok)
                {
                    
                    cout << record[count];
                    column += record[count].size();
                    count++;
                    
                    ok = false;
                }
                else
                {
                    cout << ' ';
                    column++;
                }

                
            }
            y++;
            cout << endl;
            row++;
        }
    }

    void update(){
        if (employees.empty())
        {
            cout << "\n\n"
                 << indent() << "Record is empty!";
            return;
        }
        cout<<"\n\n"<<indent()<<"Enter the Id of the employee: ";
        string a;
        cin>>a;
        int i = -1;
        for(int j = 0;j<employees.size();j++){
            if(employees[j].id == a){
                i = j;
                break;
            }
        }
        if(i == -1){
            cout<<"\n"<<indent()<<"No such record found!";
            return;
        }
        bool ok = false;
        char b,c;
        cout<<"\n"<<indent()<<"Do you want to update name of the employee id "<<employees[i].id<<" [Y/N]?";
        cin>>b;
        if(b == 'Y' or b == 'y'){
            ok = true;
            cout<<"\n"<<indent()<<"Enter the updated name of the employee id "<<employees[i].id<<" : ";
            cin>>employees[i].name;
        }

        cout << "\n"
             << indent() << "Do you want to update contect of the employee id " << employees[i].id << " [Y/N]?";
        cin >> c;

        if(c == 'Y' or c == 'y'){
            ok = true;
            cout<<"\n"<<indent()<<"Enter the updated contact of the employee id "<<employees[i].id<<" : ";
            cin>>employees[i].contact;
        }

        if(ok){
            cout<<"\n"<<indent()<<"Data has been updated successfully!";
        }
        cout<<"\n\n";
    }

    void delete_(){
        if(employees.empty()){
            cout<<"\n\n"<<indent()<<"Record is empty!";
            return;
        }
        cout << "\n\n"
             << indent() << "Enter the Id of the employee: ";
        string a;
        cin >> a;
        int i = -1;
        for (int j = 0; j < employees.size(); j++)
        {
            if (employees[j].id == a)
            {
                i = j;
                break;
            }
        }
        if (i == -1)
        {
            cout << "\n"
                 << indent() << "No such record found!";
            return;
        }
        char b;
        cout<<"\n"<<indent()<<"Do you want to delete the data of the employee id "<<employees[i].id<<" [Y/N]?";
        cin>>b;
        if(b== 'Y' or b == 'y'){
            employees.erase(employees.begin()+i);
            cout<<"\n"<<indent()<<"Data has been deleted successfully";
        }
        cout<<"\n\n";
    }

    void logout(){
        system("CLS");
        cout<<"\n\n"<<indent()<<"You has logged out successfully!";
        _sleep(4000);
        system("CLS");
        cout<<"\n\n"<<indent()<<"Press [Y] to log in or Press [N] to exit: ";
        char b;
        cin>>b;
        if(b=='Y' or b == 'y'){
            loggin_::login();
        }
    }
}


signed main()
{
    system("CLS");
    cout << "\n\n"
         << indent() << "Employee Data Managment System" << endl;
    cout << "\n\n"
         << indent() << "Sign Up" << endl;
    cout << "\n"
         << indent() << "Enter your username: ";
    cin >> name;
    cout << "\n"
         << indent() << "Enter your password: ";
    cin >> pass;
    cout << "\n\n"
         << indent() << "Please wait!";

    for (int i = 0; i < 6; i++)
    {
        cout << '.';
        _sleep(1000);
    }
    login:
    system("CLS");
    
    cout << "\n\n"
         << indent() << "Employee Data Managment System" << endl;
    cout << "\n\n"
         << indent() << "Sign In" << endl;
    string a, b;
    cout << "\n"
         << indent() << "Enter your username: ";
    cin >> a;
    cout << "\n"
         << indent() << "Enter your password: ";
    cin >> b;

    if(a!=name or b!=pass){
        cout<<"\n\n"<<indent()<<"\aUsername or Password is incorrect!";
        _sleep(4000);
        loggin_::login();
    }
    system("CLS");
    int g;
    while(true){
        cout<<"\n\n";
        cout<<"\n"<<indent()<<"Press 1 to insert the data";
        cout<<"\n"<<indent()<<"Press 2 to see the data of a perticular employee";
        cout<<"\n"<<indent()<<"Press 3 to see the data of all the employees";
        cout<<"\n"<<indent()<<"Press 4 to delete the existing record";
        cout<<"\n"<<indent()<<"Press 5 to update the existing record";
        cout<<"\n"<<indent()<<"Press 6 to signout";
        cout<<"\n"<<indent()<<"Press 7 to exit";
        cout<<endl;
        cin>>g;
        switch(g){
            case 1:
                emp::insert_data();
                break;
            case 2:
                emp::show_data1();
                break;
            case 3:
                emp::show_data2();
                break;
            case 4:
                emp::delete_();
                break;
            case 5:
                emp::update();
                break;
            case 6:
                emp::logout();
                system("CLS");
                break;
            case 7:
                exit(0);
                break;
            default:
                cout<<"Invalid option"<<endl;
                break;
        }
    }
}
