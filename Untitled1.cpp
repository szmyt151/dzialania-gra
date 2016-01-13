#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

class gracz{
    public:
    int zycie;
    int punkty;
	int zadan;
	
    gracz(){
        zycie=3;
        punkty=0;
        zadan=0;
    }
      
    void usun_hp(){
    	zycie--;
    }
    
    void dodaj_hp(){
    	punkty++;
    }
    
};

class dzialanie{

    public:
    virtual void zadanie(int a,int b,float &wynik)=0;
    friend class gracz;
};

class dodawanie:public dzialanie{

    public:
    virtual void zadanie(int a,int b,float &wynik){
  		cout<<a<<"+"<<b<<"="<<endl;
  		wynik=a+b;
    }
};

class odejmowanie:public dzialanie{

    public:
    virtual void zadanie(int a,int b,float &wynik){
        cout<<a<<"-"<<b<<"="<<endl;
        wynik=a-b;
    }
};

class mnozenie:public dzialanie{

    public:
    virtual void zadanie(int a,int b,float &wynik){
        cout<<a<<"*"<<b<<"="<<endl;
        wynik=a*b;
    }
};


int main()
{	
	srand(time(0));
   unsigned char znak;
    do{    
	gracz first;
    
    dzialanie *wsk;
    dodawanie z1;
    odejmowanie z2;
    mnozenie z3;

	wsk = &z1;
	
	int zadanie = rand()%3;

	while(first.zycie!=0){
 		zadanie = rand()%3;
		  
  		int liczbaa = rand()%100+1;
	 	int liczbab = rand()%liczbaa+10;
		float wynik=0; //wynik dzilania;
		float odp;
		  
		  {
		  	cout<<"---------------|---|"<<endl;
		  	cout<<"|Ilosc punktow:|"<<first.punkty<<"  |"<<endl;
			cout<<"|Ilosc zadan:  |"<<first.zadan<<"  |"<<endl;
			cout<<"|Ilosc zyc:    |"<<first.zycie<<"  |"<<endl;
			cout<<"---------------|---|"<<endl;
		  }
	  switch(zadanie){
		case 0: {
			 wsk = &z1; 
			 wsk -> zadanie(liczbaa,liczbab,wynik);
			 
			break;
		}
		case 1: {
			 wsk = &z2; 
			 wsk -> zadanie(liczbaa,liczbab,wynik); 
			  
			break;
		}
		case 2:{
			 wsk = &z3; 
			 wsk -> zadanie(liczbaa,liczbab,wynik);
			 
			break;
		}	
	}
		cin>>odp;
		
    	if(odp==wynik)
			  first.punkty++;
  			  else
  			  first.usun_hp();
    		  	  
    first.zadan++;
 	 
     system("cls");
	}
	system("cls");
	
            cout<<"---------------|---|"<<endl;
		  	cout<<"|Ilosc punktow:|"<<first.punkty<<"  |"<<endl;
			cout<<"|Ilosc zadan:  |"<<first.zadan<<"  |"<<endl;
			cout<<"---------------|---|"<<endl;
			
	cout<<"Chcesz wyjsc z gry ? Przycisnij ESC"<<endl;
	
	znak = getch();
	static_cast < int >( znak );
	system("cls");
	}while(znak != 27 );
    return 0;
}

