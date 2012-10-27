#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <Utils/PlainStorage>

class Case;

template<uint HAUTEUR, uint LARGEUR> class Graph : public PlainStorage<boost::shared_ptr<Case>, HAUTEUR, LARGEUR>
{
public:
    Graph();
};

#endif // GRAPH_HPP
