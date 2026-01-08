#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "Product.hpp"

namespace lk {

/**
 * \brief Exception thrown when product name doesnt exist on list.
 *
 * This exception is thrown when user provides an invalid string
 * product name.
 */    
struct ErrNoExistingProduct {
    /**
     * \brief Print information about no existing product.
     */
    void what();
};

/**
 * \brief Exception thrown when amount of to delete is incorrect.
 *
 * This exception is thrown when user provides amount to delete
 * lower than 0.
 */
struct ErrWrongAmountToDel {
    /**
     * \brief Print information about wrong provided amount to delete.
     */
    void what();
};

/**
 * \brief Represent a list of products.
 *
 * This class can represent the list of Product objects. Its
 * provides methods to modify and show list. 
 */
class List {
private:
    /**
     *\brief Contains Product type objects.
     * 
     * By default its empty.
    */
    std::vector<Product> list;
public:
    /**
     * \brief Add new product to list.
     *
     * \param p Product type object.
     */
    void addProduct(const Product &p);

    /**
     * \brief Delete existing product from list.
     * 
     * Delete existing product from list by his name 
     * which is provided by user. When the name is wrong or 
     * product doesnt exist, an  ErrNoExistingProduct exception 
     * is thrown.
     *
     *\param nameToFind Name of product to delete. 
     */
    void delProduct(std::string nameToFind);

    /**
     * \brief Delete existing product from list.
     *
     * Delete couple pieces of product from list by his 
     * name and amount to delete. When the name or amount is 
     * invalid value , an ErrNoExistingProduct/ErrWrongAmountToDel
     * is thrown.
     */
    void delProductNameAmout(std::string nameToFind, int amountToDel);
    
    /**
     * \brief Clear whole list.
     */
    void delWholeList();

    /** 
     * \brief Shows list of products.
     */
    void showList() const;
};

}