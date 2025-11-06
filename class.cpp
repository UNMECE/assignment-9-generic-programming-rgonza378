#include <iostream>
#include <stdexcept>


template <typename T>
class GenericArray {
private:
		T* data;
		int length;

public:

		GenericArray() {
				data = nullptr;
				length = 0;
		}

		~GenericArray() {
				delete[] data;
		}


		void addElement(T value) {
				T* newData = new T[length +1];

				for (int i = 0; i < length; i++)
						newData[i] = data[i];

				newData[length] = value;

				delete[] data;

				data = newData;
				length++;
		}


		T at(int index) const {
				if (index < 0 || index >= length)
						throw std::out_of_range("Index is out of bounds");
				return data[index];
		}


		int size() const {
				return length;
		}


		T sum() const {
				T total = 0;
				for (int i = 0; i < length; i++)
						total += data[i];
				return total;
		}


		T max() const {
				if (length == 0)
						throw std::runtime_error("The array is empty");
				T maxVal = data[0];
				for (int i = 1; i < length; i++)
						if (data[i] > maxVal)
								maxVal = data[i];
				return maxVal;
		}


		T min() const {
				if (length == 0)
						throw std::runtime_error("the array is empty");
				T minVal = data[0];
				for (int i = 1; i < length; i++)
						if (data[i] < minVal)
								minVal = data[i];
				return minVal;
		}

		T* slice(int begin, int end) const {
				if (begin < 0 || end >= length || begin > end)
						throw std::out_of_range("Slice bounds are invalid");

				int newSize = end - begin +1;
				T* sliceArray = new T[newSize];

				for (int i = 0; i < newSize; i++)
						sliceArray[i] = data[begin + i];

				return sliceArray;
		}
};


int main() {
		GenericArray<int> int_array;

		for (int i = 0; i < 10; i++)
				int_array.addElement(i * 2);

		std::cout << "Size of array: " << int_array.size() << std::endl;
		std::cout << "Sum of array: " << int_array.sum() << std::endl;
		std::cout << "Max: " << int_array.max() << "\tmin: " << int_array.min() << std::endl;

		int begin = 1, end = 5;
		int* sliced = int_array.slice(begin, end);
		std::cout << "Slice (" << begin << "," << end << "): ";
		for (int i = 0; i <= end - begin; i++)
				std::cout << sliced[i] << " ";
		std::cout << std::endl;

		delete[] sliced;

		return 0;
}
