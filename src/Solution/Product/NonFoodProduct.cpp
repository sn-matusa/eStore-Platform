#include "NonFoodProduct.h"

NonFoodProduct::NonFoodProduct():Product()
{
	producer=string("");
	yearsOfWarranty=0;
	price=0;
}

NonFoodProduct::NonFoodProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int quantity) : Product(category, id, name, quantity)
{
	this->producer=producer;
	this->yearsOfWarranty=yearsOfWarranty;
	this->price=price;
}

NonFoodProduct::NonFoodProduct(const NonFoodProduct &pn) : Product(pn)
{
	this->producer=pn.producer;
	this->yearsOfWarranty=pn.yearsOfWarranty;
	this->price=pn.price;
}

void NonFoodProduct::setYearsOfWarranty(int garantieAni)
{
	this->yearsOfWarranty=garantieAni;
}

void NonFoodProduct::setPrice(float price)
{
	this->price=price;
}

void NonFoodProduct::setProducer(const string &producer)
{
	this->producer=producer;
}

int NonFoodProduct::getYearsOfWarranty()
{
	return yearsOfWarranty;
}

float NonFoodProduct::getPrice()
{
	return price;
}

string &NonFoodProduct::getProducer()
{
	return producer;
}

bool NonFoodProduct::operator==(const NonFoodProduct &obj) const
{
	if(this->producer==obj.producer && this->yearsOfWarranty==obj.yearsOfWarranty && this->price==obj.price && category==obj.category && quantity==obj.quantity && id==obj.id && name==obj.name )
		return true;
	return false;
}

const NonFoodProduct &NonFoodProduct::operator=(const NonFoodProduct &a)
{
	(Product&)(*this)=a;
	if(this!=&a)
	{
		this->producer=a.producer;
		this->yearsOfWarranty=a.yearsOfWarranty;
		this->price=a.price;
	}
	return *this;
}

string NonFoodProduct::getProductType()
{
	return string("nonalimentar");
}

json NonFoodProduct::toJSON()
{
	return json(*this);
}

void NonFoodProduct::display()
{
	cout << "Product Nealimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl
		 << endl;
}
