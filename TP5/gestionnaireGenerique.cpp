#include "gestionnaireGenerique.h"

template<typename T, typename C>
C GestionnaireGenerique<T, C>::getConteneur() const
{
	return conteneur_;
}

template<typename T, typename C>
void GestionnaireGenerique<T, C>::ajouter(const T& t)
{
	FoncteurAjouter(T);
}

template<typename T, typename C>
int GestionnaireGenerique<T, C>::getNombreElements() const
{
	return C.size();
}
