#include "MultiDictionar.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
MD::MD()
{
	/*
	 Complexitatea
		Teta(1)
	 */
	this->head = nullptr;
	this->lungcheie = 0;
	this->lungval = 0;
}

void MD::adauga(TCheie c, TValoare v)
{
	/*
	 n = lungimea key-lor
	 m = lungimea valorilor din key
	 Complexitatea
		Teta(n)
	 */
	NodCheie* new_nod = new NodCheie(c);
	NodValoare* new_val = new NodValoare(v);
	new_nod->next = nullptr;
	new_val->next = nullptr;
	if (this->head == nullptr)
	{
		new_nod->pr = new_val;
		new_nod->next = head;
		this->head = new_nod;
		this->lungcheie += 1;
		this->lungval += 1;
		return;
	}
	NodCheie* curent = head;
	int aux = 1;
	while (curent->next != nullptr)
	{
		if (curent->val == c)
		{
			new_val->next = curent->pr;
			curent->pr = new_val;
			aux = 0;
			this->lungval += 1;
			return;
		}
		else
			curent = curent->next;	
	}

	if (curent->val == c)
	{

		new_val->next = curent->pr;
		curent->pr = new_val;
		aux = 0;
		this->lungval += 1;
		return;
	}
	if (aux != 0)
	{
		new_nod->pr = new_val;
		curent->next = new_nod;
		curent->next->pr->next = nullptr;
		this->lungcheie += 1;
		this->lungval += 1;
	}
}

vector<TValoare> MD::cauta(TCheie c) const
{
	/*
	 n = lungimea key-lor
	 m = lungimea valorilor din key
	 Complexitatea
		O(n * m)
	 */
	vector <TCheie> v;
	NodCheie* curent = head;
	while (curent != nullptr && curent->val != c)
		curent = curent->next;
	if (curent != nullptr)
	{
		NodValoare* curentValori = curent->pr;
		while (curentValori != nullptr)
		{
			v.push_back(curentValori->val);
			curentValori = curentValori->next;
		}
	}
	return v;
}

vector<TValoare> MD::colectiaValorilor() const
{
	/*
	 n = lungimea key-lor
	 m = lungimea valorilor din key
	 Complexitatea
		Teta(n * m)
	 */
	vector <TValoare> valori;
	NodCheie* curent = head;
	while (curent != nullptr)
	{
		NodValoare* curentValori = curent->pr;
		while (curentValori != nullptr)
		{
			valori.push_back(curentValori->val);
			curentValori = curentValori->next;
		}
		curent = curent->next;
	}
	return valori;
}

bool MD::sterge(TCheie c, TValoare v)
{
	/*
	 n = lungimea key-lor
	 m = lungimea valorilor din key
	 Complexitatea
		O(m)
	 */
	bool ok = false;
	bool ver = vid();
	if (ver == true)
		return false;
	//cout << c << " " << v << ' ';
	if (head->val == c)
	{
		NodCheie* curent = head;
		if (curent->pr->val == v)
		{
			NodValoare* v = curent->pr;
			curent->pr = curent->pr->next;
			this->lungval--;
			delete v;
			ok = true;
		}
		else {
			NodValoare* v1 = curent->pr;
			while (v1->next != nullptr && v1->next->val != v)
				v1 = v1->next;
			if (v1->next != nullptr)
			{
				NodValoare* v18 = v1->next;
				if (v18->val == v)
				{
					NodValoare* for_del = v18;
					v1->next = v1->next->next;
					delete for_del;
					this->lungval--;
					ok = true;
				}
			}
		}
		if (curent->pr == nullptr && ok == true)
		{
			head = head->next;
			delete curent;
			this->lungcheie--;
			ok = true;
		}
		return ok;
	}
	NodCheie* elem = head;
	while (elem->next != nullptr && elem->next->val != c)
	{
		elem = elem->next;
	}
	if (elem->next != nullptr)
	{
		//cout << 2;
			NodValoare* curent1 = elem->next->pr;
			if (curent1->val == v)
			{
				
				elem->next->pr = elem->next->pr->next;
				this->lungval--;
				delete curent1;
				ok = true;
			}
			else
			{
				NodValoare* v1 = elem->next->pr;
				while (v1->next != nullptr && v1->next->val != v)
					v1 = v1->next;
				if (v1->next != nullptr)
				{
					//cout << 1;
					NodValoare* v18 = v1->next;
					if (v18->val == v)
					{
						NodValoare* for_del = v18;
						v1->next = v1->next->next;
						delete for_del;
						this->lungval--;
						ok = true;
					}
				}
			}
			
			if (elem->next->pr == nullptr)
			{
				NodCheie* for_delete = elem->next;
				elem->next = elem->next->next;
				this->lungcheie--;
				delete for_delete;
				ok = true;
			}
		
	}



	return ok;
}

int MD::dim() const
{
	/*
	 Complexitatea
		Teta(1)
	 */
	return this->lungval;
}

bool MD::vid() const
{
	/*
	 Complexitatea
		Teta(1)
	 */

	if (this->head == nullptr)
		return true;
	return false;
}

IteratorMD MD::iterator() const
{
	return IteratorMD(*this);
}

MD::~MD()
{
	/*
	 n = lungimea key-lor
	 m = lungimea valorilor din key
	 Complexitatea
		Teta(n * m)
	 */
	while (head != nullptr)
	{
		NodCheie* nod = head;
		while (nod->pr != nullptr)
		{
			NodValoare* valoare = nod->pr;
			nod->pr = nod->pr->next;
			delete valoare;
		}
		head = head->next;
		delete nod;
	}
}

NodCheie::NodCheie(TCheie val)
{
	/*
	 Complexitatea
		Teta(1)
	 */

	this->val = val;
}

NodValoare::NodValoare(TValoare val)
{
	/*
	 Complexitatea
		Teta(1)
	 */

	this->val = val;
}
