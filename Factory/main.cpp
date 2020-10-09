#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Apple {
public:

    // Factory Method, note it's static
    static Apple* make_apple(string choice);

    // method that we will use polymorphically per product
    virtual void io() = 0;

    // Note: need to specify an explicicit default destructor
    virtual ~Apple() = default;
};

class iPhone : public Apple {
public:
    void io() {
        cout << "iPhone: touchscreen\n";
    }
};

class iPad : public Apple {
public:
    void io() {
        cout << "iPad: touchscreen & keyboard\n";
    }
};

class Mac : public Apple {
public:
    void io() {
        cout << "Mac: keyboard\n";
    }
};


// this is the FACTORY Method
// it does need to know about the derived methods
// but this allows us to abstract this from our 
// "client" calling code in main()
Apple* Apple::make_apple(string choice) {
    if (choice == "iPhone")
        return new iPhone;
    else if (choice == "iPad")
        return new iPad;
    else
        return new Mac;
}


//  main() is considered the "client"
// while in this example we could hard code the
// derived classes since we are making a menu anyway
// imagine having 

int main(int argc, char* argv[])
{
    for (int i=0;i<argc;i++)
    {
        cout << "Arg " << i << ":" << argv[i] << endl;
    }
	
    vector<Apple*> products;
    string choice;
    while (true) {
        cout << "Enter Apple Product (Mac is default) or 0 if done: ";
        cin >> choice;
        if (choice == "0") break;
        products.push_back(Apple::make_apple(choice));
    }
    for (int i = 0; i < products.size(); i++) {
        products[i]->io();
    }
    for (int i = 0; i < products.size(); i++) {
        delete products[i];
    }
}
