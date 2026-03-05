#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()                   //template -> class -> function. need to write typename because type of iterator is dependent on template parameter T
{
    return this->c.begin();                                                 //this -> underlying container_type c -> original function
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

#endif