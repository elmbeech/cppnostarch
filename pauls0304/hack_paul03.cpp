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

std::vector<Person*> all_person_list;
Person::Person() {
    name = "nobody";
    age = 0.0;
    all_person_list.push_back(this);  // add this object pointer to the list
    return;
}

Person::Person( Person& p) {
    name = p.name;
    age = p.age;
    all_person_list.push_back(this);  // add this object pointer to the list
    return;
}

Person::~Person() { 
    // find and remove me in the list of all persons
    int n = 0;
    bool search = true;
    while (search) {  // search for me
        if (all_person_list[n] == this) {
            all_person_list[n] = all_person_list.back();  // put last item in the list at my place
            all_person_list.pop_back();  // shrink list
            search = false;
        }
        n++;
    }
    return; 
}

void Person::display( void ) {
    std::cout << "id " << this << " has " << name << " is " << age << std::endl;
    return;
}


int main(int argc, char* argv[]) {
    std::cout << "starting program ..." << std::endl;

    Person* pPerson = NULL;  // uninitiated pointer to a person bue: is this kind of a declaration?

    pPerson = new Person;
    pPerson->name = "Alice";

    pPerson = new Person;
    pPerson->name = "Bob";

    pPerson = new Person;
    pPerson->name = "Chuck";

    // iterate over list to display
    std::cout << std::endl;
    for (unsigned int n=0; n < all_person_list.size(); n++) {
        all_person_list[n]->display();
    } 

    // delete bob
    delete all_person_list[1];

    // iterate over list to display
    std::cout << std::endl;
    for (unsigned int n=0; n < all_person_list.size(); n++) {
        all_person_list[n]->display();
    } 

    std::cout << "done!"  << std::endl;
    return 0;
}

