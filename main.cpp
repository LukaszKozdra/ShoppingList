#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include "Product.hpp"
#include "List.hpp"

void pause_and_clear(std::string str){
    std::cout << str <<  " " << std::endl;
    std::cin.clear();
    std::cin.ignore();
    char enter;
    std::cin.get(enter);
    system("clear");
}

int main(){
    std::string chooseOperationS;
    int chooseOperationI {};

    std::string ProductName ;
    int ProductAmount = 0;
    double ProductPrice = 0;
    lk::List list;

    while(1){

        std::cout << std::endl << "Shoping list operations" << std::endl << std::endl;
        std::cout << "1. Add product " << std::endl;
        std::cout << "2. Delete product by his name " << std::endl;
        std::cout << "3. Delete product by his name and amount " << std::endl;
        std::cout << "4. Delete whole list " << std::endl;
        std::cout << "5. Show list" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cout << std::endl <<  "Select operation (1, 2, 3, 4, 5 or 6): ";
        std::cin >> chooseOperationS;

        if(chooseOperationS.find_first_not_of("0123456789") != std::string::npos){
            std::cout << std::endl << "ERORR: Arument is not a number" << std::endl;
            pause_and_clear("Click enter to try again");
            system("clear");
            continue;
        }

        chooseOperationI = std::stoi(chooseOperationS);

        if(chooseOperationI < 0 || chooseOperationI > 6){
            std::cout << std::endl << "ERORR: Operation number is not form range 1-6 " << std::endl;
            std::cout << "Click enter to try again " << std::endl;
            std::cin.ignore();
            char enter;
            std::cin.get(enter);
            system("clear");
            continue;
        }


        try{
            switch(chooseOperationI){
                case(1):
                    std::cout << "Provide name of product to add: ";
                    std::cin >> ProductName;
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore();
                        throw lk::ErrWrongName();
                    }
                    std::cout << "Provide amount of product to add: ";
                    std::cin >> ProductAmount;
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore();
                        throw lk::ErrWrongAmount();
                    }
                    std::cout << "Provide price of single product: ";
                    std::cin >> ProductPrice;
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore();
                        throw lk::ErrWrongPrice();
                    }
                    list.addProduct(lk::Product(ProductName, ProductAmount, ProductPrice));
                    system("clear");
                    break;
                case(2):
                    std::cout << "Provide name of product to delete: ";
                    std::cin >> ProductName;
                    list.delProduct(ProductName);
                    system("clear");
                    break;
                case(3):
                    std::cout << "Provide name of product to delete: ";
                    std::cin >> ProductName;
                    std::cout << "Provide amount of product to delete: ";
                    std::cin >> ProductAmount;
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore();
                        throw lk::ErrWrongAmountToDel();
                    }
                    list.delProductNameAmout(ProductName, ProductAmount);
                    system("clear");
                    break;
                case(4):
                    list.delWholeList();
                    system("clear");
                    break;
                case(5):
                    list.showList();
                    pause_and_clear("Click enter to continue");
                    break;
                case(6):  
                    return 0;    
                    break;     
                default:
                    system("clear");
                    break;
            }

        }catch(lk::ErrNoExistingProduct e){
            std::cout << std::endl << "ERROR: ";
            e.what();
            pause_and_clear("Click enter to continue");
        }catch(lk::ErrWrongAmountToDel e){
            std::cout << std::endl << "ERROR: ";  
            e.what();
            pause_and_clear("Click enter to continue");
        }catch(lk::ErrWrongName e){
            std::cout << std::endl << "ERROR: ";  
            e.what();        
            pause_and_clear("Click enter to continue");
        }catch(lk::ErrWrongAmount e){
            std::cout << std::endl << "ERROR: ";  
            e.what();
            pause_and_clear("Click enter to continue");
        }catch(lk::ErrWrongPrice e){
            std::cout << std::endl << "ERROR: ";  
            e.what();
            pause_and_clear("Click enter to continue");
        }
    }
}