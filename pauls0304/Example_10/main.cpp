#include <iostream>
#include <string>
#include <vector>
class Person
{
		private:
		public: 
			std::string name; 
			double age; 
			Person(); 	// default constructor 
		~Person(); 		// default destructor 
		Person( Person& p ); 	// copy constructor	 
	
		void display( void ); 
};

std::vector<Person*> all_persons_list; 
Person::Person()
{
		name = "Nobody";
		age = 0.0; 
		all_persons_list.push_back( this ); // add this object to the list
		return; 
}

Person::~Person()
{
	// find and remove "me" in the list of all persons
	int n = 0; 
	bool done = false; 
	while( done == false )
	{ // search for "me"
		if( all_persons_list[n] == this )
		{ 
			// put last item on the list in my place
			all_persons_list[n] = all_persons_list.back();
			// shrink list 
			all_persons_list.pop_back(); 
			done = true; 
		}
		n++; 
	}
	return; 
}

void Person::display( void )
{
	std::cout << name << " is " << age << " years old." << std::endl;   
	return; 
}
Person::Person( Person& p )
{
	name = p.name; 
	age = p.age; 
	all_persons_list.push_back( this ); // add this object to the list
	return; 
}

int main( int argc , char* argv[] )
{
	std::cout << "starting program ..." << std::endl; // your code here
	
	Person* pPerson = NULL; // un-initiated pointer to a person 
	
	// make three objects and add them to this list
	pPerson = new Person; 
	pPerson->name = "Alice"; 
	
	pPerson = new Person; 
	pPerson->name = "Bob"; 
	
	pPerson = new Person; 
	pPerson->name = "Charlie"; 
	
	// iterate through all of the Person objects 
	std::cout << std::endl; 
	for( unsigned int n = 0; n < all_persons_list.size() ; n++ )
	{ all_persons_list[n]->display(); } 
 
	// delete Bob
	delete all_persons_list[1];
	
	// iterate through all of the Person objects 
	std::cout << std::endl; 
	for( unsigned int n = 0; n < all_persons_list.size() ; n++ )
	{ all_persons_list[n]->display(); } 
	
	std::cout << "done!" << std::endl; 
	return 0;
}

/*

https://cpp.sh/?source=%23include+%3Ciostream%3E%0D%0A%23include+%3Cstring%3E%0D%0A%23include+%3Cvector%3E%0D%0Aclass+Person%0D%0A%7B%0D%0A%09%09private%3A%0D%0A%09%09public%3A+%0D%0A%09%09%09std%3A%3Astring+name%3B+%0D%0A%09%09%09double+age%3B+%0D%0A%09%09%09Person()%3B+%09%2F%2F+default+constructor+%0D%0A%09%09~Person()%3B+%09%09%2F%2F+default+destructor+%0D%0A%09%09Person(+Person%26+p+)%3B+%09%2F%2F+copy+constructor%09+%0D%0A%09%0D%0A%09%09void+display(+void+)%3B+%0D%0A%7D%3B%0D%0A%0D%0Astd%3A%3Avector%3CPerson*%3E+all_persons_list%3B+%0D%0APerson%3A%3APerson()%0D%0A%7B%0D%0A%09%09name+%3D+%22Nobody%22%3B%0D%0A%09%09age+%3D+0.0%3B+%0D%0A%09%09all_persons_list.push_back(+this+)%3B+%2F%2F+add+this+object+to+the+list%0D%0A%09%09return%3B+%0D%0A%7D%0D%0A%0D%0APerson%3A%3A~Person()%0D%0A%7B%0D%0A%09%2F%2F+find+and+remove+%22me%22+in+the+list+of+all+persons%0D%0A%09int+n+%3D+0%3B+%0D%0A%09bool+done+%3D+false%3B+%0D%0A%09while(+done+%3D%3D+false+)%0D%0A%09%7B+%2F%2F+search+for+%22me%22%0D%0A%09%09if(+all_persons_list%5Bn%5D+%3D%3D+this+)%0D%0A%09%09%7B+%0D%0A%09%09%09%2F%2F+put+last+item+on+the+list+in+my+place%0D%0A%09%09%09all_persons_list%5Bn%5D+%3D+all_persons_list.back()%3B%0D%0A%09%09%09%2F%2F+shrink+list+%0D%0A%09%09%09all_persons_list.pop_back()%3B+%0D%0A%09%09%09done+%3D+true%3B+%0D%0A%09%09%7D%0D%0A%09%09n%2B%2B%3B+%0D%0A%09%7D%0D%0A%09return%3B+%0D%0A%7D%0D%0A%0D%0Avoid+Person%3A%3Adisplay(+void+)%0D%0A%7B%0D%0A%09std%3A%3Acout+%3C%3C+name+%3C%3C+%22+is+%22+%3C%3C+age+%3C%3C+%22+years+old.%22+%3C%3C+std%3A%3Aendl%3B+++%0D%0A%09return%3B+%0D%0A%7D%0D%0APerson%3A%3APerson(+Person%26+p+)%0D%0A%7B%0D%0A%09name+%3D+p.name%3B+%0D%0A%09age+%3D+p.age%3B+%0D%0A%09all_persons_list.push_back(+this+)%3B+%2F%2F+add+this+object+to+the+list%0D%0A%09return%3B+%0D%0A%7D%0D%0A%0D%0Aint+main(+int+argc+%2C+char*+argv%5B%5D+)%0D%0A%7B%0D%0A%09std%3A%3Acout+%3C%3C+%22starting+program+...%22+%3C%3C+std%3A%3Aendl%3B+%2F%2F+your+code+here%0D%0A%09%0D%0A%09Person*+pPerson+%3D+NULL%3B+%2F%2F+un-initiated+pointer+to+a+person+%0D%0A%09%0D%0A%09%2F%2F+make+three+objects+and+add+them+to+this+list%0D%0A%09pPerson+%3D+new+Person%3B+%0D%0A%09pPerson-%3Ename+%3D+%22Alice%22%3B+%0D%0A%09%0D%0A%09pPerson+%3D+new+Person%3B+%0D%0A%09pPerson-%3Ename+%3D+%22Bob%22%3B+%0D%0A%09%0D%0A%09pPerson+%3D+new+Person%3B+%0D%0A%09pPerson-%3Ename+%3D+%22Charlie%22%3B+%0D%0A%0D%0A%09%2F%2F+iterate+through+all+of+the+Person+objects+%0D%0A%09std%3A%3Acout+%3C%3C+std%3A%3Aendl%3B+%0D%0A%09for(+unsigned+int+n+%3D+0%3B+n+%3C+all_persons_list.size()+%3B+n%2B%2B+)%0D%0A%09%7B+all_persons_list%5Bn%5D-%3Edisplay()%3B+%7D+%0D%0A+%0D%0A%09%2F%2F+delete+Bob%0D%0A%09delete+all_persons_list%5B1%5D%3B%0D%0A%09%0D%0A%09%2F%2F+iterate+through+all+of+the+Person+objects+%0D%0A%09std%3A%3Acout+%3C%3C+std%3A%3Aendl%3B+%0D%0A%09for(+unsigned+int+n+%3D+0%3B+n+%3C+all_persons_list.size()+%3B+n%2B%2B+)%0D%0A%09%7B+all_persons_list%5Bn%5D-%3Edisplay()%3B+%7D+%0D%0A%09%0D%0A%09std%3A%3Acout+%3C%3C+%22done!%22+%3C%3C+std%3A%3Aendl%3B+%0D%0A%09return+0%3B%0D%0A%7D%0D%0A

*/