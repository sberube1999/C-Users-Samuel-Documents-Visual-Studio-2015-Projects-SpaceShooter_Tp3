#pragma once
#ifndef _D_QUEUE_H_

// DECLARATIONS
template <class T>
class DQueue
{
	//DQueue(const DQueue&) = delete;

	//Representation
	T *data[10];
	size_t sz;
	size_t cap;
	int head;

public:

	//Constructeur et affectateur
	DQueue();
	~DQueue();
	DQueue& operator=(const DQueue<T>&);
	T operator[](const int index);
	//Accesseur
	T& front();
	T& back();
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
	void Swap(DQueue&) noexcept;
};

//DEFINITIONS
template<class T>
inline DQueue<T>::DQueue()
{
	cap = data->GetSize()
	sz = 0;
	head = 0;
}

template<class T>
inline DQueue<T>::~DQueue()
{
	delete data;
	data = nullptr;
}

template<class T>
inline DQueue<T> & DQueue<T>::operator=(const DQueue<T> &other)
{

}

template<class T>
T DQueue<T>::operator[](const int index)
{
	return data[(head + index) % cap];
}

template<class T>
inline T & DQueue<T>::front()
{
	// Il n'y a pas de front si la file est vide. Attention à l'utilisation.
	return data[head];
}

template<class T>
inline T & DQueue<T>::back()
{
	// Il n'y a pas de back si la file est vide. Attention à l'utilisation.
	return data[(head + sz - 1) % cap];
}

template<class T>
inline const T & DQueue<T>::Front() const
{
	// Il n'y a pas de front si la file est vide. Attention à l'utilisation.
	return data[head];
}

template<class T>
inline const T & DQueue<T>::Back() const
{
	// Il n'y a pas de back si la file est vide. Attention à l'utilisation.
	return data[(head + sz - 1) % cap];
}

template<class T>
inline bool DQueue<T>::Empty() const
{
	// Si le size est de 0, c'est qu'il est vide.
	return sz == 0;
}

template<class T>
inline size_t DQueue<T>::Size() const
{
	// On retourne la taille de la file.
	return sz;
}

template<class T>
inline void DQueue<T>::PushFront(const T & value)
{

	sz++;
}

template<class T>
inline void DQueue<T>::PushBack(const T & value)
{

	sz++;
}

template<class T>
inline void DQueue<T>::PopFront()
{

	sz--;
}

template<class T>
inline void DQueue<T>::PopBack()
{

	sz--;
}

template<class T>
inline void DQueue<T>::Swap(DQueue & other) noexcept
{

}

#endif // !_D_QUEUE_H_