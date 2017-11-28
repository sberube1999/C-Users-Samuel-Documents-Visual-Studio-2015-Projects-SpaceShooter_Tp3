#pragma once
// <sberube>
#ifndef _DBL_CHAINED_LIST_H_
/*
Liste doublement chaînée représentée par des boîtes
qui pointe sur la suivante et la précédante.

Utilisation: - Liste d'armes du joueur
			 - Liste d'ennemies dans le jeu
			 - Liste des bonus dans le jeu
			 - Liste des météorites
*/
template <class T>
class DblChainedList
{
private:
	struct Box
	{
		T value;
		Box* next;
		Box* previous;
		Box(const T& value, Box* next) :value(value), next(next) {}
		Box() {}
	};

	DblChainedList(const DblChainedList&) = delete;

	//Representation
	Box *first, *last;
	size_t sz;
public:
	//Constructeur et affectateur
	DblChainedList();
	~DblChainedList();
	DblChainedList& operator=(const DblChainedList<T>&);
	DblChainedList& operator[](const DblChainedList<T>&);

	//Accesseur
	T& Front();
	T& Back();
	const T& Front() const;
	const T& Back() const;

	//Capacite
	bool Empty() const;
	size_t Size() const;

	//Fonction generatrice
	void PushFront(const T& value);
	void PushBack(const T& value);
	void PopFront();
	void PopBack();
	void Swap(DblChainedList&) noexcept;
};


template<class T>
inline DblChainedList<T>::DblChainedList() : sz(0)
{
}

template<class T>
inline DblChainedList<T>::~DblChainedList()
{
	// On vide la list
	while (sz > 0)
	{
		popFront();
	}
	// Cleaning
	first = nullptr;
	last = nullptr;
}

template<class T>
inline DoubleChainedList& DblChainedList<T>::operator=(const DblChainedList<T>&)
{

}

template<class T>
inline DoubleChainedList& DblChainedList<T>::operator[](const DblChainedList<T>&)
{

}

template<class T>
inline T & DblChainedList<T>::Front()
{
	if (size > 0)
	{
		return first->value;
	}
}

template<class T>
inline T & DblChainedList<T>::Back()
{
	if (size > 0)
	{
		return last->value;
	}
}

template<class T>
inline const T & DblChainedList<T>::Front() const
{
	if (size > 0)
	{
		return first->value;
	}
}

template<class T>
inline const T & DblChainedList<T>::Back() const
{
	if (size > 0)
	{
		return last->value;
	}
}

template<class T>
inline bool DblChainedList<T>::Empty() const
{
	return sz == 0;
}

template<class T>
inline size_t DblChainedList<T>::Size() const
{
	return sz;
}

template<class T>
inline void DblChainedList<T>::PushFront(const T& value)
{
	// Si la taille est de 0...
	if (sz == 0)
	{
		// Création d'une première nouvelle boîte qui pointe sur elle-même.
		first = new Box()
		first->next = first;
		first->previous = first;
		// La dernière est aussi la première boîte.
		last = first;
	}

	// Il y a un élément de plus
	sz++;
}

template<class T>
inline void DblChainedList<T>::PushBack(const T& value)
{

}

template<class T>
inline void DblChainedList<T>::PopFront()
{

}

template<class T>
inline void DblChainedList<T>::PopBack()
{

}

template<class T>
inline void DblChainedList<T>::Swap(DblChainedList&) noexcept
{

}

#endif // !_DBL_CHAINED_LIST_H_
// </sberube>