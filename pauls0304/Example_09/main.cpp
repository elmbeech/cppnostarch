#include <iostream>
#include <string>
#include <vector>

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
    age = p.age; 
    return; 
}


void Person::display( void )
{
    std::cout << name << " is " << age << " years old." << std::endl;   
    return; 
}

int main( int argc , char* argv[] )
{
	std::cout << "starting program ..." << std::endl; // your code here
	
	Person* pPerson = NULL; // un-initiated pointer to a person 

	std::vector<Person*> all_persons_list; // vector of all Person objects
	
    // make three objects and add them to this list
    pPerson = new Person; 
    pPerson->name = "Alice"; 
    all_persons_list.push_back( pPerson ); 
    
    pPerson = new Person; 
    pPerson->name = "Bob"; 
    all_persons_list.push_back( pPerson ); 
    
    pPerson = new Person; 
    pPerson->name = "Charlie"; 
    all_persons_list.push_back( pPerson ); 
    
    // iterate through all of the Person objects 
    for( unsigned int n = 0; n < all_persons_list.size() ; n++ )
    { all_persons_list[n]->display(); } 
    
	std::cout << "done!" << std::endl; 
	return 0;
}

/*

https://cpp.sh/?source=%23include+%3Ciostream%3E%0D%0A%23include+%3Cstring%3E%0D%0A%23include+%3Cvector%3E%0D%0A%0D%0Aclass+Person%0D%0A%7B%0D%0A++++private%3A%0D%0A++++public%3A+%0D%0A++++++++std%3A%3Astring+name%3B+%0D%0A++++++++double+age%3B+%0D%0A++++Person()%3B+%2F%2F+default+constructor+%0D%0A++++~Person()%3B+%2F%2F+default+destructor+%0D%0A++++Person(+Person%26+p+)%3B+%2F%2F+copy+constructor+++++++++%0D%0A++++void+display(+void+)%3B+%0D%0A%7D%3B%0D%0A%0D%0APerson%3A%3APerson()%0D%0A%7B%0D%0A++++name+%3D+%22Nobody%22%3B%0D%0A++++age+%3D+0.0%3B+%0D%0A++++return%3B+%0D%0A%7D%0D%0A%0D%0APerson%3A%3A~Person()%0D%0A%7B+return%3B+%7D%0D%0A%0D%0APerson%3A%3APerson(+Person%26+p+)%0D%0A%7B%0D%0A++++name+%3D+p.name%3B+%0D%0A++++age+%3D+p.age%3B+%0D%0A++++return%3B+%0D%0A%7D%0D%0A%0D%0A%0D%0Avoid+Person%3A%3Adisplay(+void+)%0D%0A%7B%0D%0A++++std%3A%3Acout+%3C%3C+%22Person+with+ID+%22+%3C%3C+this+%3C%3C+%22+has+name+%22+%3C%3C++name+%3C%3C+%22+and+is+%22+%3C%3C+age+%3C%3C+%22+years+old.%22+%3C%3C+std%3A%3Aendl%3B+++%0D%0A++++return%3B+%0D%0A%7D%0D%0A%0D%0Aint+main(+int+argc+%2C+char*+argv%5B%5D+)%0D%0A%7B%0D%0A%09std%3A%3Acout+%3C%3C+%22starting+program+...%22+%3C%3C+std%3A%3Aendl%3B+%2F%2F+your+code+here%0D%0A%09%0D%0A%09Person*+pPerson+%3D+NULL%3B+%2F%2F+un-initiated+pointer+to+a+person+%0D%0A%0D%0A%09std%3A%3Avector%3CPerson*%3E+all_persons_list%3B+%2F%2F+vector+of+all+Person+objects%0D%0A%09%0D%0A++++%2F%2F+make+three+objects+and+add+them+to+this+list%0D%0A++++pPerson+%3D+new+Person%3B+%0D%0A++++pPerson-%3Ename+%3D+%22Alice%22%3B+%0D%0A++++all_persons_list.push_back(+pPerson+)%3B+%0D%0A++++%0D%0A++++pPerson+%3D+new+Person%3B+%0D%0A++++pPerson-%3Ename+%3D+%22Bob%22%3B+%0D%0A++++all_persons_list.push_back(+pPerson+)%3B+%0D%0A++++%0D%0A++++pPerson+%3D+new+Person%3B+%0D%0A++++pPerson-%3Ename+%3D+%22Charlie%22%3B+%0D%0A++++all_persons_list.push_back(+pPerson+)%3B+%0D%0A++++%0D%0A++++%2F%2F+iterate+through+all+of+the+Person+objects+%0D%0A++++for(+unsigned+int+n+%3D+0%3B+n+%3C+all_persons_list.size()+%3B+n%2B%2B+)%0D%0A++++%7B+all_persons_list%5Bn%5D-%3Edisplay()%3B+%7D+%0D%0A++++%0D%0A%09std%3A%3Acout+%3C%3C+%22done!%22+%3C%3C+std%3A%3Aendl%3B+%0D%0A%09return+0%3B%0D%0A%7D%0D%0A

*/