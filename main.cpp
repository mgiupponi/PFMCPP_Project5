/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */

#include <iostream>

/*
 copied UDT 1:
 */
struct StationersShop      
{
    int numPaperSizesForsale = 15;    
    int numWrappingPaperDesignsForsale = 20;        
    float monthElectricityBill;            
    float profitPerDay;               
    int numberOfEmployees;

    StationersShop() : monthElectricityBill( 138.2f ), profitPerDay( 138.2f ), numberOfEmployees( 10 ) { }
    ~StationersShop() { std::cout << "StationersShop Destructor" << std::endl; }

    struct Paper
    {
        bool forPhotoPrinting = false;
        float thicnessInuM = 200.0f;        
        float priceInUsd = 0.1f;
        std::string sizeStandard = "A4";
        std::string manufacturer = "whixe";

        void printDocument(std::string fileName, float zoomPercentage, bool onesided = false); 
        float printPhoto(int qualityIndex);
        bool moveToSellingOutbox(Paper paperB);
        
    };

    float makeAPhotocopy(Paper paperA, bool isBlackAndWhite = true , bool onesided = false);
    float takePassportPhoto(Paper paperB, std::string sizeStandard);
    void wrapAGift(std::string wrappingPaperModel);
    float chargeCustomer(std::string customerName, float maxCredit, int numItems);
    float sendItems(std::string customerAddress, float weightPerItem, int numItems);

    Paper paperToBeUsed;  
};

float StationersShop::makeAPhotocopy(Paper paperA, bool isBlackAndWhite, bool onesided)
{    
    float price = paperA.priceInUsd;
    if (isBlackAndWhite == false)
    {
         price = price * 2;
    }
    if (onesided == false)
    {
         price = price * 2;
    }
    std::cout << "Making a photocopy!" << std::endl;
    std::cout << "StationersShop::makeAPhotocopy(...) monthElectricityBill:" << monthElectricityBill << " numberOfEmployees: " << numberOfEmployees << std::endl;
    return price;
}

float StationersShop::takePassportPhoto(Paper paperB, std::string sizeStandard)
{    
    float price = paperB.priceInUsd;
    if (sizeStandard.length() > 2)
    {
         price = price * 2;
    }
    return price;
}

void StationersShop::wrapAGift(std::string wrappingPaperModel)
{    
    std::cout << wrappingPaperModel.size();
}

float StationersShop::chargeCustomer(std::string customerName, float maxCredit, int numItems)
{    
    float totalPrice = 0.0f;
    auto paper = StationersShop::Paper();
    while ( totalPrice < maxCredit ) 
    {
        paper.priceInUsd = ( maxCredit / numItems ) * 0.95f - paper.priceInUsd * 0.2f;
        totalPrice += paper.priceInUsd * 1.2f;
        std::cout << "chargeCustomer customerName:" << customerName << " totalPrice: " << totalPrice << std::endl;
    }
    return totalPrice;
}


float StationersShop::sendItems(std::string customerAddress, float weightPerItem, int numItems)
{   
    float shippingCost = 0.0f;
    auto paper = StationersShop::Paper();
    int i = 0;
    while ( i < numItems ) 
    {
        paper.thicnessInuM = ( paper.thicnessInuM ) * 0.95f + paper.thicnessInuM * 0.2f;
        shippingCost += paper.thicnessInuM * 0.8f + weightPerItem;
        std::cout << "sendItems customerAddress:" << customerAddress << " shippingCost: " << shippingCost << std::endl;
        ++i;
    }
    return shippingCost;
}


/*
 copied UDT 2:
 */

struct Wallet     
{
    int numSlots;  
    int numCreditCards = 4;     
    float amountOfCashCarried = 250.0f;            
    float weightInGrams = 150.5f;               
    std::string color = "Brown";

    Wallet() : numSlots( 7 ), color( "Brown" ) { }
    ~Wallet() { std::cout << "Wallet Destructor" << std::endl; }
    
    struct CreditCard      
    {
        bool isInternational = true;
        float widthInCm = 200.0f;
        double cardNumber = 23344331776;
        float availableCreditInUsd = 1400.0f;
        std::string bank = "HSBC";
        std::string program = "flyingSilver";

        int payInPOS(bool useChip = true);
        std::string payOnline(std::string url, bool requiresToken = false);
        float getAvailableCredit();
    };

    std::string identifyTheOwner(CreditCard creditCardA);
    bool payLunch(CreditCard creditCardB, float tipPercentage = 10.0);
    bool enterABuilding(float walletOrientationToUseInDegrees = 0.0f);
    float creditAuthorization(CreditCard creditCardB, float pricePerItem, int numItems);
    float creditCardBalance(CreditCard creditCardB, int maxEntries);
    
    CreditCard creditCardSelected;
};

std::string Wallet::identifyTheOwner(CreditCard creditCardA)
{   
    std::cout << "Owner being identified!" << std::endl;
    std::cout << "Wallet::identifyTheOwner(...) numSlots:" << numSlots << " numCreditCards: " << numCreditCards << std::endl;
    return std::to_string(creditCardA.cardNumber);
}

bool Wallet::payLunch(CreditCard creditCardB, float tipPercentage)
{    
    if (creditCardB.availableCreditInUsd*tipPercentage > 50)
    {
        return true;
    }
    return false;
}

bool Wallet::enterABuilding(float walletOrientationToUseInDegrees)
{    
    if (walletOrientationToUseInDegrees > 45)
    {
        return true;
    }
    return false;
}

float Wallet::creditAuthorization(CreditCard creditCardB, float pricePerItem, int numItems)
{    
    float amountReserved = 0.0f;
    for (int i = 0; i < numItems; ++i)
    {
        creditCardB.availableCreditInUsd = ( creditCardB.availableCreditInUsd ) * 0.7f + pricePerItem;
        amountReserved += creditCardB.availableCreditInUsd * 1.01f;
        std::cout << "creditAuthorization cardNumber:" << creditCardB.cardNumber << " availableCreditInUsd: " << creditCardB.availableCreditInUsd << std::endl;
    }
    return amountReserved;
}

float Wallet::creditCardBalance(CreditCard creditCardB, int maxEntries)
{    
    float finalBalance = 0.0f;
    for (int i = 0; i < maxEntries; ++i) 
    {
        creditCardB.availableCreditInUsd *= 0.9f;
        finalBalance += creditCardB.availableCreditInUsd * 1.05f;
        std::cout << "creditCardBalance cardNumber:" << creditCardB.cardNumber << " finalBalance: " << finalBalance << std::endl;
    }
    return finalBalance;
}

/*
 copied UDT 3:
 */

struct Laptop   
{
    std::string color;
    float weightInGrams = 150.5f;     
    std::string processorModel = "Corei3";              
    int screenSizeInInches;               
    std::string brand = "Lenovo";

    Laptop() : color( "Black" ), screenSizeInInches( 17 ) { }
    ~Laptop() { std::cout << "Laptop Destructor" << std::endl; }
    
    struct File      
    {
        bool isReadOnly = false;
        float sizeInBytes = 2000.0f;        
        std::string fullPath = "/root/file.jpg";
        std::string fileType = "image";

        std::string readFile(int startPosition, int endPosition);
        void replaceFile(std::string content);
        bool deleteFile(bool askForConfirmation);
    };

    std::string readDocument(File inputFile);
    float surfTheWeb(std::string url = "www.google.com", bool incognitoMode = false);
    void TakeAPicture(File outputFile, float lidOrientationInDegrees = 55.0f);
    float defragmentFile(File inputFile, float precision);
    float zoomFile(File inputFile, float zoomPercentage);

    File fileBeingProcessed;
};

std::string Laptop::readDocument(File inputFile)
{    
    std::cout << "Starting to read document!" << std::endl;
    std::cout << "Laptop::readDocument(...) color:" << color << " weightInGrams: " << weightInGrams << std::endl;
    return inputFile.fullPath;
}

float Laptop::surfTheWeb(std::string url, bool incognitoMode)
{    
    float output = url.length();
    if (incognitoMode)
    {
         output *= 2;
    }
    return output;
}

void Laptop::TakeAPicture(File outputFile, float lidOrientationInDegrees)
{    
    if (lidOrientationInDegrees > 5)
        outputFile.fullPath.size();
}

float Laptop::defragmentFile(File inputFile, float precision)
{    
    float achievedPrecision = 0.0f;
    while ( achievedPrecision < precision ) 
    {
        inputFile.sizeInBytes *= 0.8f;
        achievedPrecision += 2.0f ;
        std::cout << "defragmentFile fullPath:" << inputFile.fullPath << " achievedPrecision: " << achievedPrecision << std::endl;
    }
    return achievedPrecision;
}

float Laptop::zoomFile(File inputFile, float zoomPercentage)
{    
    float currentZoom = 100.0f;
    while ( currentZoom < zoomPercentage ) 
    {
        inputFile.sizeInBytes *= 1.1f;
        currentZoom += inputFile.sizeInBytes * 0.02f;
        std::cout << "zoomFile fullPath:" << inputFile.fullPath << " sizeInBytes: " << inputFile.sizeInBytes << std::endl;
    }
    return currentZoom;
}

/*
 new UDT 4:
 with 2 member functions
 */

struct businessOwner      
{
    StationersShop stationersShop = StationersShop();
    Wallet wallet = Wallet();            
    Laptop laptop = Laptop();               

    StationersShop()
    {
        stationersShop.makeAPhotocopy(Paper paperA, bool isBlackAndWhite, bool onesided);
    }
    ~StationersShop()
    { 
        std::cout << "StationersShop Destructor" << std::endl;
    }

    float makeAPhotocopy(Paper paperA, bool isBlackAndWhite = true , bool onesided = false);
    float takePassportPhoto(Paper paperB, std::string sizeStandard);
    void wrapAGift(std::string wrappingPaperModel);
    float chargeCustomer(std::string customerName, float maxCredit, int numItems);
    float sendItems(std::string customerAddress, float weightPerItem, int numItems);

};

float StationersShop::makeAPhotocopy(Paper paperA, bool isBlackAndWhite, bool onesided)
{    
    float price = paperA.priceInUsd;
    if (isBlackAndWhite == false)
    {
         price = price * 2;
    }
    if (onesided == false)
    {
         price = price * 2;
    }
    std::cout << "Making a photocopy!" << std::endl;
    std::cout << "StationersShop::makeAPhotocopy(...) monthElectricityBill:" << monthElectricityBill << " numberOfEmployees: " << numberOfEmployees << std::endl;
    return price;
}

float StationersShop::takePassportPhoto(Paper paperB, std::string sizeStandard)
{    
    float price = paperB.priceInUsd;
    if (sizeStandard.length() > 2)
    {
         price = price * 2;
    }
    return price;
}

void StationersShop::wrapAGift(std::string wrappingPaperModel)
{    
    std::cout << wrappingPaperModel.size();
}

float StationersShop::chargeCustomer(std::string customerName, float maxCredit, int numItems)
{    
    float totalPrice = 0.0f;
    auto paper = StationersShop::Paper();
    while ( totalPrice < maxCredit ) 
    {
        paper.priceInUsd = ( maxCredit / numItems ) * 0.95f - paper.priceInUsd * 0.2f;
        totalPrice += paper.priceInUsd * 1.2f;
        std::cout << "chargeCustomer customerName:" << customerName << " totalPrice: " << totalPrice << std::endl;
    }
    return totalPrice;
}


float StationersShop::sendItems(std::string customerAddress, float weightPerItem, int numItems)
{   
    float shippingCost = 0.0f;
    auto paper = StationersShop::Paper();
    int i = 0;
    while ( i < numItems ) 
    {
        paper.thicnessInuM = ( paper.thicnessInuM ) * 0.95f + paper.thicnessInuM * 0.2f;
        shippingCost += paper.thicnessInuM * 0.8f + weightPerItem;
        std::cout << "sendItems customerAddress:" << customerAddress << " shippingCost: " << shippingCost << std::endl;
        ++i;
    }
    return shippingCost;
}


/*
 new UDT 5:
 with 2 member functions
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
