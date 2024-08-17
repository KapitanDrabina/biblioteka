#include <iostream>
#include <vector>
using namespace std;

class ksiazka
{
    private:
        int id;
        string tytul;
        string autor;
        int data;
        int egzemplarz;

    public:
        void wstawianie_danych()
        {
            cout << "Podaj ID: ";
            cin >> id;
            cout << endl;

            cout << "Podaj tytuł: ";
            cin >> tytul;
            cout << endl;

            cout << "Podaj autora: ";
            cin >> autor;
            cout << endl;

            cout << "Podaj datę: ";
            cin >> data;
            cout << endl;

            cout << "Podaj egzemplarz: ";
            cin >> egzemplarz;
            cout << endl;
        }  
        void wyswietlanie_danych()
        {
            cout << " +" << endl;
            cout << " | ID: " << id << endl;
            cout << " | Tytuł: " << tytul << endl;
            cout << " | Autor: " << autor << endl;
            cout << " | Data: " << data << endl;
            cout << " | Egzemplarz: " << egzemplarz << endl;
            cout << " +" << endl;
        }
};

int main()
{
    vector<ksiazka> biblioteka;

    bool uzywanie = true;
    while (uzywanie == true)
    {
        cout << "Co chcesz zrobić?" << endl;
        cout << "   1 - Dodać nową książkę" << endl;
        cout << "   2 - Edytować dane istniejącej książki" << endl;
        cout << "   3 - Przejrzeć istniejące zapisane książki" << endl;
        cout << "   4 - Zakończyć program" << endl << endl;

        int akcja;
        cin >> akcja;
        cout << endl;

        if (akcja>4 or akcja<0)
        {
            cout<< "Podaj poprawny numerek" << endl << endl;
        }
        else if (akcja == 4)
        {
            break;
        }
        else if (akcja == 1)
        {
            ksiazka ksiazka1;
            ksiazka1.wstawianie_danych();
            biblioteka.push_back(ksiazka1);
        }
        else if (akcja == 3)
        {
            for(int i = 0; i < biblioteka.size(); i = i + 1)
            {
                biblioteka[i].wyswietlanie_danych();
                cout << endl;
            }
        }
        else if (akcja == 2)
        {
            int numer;
            for(int i = 0; i < biblioteka.size(); i = i + 1)
            {
                cout << (i+1) << ". " << endl;
                biblioteka[i].wyswietlanie_danych();
                cout << endl;
            }
            cout << "Którą książkę chcesz edytować? (Podaj numer) ";
            cin >> numer;
            numer = numer - 1;
            biblioteka[numer].wstawianie_danych();
        }
    }
    return 0;
}