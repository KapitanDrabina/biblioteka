#include <iostream>
#include <vector>
using namespace std;
 
 class Ksiazka
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
            setId();
            cout << endl;
 
            setTytul();
            cout << endl;
 
            setAutor();
            cout << endl;
 
            setDate();
            cout << endl;
 
            setEgzemplarz();
            cout << endl;
        }  
        void setId()
        {
            cout << "Podaj ID: ";
            cin >> this->id;
            cin.ignore();
        }
        void setTytul()
        {
            cout << "Podaj tytuł: ";
            getline(cin, this->tytul);
        }
        void setAutor()
        {
            cout << "Podaj autora: ";
            getline(cin, autor);
            int spacja = autor.find(" ");

            autor[0] = toupper(autor[0]);

            for(int i = 1; i<=spacja; i++)
            {
                autor[i] = tolower(autor[i]);
            }

            autor[spacja+1] = toupper(autor[spacja+1]);

            for(int i = spacja + 2; i<autor.length(); i++)
            {
                autor[i] = tolower(autor[i]);
            }

            this->autor = autor;
        }
        void setDate()
        {
            cout << "Podaj datę: ";
            cin >> this->data;
        }
        void setEgzemplarz()
        {
            cout << "Podaj egzemplarz: ";
            cin >> this->egzemplarz;
        }
        void wyswietlanie_danych()
        {
            cout << " +" << endl;
            cout << " | ID: " << this->id << endl;
            cout << " | Tytuł: " << this->tytul << endl;
            cout << " | Autor: " << this->autor << endl;
            cout << " | Data: " << this->data << endl;
            cout << " | Egzemplarz: " << this->egzemplarz << endl;
            cout << " +" << endl;
        }
 
        int getId()
        {
            return this->id;
        }
};

class Biblioteka
{
    private:
        vector<Ksiazka> ksiazki;
 
    public:
        void showAllKsiazki()
        {
            for(int i = 0; i < ksiazki.size(); i++) 
            {
                ksiazki[i].wyswietlanie_danych();
                cout << endl;
            }
        } 
 
        void showKsiazka(int id)
        {
            for(Ksiazka ksiazka : this->ksiazki) 
            {
                if(ksiazka.getId() == id) 
                {
                    ksiazka.wyswietlanie_danych();
                }
            }
        }

        void addKsiazka(Ksiazka ksiazka)
        {
            this->ksiazki.push_back(ksiazka);
        }

        void editKsiazka()
        {
            int numer;
            for(int i = 0; i < ksiazki.size(); i = i + 1)
            {
                cout << (i+1) << ". " << endl;
                ksiazki[i].wyswietlanie_danych();
                cout << endl;
            }
            cout << "Którą książkę chcesz edytować? (Podaj numer) ";
            cin >> numer;
            numer = numer - 1;
            ksiazki[numer].wstawianie_danych();
        }

        void editAutor()
        {
            int numer;
            for(int i = 0; i < ksiazki.size(); i = i + 1)
            {
                cout << (i+1) << ". " << endl;
                ksiazki[i].wyswietlanie_danych();
                cout << endl;
            }
            cout << "Autora Której książki chcesz edytować? (Podaj numer) ";
            cin >> numer;
            numer = numer - 1;
            ksiazki[numer].setAutor();
        }
};
 

 
int main()
{
    //rozwiazanie poprawne, ale malo rozwojowe lepiej dodac klase biblioteki przechowujaca ksiazki
    // vector<ksiazka> biblioteka;
    Biblioteka biblioteka;
 
    while (0 == 0)
    {
        cout << "Co chcesz zrobić?" << endl;
        cout << "   1 - Dodać nową książkę" << endl;
        cout << "   2 - Edytować dane istniejącej książki" << endl;
        cout << "   3 - Przejrzeć istniejące zapisane książki" << endl;
        cout << "   4 - Zakończyć program" << endl;
        cout << "   5 - Zmienić autora wybranej książki" << endl << endl;
 
        int akcja;
        cin >> akcja;
        cout << endl;
 
        if (akcja>5 or akcja<0)
        {
            cout<< "Podaj poprawny numerek" << endl << endl;
        }
        else if (akcja == 4)
        {
            break;
        }
        else if (akcja == 1)
        {
            Ksiazka ksiazka1;
            ksiazka1.wstawianie_danych();
            biblioteka.addKsiazka(ksiazka1);
        }
        else if (akcja == 3)
        {
            biblioteka.showAllKsiazki();
        }
        else if (akcja == 2)
        {
            biblioteka.editKsiazka();
        }
        else if (akcja == 5)
        {
            biblioteka.editAutor();
        }
    }
    return 0;
}