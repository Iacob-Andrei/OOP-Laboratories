#include "Contact.h"

int main()
{
	cout << endl << "[ Tip contact : Prieten = 1 | Cunoscut = 2 | Coleg = 3]" << endl << endl;

	Agenda Ag;
	Ag.add_contact(new Prieten("Ana", "0712345678", "01.01.2001", "Str. Soarelui"));
	Ag.add_contact(new Coleg("Andrei", "0744556677", "SC. Andrei", "Str. Mihai Viteazu"));
	Ag.add_contact(new Cunoscut("Elena", "0799663322"));
	Ag.add_contact(new Prieten("Gabi", "0711223344", "08.10,1999", "Str. Kogalniceanu"));
	Ag.add_contact(new Cunoscut("Mariana", "0748591536"));

	Ag.afisareLista();
	cout << endl;

	Ag.delete_contact("Elena");
	Ag.afisareLista();

	if (Ag.find_nume("Bogdan") == true)
		cout << endl << "Numele Bogdan s-a gasit in agenda." << endl;
	else
		cout << endl << "Numele Bogdan NU s-a gasit in agenda." << endl;


	cout << endl << "Lista de prieteni:" << endl;
	vector<Contact*> vector_de_prieteni;
	vector_de_prieteni = Ag.listaDePrieteni();

	for (auto it : vector_de_prieteni)
		cout << it->getNume() << endl;

	return 0;
}