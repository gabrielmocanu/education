#include <iostream>
#include <vector>
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
		string model;
		int nrPasageri;
		int consum;
};


autovehicul::autovehicul()
{
	nrPasageri = 0;
	consum = 0;
}

void bubbleSort(vector<autovehicul> &a)
{
	bool swap = true;
	while(swap)
	{
		swap = false;
		for(int i = 0; i < a.size() - 1; i++)
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

	vector<autovehicul> list;
	string model;
	int nrPasageri;
	int consum;
	int n;

	cout << " Enter number of vehicle: ";
	cin >> n;
	cin.get();

	autovehicul *automobil;

	for(int i = 0; i < n; i++)
	{
		cout <<"Enter model : ";
    getline(cin, model);
    cout <<"Enter pasageri : ";
    cin >> nrPasageri;
    cout <<"Enter consm : ";
    cin>> consum;

		automobil = new autovehicul;
		automobil->model = model;
		automobil->nrPasageri = nrPasageri;
		automobil->consum = consum;
		list.push_back(*automobil);
		cin.get();
	}

	bubbleSort(list);

	vector<autovehicul>::iterator it;

	for(int i = 0;i<n;i++)
	{
		cout << list[i].model << endl;
	}
	return 0;
}
