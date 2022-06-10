#include <iostream>
#include <string>

using namespace std;

class produs
{
  public:
    produs();
    ~produs(){}
    string name;
    string model;
    int pret;
};

produs::produs()
{
  name = "";
  model = "";
  pret = 0;
}

void bubbleSort(produs a[], int n)
{
  bool swap = true;
  while(swap)
  {
    swap = false;
    for(int i = 0; i < n-1; i++)
    {
      if(a[i].pret > a[i+1].pret)
      {
        produs temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
        swap = true;
      }
      }
    }
  }

int main()
{
  produs *prod = new produs[10];
  string name;
  string model;
  int pret;
  int n;
  int valPrag;

  cout << "Introdu numarul de produse: ";
  cin >> n;

  cout << "Introdu valoarea de prag: ";
  cin >> valPrag;
  cin.get();

  for(int i = 0; i < n ;i++)
  {
    cout << "Introdu numele: ";
    getline(cin, name);
    cout << "Introdu model: ";
    getline(cin, model);
    cout << "Introdu pret: ";
    cin >> pret;
    cin.get();

    prod[i].name = name;
    prod[i].model = model;
    prod[i].pret = pret;
  }

  bubbleSort(prod,n);

  for(int i = 0; i<n ; i++)
  {
    if(prod[i].pret < valPrag)
    {
      cout << prod[i].name << " " << prod[i].model << " " << prod[i].pret << endl;
    }
  }
  return 0;
}
