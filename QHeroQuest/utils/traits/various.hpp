#ifndef __TRAITS_HPP__
#define __TRAITS_HPP__

#include <string>

namespace Utils {

namespace Traits {

template<class T> struct isVoid 
{
	static const bool value = false;
};
	
template<> struct isVoid<void> 
{
	static const bool value = true;
};

template<class T> struct isPointer 
{
	static const bool value = false;
};

template<class T> struct isPointer<T*> 
{
	static const bool value = true;
};

template<class T> struct isPointer<const T*> 
{
	static const bool value = true;
};

template<class T> struct isReference 
{
	static const bool value = false;
};

template<class T> struct isReference<T&> 
{
	static const bool value = true;
};

template<class T> struct isReference<const T&> 
{
	static const bool value = true;
};

// class template Select
// Selectionne un des deux type en fonction d'une valeur booléenne constante
// Utilisation: Select<flag, T, U>::type
// où:
// FLAG est un booléen constant lors de la compilation
// T et U sont des types
// type vaut T si flag vaut true, U sinon.

template<bool flag, typename T, typename U> struct Select 
{
	typedef T type;
};

template<typename T, typename U> struct Select<false, T, U> 
{
	typedef U type;
};

// class template IsSameType
// Renvoi true ssi les deux types sont identiques
// Utilisation: SameType<T, U>::value
// où:
// T et U sont des types
// value vaut vrai ssi les deux type sont identiques

template<typename T, typename U> struct IsSameType 
{
	enum { value = false};
};

template<typename T> struct IsSameType<T,T>
{
	enum { value = true};
};

template<class T> struct NullValue
{
        const static T value = 0;
};

template<> struct NullValue<std::string>
{
	static const std::string value;
};

}

}

#endif
