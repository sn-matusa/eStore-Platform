#include "QuerySolver.h"

using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver()
{
  server = Server::GetInstance();
}

/* NU MODIFICATI */
QuerySolver::~QuerySolver()
{
  if (server != nullptr)
  {
    server = nullptr;
  }
}

list<Product *> QuerySolver::Query_3a()
{
  list<Product *> lista = server->getProductsList();
  list<Product *>::iterator it = lista.begin();
  list<Product *> exp;
  int a, b, id;
  while (it != lista.end())
  {
    id = (*it)->getId();
    while (id > 99)
      id = id / 10;
    b = id % 10;
    a = id / 10;

    if (a == 3 && b == 9)
      exp.push_back(*it);
    it++;
  }
  return exp;
}

list<User *> QuerySolver::Query_3b()
{
  list<User *> lista = server->getUsersList();
  list<User *>::iterator it = lista.begin();
  list<User*> us;
  while (it!=lista.end())
  {
    if((*it)->getUserType()==string("nonpremium") && (*it)->getTransportCost()<=11.5)
      us.push_back(*it);
    it++;
  }
  return us;
}

list<Product *> QuerySolver::Query_3c()
{
  list<Product*> lista= server->getProductsList();
  list<Product*>::iterator it=lista.begin();
  list<Product*> p;

  while (it!=lista.end())
  {
    ResealedProduct* res = dynamic_cast<ResealedProduct*>(*it);
    if(res!=nullptr)
      if(res->getReason()==string("lipsa_accesorii"))
       p.push_back(res);
    it++;
  }
  p.sort(Utility::compare_list);
  return p;
}

list<Product *> QuerySolver::Query_3d()
{
  list<Product*> lista= server->getProductsList();
  list<Product*>::iterator it=lista.begin();
  list<Product*> p;
  
  while(it!=lista.end())
  {
    int id=(*it)->getId();
    while(id>9)
      id=id/10;
    if(id==1)
      p.push_back(*it);
    it++;
  }

  p.sort(Utility::compare_list2);

  return p;
}

list<User *> QuerySolver::Query_3e()
{
  list<User*> lista=server->getUsersList();
  list<User*>::iterator it=lista.begin();
  list<User*> us;
 
  while(it!=lista.end())
  {
    if(((*it)->getBillingData()).getCounty()==((*it)->getDeliveryData()).getCounty())
     us.push_back(*it);
    it++;
  }

  us.sort(Utility::compare_user_by_county);

  it=us.begin();

  string jud=((*it)->getDeliveryData()).getCounty();
  int nr_users=1,max_nr_users=0;;
  string jud_max=jud;

  for(it=us.begin();it!=us.end();it++)   ///parcurg lista de useri deja ordonata dupa judet pentru a alfa cel mai poplat judet
  {
    if(((*it)->getDeliveryData()).getCounty()!=jud)
      {
        if(max_nr_users<nr_users)
          {
          max_nr_users=nr_users;
          jud_max=jud;
          }
        nr_users=1;
        jud=((*it)->getDeliveryData()).getCounty();
      }
      else
      {
        nr_users++;
      }
  }
  it=us.begin();
  list<User*> uss;
  while(it!=us.end())
  {
    if(((*it)->getDeliveryData()).getCounty()==jud_max)
       if( ((*it)->getDeliveryData()).getBlock()==string("-") && ((*it)->getDeliveryData()).getApartment()==0 )
         uss.push_back(*it);
    it++;
  }
  uss.sort(Utility::compare_user_by_id);
  return uss;
}

list<User *> QuerySolver::Query_3f()
{
  list<User*>lista=server->getUsersList();
  list<Product*> lista2=server->getProductsList();
  list<User*> premium_list;
  list<User*> premium_list2;
  list<Product*> list_tel_imp;

  
  int id, ok=0;

  ///creez o lista de produse cu telefoane si imprimante
  list<Product*>::iterator iter=lista2.begin();
  while(iter!=lista2.end())
  {
    id=(*iter)->getId();
    while(id>99)
      id=id/10;
    if(id/10!=1)  
      if(id%10 == 1 || id%10 == 6)
       list_tel_imp.push_back(*iter);
    iter++;
  }

  ///creez o lista cu userii premium
  list<User*>::iterator it=lista.begin();
  while(it!=lista.end())
  {
   PremiumUser* pm=dynamic_cast<PremiumUser*>(*it);
   if(pm!=nullptr)
    premium_list.push_back(pm);
   it++;
  }
  ///parcurg lista de useri premium
  it=premium_list.begin();
  while(it!=premium_list.end())
  {
    PremiumUser* pm=dynamic_cast<PremiumUser*>(*it);
    map<int,int>::iterator ite=(pm->getDiscounts()).begin();
    ok=0;
    while(ite!=(pm->getDiscounts()).end())  ///parcurg map ul de discounts
    {
      id=ite->first;
      while(id>99)
        id=id/10;
      if(id/10!=1)    /// daca produsul nu e alimentar
       if(id%10==1 || id%10==6)   /// daca am gasit un telefon sau o imprimanta
        {
          iter=list_tel_imp.begin();
          while(iter!=list_tel_imp.end())
            {
             if(ite->first==(*iter)->getId())
               ok=1;
              iter++;
            }
        }
      ite++;
    }
    if(ok==1)
      premium_list2.push_back(*it);
    it++;
  }
  return premium_list2;
}
