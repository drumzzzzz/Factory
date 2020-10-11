#include <iostream>
#include <vector>
#include <string.h>
#include <sstream> 

using namespace std;

class Subaru
{
public:
    // Static factory method
    static Subaru* make_subaru(const char* model);

    // Methods per model
    virtual void Model() = 0;
    virtual void Engine() = 0;
    virtual void Transmission() = 0;
    virtual void Options() = 0;

    // Explicit default destructor
    virtual ~Subaru() = default;
};

// Factory Objects
class Legacy : public Subaru {
public:
    void Model()
    {
        cout << "Legacy\n";
    }
	
    void Engine()
    {
        cout << "3.0L F6\n";
    }

    void Transmission()
    {
        cout << "CVT\n";
    }

    void Options()
    {
        cout << "Heated seats\n";
    }
};

class Impreza : public Subaru {
public:
    void Model()
    {
        cout << "Impreza\n";
    }
	
    void Engine()
	{
        cout << "SOHC 2.5L\n";
    }

	void Transmission()
    {
        cout << "MT 5 speed\n";
    }

	void Options()
    {
        cout << "Roof Rack\n";
    }
};

class Outback : public Subaru
{
public:
    void Model()
    {
        cout << "Outback\n";
    }

    void Engine()
    {
        cout << "SOHC 2.5L\n";
    }

    void Transmission()
    {
        cout << "CVT\n";
    }

    void Options()
    {
        cout << "Roof Rack, Towing Package\n";
    }
};

class WRX : public Subaru {
public:
    void Model()
    {
        cout << "WRX\n";
    }
	
    void Engine()
    {
        cout << "DOHC 2.5L Turbo\n";
    }

    void Transmission()
    {
        cout << "MT 6 speed\n";
    }

    void Options()
    {
        cout << "Hood Scoop and Wing\n";
    }
};

// Factory Method: Returns a constructed object based on supplied model type
Subaru* Subaru::make_subaru(const char* model)
{	
    if (strcmp(model,"legacy") == 0)
        return new Legacy;
    else if (strcmp(model, "impreza") == 0)
        return new Impreza;
    else if (strcmp(model, "outback") == 0)
        return new Outback;
    else if (strcmp(model, "wrx") == 0)
		return new WRX;

    return nullptr;
}

// Converts a string to lower case
static void ToLower(char* svalue)
{
    for (unsigned int i = 0; i < strlen(svalue); i++)
        svalue[i] = (char)tolower(svalue[i]);
}

// Iterates and creates factory objects based on supplied arguments
int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " [Model] [Quantity]" << endl
            << "Ex. Impreza 10 || Outback 5 || Wrx 11" << endl;
    }

    vector<Subaru*> subarus;

	// Create factory objects per valid argument
	for (int idx=1; idx<argc; idx++)
	{
        ToLower(argv[idx]);
        Subaru* s = Subaru::make_subaru(argv[idx]);

		if (s != nullptr)
        {
            subarus.push_back(s);
            cout << "Subaru Model " << argv[idx] << " Constructed." << endl;
        }
        else
            cout << "Skipping Invalid Model Name '" << argv[idx] << "'." << endl;	
	}

	// Iterate the created object methods	
	for (unsigned int i=0; i<subarus.size(); i++)
	{
        cout << "************" << endl;
        subarus[i]->Model();
        subarus[i]->Engine();
        subarus[i]->Transmission();
        subarus[i]->Options();
	}
}
