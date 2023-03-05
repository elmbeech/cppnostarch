#include <iostream>
#include <string>
#include <vector>

class Person {
    private:
    public:
        std::string name;
        double age;
    Person();  // default constructor
    Person( Person & p); // copy constructor
    ~Person();  // default deconstructor
    void display( void );
};

Person::Person() {
    name = "nobody";
    age = 0.0;
    return;
}

Person::Person( Person& p) {
    name = p.name;
    age = p.age;
    return;
}

Person::~Person() { return; }

void Person::display( void ) {
    std::cout << "id " << this << " has " << name << " is " << age << std::endl;
    return;
}


int main(int argc, char* argv[]) {
    std::cout << "starting program ..." << std::endl;

    /*
    Person bob;
    //std::cout << bob.name << " is " << bob.age << std::endl;
    bob.display();

    bob.name = "Dennis";
    bob.age = 37;
    //std::cout << bob.name << " is " << bob.age << std::endl;
    bob.display();

    Person alice = bob;
    alice.name = "Alice";
    alice.display();

    // person by pointer
    Person* pPerson = NULL;  // uninitiated pointer to a person bue: is this kind of a declaration?
    pPerson = new Person;  // make a new person
    pPerson->display();   // display new person with arrow syntax
    pPerson->name = "Mallory";  // operate on the pointer
    (*pPerson).display();   // display new peson with bracket syntax
    */

    Person* pPerson = NULL;  // uninitiated pointer to a person bue: is this kind of a declaration?
    std::vector<Person*> all_person_list;  // vector of all Person object pointers

    pPerson = new Person;
    pPerson->name = "Alice";
    all_person_list.push_back(pPerson);

    pPerson = new Person;
    pPerson->name = "Bob";
    all_person_list.push_back(pPerson);

    pPerson = new Person;
    pPerson->name = "Cesar";
    all_person_list.push_back(pPerson);

    // iterate over list to display
    for (unsigned int n=0; n < all_person_list.size(); n++) {
        all_person_list[n]->display();
    } 

    std::cout << "done!"  << std::endl;
    return 0;
}

