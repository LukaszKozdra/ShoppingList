#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "List.hpp"
#include "Product.hpp"


namespace lk {

void ErrNoExistingProduct::what() {
    std::cout << std::endl << "This product doesnt exist in your shopping list !!!" << std::endl;   
}

void ErrWrongAmountToDel::what() {
    std::cout << std::endl << "You provide wrong amount" << std::endl;
}

void List::addProduct(const Product &p) {
    for(auto it = list.begin(); it != list.end(); it++){
        if(it->getName() == p.getName()){
            it->setAmount(/*it->getAmount() + */p.getAmount());
            it->setPrice(/*it->getPrice() +*/ p.getPrice());
            return;
        }           
    }
    list.push_back(p);
}

void List::delProduct(std::string nameToFind){
    if(nameToFind.empty()){
        throw ErrNoExistingProduct();
        return;
    }

    bool productFound = false;
    for(auto it = list.begin(); it != list.end(); it++){
        if(it->getName() == nameToFind){
            list.erase(it);
            productFound = true;
            return;
        }
    }

    if(!productFound){
        throw ErrNoExistingProduct();
        return;       
    }
}

void List::delProductNameAmout(std::string nameToFind, int amountToDel){
    if(amountToDel < 0){
        throw ErrWrongAmountToDel();         
        return;               
    }

    bool productFound = false;
    for(auto it = list.begin(); it != list.end(); it++){
        if(it->getName() == nameToFind &&  amountToDel >= it->getAmount()){
            list.erase(it);
            productFound = true;
            return;
        }else if (it->getName() == nameToFind &&  amountToDel < it->getAmount()){
            it->setAmount(it->getAmount() - amountToDel);
            productFound = true;
            return;
        }
    }

    if(!productFound){
        throw ErrNoExistingProduct();
        return;          
    }
}

void List::delWholeList(){
    list.clear();
}

void List::showList() const {
    double sum {};
    std::cout << std::endl << "SHOPING LIST" << std::endl;

    std::cout << std::left << std::setw(20) << "Product name:" << 
    std::right << std::setw(15) << "Amount:" <<  
    std::right << std::setw(15) << "Price:" << std::endl; 

    for(auto &itList : list){
    std::cout << std::left << std::setw(20) << itList.getName() << 
    std::right << std::setw(15) << itList.getAmount() <<  
    std::right << std::setw(15) << itList.getPrice() << std::endl; 
    sum += itList.getPrice() * itList.getAmount();
    }
    std::cout << std::left << std::setw(20) << "Total: "<< sum << std::endl;
}

}
