#pragma once
#ifndef _DOUBLE_CHAINED_LIST_H_

template <class T>
class DoubleChainedList
{
private:
	struct Box
	{
		T value;
		Box* next;
		Box* previous;
		Box(const T& value, Box* next) :value(value), next(next) {}
	};

	DoubleChainedList(const DoubleChainedList&) = delete;

	//Representation
	Box *first, *last;
	size_t sz;
public:
	//Constructeur et affectateur
	DoubleChainedList();
	~DoubleChainedList();
	DoubleChainedList& operator=(const DoubleChainedList<T>&);
	DoubleChainedList& operator[](const DoubleChainedList<T>&);

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
	void Swap(DoubleChainedList&) noexcept;
};


template<class T>
inline DoubleChainedList<T>::DoubleChainedList() : sz(0)
{
}

template<class T>
inline DoubleChainedList<T>::~DoubleChainedList()
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
inline DoubleChainedList& DoubleChainedList<T>::operator=(const DoubleChainedList<T>&)
{

}

template<class T>
inline DoubleChainedList& DoubleChainedList<T>::operator[](const DoubleChainedList<T>&)
{

}

template<class T>
inline T & DoubleChainedList<T>::Front()
{
	if (size > 0)
	{
		return first->value;
	}
}

template<class T>
inline T & DoubleChainedList<T>::Back()
{
	if (size > 0)
	{
		return last->value;
	}
}

template<class T>
inline const T & DoubleChainedList<T>::Front() const
{
	if (size > 0)
	{
		return first->value;
	}
}

template<class T>
inline const T & DoubleChainedList<T>::Back() const
{
	if (size > 0)
	{
		return last->value;
	}
}

template<class T>
inline bool DoubleChainedList<T>::Empty()
{
	return sz == 0;
}

template<class T>
inline size_t DoubleChainedList<T>::Size()
{
	return sz;
}

template<class T>
inline void DoubleChainedList<T>::PushFront(const T& value)
{
	if (sz == 0)
	{
		first = new Box()
	}
	sz++;
}

template<class T>
inline void DoubleChainedList<T>::PushBack(const T& value)
{

}

template<class T>
inline void DoubleChainedList<T>::PopFront()
{

}

template<class T>
inline void DoubleChainedList<T>::PopBack()
{

}

template<class T>
inline void DoubleChainedList<T>::Swap(DoubleChainedList&) noexcept
{

}

#endif // !_DOUBLE_CHAINED_LIST_H_