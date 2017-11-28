/*
Origine: Travail pratique #2: Chained queue
Date: 2017-11-03
Auteur: Samuel Bérubé & Samuel Masson

Nous avons ici un implementation d'une file chainée
representée a l'aide de boîtes contenant la valeur
stockée et un pointeur vers la suivante. Nou avons
la première et la dernière boîte comme limites.

Utilisation: -Liste d'ennemies à mettre dans le jeu
			 -Liste des projectiles du jeu
			 -Accumulation de commande
*/
#ifndef _CHAINED_QUEUE_H_

// DECLARATIONS
template <class T>
class ChainedQueue
{
	

	ChainedQueue(const ChainedQueue&) = delete;

	//Representation
	T *data[10];
	size_t sz;
	size_t cap;
	int head;

public:

	//Constructeur et affectateur
	ChainedQueue();
	~ChainedQueue();
	ChainedQueue& operator=(const ChainedQueue<T>&);

	//Accesseur
	T& front();
	T& back();
	const T& front() const;
	const T& back() const;

	//Capacite
	bool empty() const;
	size_t size() const;

	//Fonction generatrice
	void PushFront(const T& value);
	void PushBack(const T& value);
	void PopFront();
	void PopBack();
	void swap(ChainedQueue&) noexcept;
};

//DEFINITIONS
template<class T>
inline ChainedQueue<T>::ChainedQueue()
{
	// La file commence vide
	sz = 0;
}

template<class T>
inline ChainedQueue<T>::~ChainedQueue()
{
	// On enleve TOUS les elements
	while (sz != 0)
	{
		pop();
	}
	// Nettoyage
	first = nullptr;
	last = nullptr;
}

template<class T>
inline ChainedQueue<T> & ChainedQueue<T>::operator=(const ChainedQueue<T> &other)
{
		// index qui commence au début
		Box* currBox = other.first;
		// On vide notre chaine actuelle (gauche de =)
		while (sz != 0)
		{
			pop();
		}
		// on met tous les elements de other dans this.
		while (sz != other.sz)
		{
			push(currBox->value);
			currBox = currBox->next;
		}
	return *this;
}

template<class T>
inline T & ChainedQueue<T>::front()
{
	// Il n'y a pas de front si la file est vide.
	if (sz > 0)
	{
		return first->value;
	}
}

template<class T>
inline T & ChainedQueue<T>::back()
{
	// Il n'y a pas de back si la file est vide.
	if (sz > 0)
	{
		return last->value;
	}
}

template<class T>
inline const T & ChainedQueue<T>::front() const
{
	// Il n'y a pas de front si la file est vide.
	if (sz > 0)
	{
		return first->value;
	}
}

template<class T>
inline const T & ChainedQueue<T>::back() const
{
	// Il n'y a pas de back si la file est vide.
	if (sz > 0)
	{
		return last->value;
	}
}

template<class T>
inline bool ChainedQueue<T>::empty() const
{
	// Si le size est de 0, c'est qu'il est vide.
	return sz == 0;
}

template<class T>
inline size_t ChainedQueue<T>::size() const
{
	// On retourne la taille de la file.
	return sz;
}

template<class T>
inline void ChainedQueue<T>::push(const T & value)
{
	// Si le size est de 0, la fin et le début deviennent la meme nouvelle boite
	if (sz == 0)
	{
		first = new Box(value, nullptr);
		last = first;
		sz++;
	}
	else
	{
		// Creation de la nouvelle boite.
		Box* newBox = new Box(value, nullptr);
		// On pointe sur la nouvelle boite
		last->next = newBox;
		// La derniere box change
		last = newBox;
		// alors taille augmente donc.
		sz++;
	}

}

template<class T>
inline void ChainedQueue<T>::pop()
{
	if (sz > 0)
	{
		// On cree un pointeur temporaire sur le deuxieme elmement,
		Box* newFirst = first->next;
		// on efface le prmier element
		delete first;
		// et le deuxieme element devient le premier.
		first = newFirst;
		// cleaning
		newFirst = nullptr;
		// On perd un element, donc la taille est reduite.
		sz--;
	}
}

template<class T>
inline void ChainedQueue<T>::swap(ChainedQueue & other) noexcept
{
	// On fait ici une permutation des deux pointeurs et du size.

	// Structure teporaire
	Box* firstTemp = first;
	Box* lastTemp = last;
	size_t szTemp = sz;

	// On met la structure interne de other dans this
	first = other.first;
	last = other.last;
	sz = other.sz;

	// On met la strtucture temporaire de this dans other
	other.first = firstTemp;
	other.last = lastTemp;
	other.sz = szTemp;

	// clean-up
	firstTemp = nullptr;
	lastTemp = nullptr;
}

#endif // !_CHAINED_QUEUE_H_