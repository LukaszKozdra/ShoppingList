#include <string>
#include "Product.hpp"
#include "List.hpp"

namespace lk {

void ErrWrongName::what() {
    std::cout << "You dont provide proper name" << std::endl;
}

void ErrWrongAmount::what() {
    std::cout << "You provide wrong amount" << std::endl;
}

void ErrWrongPrice::what() {
    std::cout << "You provide wrong price" << std::endl;
}

Product::Product(std::string n, int a, double p) {
    setName(n);
    setAmount(a);
    setPrice(p);
}

Product::Product() {
    setName("Unknown");
    setAmount(0);
    setPrice(0);
}

void Product::setName(std::string n) {
    if(n.empty()){
        m_name = "Unknown";
        throw ErrWrongName();                    
    }else{
        m_name = n;
    }
}

void Product::setAmount(int a) {
    if(a <= 0){
        m_amount = 0;
        throw ErrWrongAmount();                 
    }else{
        m_amount = a;
    }
}

void Product::setPrice(double p) {
    if(p < 0){
        m_price = 0;                  
        throw ErrWrongPrice();                  
    }else{
        m_price = p;
    }
}

std::string Product::getName() const {
    return m_name;
}

int Product::getAmount() const {
    return m_amount;
}

double Product::getPrice() const {
    return m_price;
}

double Product::getPriceOfAll() const {
    return m_price * m_amount;
}

}