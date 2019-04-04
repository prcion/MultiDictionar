//iterator unidirectional pe un Container
#pragma once
#include "MultiDictionar.h"
#include <iostream>
#include <exception>

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;


class IteratorMD {
	friend class MD;
	friend class NodCheie;
	friend class NodValoare;
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorMD(const MD& container);

	//contine o referinta catre containerul pe care il itereaza
	const MD& cont;
	NodCheie* curent;
	/* aici e reprezentarea specifica a iteratorului*/

public:

	//reseteaza pozitia iteratorului la inceputul containerului
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	TElem element() const;

};
