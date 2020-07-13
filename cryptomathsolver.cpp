#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string.h>
using namespace std;

//variable
int pilih,num;
string kembali;
char plaintext[50];

//modular exponentation function
int modexp(int a, unsigned int b, int n) 
{ 
    int r = 1;

    a = a % n;
    if (a == 0)
    {
        return 0;
    }

    while (b > 0) 
    { 
        if (b & 1)
        {
          r = (r*a) % n; 
        }
        b = b>>1;
        a = (a*a) % n; 
    } 
    return r; 
} 

//modinv
int modInverse(int a, int n) 
{ 
	a = a%n; 
	for (int x=1; x<n; x++)
    {
        if ((a*x) % n == 1)
        {
            return x;
        }
    }
    return 0;
}

//prime check
int prime(int num)
{
   for(int i = 2; i <= num / 2; i++) 
   {
      if(num % i == 0) 
	  {
         cout<<num<<" is not a prime number" << endl;
         break;
      }
      else
      cout<<num<<" is a prime number" << endl;
      return num;
   }
   return 0;
}

//enc rsa
int enc(int e, int n)
{
    char cipher[50];
    cout << "Ciphertext : ";
    int z = strlen(plaintext);
    for (int i=0; i < z; i++)
    {
        int x = plaintext[i];
        int c = modexp(x,e,n);
        cipher[i] = c;
        cout << c << " ";
    }
    cout << endl;
    return 0;
}

//rsa
int rsa(int p, int q, int e)
{
    cout << "======================" << endl;
    int n = p*q;
    cout << "nilai n : " << n << endl;
    int lcm = (p-1)*(q-1);
    cout << "nilai lcm : " << lcm << endl;
    int d = modInverse(e,lcm);
    cout << "nilai d : " << d << endl;
    cout << "======================" << endl;
    cout << "Plaintext : ";
    cin >> plaintext;
    enc(e,n);
    return 0;
}
//enkripsi elgamal
int enk(int y,int k,int p )
{
	char cipher[50];
    cout << "Ciphertext : ";
    int z = strlen(plaintext);
    for (int i=0; i < z; i++)
    {
        int x = plaintext[i];
        unsigned long int pw = pow(y,k);
        unsigned long int c = x % p;
        cipher[i] = c;
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
//elgamal
int elgamal(int p,int g,int k)
{
    cout << "======================" << endl;
    unsigned long int q=pow(g,k);
    int y=q%p;
    cout << "kunci publik : " << y << endl;
    cout << "Plaintext : ";
    cin >> plaintext;
    enk(p,g,k);
    return 0;
}

//rumus kunci publik dh
long long int rumusk(long long int a, long long int b, long long int P) 
{ 
	long long int t;
	if (b == 1) 
		return a; 
	t = rumusk(a, b/2, P);
	if(b%2==0)
		return (t*t)%P;
	else
		return (((t*t)%P)*a)%P;
}

//pertukaran kunci publik dh
long long int kpdh (long long int P, long long int G, long long int x, long long int a, long long int y, long long int b, long long int ka, long long int kb)
{
	x = rumusk(G, a, P);
	y = rumusk(G, b, P);
	
	ka = rumusk(y, a, P);
	kb = rumusk(x, b, P);
    return ka,kb;
}

//title banner
void title()
{
    cout << R"(

 .----------------.    .----------------.    .----------------.
| .--------------. |  | .--------------. |  | .--------------. |
| |     ______   | |  | | ____    ____ | |  | |    _______   | |
| |   .' ___  |  | |  | ||_   \  /   _|| |  | |   /  ___  |  | |
| |  / .'   \_|  | |  | |  |   \/   |  | |  | |  |  (__ \_|  | |
| |  | |         | |  | |  | |\  /| |  | |  | |   '.___`-.   | |
| |  \ `.___.'\  | |  | | _| |_\/_| |_ | |  | |  |`\____) |  | |
| |   `._____.'  | |  | ||_____||_____|| |  | |  |_______.'  | |
| |              | |  | |              | |  | |              | |
| '--------------' |  | '--------------' |  | '--------------' |
 '----------------'    '----------------'    '----------------'
                       Crypto Math solver
)" << endl;
}

//rsa title
void rsa_title()
{
    cout << R"(

____/\\\\\\\\\_________/\\\\\\\\\\\_______/\\\\\\\\\____        
 __/\\\///////\\\_____/\\\/////////\\\___/\\\\\\\\\\\\\__       
  _\/\\\_____\/\\\____\//\\\______\///___/\\\/////////\\\_      
   _\/\\\\\\\\\\\/______\////\\\_________\/\\\_______\/\\\_     
    _\/\\\//////\\\_________\////\\\______\/\\\\\\\\\\\\\\\_    
     _\/\\\____\//\\\___________\////\\\___\/\\\/////////\\\_   
      _\/\\\_____\//\\\___/\\\______\//\\\__\/\\\_______\/\\\_  
       _\/\\\______\//\\\_\///\\\\\\\\\\\/___\/\\\_______\/\\\_ 
        _\///________\///____\///////////_____\///________\///__
    )" << endl;
}

//elgamal title
void el_title()
{
    cout << R"(
  ______ _      _____          __  __          _      
 |  ____| |    / ____|   /\   |  \/  |   /\   | |     
 | |__  | |   | |  __   /  \  | \  / |  /  \  | |     
 |  __| | |   | | |_ | / /\ \ | |\/| | / /\ \ | |     
 | |____| |___| |__| |/ ____ \| |  | |/ ____ \| |____ 
 |______|______\_____/_/    \_\_|  |_/_/    \_\______|                                           
    )" << endl;
}

//modinv title
void modinv_title()
{
    cout << R"(

          /\       __   __  __           _   _   _ 
     /\  |/\|     /_ | |  \/  |         | | | \ | |
    /  \     ______| | | \  / | ___   __| | |  \| |
   / /\ \   |______| | | |\/| |/ _ \ / _` | | . ` |
  / ____ \         | | | |  | | (_) | (_| | | |\  |
 /_/    \_\        |_| |_|  |_|\___/ \__,_| |_| \_|
                    
                    Modular Inversion
    )" << endl;
}

//modexp title
void modexp_title()
{
    cout << R"(

     _   /\ ____    __  __           _   _   _ 
    / \ |/\| __ )  |  \/  | ___   __| | | \ | |
   / _ \   |  _ \  | |\/| |/ _ \ / _` | |  \| |
  / ___ \  | |_) | | |  | | (_) | (_| | | |\  |
 /_/   \_\ |____/  |_|  |_|\___/ \__,_| |_| \_|

               Modular Exponentation
)" << endl;
}

//prime title
void prime_title()
{
    cout << R"(                                                                                                                                     
                      ,,                            
`7MM"""Mq.            db                            
  MM   `MM.                                         
  MM   ,M9 `7Mb,od8 `7MM  `7MMpMMMb.pMMMb.  .gP"Ya  
  MMmmdM9    MM' "'   MM    MM    MM    MM ,M'   Yb 
  MM         MM       MM    MM    MM    MM 8M"""""" 
  MM         MM       MM    MM    MM    MM YM.    , 
.JMML.     .JMML.   .JMML..JMML  JMML  JMML.`Mbmmd'                                                                                 
)" << endl;
}

int main()
{
    menu:
        system("clear");
        title();
        cout<<"[1] Rsa"<<endl;
        cout<<"[2] Elgamal"<<endl;
        cout<<"[3] Pertukaran Kunci Publik Diffie Helman"<<endl;
        cout<<"[4] Modular Exponen"<<endl;
        cout<<"[5] Modular Inverse"<<endl;
        cout<<"[6] Prime Number"<<endl;
        cout << endl;
        cout << "--> ";
        cin >> pilih;

        switch (pilih)
        {
            case 1:
            {
                rsa:
                    system("clear");
                    int p, q, e;
                    rsa_title();
                    cout << "input p : ";
                    cin >> p;
                    cout << "input q : ";
                    cin >> q;
                    cout << "input e : ";
                    cin >> e;
                    rsa(p,q,e);
                    cout << endl <<"=================" << endl << endl;
                    cout << "[back] goto menu" << endl;
                    cout << "[] go to top" << endl ;
                    cout << "[ctrl-c] exit program" << endl << endl;
                    cout << "--> ";
                    cin >> kembali;
                    if (kembali == "back")
                    {
                        goto menu;
                    }else
                    {
                        goto rsa;
                    }
            }
            case 2:
            {
                elgamal:
                    system("clear");
                    int p, g, k;
                    el_title();
                    cout << "input p : ";
                    cin >> p;
                    cout << "input g : ";
                    cin >> g;
                    cout << "input kunci privat : ";
                    cin >> k;
                    elgamal(p,g,k);
                    cout << endl <<"=================" << endl << endl;
                    cout << "[back] goto menu" << endl;
                    cout << "[] go to top" << endl ;
                    cout << "[ctrl-c] exit program" << endl << endl;
                    cout << "--> ";
                    cin >> kembali;
                    if (kembali == "back")
                    {
                        goto menu;
                    }else
                    {
                        goto elgamal;
                    }
            }
            case 3:
            {
                kpdh:
				system("clear");
				cout << "##### Pertukaran Kunci Publik Diffie Helman #####" << endl;
				cout << "** Nilai P dan Kunci Privat bersifat Bilangan Prima, P > Kunci Privat **" << endl;
				cout << "================="<< endl;
				long long int P, G, x, a, y, b, ka, kb; 
				cout << "Input Nilai P (Bilangan Pemodulo) : ";
				cin >> P;
				cout << "Input Nilai G : ";
				cin >> G;
				cout << "Input Nilai Kunci Privat(Alice) : ";
				cin >> a;
				cout << "Input Nilai Kunci Privat(Bob) : ";
				cin >> b;
				cout << "Kunci Rahasia Alice : " << kpdh(P, G, x, a, y, b, ka, kb) << endl;
				cout << "Kunci Rahasia Bob : " << kpdh(P, G, x, a, y, b, ka, kb) << endl;
				cout << endl <<"=================" << endl << endl;
                    cout << "[back] goto menu" << endl;
                    cout << "[] go to top" << endl ;
                    cout << "[ctrl-c] exit program" << endl << endl;
                    cout << "--> ";
                    cin >> kembali;
                    if (kembali == "back")
                    {
                        goto menu;
                    }else
                    {
                        goto kpdh;
                    }
            }
            case 4:
            {
                modexp:
                    system("clear");
                    modexp_title();
                    int a,b,n;
                    cout << "input a : ";
                    cin >> a;
                    cout << "input b : ";
                    cin >> b;
                    cout << "input n : ";
                    cin >> n;
                    cout << "result  : " << modexp(a,b,n);
                    cout << endl <<"=================" << endl << endl;
                    cout << "[back] goto menu" << endl;
                    cout << "[] go to top" << endl ;
                    cout << "[ctrl-c] exit program" << endl << endl;
                    cout << "--> ";
                    cin >> kembali;
                    if (kembali == "back")
                    {
                        goto menu;
                    }else
                    {
                        goto modexp;
                    }
                    
            }
            case 5:
            {
                modinv:
                    system("clear");
                    modinv_title();
                    int a, n;
                    cout << "a : ";
                    cin >> a;
                    cout << "n : ";
                    cin >> n;
                    cout << "reslut : "<< modInverse(a, n);
                    cout << endl <<"=================" << endl << endl;
                    cout << "[back] goto menu" << endl;
                    cout << "[] go to top" << endl ;
                    cout << "[ctrl-c] exit program" << endl << endl;
                    cout << "--> ";
                    cin >> kembali;
                    if (kembali == "back")                    {
                        goto menu;
                    }else
                    {
                        goto modinv;
                    }
            }
            case 6:
            {
                prime :
                    system("clear");
                    prime_title();
                    cout<<"Masukkan Angka : ";
                    cin>>num;
                    prime(num);
                    cout << endl <<"=================" << endl << endl;
                    cout << "[back] goto menu" << endl;
                    cout << "[] go to top" << endl ;
                    cout << "[ctrl-c] exit program" << endl << endl;
                    cout << "--> ";
                    cin >> kembali;
                    if (kembali == "back")                    
                    {
                        goto menu;
                    }else
                    {
                        goto prime;
                    }
            
            }
        }
}
