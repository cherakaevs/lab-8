#include<iostream>
#include<cstdio>

template<typename T>
std::size_t binSearch(T* arr, const size_t size, const T& key) {
	if (!arr)return 0;
	int l = 0, r = size - 1;
	int mid;
	while (l <= r) {
		mid = (r + l) / 2;
		if (key < arr[mid])r = mid - 1;
		else if (arr[mid] < key)l = mid + 1;
		else return mid;
	}
	return l;
	
}

template<typename T>
class OrderedVector {
	T* _data;
	size_t _size;
public:
	OrderedVector() :_data(nullptr), _size(0) {}
	OrderedVector(const size_t size) {
		if (size == 0) {
			_size = 0;
			_data = nullptr;
		}
		else {
			_size = size;
			_data = new T[size];
			for (std::size_t i = 0; i < size; ++i)_data[i] = 0;
		}
	}
	~OrderedVector() {
		delete _data;
		_data = nullptr;
		_size = 0;
	}

	OrderedVector(const OrderedVector&) = delete;

	OrderedVector(OrderedVector&&) = delete;

	OrderedVector& operator=(const OrderedVector&) = delete;

	OrderedVector& operator=(OrderedVector&&) = delete;

	void Print()const {
		for (std::size_t i = 0; i < _size; ++i) cout << _data[i] << "  ";
	}

	bool Insert(const T & value) {
		if (_size == 0) {
			_data = new T[1];
			_data[0] = value;
			++_size;
			return true;
		}
		if (_size == 1) {
			auto tmp = _data[0];
			std::size_t ind = binSearch(_data, _size, value);
			delete _data;
			_data = new T[2];
			if (ind == 1) {
				_data[0] = tmp;
				_data[1] = value;
				++_size;
				return true;
			}
			else {
				_data[0] = value;
				_data[1] = tmp;
				++_size;
				return true;
			}
		}
		else {
			std::size_t ind = binSearch(_data, _size, value);
			T* newArr = new T[_size + 1];
			for (std::size_t i = 0; i < ind; ++i) {
				newArr[i] = _data[i];
			}
			newArr[ind] = value;
			for (std::size_t i = ind + 1; i < _size + 1; ++i) {
				newArr[i] = _data[i - 1];
			}
			_data = newArr;
			++_size;
			return true;
		}
		return false;
	}

	bool Contains(const T & key) {
		if (_size == 0)return false;
		if (_size == 1)return !(_data[1] != key);
		auto i = binSearch(_data, _size, key);
		if (i == _size)return false;
		return !(_data[i] != key);
	}

	bool Remove(const T & key) {
		if (_size == 0)return false;
		if (_size == 1) {
			if (_data[0] != key)return false;
			else delete _data;
			_data = nullptr;
			--_size;
			return true;
		}
		else {
			auto ind = binSearch(_data, _size, key);
			if (ind == _size)return false;
			if (_data[ind] != key)return false;
			else {
				auto tmp = new T[_size - 1];
				for (std::size_t i = 0; i < ind; ++i)tmp[i] = _data[i];
				for (std::size_t i = ind + 1; i < _size; ++i)tmp[i - 1] = _data[i];
				delete _data;
				_data = tmp;
				--_size;
				return true;
			}
		}
		return false;
	}

};