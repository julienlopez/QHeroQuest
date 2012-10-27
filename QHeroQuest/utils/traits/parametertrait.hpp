#ifndef __PARAMETERTRAIT_HPP__
#define __PARAMETERTRAIT_HPP__

#include <Utils/Traits/Various>

namespace Utils {
namespace Traits {

template<class T> class ParameterTrait
{
public:

    typedef typename Select<isPointer<T>::value, T, T*>::type pointer;

    typedef typename Select<isPointer<T>::value, const T, const T*>::type const_pointer;

    typedef typename Select<isReference<T>::value, T, T&>::type reference;

    typedef typename Select<isReference<T>::value, const T, const T&>::type const_reference;
};

}
}

#endif
