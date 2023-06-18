#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &src) {}
Serializer::~Serializer() {}

Serializer &Serializer::operator=(Serializer const &rhs) {
  // if ( this != &rhs )
  //{
  // this->_value = rhs.getValue();
  //}
  return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
 }

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

std::ostream &operator<<(std::ostream &o, Serializer const &i) {
  // o << "Value = " << i.getValue();
  return o;
}
