/*
Ögrenci Isleri Otomasyonu
*/

//KUTUPHANELER
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//FONKSIYONLAR
void ogrenciKayit(string ad, string soyad, string numara, string bolum, string sinif);
void numaraAra(string numara);
void isimAra(string ad);
void bolumListele(string bolum);
void sinifListeleme(string sinif);
void ogretimElemaniKayit(string ad, string soyad, string sicil_numara, string bolum);
void sicilNumaraAra(string sicil_numara);
void ogretimElemaniListele(string bolum);
void dersKayit(string ders_adi, string ders_kodu, string ogretimElemaniAdi, string ogretimElemaniSoyadi);
void dersListele(string ders_adi);
void dersAra(string ders_adi);
void notDersKayit(string ders_adi, string ders_kodu, string ad, string soyad, string ogretimElemaniAdi, string ogretimElemaniSoyadi);
void ogrenciAldigiNotKayit(string numara, string ders_adi, string ogrenci_notu);
void ogrenciNumaraDuzenle(string numara);
void ogretimElemaniDuzenle(string sicil_numara);
void dersKoduDuzenle(string ders_kodu);
void karneGoruntule(string numara);

int main() {
	string ad, soyad, numara, bolum, sinif, sicil_numara, ders_adi, ders_kodu, ogretimElemaniAdi, ogretimElemaniSoyadi, ogrenci_notu;
	int secim;
	char secim1, secim2, secim3;
	A:
	cout << "\nO*O*O*O*O*O*O*O*O*O*O*O*O*O*O*O*O*O*O*O*O" << "\n" ;
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << "\n" ;
	cout << "********OGRENCI ISLERI OTOMASYONU********" << "\n" ;
	cout << "#### Ogrenci Modulu Icin------------->1  #" << "\n" ;
	cout << "#### Ogretim Elemani Modulu Icin----->2  #" << "\n" ;
	cout << "#### Ders Modulu Icin---------------->3  #" << "\n" ;
	cout << "#### Not Giris Modulu Icin----------->4  #" << "\n" ;
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << "\n" ;
	cout << "O*O*O*O*O*O*O*O*O*O*O*O*O*O*O*O*O*O*O*O*O" << "\n";	
	cin>>secim;
	
	switch(secim){
		//OGRENCI MODULU
		case 1:
			cout << "##########################################" << "\n";
			cout << "Ogrenci Kayit Eklemek Icin-------------> a" << "\n" ;
			cout << "Ogrenci Aramak Icin--------------------> b" << "\n" ;
			cout << "Ogrenci Listelemek Icin----------------> c" << "\n" ;
			cout << "Ogrenci Bilgilerini Duzeltmek Icin-----> d" << "\n" ;
			cout << "##########################################" << "\n";		
			cin >> secim1;
		switch(secim1){
			case 'a':
				cout << "##########################################" << "\n";
				cout << "Ogrenci Adini ve Soyadini Giriniz: "; 
				cin >> ad >> soyad;
				fflush(stdin);
				cout << "Ogrenci Numarasini Giriniz: ";
				getline(cin , numara) ;
				cout << "Ogrenci Bolumunu Giriniz: ";
				getline(cin , bolum) ;
				cout << "Ogrenci Sinifini Giriniz: ";
				getline(cin , sinif );
				cout << "##########################################" << "\n";
				ogrenciKayit(ad, soyad, numara, bolum, sinif);
				goto A;
			case 'b':
				cout << "##########################################" << "\n";
				cout << "Ogrenci Numarasina Gore Aramak Icin----->x" << "\n";
				cout << "Ogrenci Adina Gore Aramak Icin---------->y" << "\n";
				cout << "##########################################" << "\n";
				cin >> secim2;
				switch(secim2){
					case 'x':
						cout << "Aramak istediginiz ogrenci numarasini giriniz: ";
						cin >> numara;
						numaraAra(numara);
						goto A;
					case 'y':
						cout << "Aramak istediginiz ogrencinin adini giriniz: ";
						cin >> ad ;
						isimAra(ad);
						goto A;	
					default:
						cout << "Hatali secim yaptiniz!!!";
						goto A;				
				}
				break;
			case 'c':
				cout << "##########################################" << "\n";
				cout << "Bolume gore listelemek Icin---------->k" << "\n";
				cout << "Sinifa gire listelemek Icin---------->l" << "\n";
				cout << "##########################################" << "\n";
				cin >> secim3;
				switch(secim3){
					case 'k':
						cout << "Listeleme yapmak istediginiz bolum ismini giriniz: ";
						fflush(stdin);
						getline(cin , bolum);
						bolumListele(bolum);
						goto A;
					case 'l':
						cout << "Listeleme yapmak istediginiz sinif numarasini giriniz: ";
						fflush(stdin);
						getline(cin , sinif);
						sinifListeleme(sinif);
						goto A;
					default:
						cout << "Hatali secim yaptiniz!!!";
						goto A;
				}				
				break;
			case 'd':
				cout << "Duzenlemek istediginiz ogrenci numarasini giriniz: ";
				cin >> numara;
				ogrenciNumaraDuzenle(numara);				
				goto A;	
			default:
						cout << "Hatali secim yaptiniz!!!";
						goto A;										
		}
		
		//OGRETIM ELEMANI MODULU
		case 2: 
			cout << "##########################################" << "\n";
			cout << "Ogretim Elemani Kayit Eklemek Icin---------------------------------> a" << "\n" ;
			cout << "Ogretim Elemani Aramak Icin(Sicil Numarasina Gore)-----------------> b" << "\n" ;
			cout << "Ogretim Elemani Bilgilerini Duzenlemek Icin------------------------> c" << "\n" ;
			cout << "Ogretim Elemani Listelemek Icin(Bolume Gore)-----------------------> d" << "\n" ;	
			cout << "##########################################" << "\n";	
			cin >> secim1;
			switch(secim1)
			{
				case 'a':
					cout << "##########################################" << "\n";
					cout << "Ogretim Elemani Adi ve Soyadini Giriniz: " ; 
					cin >> ad >> soyad;
					fflush(stdin);
					cout << "Ogretim Elemani Sicil Numarasini Giriniz: ";
					getline(cin ,sicil_numara);
					cout << "Ogretim Elemani Bolumunu Giriniz: ";
					getline(cin , bolum );
					cout << "##########################################" << "\n";
					ogretimElemaniKayit(ad, soyad, sicil_numara, bolum);
					goto A;
				case 'b':
					cout << "Aramak istediðiniz Ogretim Elemani Sicil Numarasýna giriniz: ";
					cin >> sicil_numara;
					sicilNumaraAra(sicil_numara);
					goto A;		
				case 'c':
					cout << "Duzenlemek istediginiz ogretim elemani sicil numarasini giriniz: ";
					cin >> sicil_numara;
					ogretimElemaniDuzenle(sicil_numara);			
					goto A;
				case 'd':
					cout << "Bolume gore listelemek istediðiniz Ogretim Elemani ismini giriniz: ";
					cin >> bolum;
					ogretimElemaniListele(bolum);
					goto A;
				default:
					cout << "Hatali secim yaptiniz!!!";
					goto A;
			}
		case 3: 
		//DERS MODULU
			cout << "##########################################" << "\n";
			cout << "Ders Eklemek Icin------------------------------------> a" << "\n" ;
			cout << "Ders Bilgilerini Guncellemek Icin--------------------> b" << "\n" ;
			cout << "Ders Listelemek Icin---------------------------------> c" << "\n" ;
			cout << "Ders Aramak Icin(Ders Adina Gore)--------------------> d" << "\n" ;	
			cout << "##########################################" << "\n";	
			cin >> secim1;
			switch(secim1)
			{
				case 'a':
					cout << "Dersin Adini Giriniz: " ; 
					fflush(stdin);
					getline(cin , ders_adi );
					fflush(stdin);
					cout << "Dersin Kodunu Giriniz: ";
					getline (cin , ders_kodu );
					cout << "Dersi veren Ogretim Elemaninin Adini Giriniz: ";
					getline(cin , ogretimElemaniAdi );
					cout << "Dersi Veren Ogretim Elemaninin Soyadini Giriniz: ";
					getline (cin ,ogretimElemaniSoyadi);
					dersKayit(ders_adi, ders_kodu, ogretimElemaniAdi, ogretimElemaniSoyadi);
					goto A;
				case 'b':
					cout << "Duzenlemek istediginiz ders kodunu giriniz: ";
					cin >> ders_kodu;
					dersKoduDuzenle(ders_kodu);
					goto A;				
				case 'c':
					cout << "Listelemek istediðiniz ders ismini giriniz: ";
					cin >> ders_adi;
					dersListele(ders_adi);
					goto A;			
				case 'd':
					cout << "Aramak istediðiniz Ders Adini giriniz: ";
					fflush(stdin);
					getline(cin , ders_adi);
					dersAra(ders_adi);
					goto A;	
				default:
					cout << "Hatali secim yaptiniz!!!";
					goto A;									
			}
			
			break;
		case 4: 
		//NOT MODULU
			cout << "##########################################" << "\n";
			cout << "Ogrenciye Ders Eklemek Icin----------------------------------> a" << "\n" ;
			cout << "Ogrencinin Aldigi Ders Icýn Not Girisi Yapmak Icin-----------> b" << "\n" ;
			cout << "Ogrenci Ders Listelemek Icin---------------------------------> c" << "\n" ;
			cout << "Ogrenci Karnesi Olusturma ve Gorsellestirmek Icin------------> d" << "\n" ;	
			cout << "##########################################" << "\n";	
			cin >> secim1;
			switch(secim1)
			{
				case 'a':
					cout << "Dersin Adini Giriniz: " ; 
					cin >> ders_adi ;
					cout << "Dersin Kodunu Giriniz: ";
					cin >> ders_kodu ;
					cout << "Ogrencinin Adini Giriniz: ";
					cin >> ad;
					cout << "Ogrencinin Soyadini Giriniz: ";
					cin >> soyad;
					cout << "Dersi veren Ogretim Elemaninin Adini Giriniz: ";
					cin >> ogretimElemaniAdi ;
					cout << "Dersi Veren Ogretim Elemaninin Soyadini Giriniz: ";
					cin >> ogretimElemaniSoyadi;
					notDersKayit(ders_adi, ders_kodu, ad, soyad, ogretimElemaniAdi, ogretimElemaniSoyadi);
					break;
				case 'b':
					cout << "Ogrenci Numarasini Giriniz: ";
					cin >> numara ;
					cout << "Ogrencinin Aldigi Dersi Giriniz: ";
					cin >> ders_adi;
					cout << "Ogrencinin notunu giriniz: ";
					cin >> ogrenci_notu;
					ogrenciAldigiNotKayit(numara, ders_adi, ogrenci_notu);
					break;					
				case 'c':
					cout << "Listelemek istediðiniz ders ismini giriniz: ";
					fflush(stdin);
					getline(cin , ders_adi);
					dersListele(ders_adi);
					break;				
				case 'd':
					//karne
					cout << "Karnesini goruntulemek istediginiz ogrenci numarasini giriniz: ";
					cin >> numara;
					karneGoruntule(numara);
					break;
				default:
					cout << "Hatali secim yaptiniz!!!";
					goto A;										
			}			

	}	
	return 0;
}


//FONKSIYONLAR
//OGRENCI MODULU FONKSIYONLARI	
//OGRENCI KAYIT
void ogrenciKayit(string ad, string soyad, string numara, string bolum, string sinif)
{
	ofstream myfile;
	myfile.open("ogrenci.txt", ios::app);
	myfile << ad << "\t\t" << soyad << "\t\t" << numara << "\t\t"<< bolum << "\t\t"<< sinif <<endl;
	cout << "Ogrenci Eklendi..." << "\n";
	myfile.close();
}

//OGRENCI ARAMA (NUMARAYA GORE)
void numaraAra(string numara)
{	
	string line;
	ifstream myfile;
	myfile.open("ogrenci.txt");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			string aranan(numara);
			size_t bulunan;
			bulunan=line.rfind(aranan);
			if(bulunan!=string::npos)
			{
				cout << line << endl;
			}
		}
		myfile.close();		
	}
	else 
	{
		cout << "Unable to open file";
	}
}

//OGRENCI ARAMA (ISME GORE)
void isimAra(string ad)
{
	string line;
	ifstream myfile;
	myfile.open("ogrenci.txt");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			string aranan(ad);
			size_t bulunan;
			bulunan=line.rfind(aranan);
			if(bulunan!=string::npos)
			{
				cout << line << endl;
			}
		}
		myfile.close();
	}
	else 
	{
	cout << "Unable to open file";
	}
}

//OGRENCI LISTELEME (BOLUME GORE)
void bolumListele(string bolum)
{
	string line;
	
	ifstream myfile;
	myfile.open("ogrenci.txt");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			string aranan(bolum);
			size_t bulunan;
			bulunan=line.rfind(aranan);
			if(bulunan!=string::npos)
			{
				cout << line << endl;
			}
		}
		myfile.close();
	}
	else 
	{
		cout << "Unable to open file";
	}
}

//OGRENCI LISTELEME (SINIFA GORE)
void sinifListeleme(string sinif)
{
	sinif = "\t\t" + sinif;
	string line;
	ifstream myfile;
	myfile.open("ogrenci.txt");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			string aranan(sinif);
			size_t bulunan;
			bulunan=line.rfind(aranan);
			if(bulunan!=string::npos)
			{
				cout << line << endl;
			}
		}
		myfile.close();
	}
	else 
	{
		cout << "Unable to open file";
	}
}

//OGRENCI DUZELTME (NUMARAYA GORE)
void ogrenciNumaraDuzenle(string numara){
	string line, ad, soyad, bolum, sinif;
	ifstream myfile;
	ofstream myfile1;
	myfile.open("ogrenci.txt");
	myfile1.open("gecici.txt" , ios::app);
	if(myfile.is_open())
	{
		cout << "##########################################" << "\n";
				cout << "Ogrenci Adini Giriniz: " ; 
				cin >> ad ;
				cout << "Ogrenci Soyadini Giriniz: ";
				cin >> soyad ;
				cout << "Ogrenci Bolumunu Giriniz: ";
				cin >> bolum ;
				cout << "Ogrenci Sinifini Giriniz: ";
				cin >> sinif ;
				cout << "##########################################" << "\n";
		while(getline(myfile,line))
		{
			string aranan(numara);
			size_t bulunan;
			bulunan=line.rfind(aranan);
			if(bulunan!=string::npos)
			{				
				cout << "Kayýt basarili bir sekilde guncellendi:)))" << endl;
				myfile1 << ad << "\t\t" << soyad << "\t\t" << numara << "\t\t"<< bolum << "\t\t"<< sinif <<endl;
			}
			else{
				myfile1 << line << endl;
			}
		}
		myfile.close();
		myfile1.close();
		remove("ogrenci.txt");
		rename("gecici.txt","ogrenci.txt"); //isim degistiriyor		
	}
	else 
	{
		cout << "Unable to open file";
	}	
}

//OGRETIM ELEMANI FONKSIYONLARI
//OGRETIM ELEMANI KAYIT
void ogretimElemaniKayit(string ad, string soyad, string sicil_numara, string bolum)
{
	ofstream myfile;
	myfile.open("ogretimElemani.txt", ios::app);
	myfile << ad << "\t\t" << soyad << "\t\t" << sicil_numara << "\t\t"<< bolum << endl;
	cout << "Ogretim Elemani Eklendi..." << "\n";
	myfile.close();
}

//OGRETIM ELEMANI ARAMA (SICIL NUMARASINA GORE)
void sicilNumaraAra(string sicil_numara)
{
	string line;
	ifstream myfile;
	myfile.open("ogretimElemani.txt");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			string aranan(sicil_numara);
			size_t bulunan;
			bulunan=line.rfind(aranan);
			if(bulunan!=string::npos)
			{
				cout << line << endl;
			}
		}
		myfile.close();
	}
	else 
	{
		cout << "Unable to open file";
	}
}

//OGRETIM ELEMANI LISTELEME (BOLUME GORE)
void ogretimElemaniListele(string bolum)
{
	string line;
	ifstream myfile;
	myfile.open("ogretimElemani.txt");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			string aranan(bolum);
			size_t bulunan;
			bulunan=line.rfind(aranan);
			if(bulunan!=string::npos)
			{
				cout << line << endl;
			}
		}
		myfile.close();
	}
	else 
	{
		cout << "Unable to open file";
	}	
}

//OGRETIM ELEMANI DUZELTME (SICIL NUMARASINA GORE)
void ogretimElemaniDuzenle(string sicil_numara){
	string line, ad, soyad, bolum;
	ifstream myfile;
	ofstream myfile1;
	myfile.open("ogretimElemani.txt");
	myfile1.open("gecici.txt" , ios::app);
	if(myfile.is_open())
	{
		cout << "##########################################" << "\n";
		cout << "Ogretim Elemani Adi Giriniz: " ; 
		cin >> ad ;
		cout << "Ogretim Elemani Soyadini Giriniz: ";
		cin >> soyad ;
		cout << "Ogretim Elemani Bölümünü Giriniz: ";
		cin >> bolum ;
		cout << "##########################################" << "\n";
		while(getline(myfile,line))
		{
			string aranan(sicil_numara);
			size_t bulunan;
			bulunan=line.rfind(aranan);
			if(bulunan!=string::npos)
			{
				
				cout << "Kayýt basarili bir sekilde guncellendi:)))" << endl;
				myfile1 << ad << "\t" << soyad << "\t" << sicil_numara <<endl;
			}
			else{
				myfile1 << line << endl;
			}
		}
		myfile.close();
		myfile1.close();
		remove("ogretimElemani.txt");
		rename("gecici.txt","ogretimElemani.txt"); //isim degistiriyor		
	}
	else 
	{
		cout << "Unable to open file";
	}	
}


//DERS FONKSIYONLARI
//DERS KAYIT
void dersKayit(string ders_adi, string ders_kodu, string ogretimElemaniAdi, string ogretimElemaniSoyadi)
{
	ofstream myfile;
	myfile.open("ders.txt", ios::app);
	myfile << ders_adi << "\t" << ders_kodu << "\t" << ogretimElemaniAdi << "\t" << ogretimElemaniSoyadi << endl;
	cout << "Ders Eklendi..." << "\n";	
	myfile.close();	
}

//DERS LISTELEME
void dersListele(string ders_adi)
{
	string line;
	ifstream myfile;
	myfile.open("ders.txt");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			string aranan(ders_adi);
			size_t bulunan;
			bulunan=line.rfind(aranan);
			if(bulunan!=string::npos)
			{
				cout << line << endl;
			}
		}
		myfile.close();
	}
	else 
	{
		cout << "Unable to open file";
	}
}

//DERS ARAMA (DERS ADINA GORE)
void dersAra(string ders_adi)
{
	string line;
	ifstream myfile;
	myfile.open("ders.txt");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			string aranan(ders_adi);
			size_t bulunan;
			bulunan=line.rfind(aranan);
			if(bulunan!=string::npos)
			{
				cout << line << endl;
			}
		}
		myfile.close();
	}
	else 
	{
		cout << "Unable to open file";
	}
}

//DERS DUZELTME (DERS KODUNA GORE)
void dersKoduDuzenle(string ders_kodu){
	string line, ders_adi, ogretimElemaniAdi, ogretimElemaniSoyadi;
	ifstream myfile;
	ofstream myfile1;
	myfile.open("ders.txt");
	myfile1.open("gecici.txt" , ios::app);
	if(myfile.is_open())
	{
		cout << "#########################################\n"; 
		cout << "Dersin Adini Giriniz: " ; 
		cin >>  ders_adi;
		cout << "Dersi veren Ogretim Elemaninin Adini Giriniz: ";
		cin >> ogretimElemaniAdi ;
		cout << "Dersi Veren Ogretim Elemaninin Soyadini Giriniz: ";
		cin >> ogretimElemaniSoyadi;
		cout << "##########################################" << "\n";
		while(getline(myfile,line))
		{
			string aranan(ders_kodu);
			size_t bulunan;
			bulunan=line.rfind(aranan);
			if(bulunan!=string::npos)
			{
				
				cout << "Kayýt basarili bir sekilde guncellendi:)))" << endl;
				myfile1 << ders_adi << "\t" << ders_kodu <<  "\t" << ogretimElemaniAdi << "\t" << ogretimElemaniSoyadi <<endl;
			}
			else{
				myfile1 << line << endl;
			}
		}
		myfile.close();
		myfile1.close();
		remove("ders.txt");
		rename("gecici.txt","ders.txt"); //isim degistiriyor		
	}
	else 
	{
		cout << "Unable to open file";
	}	
}


//NOT MODULU FONKSIYONLARI
//OGRENCIYE DERS KAYIT
void notDersKayit(string ders_adi, string ders_kodu, string ad, string soyad, string ogretimElemaniAdi, string ogretimElemaniSoyadi)
{
	ofstream myfile;
	myfile.open("not.txt", ios::app);
	myfile << ders_adi << "\t" << ders_kodu << "\t" << ad << "\t" << soyad << "\t" <<  ogretimElemaniAdi << "\t" << ogretimElemaniSoyadi << endl;
	cout << "Ders Eklendi..." << "\n";	
	myfile.close();		
}

//OGRENCIYE NOT EKLEME
void ogrenciAldigiNotKayit(string numara, string ders_adi, string ogrenci_notu){
	ofstream myfile;
	myfile.open("not.txt", ios::app);
	myfile << numara << "\t" << ders_adi << "\t" << ogrenci_notu << endl;
	cout << "Not Eklendi..." << "\n";	
	myfile.close();	
}

//OGRENCI KARNESI GORUNTULEME
void karneGoruntule(string numara)
{
	string line;
	ifstream myfile;
	myfile.open("not.txt");
	cout << "***Numara\tDers Adi\tNot***\n";
	
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			string aranan(numara);
			size_t bulunan;
			bulunan=line.rfind(aranan);
			if(bulunan!=string::npos)
			{
				cout << line << endl;
			}
		}
		myfile.close();
	}
	else 
	{
		cout << "Unable to open file";
	}
}
