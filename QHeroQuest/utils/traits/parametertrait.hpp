#ifndef __PARAMETERTRAIT_HPP__
#define __PARAMETERTRAIT_HPP__

namespace Utils {
namespace Traits {

template<class T> class ParameterTrait
{
public:
	typedef T& reference;
    typedef const T& const_reference;
};

}
}

#endif
