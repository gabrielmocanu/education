#include <iostream>
#include <vector>
#include <string>
using namespace std;

class student
{
	public:
		student();
		~student(){}
		string name;
		int anStudiu;
		int notaPOO;
    int notaPC;
    int notaSDA;
};


student::student()
{
	anStudiu = 0;
	notaPC = 0;
  notaPOO = 0;
  notaSDA = 0;
}

void bubbleSort(student a[], int n)
{
	bool swap = true;
	while(swap)
	{
		swap = false;
		for(int i = 0; i < n - 1; i++)
		{
      float medie1 = (float)a[i].notaPC + a[i].notaPOO + a[i].notaSDA;
      medie1 = (float)medie1/3;
      float medie2 = (float)a[i+1].notaPC + a[i+1].notaPOO + a[i+1].notaSDA;
      medie2 = (float)medie2/3;
			if( medie1 < medie2)
			{
				student temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				swap = true;
			}
		}
	}
}



int main()
{
	student *stud = new student[10];
	string name;
	int anStudiu;
	int notaPC;
  int notaPOO;
  int notaSDA;
	int n;

	cout << " Enter number of student: ";
	cin >> n;
	cin.get();


	for(int i = 0; i < n; i++)
	{
		cout <<"Enter name : ";
    getline(cin, name);
    cout <<"Enter year of study : ";
    cin >> anStudiu;
    cout <<"Enter notaPC : ";
    cin>> notaPC;
    cout <<"Enter notaPOO : ";
    cin >> notaPOO;
    cout << "Enter notaSDA : ";
    cin >> notaSDA;


		stud[i].name = name;
		stud[i].anStudiu = anStudiu;
		stud[i].notaPC = notaPC;
    stud[i].notaPOO = notaPOO;
    stud[i].notaSDA = notaSDA;
		cin.get();
	}

	bubbleSort(stud,n);

  vector<int> ani;
  for(int i = 1; i <= 2; i++)
    ani.push_back(i);


	for(int i = 0;i<n;i++)
	{
    if(stud[i].notaPC >= 5 && stud[i].notaPOO >= 5 && stud[i].notaSDA >= 5 )
		{
      for(int j = 0; j < ani.size(); j++)
      {
        if(stud[i].anStudiu == ani[j])
        {
            float medie = (float)stud[i].notaPC + stud[i].notaPOO + stud[i].notaSDA;
            medie = (float)medie/3;
            cout << stud[i].name << " " << stud[i].anStudiu << " " << medie << endl;
            ani.erase(ani.begin()+j);
        }
      }
	   }
   }

	 bool ok1 = true;
	 bool ok2 = true;

	 for(int i = 0; i < n;i++)
	 {
		 if(stud[i].notaPC >= 5 && stud[i].notaPOO >= 5 && stud[i].notaSDA >= 5 && stud[i].anStudiu == 1 && ok1 == true)
		 	{
				float medie = (float)stud[i].notaPC + stud[i].notaPOO + stud[i].notaSDA;
				medie = (float)medie/3;
				cout << stud[i].name << " " << stud[i].anStudiu << " " << medie << endl;
				ok1 = false;
			}
			if(stud[i].notaPC >= 5 && stud[i].notaPOO >= 5 && stud[i].notaSDA >= 5 && stud[i].anStudiu == 2 && ok2 == true)
 		 	{
 				float medie = (float)stud[i].notaPC + stud[i].notaPOO + stud[i].notaSDA;
 				medie = (float)medie/3;
 				cout << stud[i].name << " " << stud[i].anStudiu << " " << medie << endl;
				ok2 = false;
 			}

	 }
	return 0;
}
