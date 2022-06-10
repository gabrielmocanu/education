#include <iostream>
#include <string>
using namespace std;

class autovehicul
{
	public:
		autovehicul();
		~autovehicul(){}
		void setModel(string model) { this -> model = model; }
		void setPasageri(int nrPasageri) { this -> nrPasageri = nrPasageri; }
		void setConsum(int consum) { this -> consum = consum; }
    string getModel() { return this -> model; }
    int getPasageri() { return this -> nrPasageri; }
    int getConsum() { return this -> consum; }
    string model;
		int nrPasageri;
		int consum;
};


autovehicul::autovehicul()
{
	nrPasageri = 0;
	consum = 0;
}

void bubbleSort(autovehicul a[], int n)
{
	bool swap = true;
	while(swap)
	{
		swap = false;
		for(int i = 0; i < n - 1; i++)
		{
			if((float)a[i].nrPasageri/a[i].consum < (float)a[i+1].nrPasageri/a[i+1].consum)
			{
				autovehicul temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				swap = true;
			}
		}
	}
}



int main()
{

  autovehicul *masina = new autovehicul[10];
  string model;
	int nrPasageri;
	int consum;
	int n;

	cout << " Enter number of vehicle: ";
	cin >> n;
	cin.get();

	for(int i = 0; i < n; i++)
	{
		cout <<"Enter model : ";
    getline(cin, model);
    cout <<"Enter pasageri : ";
    cin >> nrPasageri;
    cout <<"Enter consm : ";
    cin>> consum;

//    masina[i].setModel(model);
//    masina[i].setPasageri(nrPasageri);
//    masina[i].setConsum(consum);

    masina[i].model = model;
    masina[i].nrPasageri = nrPasageri;
    masina[i].consum = consum;

    cin.get();
	}

	bubbleSort(masina,n);


	for(int i = 0;i<3;i++)
	{
		cout << masina[i].model << endl;
	}
	return 0;
}
