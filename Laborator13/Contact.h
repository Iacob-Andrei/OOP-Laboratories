#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum tip_contact
{
	prieten = 1,
	cunoscut = 2,
	coleg = 3
};

class Contact
{
protected:
	string nume;
	int tipContact;

public:
	virtual string getNume() = 0;
	virtual int getTipContact() = 0;
};


class Prieten : public Contact
{
	string numar_telefon;
	string data_nastere;
	string adresa;

public:
	Prieten(string Nume, string nrTel, string dataNastere, string Adresa)
	{
		nume = Nume;
		numar_telefon = nrTel;
		data_nastere = dataNastere;
		adresa = Adresa;
		tipContact = 1;
	}

	string getNume()
	{
		return nume;
	}

	string getNumarTelefon()
	{
		return numar_telefon;
	}

	int getTipContact()
	{
		return tipContact;
	}
};

class Cunoscut : public Contact
{
	string numar_telefon;

public:
	Cunoscut(string Nume, string nrTel)
	{
		nume = Nume;
		numar_telefon = nrTel;
		tipContact = 2;
	}

	string getNume()
	{
		return nume;
	}

	int getTipContact()
	{
		return tipContact;
	}
};

class Coleg : public Contact
{
	string numar_telefon;
	string firma;
	string adresa;

public:
	Coleg(string Nume, string nrTel, string Firma, string Adresa)
	{
		nume = Nume;
		numar_telefon = nrTel;
		firma = Firma;
		adresa = Adresa;
		tipContact = 3;
	}

	string getNume()
	{
		return nume;
	}

	int getTipContact()
	{
		return tipContact;
	}
};


class Agenda
{
	vector<Contact*> lista_contacte;

public:

	void add_contact(Contact* newContact)
	{
		lista_contacte.push_back(newContact);
	}

	void delete_contact(string NUME)
	{
		for (int i = 0; i < lista_contacte.size(); i++)
		{
			if ((*lista_contacte[i]).getNume() == NUME)
			{
				lista_contacte.erase(lista_contacte.begin() + i);
			}
		}
	}

	void afisareLista()
	{	
		for (auto it : *this)
			cout << it->getNume() << " " << it->getTipContact() << endl;
	}

	vector<Contact*> listaDePrieteni()
	{
		vector<Contact*> lista_prieteni;

		for (auto it : *this)
		{
			if (it->getTipContact() == 1)
			{
				lista_prieteni.push_back(it);
			}
		}
		return lista_prieteni;
	}

	bool find_nume(string NUME)
	{
		for (auto it : *this)
		{
			if (it->getNume() == NUME)
				return true;
		}
		return false;
	}

	vector<Contact*>::iterator begin()
	{
		return lista_contacte.begin();
	}

	vector<Contact*>::iterator end()
	{
		return lista_contacte.end();
	}

};