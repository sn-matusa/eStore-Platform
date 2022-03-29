#include "utility.h"

 bool Utility::compare_list  (Product* p1, Product* p2)
{
    NonFoodProduct* p11= dynamic_cast<NonFoodProduct*>(p1);
    NonFoodProduct* p21= dynamic_cast<NonFoodProduct*>(p2);
    if(p11->getPrice()<p21->getPrice())
        return true;
    return false;
}

 bool Utility::compare_list2 (Product* p1, Product* p2)
{
    FoodProduct* p11= dynamic_cast<FoodProduct*>(p1);
    FoodProduct* p21= dynamic_cast<FoodProduct*>(p2);
    if(p11->getName()<p21->getName())
        return true;
    else if (p11->getName()==p21->getName() && p11->getCountryOfOrigin()<p21->getCountryOfOrigin())
        return true;
    else if(p11->getName()==p21->getName() && p11->getCountryOfOrigin()==p21->getCountryOfOrigin() && p11->getLeiPerKg()<p21->getLeiPerKg())
        return true;
    return false;
}

bool Utility::compare_user_by_county(User* u1, User* u2)
{
    if( (u1->getDeliveryData()).getCounty() < (u2->getDeliveryData()).getCounty() )
        return true;
    return false;
}

bool Utility::compare_user_by_id(User* u1, User* u2)
{
    if(u1->getUserID()<u2->getUserID())
        return true;
    return false;
}