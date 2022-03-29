#include "Server.h"

using namespace std;

/* NU MODIFICATI */
Server::Server() {}

/* NU MODIFICATI */
Server *Server::GetInstance()
{
	if (!instance)
	{
		instance = new Server;
	}

	return instance;
}

/* NU MODIFICATI */
Server::~Server()
{
	if (instance != NULL)
		instance = NULL;

	if (!__UserID__ProductsCart__.empty())
		__UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__()
{
	int tp;

	list<User *>::iterator p = usr.begin();

	while (p != usr.end())
	{
		tp = (*p)->getUserID();
		__UserID__ProductsCart__[tp] = new ShoppingCart();
		p++;
	}
}

list<Product *> &Server::getProductsList()
{
	return prod;
}

list<User *> &Server::getUsersList()
{
	return usr;
}

map<int, ShoppingCart *> Server::get__UserID__ProductsCart__()
{
	return __UserID__ProductsCart__;
}

bool Server::requestAddProduct(int userID, int productID, int quantity)
{
	list<Product *>::iterator it;
	list<User *>::iterator ite;

	int ok = 0, quant;

	if (quantity <= 0)    ///verific daca cantitatea este mai mare ca 0
		return false;

	it = getProductsList().begin();     ///pentru a verifica daca produsul exista in magazin
	while (it != getProductsList().end())
	{
		if (productID == (*it)->getId())
		{
			ok = 1;
			quant = (*it)->getQuantity();
			if (quant>quantity)
			{
				(*it)->decreaseQuantity(quantity);  /// daca exista ii actualizez si stoc conform cantitatii cerute.
			}
			else if(quant==quantity)    
			{
				(*it)->setQuantity(0); 
			}
			else 
				return false;
		}
		it++;
	}
	if (ok == 0)
		return false;

	ok = 0;
	ite = getUsersList().begin();
	
	while (ite != getUsersList().end())        ///verific daca user-ul exista 
	{
		if (userID == (*ite)->getUserID())
			ok = 1;
		ite++;
	}
	if (ok == 0)
		return false;

	ok = __UserID__ProductsCart__[userID]->getQuantity(productID);

	if (quant >= quantity) // daca magazinul are pe stoc cantitatea cerutata de utilizator
	{
		if (ok == -1)     /// daca utilizatorul nu are produsul in cos
		{
			__UserID__ProductsCart__[userID]->addProduct(productID, quantity);
			return true;
		}
		else           //// daca utilizatorul are o parte din produs in cos
		{
			__UserID__ProductsCart__[userID]->raiseQuantity(productID, quantity);
			return true;
		}
	}
	return false;
}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
	list<Product *>::iterator it;
	list<User *>::iterator ite;

	int ok = 0, quant;

	if (quantity <= 0)    ///verific daca cantitatea este mai mare ca 0
		return false;

	it = getProductsList().begin();     
	while (it != getProductsList().end())        ///verific daca produsul exista
	{
		if (productID == (*it)->getId())
		{
			ok = 1;
			quant = __UserID__ProductsCart__[userID]->getQuantity(productID);
			if(quant==-1)
				return false;
			if(quant>quantity)
				(*it)->increaseQuantity(quantity);     ///actualizez cantitatea din stoc
			else 
				(*it)->increaseQuantity(quant);
		}
		it++;
	}
	if (ok == 0)
		return false;

	ok = 0;
	ite = getUsersList().begin();
	while (ite != getUsersList().end())       ///verific daca user-ul exista 
	{
		if (userID == (*ite)->getUserID())
			ok = 1;
		ite++;
	}
	if (ok == 0)
		return false;
	
	if (quant > quantity)
	{
		__UserID__ProductsCart__[userID]->lowerQuantity(productID, quantity);
		return true;
	}
	else
	{
		__UserID__ProductsCart__[userID]->deleteProduct(productID);           /// in caz ca cantitatea ceruta este egala cu cantitatea din stoc, sterg produsul
		return true;
	}
}

/* NU MODIFICATI */
void Server::populateProducts(const json &input)
{
	prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

/* NU MODIFICATI */
void Server::populateUsers(const json &input)
{
	usr = ObjectFactory::getUserList(input["useri"]);
}