#ifndef __PLAIN_STORAGE_HPP__
#define __PLAIN_STORAGE_HPP__

#include <Utils/Traits/ParameterTrait>
#include <Utils/Exception>

#include <boost/array.hpp>

namespace Utils {

template<class T, uint HAUTEUR = 3, uint LARGEUR = 3> class PlainStorage
{
public:
	typedef T stored_type;

	PlainStorage()
	{}

        PlainStorage(typename Traits::ParameterTrait<T>::const_reference defaut)
	{
            for(int i = 0; i < HAUTEUR; i++)
                for(int j = 0; j < LARGEUR; j++) m_data[i][j] = defaut;
	}

        typename Traits::ParameterTrait<T>::const_reference operator()(uint i, uint j) const
	{
		if(i >=HAUTEUR || j >= LARGEUR) throw Exception("Index invalide");
		return m_data[i][j];
	}

        typename Traits::ParameterTrait<T>::reference operator()(uint i, uint j)
	{
		if(i >=HAUTEUR || j >= LARGEUR) throw Exception("Index invalide");
		return m_data[i][j];
	}
	
        uint height() const
	{
		return HAUTEUR;
	}
	
        uint width() const
	{
		return LARGEUR;
	}

private:
        boost::array<boost::array<T, LARGEUR>, HAUTEUR> m_data;
};

}

#endif
