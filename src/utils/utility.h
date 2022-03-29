#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../Solution/Product/NonFoodProduct.h"
#include "../Solution/Product/FoodProduct.h"

#include "../Solution/User/PremiumUser.h"

class Utility{

public:
    static bool compare_list(Product* , Product*); 
    static bool compare_list2(Product* , Product*); 
    static bool compare_user_by_county(User*, User*);
    static bool compare_user_by_id(User*, User*);
};