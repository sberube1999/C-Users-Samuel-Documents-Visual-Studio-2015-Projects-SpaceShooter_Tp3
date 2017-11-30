#pragma once
// <sberube>
#ifndef _LIST_H_
/*
Liste doublement chaînée représentée par des boîtes
qui pointe sur la suivante et la précédante.

Utilisation: - Liste d'armes du joueur
- Liste d'ennemies dans le jeu
- Liste des bonus dans le jeu
- Liste des météorites
*/
template <class T>
class List
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

	List(const List&) = delete;

	//Representation
	Box start, end;
	size_t sz;

public:
	//Constructeur et affectateur
	List();
	~List();
	List& operator=(const List<T>& other);
	T& operator[](const int index);

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
	void Swap(List& other) noexcept;
};


template<class T>
inline List<T>::List() : sz(0)
{
}

template<class T>
inline List<T>::~List()
{
	// On vide la list
	while (sz > 0)
	{
		popFront();
	}
	delete start;
	delete end;
}

template<class T>
inline List<T>& List<T>::operator=(const List<T>& other)
{
	// l'index pour parcourir la chaine.
	Box *index = other.start.next;

	// On vide la chaîne
	while (sz > 0)
	{
		PopFront();
	}

	// On copie chaque éléments de other a this.
	for (size_t i = 0; i < other.sz; i++)
	{
		this->PushFront(index->value);
		index = index->next;
	}

	return *this;
}

template<class T>
inline T& List<T>::operator[](const int index)
{
	Box *indexPtr = start;
	for (size_t i = 0; i <= index; i++)
	{
		index = index->next;
	}
	return indexPtr->value;
}

template<class T>
inline T & List<T>::Front()
{
	return start.next->value;
}

template<class T>
inline T & List<T>::Back()
{
	return end.previous->value;
}

template<class T>
inline const T & List<T>::Front() const
{
		return start.next->value;
}

template<class T>
inline const T & List<T>::Back() const
{
	return end.previous->value;
}

template<class T>
inline bool List<T>::Empty() const
{
	return sz == 0;
}

template<class T>
inline size_t List<T>::Size() const
{
	return sz;
}

template<class T>
inline void List<T>::PushFront(const T& value)
{
	// Si la taille est de 0...
	if (sz == 0)
	{
		// Création d'une première nouvelle boîte.
		Box *first = new Box();
		first->next = end;
		first->previous = start;

		start.next = first;
		end.previous = first;
	}
	else
	{
		// Création d'une nouvelle boîte.
		Box *box = new Box();

		// On positionne cette-ci entre le début et la première boîte.
		box->previous = start;
		box->next = start.next;

		start.next->previous = box;
		start.next = box;
	}
	// Il y a un élément de plus
	sz++;
}

template<class T>
inline void List<T>::PushBack(const T& value)
{
	// Si la taille est de 0...
	if (sz == 0)
	{
		// Création d'une première nouvelle boîte.
		Box *first = new Box();
		first->next = end;
		first->previous = start;

		start.next = first;
		end.previous = first;
	}
	else
	{
		// Création d'une nouvelle boîte.
		Box *box = new Box();

		// On positionne cette-ci entre la fin et la dernière boîte.
		box->previous = end->previous;
		box->next = end;

		end.previous->next = box;
		end.previous = box;
	}
	// Il y a un élément de plus
	sz++;
}

template<class T>
inline void List<T>::PopFront()
{
	// Si il y a au moins un élément...
	if (sz > 0)
	{
		// On pointe sur le premier élément
		Box *popBox = start.next;
		
		// On l'enlève de la chaîne.
		start.next = popBox->next;
		popBox->next->previous = start;

		// On le supprime
		delete popBox;
		popBox = nullptr;

		// La taille est réduite
		sz--;
	}
}

template<class T>
inline void List<T>::PopBack()
{
	// Si il y a au moins un élément...
	if (sz > 0)
	{
		// On pointe sur le dernier élément
		Box *popBox = end.previous;

		// On l'enlève de la chaîne.
		end.previous = popBox->previous;
		popBox->previous->next = end;

		// On le supprime
		delete popBox;
		popBox = nullptr;

		// La taille est réduite
		sz--;
	}
}

template<class T>
inline void List<T>::Swap(List& other) noexcept
{
	// valeurs temporaires pour la permutation.
	Box *first = start.next;
	Box *last = end.previous;

	// On échange le premier et le dernier élément.
	start.next = other.start.next;
	end.previous = other.end.previous;

	other.start.next = first;
	other.end.prev = last;
}

#endif // !_DBL_CHAINED_LIST_H_
// </sberube>