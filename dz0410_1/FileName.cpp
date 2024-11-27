#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

struct PIB
{
    string Surname;
    string Name;
};

class PhoneBook
{
public:
    PhoneBook() = default;
    ~PhoneBook() = default;

    PhoneBook Enter(PhoneBook object, string objname)
    {
        object.objname = objname;
        cout << "Enter Surname: ";
        cin >> object.Pib.Surname;
        cout << "Enter Name: ";
        cin >> object.Pib.Name;
        cout << "Enter Home Number: ";
        cin >> object.HomeNum;
        cout << "Enter Work Number: ";
        cin >> object.WorkNum;
        cout << "Enter Mobile Number: ";
        cin >> object.Mobile;
        cout << "Enter Details: ";
        cin >> object.Details;
        return object;
    }

    vector<PhoneBook> Delete(vector<PhoneBook>& v, int num)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (i == num)
            {
                v.erase(v.begin() + i);
            }
        }
        return v;
    }

    void FindByName(vector<PhoneBook>& vec, string surname, string name)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i].Pib.Surname == surname && vec[i].Pib.Name == name)
            {
                cout << "Phone name: " << vec[i].objname << endl;
                cout << "Surname: " << vec[i].Pib.Surname << endl;
                cout << "Name: " << vec[i].Pib.Name << endl;
                cout << "Home Number: " << vec[i].HomeNum << endl;
                cout << "Work Number: " << vec[i].WorkNum << endl;
                cout << "Mobile Number: " << vec[i].Mobile << endl;
                cout << "Details: " << vec[i].Details << endl;
                cout << "------------------" << endl;
            }
        }
    }

    void PrintInf(vector<PhoneBook> vec)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << "Phone name: " << vec[i].objname << endl;
            cout << "Surname: " << vec[i].Pib.Surname << endl;
            cout << "Name: " << vec[i].Pib.Name << endl;
            cout << "Home Number: " << vec[i].HomeNum << endl;
            cout << "Work Number: " << vec[i].WorkNum << endl;
            cout << "Mobile Number: " << vec[i].Mobile << endl;
            cout << "Details: " << vec[i].Details << endl;
        }
    }

    void savetofile(vector<PhoneBook> vec, string filename)
    {
        ofstream out(filename);
        for (int i = 0; i < vec.size(); i++)
        {
            out << vec[i].objname << endl;
            out << vec[i].Pib.Surname << endl;
            out << vec[i].Pib.Name << endl;
            out << vec[i].HomeNum << endl;
            out << vec[i].WorkNum << endl;
            out << vec[i].Mobile << endl;
            out << vec[i].Details << endl;
        }
    }

    vector<PhoneBook> getfromfile(string filename)
    {
        vector<PhoneBook> vec; PhoneBook phones;
        ifstream in(filename);
        while (!in.eof())
        {
            in >> phones.objname;
            in >> phones.Pib.Surname;
            in >> phones.Pib.Name;
            in >> phones.HomeNum;
            in >> phones.WorkNum;
            in >> phones.Mobile;
            in >> phones.Details;
            vec.push_back(phones);
        }
        in.close();
        vec.pop_back();
        return vec;
    }

private:
    string objname;
    PIB Pib;
    int HomeNum;
    int WorkNum;
    int Mobile;
    string Details;
};

vector<string> vectors(vector<PhoneBook>& v)
{
    int amount; string ObjName; vector<string> names;
    cout << "How much objects would you like to create: "; cin >> amount;
    for (int i = 0; i < amount; i++)
    {
        cout << "Enter object name: "; cin >> ObjName;
        names.push_back(ObjName);
        PhoneBook ObjName;
        v.push_back(ObjName);
    }
    return names;
}

void Start()
{
    cout << "0. Print all" << endl;
    cout << "1. Create New" << endl;
    cout << "2. Delete Number" << endl;
    cout << "3. Save to file" << endl;
    cout << "4. Get from file" << endl;
    cout << "5. Find by Name" << endl;
    cout << "6. Exit" << endl;
    cout << "Your choice: ";
}

vector<PhoneBook> vec;

int main()
{
    PhoneBook phones;
    int choice; int num;
    vector<PhoneBook> vec;
    bool active = true;
    string filename; string surname, Name;
    vector<string> name;
    while (active)
    {
        Start(); cin >> choice;
        switch (choice)
        {
        case 0:
            phones.PrintInf(vec);
            break;
        case 1:
            name = vectors(vec);
            for (int i = 0; i < vec.size(); i++)
            {
                vec.push_back(vec[i].Enter(vec[i], name[i]));
            }
            break;
        case 2:
            cout << "Enter phone num you would like to delete: "; cin >> num;
            phones.Delete(vec, num);
            break;
        case 3:
            cout << "Enter filename: "; cin >> filename;
            phones.savetofile(vec, filename);
            break;
        case 4:
            cout << "Enter filename: "; cin >> filename;
            vec = phones.getfromfile(filename);
            break;
        case 5:
            cout << "Enter surname, name: "; cin >> surname >> Name;
            phones.FindByName(vec, surname, Name);
            break;
        case 6:
            active = false;
            break;
        default:
            break;
        }
    }
}
