#pragma once

#include <vector>
#include "IteratorMD.h"
using namespace std;
typedef int TCheie;
typedef int TValoare;
typedef std::pair<TCheie, TValoare> TElem;

class MD {
	friend class IteratorMD;
	friend class NodCheie;
	friend class NodValoare;
private:

	NodCheie* head;

	int lungcheie;
	int lungval;

public:

	// constructorul implicit al MultiDictionarului
	MD();

	// adauga o pereche (cheie, valoare) in MD	
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	vector<TValoare> colectiaValorilor() const;
	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MD 
	int dim() const;

	//verifica daca MultiDictionarul e vid 
	bool vid() const;

	// se returneaza iterator pe MD
	IteratorMD iterator() const;

	// destructorul MultiDictionarului	
	~MD();

};

class NodCheie
{
	friend class MD;
	friend class NodValoare;
	friend class IteratorMD;
private:
	TCheie val;
	NodCheie* next;
	NodValoare* pr;
	NodCheie(TCheie val);
};

class NodValoare
{
	friend class MD;
	friend class NodCheie;
	friend class IteratorMD;
private:
	TValoare val;
	NodValoare* next;
	NodValoare(TValoare val);
};
