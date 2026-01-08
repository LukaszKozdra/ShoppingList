#pragma once
#include <string>

namespace lk {

/**
 * \brief Exception thrown when product name is invalid.
 *
 * This exception is thrown when user provides an empty string 
 * or wrong value as a product name. 
 */
struct ErrWrongName {
    /**
     * \brief Print information about wrong product name.
     */
    void what();
};

/**
 * \brief Exception thrown when product amount is invalid.
 *
 * This exception is thrown when user provides an wrong amount.
 * of product.
 */
struct ErrWrongAmount {
    /**
     * \brief Print information about wrong product amount.
     */
    void what();
};

/**
 * \brief Exception thrown when product price is invalid.
 *
 * This exception is thrown when user provides a wrong price
 * of product.
 */
struct ErrWrongPrice {
    /**
     * \brief Print information about wrong product price.
     */
    void what();
};

/**
 * \brief Represent a food product.
 *
 * This class represents a food product with its name,
 * amount and price of a single product. It also provides
 * methods to modify and access to values.
 */
class Product {
private:
    /**
     * \brief Product name.
     *
     * Name is set when product is created. It can be changed.
     * When not provided by the user, it is set to "Unknown".
     */
    std::string m_name;

    /**
     * \brief Amount of product.
     *
     * Amount is set when product is created. It can be changed.
     * When not provided by the user, it is set to 0.
     */
    int m_amount;

    /**
     * \brief Price of a single product.
     *
     * Price is set when product is created. It can be changed.
     * When not provided by the user, it is set to 0.
     */
    double m_price;

public:
    /**
     * \brief Create a new product.
     *
     * Creates a new product with values provided by user.
     *
     * \param n Name of the product.
     * \param a Amount of the product.
     * \param p Price of a single product.
     */
    Product(std::string n, int a, double p);

    /**
     * \brief Create a new product with default parameters.
     *
     * Creates a new product with name set to "Unknown",
     * amount set to 0 and price set to 0.
     */
    Product();

    /**
     * \brief Set a new product name.
     *
     * Set a new product name provided by user.
     * If the name is empty, it is set to "Unknown"
     * and an ErrWrongName exception is thrown.
     *
     * \param n New product name.
     */
    void setName(std::string n);

    /**
     * \brief Set a new amount of product.
     *
     * Set a new product amount provided by user.
     * If the amount is lower than 0, it is set to 0
     * and an ErrWrongAmount exception is thrown.
     *
     * \param a New amount of product.
     */
    void setAmount(int a);

    /**
     * \brief Set a new product price.
     *
     * Set a new product price provided by the user.
     * If the price is lower than 0, it is set to 0
     * and an ErrWrongPrice exception is thrown.
     *
     * \param p New product price.
     */
    void setPrice(double p);

    /**
     * \brief Get product name.
     *
     * \return Product name.
     */
    std::string getName() const;

    /**
     * \brief Get product amount.
     *
     * \return Product amount.
     */
    int getAmount() const;

    /**
     * \brief Get product price.
     *
     * \return Price of a single product.
     */
    double getPrice() const;

    /**
     * \brief Get total price of all products.
     *
     * \return Price multiplied by amount.
     */
    double getPriceOfAll() const;
};

}
