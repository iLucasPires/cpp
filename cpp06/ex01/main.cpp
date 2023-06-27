#include "Serializer.hpp"

int main()
{
    Data *data = new Data();
    data->number = 42;
    data->str = "Hello World!";

    uintptr_t raw = Serializer::serialize(data);
    std::cout << "raw: " << raw << std::endl;
    Data *data2 = Serializer::deserialize(raw);
    std::cout << "data: " << data << std::endl;
    std::cout << "data2: " << data2 << std::endl;
    std::cout << "data2->number: " << data2->number << std::endl;
    std::cout << "data2->str: " << data2->str << std::endl;

    delete data;
    return 0;
}
