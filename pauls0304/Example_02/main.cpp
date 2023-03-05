#include <iostream>
#include <string>

class Person
{
    private:
    public: 
        std::string name; 
        double age; 
    Person(); // default constructor 
    ~Person(); // default destructor 
};

Person::Person()
{
    name = "Nobody";
    age = 0.0; 
    return; 
}

Person::~Person()
{ return; }

int main( int argc , char* argv[] )
{
	std::cout << "starting program ..." << std::endl;
	// your code here
	
	Person bob; 
	std::cout << bob.name << " is " << bob.age << std::endl; 
	
	bob.name = "Dennis";
	bob.age = 37; 
	std::cout << bob.name << " is " << bob.age << std::endl; 

	std::cout << "done!" << std::endl; 
	return 0;
}
