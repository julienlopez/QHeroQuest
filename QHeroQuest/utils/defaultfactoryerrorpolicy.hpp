#ifndef __DEFAULTFACTORYERRORPOLICY__
#define __DEFAULTFACTORYERRORPOLICY__

#include <Utils/Traits/ParameterTrait>

#include <stdexcept>

namespace Utils {

template<class IdentifierType, class ProductType> class DefaultFactoryErrorPolicy
{
public:
    class Exception : public std::exception
    {
    public:
        Exception(typename Traits::ParameterTrait<IdentifierType>::const_reference id) : std::exception(), m_unknownId(id)
        {}

        virtual const char* what()
        {
            return "Type inconnu passé à la factory.";
        }

        typename Traits::ParameterTrait<IdentifierType>::const_reference getId() const
        {
            return m_unknownId;
        }

    private:
        IdentifierType m_unknownId;
    };

protected:
    static ProductType* onUnknownType(typename Traits::ParameterTrait<IdentifierType>::const_reference id)
    {
        throw Exception(id);
    }
};

}

#endif
