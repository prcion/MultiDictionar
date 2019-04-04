#include "IteratorMD.h"
typedef std::pair<TCheie, TValoare> TElem;
IteratorMD::IteratorMD(const MD& container): cont(container)
{
	this->curent = cont.head;
}


TElem IteratorMD::element() const
{
	pair <TCheie, TValoare> f;
	if (curent != nullptr  && curent->pr != nullptr)
	{
		f = make_pair(curent->val, curent->pr->val);
		return f;
	}
}

void IteratorMD::prim()
{
	this->curent = cont.head;
}

void IteratorMD::urmator()
{
	if (curent != nullptr)
	{
		if (curent->pr->next == nullptr)
			curent = curent->next;
		else
			curent->pr = curent->pr->next;
	}
}

bool IteratorMD::valid() const
{
	return curent != nullptr;
}
