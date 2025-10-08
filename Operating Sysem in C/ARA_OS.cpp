//Ara Operating System in C

#include<iostream>
using namespace std;
#include<string>

class home
{
    private:

    public:

    void mainscr()
    {
        cout<<"Desktop        Documents        Command        Bin"<<endl;
    }

    void rootscr()
    {
        cout<<"\\root        \\bin        \\etc        \\sys        \\var        \\dev        \\logs"<<endl;
    }
};

class command :public home
{
    public:
    void comm()
    {
        cout<<"whoami : to find user\nsudo : to change root user\nclear : clear the screen\nls : list documents\ntr : terminal\nus : user\nver : version";
    }
    int commvalue(string value)
    {
        if(value=="sudo")
        {
            return 100;
        }
        else if(value=="ls")
        {
            return 101;
        }
        else if(value=="whoami" || value=="us")
        {
            return 102;
        }
        else if(value=="clear")
        {
            return 103;
        }
        else if(value=="exit")
        {
            return 104;
        }
        else if(value=="tr")
        {
            return 105;
        }
        // else if(value=="us")
        // {
        //     return 106;
        // }
        else if(value=="ver")
        {
            return 107;
        }
    }
};

class terminal : public command
{
    private:
    string user="ARA";
    string passwd;

    public:

    void password(string add)
    {
        passwd=add;
    }
    void cls()
    {
             system("cls");
                 cout<<"\033[31m ---------ARA Operating System in C---------\033[0m\n";
                 cout<<"tr for Terminal\nus for user\nver for version\nclear for clear terminal\n";
    }
    void use()
    {
      cout<<user;
    }

    void term()
  {
        int opt=1;
        

        while(opt)
    {
        string value;
        int opt;
         string pass;
        cout<<endl;
        use();
        cout<<"\033[31m--> \033[0m";
        getline(cin,value);
        opt=commvalue(value);

        switch(opt)
        {
            case 105 :
            user="general";
            cout<<"terminal unboxed";
                break;
            case 102 :
            use();
                break;
            case 103 :
            cls();
                break;
            case 107 :
            cout<<"This OS is Designed and Developed by \033[31mKrishna Kumar\033[0m and this is the first version \033[31m0.0.0.1\033[0m";
            break;
            case 100 :
            cout<<"Enter passwd: ";
          //  cin.ignore();
            getline(cin,pass);
            if(pass==passwd)
            {
                user="root";
            }
            else
            {
                cout<<"You entered wrong passwd: ";
            }
        break;
            case 101:
            if(user=="general")
            {
            home::mainscr();
            }
            else if(user=="root")
            {
                home::rootscr();
            }
            else
            {
                cout<<"no directories";
            }
        break;
            case 104 :
            if(user=="root")
            {
            cout<<"Exit successfully";
            user="general";
            }
            else if(user=="general")
            {
            cout<<"Exit successfully";
            //opt=0;
            user="ARA";
            }
        break;
        default :
        cout<<"Incorrect command...";
        }
    }
  }
    
};



int main()
{
    string value,add;
    terminal first;

    system("cls");
    cout<<"\033[31m ---------ARA Operating System in C---------\033[0m\n";
    cout<<"tr for Terminal\nus for user\nver for version\nclear for clear terminal\n";
   
    cout<<"For unboxing Os please set passwd for root: ";
    getline(cin,add);
    first.password(add);
    cout<<"                      ";
    first.cls();

    first.term();
   
    return 0;
}

