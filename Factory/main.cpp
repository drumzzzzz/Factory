#include <iostream>
#include <vector>
#include <string>
#include <sstream> 

using namespace std;

class Subaru
{
public:
    // Static factory method
    static Subaru* make_subaru(const char* model);

    // Methods used polymorphically per model

    virtual void Model() = 0;
	
    virtual void Engine() = 0;

    virtual void Transmission() = 0;

    virtual void Options() = 0;

    // Explicit default destructor
    virtual ~Subaru() = default;
};

class Legacy : public Subaru {
public:
    void Model()
    {
        cout << "Legacy\n";
    }
	
    void Engine()
    {
        cout << "iPhone: touchscreen\n";
    }

    void Transmission()
    {

    }

    void Options()
    {

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
        cout << "5MT\n";
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
        cout << "iPhone: touchscreen\n";
    }

    void Transmission()
    {

    }

    void Options()
    {

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
        cout << "iPhone: touchscreen\n";
    }

    void Transmission()
    {

    }

    void Options()
    {

    }
};

Subaru* Subaru::make_subaru(const char* model)
{
    int v = strcmp(model, "legacy");
	
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

const char* models[6] = { "legacy", "impreza", "outback", "wrx" };

void ToLower(char* svalue)
{
    for (unsigned int i = 0; i < strlen(svalue); i++)
        svalue[i] = (char)tolower(svalue[i]);
}

char* CheckModel(char* model)
{	
    for (string m : models)
    {
        if (m == model)
        {
            return model;
        }
    }

    return nullptr;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " [Model] [Quantity]" << endl
            << "Ex. Impreza 10 || Outback 5 || Wrx 11" << endl;
    }

    vector<Subaru*> subarus;
	
	for (int idx=1; idx<argc;idx++)
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

	for (unsigned int i=0; i<subarus.size();i++)
	{
        subarus[i]->Model();
        subarus[i]->Engine();
        subarus[i]->Transmission();
        subarus[i]->Options();
	}
}
