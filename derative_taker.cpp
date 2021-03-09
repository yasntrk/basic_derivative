#include <iostream>
#include <math.h>

using namespace std;

void bitis();
void menu();

void turev(double katsayi[], double ustsayi[], int terimsayisi) { //turevi bulur ve yazdirir
	double katsayi_[terimsayisi];
	int ustsayi_[terimsayisi];
	for (int i = 0; i < terimsayisi; i++) {
		katsayi_[i] = katsayi[i] * ustsayi[i]; //Turevi alir katsayiyla carpar
		ustsayi_[i] = ustsayi[i] - 1; //Turevi alinan sayinin ustunu bir azaltiyor
	}
	cout << "f'(x)="; //Turevi alir yazdirir
	for (int i = 0; i < terimsayisi; i++) {
		if(ustsayi[i]==0){
			cout << "+(0)";
		}else{
			cout << "+(" << katsayi_[i] << "x^" << ustsayi_[i] << ")";
		}
	}
	for (int i = 0; i < terimsayisi; i++) {
		katsayi[i] = katsayi_[i]; //Kullanicidan aldigi katsayiyi baska katsayi dizisine yazdirir
		ustsayi[i] = ustsayi_[i];
	}
}

double polinomTurevi(float x, double KATSY[], double USTSY[],int terimsayisi) { //Egimi bulur
	double sonuc = 0;
	double p = x;
	float araplatform = 1;//değerini bulurken ust negatif ise lazım  için float 1/2=0.5 yapıyor
	for (int i = 0; i < terimsayisi; i++) {
		if(USTSY[i]>0){ //Eger ustun derecesi pozitifse bu islemi yapar
			for (int j = 0; j < USTSY[i]; j++) {
				araplatform *= p; //p x degerine esit oldugu icin
			}
			x = araplatform;
			sonuc += KATSY[i] * x;
			araplatform = 1;
		}else{ //Eger ustun derecesi negatifse bu islemi yapar
			for (int j = 0; j > USTSY[i]; j--) {
				araplatform /= p;
			}
			x = araplatform;
			sonuc += KATSY[i] * x;
			araplatform = 1;
		}
	}
	return sonuc;
}

void polinom(){//polinomu kullanicidan alir
	float degisken;//değerini bulurken ust negatif ise lazım  için
	cout << "\n Turevini istediginiz x noktasini giriniz: ";
	cin >> degisken;
	int terimsayisi; //Kullanicidan terim sayisi alir
	cout << " Terim sayisini giriniz: ";
	cin >> terimsayisi;

	double ustsayi[terimsayisi];
	double katsayi[terimsayisi];
	for (int i = 0; i < terimsayisi; i++) {
		ustsayi[i] = 0;
		katsayi[i] = 0;
	}
	for (int i = 0; i < terimsayisi; i++) { //Kullanicidan katsayi ve us ister
		cout << " " << (i + 1) << ". katsayiyi giriniz: ";
		cin >> katsayi[i];
		cout << " " << (i + 1) << ". us sayiyi giriniz: ";
		cin >> ustsayi[i];
	}
	cout << "f(x)="; //F(x) i yazdirir
	for (int i = 0; i < terimsayisi; i++) {
		cout << "+(" << katsayi[i] << "x^" << ustsayi[i] << ")";
	}
	cout << endl;
	turev(katsayi, ustsayi, terimsayisi); //DİZİLERDE FONKSIYONLARDA KULLANIRKEN [] BU ISARET KULLANILMAZ DİZİLERİN İÇİ DEĞİŞTİ
	cout << " " << endl; //Fonksiyonu yazdirir
	cout << "------------- --- --  -   -    -        -\n";
	cout << "| f'(" << degisken << ") = "<< polinomTurevi(degisken, katsayi, ustsayi, terimsayisi) << endl;
	cout << "------------- --- --  -   -    -        -" << endl;
	bitis();
}

void trigonometrik(){ //Trigonometrik fonksiyonlarin turevini alir ve degerini hesaplar
	int xderece; //Derece alir

	cout<<"\n\n\t\t\tTrigonometrik degeri seciniz\n\t\t\t"
			//Ana ekranda secim yaptirir
			<<"1.Sinus\n\t\t\t"
			<<"2.Kosinus\n\t\t\t"
			<<"3.Tanjant\n\t\t\t"
			<<"4.Kotanjant\n\t";
	double trigodeger; //Degerleri alir ve secim yaptirir
	cin >> trigodeger;
	cout << " Turevin acisini giriniz: \n";
	cin >> xderece;
	while(xderece>360){
		xderece-=360;
	}
	//Verilen secimlerde trigonometrik degerlerden birisini sectirir
	if(trigodeger==1) {
		cout << " aSinbx\n";
		int katsayi,xkatsayi;
		cout << " a degeri: "; //Sin degerini alir
		cin >> katsayi;
		cout << " b degeri: \n";
		cin >> xkatsayi;
		cout << "f(x)="<< katsayi<<"sin"<<xkatsayi<<"x"<<endl;
		cout << "------------- --- --  -   -    -        -\n";
		cout << "f'(x)="<< (xkatsayi*katsayi)<<"cos"<<xkatsayi<<"x"<<endl;
		if(xderece==90 || xderece==270){
			cout << "------------- --- --  -   -    -        -\n";
			cout <<"| f'("<<  " x  "  <<") = " <<  0 <<endl;
			cout << "------------- --- --  -   -    -        -" << endl;
		}else{
			float x;
			x = xkatsayi*xderece*3.14159/180; //Double'i Aciya cevirir
			float deger =(xkatsayi*katsayi)*(cos(x));
			cout << "------------- --- --  -   -    -        -\n";
			cout <<"| f'("<<  " x  "  <<") = " <<  deger <<endl;
			cout << "------------- --- --  -   -    -        -" << endl;
		}
	}
	if(trigodeger==2) {
		cout << "aCosbx"<< endl;
		int katsayi,xkatsayi;
		cout << " a degeri: "; //Degerleri alir
		cin >> katsayi;
		cout << " b degeri: \n"; //Degerleri alir
		cin >> xkatsayi;
		cout << "f(x)="<< katsayi << "cos(" << xkatsayi << "*x)" <<endl;
		cout << "------------- --- --  -   -    -        -\n";
		cout << "f'(x)="<< "-" << (xkatsayi*katsayi) << "sin(" << xkatsayi << "x)" <<endl;
		if(xderece==0 || xderece==180){
			cout << "------------- --- --  -   -    -        -\n";
			cout <<"| f'("<<  " x  "  <<") = " <<  0 <<endl;
			cout << "------------- --- --  -   -    -        -" << endl;
		}else{
			float x;
			x = xderece*3.14159/180; //Double'ı Aciya cevirir
			float deger = -xkatsayi*katsayi*sin(xkatsayi*x);
			cout << "------------- --- --  -   -    -        -\n";
			cout <<"| f'("<<  " x  "  <<") = " <<  deger <<endl;
			cout << "------------- --- --  -   -    -        -" << endl;
		}
	}
	if(trigodeger==3) {
		cout << "aTanx"<< endl;
		int katsayi;
		cout << " a degeri: ";//Degerleri alir
		cin >> katsayi;
		cout << "f(x)="<< katsayi << "tan(x)^2" <<endl;
		cout << "------------- --- --  -   -    -        -\n";
		cout << "f'(x)="<< katsayi << "tan(x)" <<endl;
		double x;
		x = xderece*3.14159/180; //Aciyi radyana cevirir
		double deger = katsayi*(1+pow(tan(x),2));
		cout << "------------- --- --  -   -    -        -\n";
		cout <<"| f'("<<  " x  "  <<") = " <<  deger <<endl;
		cout << "------------- --- --  -   -    -        -" << endl;
	}
	if(trigodeger==4) {
		cout << "aCotx"<< endl;
		int katsayi; //Degerleri alir
		cout << " a degeri: ";
		cin >> katsayi;
		cout << "f(x)="<< katsayi << "cot(x)" <<endl;
		cout << "------------- --- --  -   -    -        -\n";
		cout << "f'(x)="<< "-"  << katsayi << "cot(x)" <<endl;
		double x;
		x = xderece*3.14159/180; // Aciyi radyana cevirir
		double deger = -katsayi*(1+pow((1/tan(x)),2));
		cout << "------------- --- --  -   -    -        -\n";
		cout <<"| f'("<<   x    <<") = " <<  deger <<endl;
		cout << "------------- --- --  -   -    -        -" << endl;
	}
	bitis();
}void logaritmik(){
	cout << "aLogb(Cx)"<< endl;
	cout << "Turevini almak istediginiz noktayi seciniz, E=2.71 girebilirsiniz." <<endl;
	float x;
	cout << "X:" <<endl; //Kullanicinin istedigi X noktasini bulur
	cin >> x;
	cout << "aLogbx olacak sekilde A, B ve C degerlerini giriniz"<< endl;
	float logkatsayi,xkatsayi,taban;
	cout << "a=:" << endl;
	cin >> logkatsayi; //Degerleri kullanicidan okur
	cout << "b=:" << endl;
	cin >> taban;
	cout << "c:" << endl;
	cin >> xkatsayi;
	float deger = logkatsayi*(1/x*log(taban));
	cout << "f( x ) = " << logkatsayi << "Log" << taban << "(" << xkatsayi <<"x)" << endl;
	cout << "------------- --- --  -   -    -        -\n";
	cout << "f'(x) =" << "1/" << xkatsayi << "*1/ln" << taban << endl; //Fonksiyonun turevini ve kendisini yazdirir
	cout << "------------- --- --  -   -    -        -\n";
	cout << "f'( " << x  << ") = " << deger << endl;
	cout << "------------- --- --  -   -    -        -\n";
	bitis();
}

void bitis(){
	cout <<		"\n\n\t\t\t1.Menuye Don\n\t\t\t"
			<<"2.Cikis\n\t\t\t";

	int secim; //Bitis kismini tanimlar geriye dondurur
	cin>>secim;
	if(secim==1){
		menu();
	}else{
		exit(0);
	}
}

void menu(){
	//Turev'in alinacagi yolu secer
	cout<<"\n\n";

	cout<<"\t\t\tDenklem seklini seciniz\n\n\t\t\t"

			<<"1.Polinom\n\t\t\t"
			<<"2.Trigonometrik\n\t\t\t"
			<<"3.Logaritmik\n\t\t\t"
			<<"4.Cikis\n\t";
	int secici;
	cin >> secici; //Secici kullanicidan turevini almak istedigi fonksiyonu secer

	if(secici==1){
		polinom();
	}else if(secici==2){
		trigonometrik();
	}else if(secici==3){
		logaritmik();
	}else if(secici==4){
		exit(0);
	}
}

int main() {
	cout << endl << endl ;
	menu(); //Main kodu
	return 0;
}
