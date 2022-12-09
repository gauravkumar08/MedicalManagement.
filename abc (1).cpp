// Group 08 (SRM Medical Management System)
// Gaurav Kumar(AP21110010355)


#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <dirent.h>
#define n 8
using namespace std;

class hospital
{
	string disease, name, m_q, price, medid, age,s_id;
	char *find;
	float total;

public:
	string get_id()
	{
		cout << "Medicine id : ";
		cin >> medid;
		return medid;
	}
	void get_data();
	void display_one_patient_data();
	void display_all_patient_data();
	void write_data();
	void display_all_patient_list();
	bool check_exist(string id);
	void remove_data();
	void modify_data();
};
void hospital::display_all_patient_data()
{
	string data;
	ifstream read("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\data.txt");
	while (getline(read, data))
		cout << data << endl;
	read.close();
}
void hospital ::display_all_patient_list()
{
	string data;
	ifstream read("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\data.txt");
	while (getline(read, data))
	{
		if (data.substr(0,14) == "Medicine id : ")
		{
			cout << data << endl;
		}
	}
	read.close();
}
void hospital ::write_data()
{
	ofstream write("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\data.txt", std::ios_base::app);
	write << "Medicine id : " << medid << endl;
	write << "Patient Name : " << name << endl;
	write << "Patient age : " << age << endl;
	write << "Disease : " << disease << endl;
	write << "supplier id : " << s_id << endl;
	write << "Medicine Price : " << price << endl;
	write << "Medicine Quanity : " << m_q << endl;
	write << "Total price : " << (atoi(price.c_str())*atoi(m_q.c_str())) << endl;
	write << endl;
	write.close();
}
void hospital ::remove_data()
{
	string data;
	int count = n+1;
	cout << "To remove data enter the ";
	get_id();
	ofstream writet("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\temp.txt");
	ifstream read("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\data.txt");
	while (getline(read, data))
	{
		// cout<<data;
		if (data == "Medicine id : " + medid || (count > 0 && count != n+1))
			count--;
		else
		{
			writet << data << endl;
		}
	}

	writet.close();
	read.close();

	ofstream write("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\data.txt");
	ifstream readt("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\temp.txt");
	while (getline(readt, data))
	{
		write << data << endl;
	}
	if (count == n+1)
		cout << "No data found to remove" << endl;
	else
		cout << "data removed successfully ";
	readt.close();
	write.close();
	// remove("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\temp.txt");
}

void hospital ::modify_data()
{
	string data;
	int count = n;
	cout << "To modify the data enter existing ";
	string check=get_id();
	ofstream writet("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\temp.txt");
	ifstream read("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\data.txt");
	while (getline(read, data))
	{
		if (data == "Medicine id : " + check || (count > 0 && count != n))
			count--;
		else
		{
			writet << data << endl;
		}
		if (count == 0)
		{
			cout << "Enter new ";
			while (check_exist(get_id()))
			{
				cout << "Entered id is already exist" << endl;
				cout << "Enter different ";
			}
			get_data();
			// writet << endl;
			writet << "Medicine id : " << medid << endl;
			writet << "Patient Name : " << name << endl;
			writet << "Patient age : " << age << endl;
			writet << "Disease : " << disease << endl;
			writet << "supplier id : " << s_id << endl;
			writet << "Medicine Price : " << price << endl;
			writet << "Medicine Quantity : " << m_q << endl;
			writet << "Total price : " << total << endl;

			count = -1;
		}
	}
	writet.close();
	read.close();
	ofstream write("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\data.txt");
	ifstream readt("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\temp.txt");
	while (getline(readt, data))
	{
		write << data << endl;
	}
	if (count == n)
		cout << "No data found to modify" << endl;
	else
		cout << "data modified successfully " << endl;
	readt.close();
	write.close();
	remove("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\temp.txt");
}
void hospital ::get_data()
{
	cout << "Patient Name : ";
	cin.sync();
	getline(cin, name);
	cout << "Patient age : ";
	cin >> age;
	cout << "Disease : ";
	cin>>disease;
	cin.sync();
	cout << "supplier id : ";
	cin.sync();
	getline(cin,s_id);
	cout << "Medicine Price : ";
    cin.sync();
	cin >> price;
	total=atoi(price.c_str());
	cout << "medicine quantity : ";
	cin>>m_q;
	total*=atoi(m_q.c_str());
}

void hospital ::display_one_patient_data()
{
	string data;
	int count = n;
	get_id();
	ifstream read("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\data.txt");
	while (getline(read, data))
		if (data == "Medicine id : " + medid)
		{
			while (count)
			{
				cout << data << endl;
				getline(read, data);
				count--;
			}
			read.close();
			return;
		}
	cout << "No data found" << endl;
	read.close();
}
bool hospital::check_exist(string id)
{
	string data;
	ifstream read("C:\\Users\\Lenovo\\Desktop\\Program\\txt_data\\data.txt");
	while (getline(read, data))
		if (data == "Medicine id : " + id)
		{
			read.close();
			return true;
		}
	read.close();
	return false;
}

int main()
{
	int ch;
	hospital emp;
	system("cls");
	while (1)
	{
		cout << "\nselect the option:\n";
		cout << "\n1) To add Medicine data" << endl
			 << "2) To remove Medicine data" << endl
			 << "3) Modify the Medicine data" << endl
			 << "4) Display one Medicine data" << endl
			 << "5) Display all Medicine data" << endl
			 << "6) List of all medicine"<<endl
			 << "7) quit\n\nEnter the option-->";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case 1:
			if (emp.check_exist(emp.get_id()))
				cout << "data already exists";
			else
			{
				emp.get_data();
				emp.write_data();
			}
			break;

		case 2:
			emp.remove_data();
			break;

		case 3:
			emp.modify_data();
			break;

		case 4:
			emp.display_one_patient_data();
			break;

		case 5:
			emp.display_all_patient_data();
			break;

		case 6:
			emp.display_all_patient_list();
			break;

		case 7:
			return 0;

		default:
			cout << "Enter correct option \n\n";
		}
	}
	return 0;
};
