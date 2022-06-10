#include <iostream>
#include <vector>
#include <string>
using namespace std;

class student
{
	public:
		~student(){}
		student();
		string name;
	  string cnp;
};

student::student()
{
	name = "";
	cnp = "";
}


void bubbleSort(student a[],int n)
{
  student temp;
	bool swap = true;
	while(swap)
	{
		swap = false;
		for(int i = 0; i <n - 1; i++)
		{
      string aux = a[i].cnp.substr(1,2);
      int year1 = stoi(aux);
      aux = a[i+1].cnp.substr(1,2);
      int year2 = stoi(aux);

      aux = a[i].cnp.substr(3,4);
      int month1 = stoi(aux);
      aux = a[i+1].cnp.substr(3,4);
      int month2 = stoi(aux);

      aux = a[i].cnp.substr(5,6);
      int day1 = stoi(aux);
      aux = a[i+1].cnp.substr(5,6);
      int day2 = stoi(aux);

			if( year1 > year2)
			{
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				swap = true;
			}
      else if (year1 == year2)
      {
        if(month1 > month2)
        {
          temp = a[i];
          a[i] = a[i+1];
          a[i+1] = temp;
          swap = true;
        }
        else if (month1 == month2)
        {
          if(day1 > day2)
          {
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
            swap = true;
          }
        }
      }
		}
	}
}



int main()
{
	student *stud = new student[10];
	string name;
	string cnp;
	int n;

	cout << " Enter number of student: ";
	cin >> n;
	cin.get();

	for(int i = 0; i < n; i++)
	{
		cout <<"Enter name : ";
    getline(cin, name);
    cout <<"Enter cnp : ";
    getline(cin, cnp);

		stud[i].name = name;
    stud[i].cnp = cnp;
	}

	bubbleSort(stud,n);

  for(int i = 0; i < n ; i++)
  {
    cout << stud[i].name << endl;
  }


	return 0;
}
