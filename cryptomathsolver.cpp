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
int modInverse(int a, int m) 
{ 
	a = a%m; 
	for (int x=1; x<m; x++)
    {
        if ((a*x) % m == 1)
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

int main()
{
    menu:
        system("clear");
        title();
	coba_lagi:
        cout<<"[1] Rsa"<<endl;
        cout<<"[2] Elgamal"<<endl;
        cout<<"[3] Curva Eliptik"<<endl;
        cout<<"[4] Modular Exponen"<<endl;
        cout<<"[5] Modular Inverse"<<endl;
        cout<<"[6] Prime Check"<<endl;
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
                    cout << "rsa" << endl;
                    cout << "================="<< endl;
                    cout << "input p : ";
                    cin >> p;
                    cout << "input q : ";
                    cin >> q;
                    cout << "input e : ";
                    cin >> e;
                    rsa(p,q,e);
                    cout << endl <<"=================" << endl << endl;
                    cout << "[back] goto menu" << endl;
                    cout << "[] go to top" << endl << endl;
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
                system("clear");
                    int p, g, k;
                    cout << "rsa" << endl;
                    cout << "================="<< endl;
                    cout << "input p : ";
                    cin >> p;
                    cout << "input g : ";
                    cin >> g;
                    cout << "input kunci privat : ";
                    cin >> k;
                    elgamal(p,g,k);
                    cout << endl <<"=================" << endl << endl;
                    cout << "[back] goto menu" << endl;
                    cout << "[] go to top" << endl << endl;
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
                cout << "kurva";
                break;
            }
            case 4:
            {
                modexp:
                    system("clear");
                    cout << "##### Modular Eksponen #####" << endl;
                    cout << "================="<< endl;
                    int a,b,n;
                    cout << "input a : ";
                    cin >> a;
                    cout << "input b : ";
                    cin >> b;
                    cout << "input n : ";
                    cin >> n;
                    cout << "hasil : " << modexp(a,b,n);
                    cout << endl <<"=================" << endl << endl;
                    cout << "[back] goto menu" << endl;
                    cout << "[] go to top" << endl << endl;
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
                    cout << "modinv" << endl;
                    int a, m;
                    cout << "a = ";
                    cin >> a;
                    cout << "m = ";
                    cin >> m;
                    cout << modInverse(a, m);
                    cout << endl <<"=================" << endl << endl;
                    cout << "[back] goto menu" << endl;
                    cout << "[] go to top" << endl << endl;
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
                    cout << "##### Prime Check #####" << endl;
                    cout << "||||||||||||||||||||" << endl;
                    cout << "VVVVVVVVVVVVVVVVVVVV" << endl;
                    cout<<"Masukkan Angka : ";
                    cin>>num;
                    prime(num);
                    cout << endl <<"=================" << endl << endl;
                    cout << "[back] goto menu" << endl;
                    cout << "[] go to top" << endl << endl;
                    cout << "--> ";
                    cin >> kembali;
                    if (kembali == "back")                    {
                        goto menu;
                    }else
                    {
                        goto prime;
                    }
            }
                    default:
            {
                cout << "Maaf Inputan Tidak Terdapat Dalam Pilihan" << endl;
                cout << "Silahkan Coba Lagi \n";
                goto coba_lagi;
            }
        }
}
