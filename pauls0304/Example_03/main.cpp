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
    
    Person( Person& p ); // copy constructor     
    void display( void );     
};

Person::Person()
{
    name = "Nobody";
    age = 0.0; 
    return; 
}

Person::~Person()
{ return; }

Person::Person( Person& p )
{
    name = p.name; 
    age =p.age; 
    return; 
}

void Person::display( void )
{
    std::cout << name << " is " << age << " years old." << std::endl;   
    return; 
}

int main( int argc , char* argv[] )
{
	std::cout << "starting program ..." << std::endl;
	// your code here
	
	Person bob; 
    bob.display();
	
	bob.name = "Dennis";
	bob.age = 37; 
    bob.display(); 

    Person charlie = bob; 
    charlie.name = "Charlie";
    charlie.display(); 

	std::cout << "done!" << std::endl; 
	return 0;
}

/* 

https://cpp.sh/?source=%23include+%3Ciostream%3E%0D%0A%23include+%3Cstring%3E%0D%0A%0D%0Aclass+Person%0D%0A%7B%0D%0A++++private%3A%0D%0A++++public%3A+%0D%0A++++++++std%3A%3Astring+name%3B+%0D%0A++++++++double+age%3B+%0D%0A++++Person()%3B+%2F%2F+default+constructor+%0D%0A++++~Person()%3B+%2F%2F+default+destructor+%0D%0A++++%0D%0A++++Person(+Person%26+p+)%3B+%2F%2F+copy+constructor+++++%0D%0A++++void+display(+void+)%3B+++++%0D%0A%7D%3B%0D%0A%0D%0APerson%3A%3APerson()%0D%0A%7B%0D%0A++++name+%3D+%22Nobody%22%3B%0D%0A++++age+%3D+0.0%3B+%0D%0A++++return%3B+%0D%0A%7D%0D%0A%0D%0APerson%3A%3A~Person()%0D%0A%7B+return%3B+%7D%0D%0A%0D%0APerson%3A%3APerson(+Person%26+p+)%0D%0A%7B%0D%0A++++name+%3D+p.name%3B+%0D%0A++++age+%3Dp.age%3B+%0D%0A++++return%3B+%0D%0A%7D%0D%0A%0D%0Avoid+Person%3A%3Adisplay(+void+)%0D%0A%7B%0D%0A++++std%3A%3Acout+%3C%3C+name+%3C%3C+%22+is+%22+%3C%3C+age+%3C%3C+%22+years+old.%22+%3C%3C+std%3A%3Aendl%3B+++%0D%0A++++return%3B+%0D%0A%7D%0D%0A%0D%0Aint+main(+int+argc+%2C+char*+argv%5B%5D+)%0D%0A%7B%0D%0A%09std%3A%3Acout+%3C%3C+%22starting+program+...%22+%3C%3C+std%3A%3Aendl%3B%0D%0A%09%2F%2F+your+code+here%0D%0A%09%0D%0A%09Person+bob%3B+%0D%0A++++bob.display()%3B%0D%0A%09%0D%0A%09bob.name+%3D+%22Dennis%22%3B%0D%0A%09bob.age+%3D+37%3B+%0D%0A++++bob.display()%3B+%0D%0A%0D%0A++++Person+charlie+%3D+bob%3B+%0D%0A++++charlie.name+%3D+%22Charlie%22%3B%0D%0A++++charlie.display()%3B+%0D%0A%0D%0A%09std%3A%3Acout+%3C%3C+%22done!%22+%3C%3C+std%3A%3Aendl%3B+%0D%0A%09return+0%3B%0D%0A%7D%0D%0A

*/
