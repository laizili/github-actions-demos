#include <iostream>
#include <any>
#include <string>

struct Person
{
    std::string name;
    int age;
    std::string id;
    Person(std::string name, int age, std::string id) : name(std::move(name)), age(age), id(std::move(id))
    {
    }
};

int main()
{
    char buf[sizeof(Person)];
    auto res = new (buf) Person("李东晖", 22, "li19970618");
    std::cout << res->name << " " << res->age <<" " << res->id <<"\n";
    std::cout <<std::boolalpha << ((void*)buf == (void*)res);
    // delete res;
}