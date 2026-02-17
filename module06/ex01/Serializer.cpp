#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other)
{
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t newPtr = reinterpret_cast<uintptr_t>(ptr);
    return newPtr;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* newObj;
    
    //newObj->nb = 6;
    newObj = reinterpret_cast<Data *>(raw);
    return newObj;
}