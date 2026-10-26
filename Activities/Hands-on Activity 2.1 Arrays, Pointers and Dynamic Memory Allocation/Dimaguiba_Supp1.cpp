#include <iostream>
#include <string>
#include <iomanip>

float totalSum(float, float);

class Fruit{
    private:
        std::string fName;
        float fPrice;
        int fQuantity;

    public:
    //constructor
        Fruit(std::string name = "placeholder", float price = 0, int quantity = 0){
            fName = name;
            fPrice = price;
            fQuantity = quantity;
            std::cout<<"Constructor Called"<<std::endl;
        }
    //destructor
        ~Fruit(){
            std::cout<<"Destructor Called"<<std::endl;
        }

    //copy constructor
        Fruit(const Fruit &copyFruit){
            fName = copyFruit.fName;
            fPrice = copyFruit.fPrice;
            fQuantity = copyFruit.fQuantity;
            std::cout<<"Copy Constructor Called"<<std::endl;
        }

    //copy assignment operator
        Fruit& operator = (const Fruit &copyFruit){
            if (this != &copyFruit){ 
                fName = copyFruit.fName;
                fPrice = copyFruit.fPrice;
                fQuantity = copyFruit.fQuantity;
                
            }

            return *this;
    }
            
    //display that thang
    
		void printDetails(){
    		std::cout<<std::fixed<<std::setprecision(2)<<this->fName<<" Price: "<<this->fPrice<<" Quantity: "<<this->fQuantity<<"x"<<std::endl;
    	}
	//Sum
		float totalSum(){
			return fPrice * fQuantity;
		}

    };
    
class Vegetable{
    private:
        std::string vName;
        float vPrice;
        int vQuantity;

    public:
    //constructor
        Vegetable(std::string name = "placeholder", float price = 0, int quantity = 0){
            vName = name;
            vPrice = price;
            vQuantity = quantity;
            std::cout<<"Constructor Called"<<std::endl;
        }
    //destructor
        ~Vegetable(){
            std::cout<<"Destructor Called"<<std::endl;
        }

    //copy constructor
        Vegetable(const Vegetable &copyVegetable){
            vName = copyVegetable.vName;
            vPrice = copyVegetable.vPrice;
            vQuantity = copyVegetable.vQuantity;
            std::cout<<"Copy Constructor Called"<<std::endl;
        }

    //copy assignment operator
        Vegetable& operator = (const Vegetable &copyVegetable){
            if (this != &copyVegetable){ 
                vName = copyVegetable.vName;
                vPrice = copyVegetable.vPrice;
                vQuantity = copyVegetable.vQuantity;
                
            }

            return *this;
    }
            
    //display that thang
    
		void printDetails(){
    		std::cout<<std::fixed<<std::setprecision(2)<<this->vName<<" Price: "<<this->vPrice<<" Quantity: "<<this->vQuantity<<"x"<<std::endl;
		}
		
	//Sum
	
		float totalSum(){
			return vPrice * vQuantity;
		}

    };


int main(){
	
	float fruitSum = 0;
	float veggieSum = 0;
	
	//Fruit
	const int PRODUCE = 2;
	Fruit* fruitGroceryList[PRODUCE] = {}; //a pointer  for dynamic allocation
	std::string fruitNames[PRODUCE] = {"Apple", "Banana"};
	float fruitPrices[PRODUCE] = {10,10};
	int fruitQuantity[PRODUCE] = {7,8};
	
	//Vegetables
	Vegetable* veggieGroceryList[PRODUCE] = {}; //a pointer so we can delete lettuce later
	std::string veggieNames[PRODUCE] = {"Broccoli", "Lettuce"};
	float veggiePrices[PRODUCE] = {60,50};
	int veggieQuantity[PRODUCE] = {12,10};
	
	for (int i = 0; i < PRODUCE; i++){
		Fruit* ptr = new Fruit(fruitNames[i], fruitPrices[i], fruitQuantity[i]);
		fruitGroceryList[i]= ptr;
		fruitSum += ptr->totalSum();
	} 
	
	for (int i = 0; i < PRODUCE; i++){
		Vegetable* ptrV = new Vegetable(veggieNames[i], veggiePrices[i], veggieQuantity[i]);
		veggieGroceryList[i]= ptrV;
		veggieSum += ptrV->totalSum();
	}
	
	//Display
	for (int k = 0; k < PRODUCE; k++){
		fruitGroceryList[k]->printDetails();
		veggieGroceryList[k]->printDetails();
	}
	
	std::cout<<"Total Sum: "<<std::fixed<<std::setprecision(2)<<totalSum(veggieSum,fruitSum)<<"php"<<std::endl;
	
	//Lettuce Deallocate Lettuce (pun intended)
	delete veggieGroceryList[1];
	veggieGroceryList[1] = nullptr;
	
	
	//Deallocate everything else since we used dynamic allocation for the classes
	for (int i = 0; i < PRODUCE; i++){
		delete fruitGroceryList[i];
		delete veggieGroceryList[i];
	}
	
    return 0;
}

float totalSum(float aPrice, float bPrice){
	return aPrice + bPrice;
}
