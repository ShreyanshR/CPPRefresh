#pragma once

#include <cstddef>


template<typename T>
class Vector
{
    public:
        Vector()
        {
            //allocate 2 elements
            ReAlloc(2);
        }

    void PushBack(const T& value){
        if(m_Size >= m_capacity){
            ReAlloc(m_capacity + m_capacity/2);
            
            m_data[m_Size] = value;
            m_Size++;
        }
    }

    const T& operator[](size_t index) const
    {
        return m_data[index];
    }

    T& operator[](size_t index) {
        return m_data[index];
    }

    size_t Size() const { return m_Size; }
    private:
        void ReAlloc(size_t newCapacity){
            //1. allocate new block of memory
            //2. copy(wate of perf) so maybe move existing element in the new block of memory
            //3. delete

            //as we are designing low level it's better not use smart pointer as unique ptr & shared pointer

            T* newBlock = new T[newCapacity];

            //if we are downsizing vector than we have to update it

            if(newCapacity < m_Size)
                m_Size = newCapacity;

            //move/copy the old into new block
            for(size_t i = 0; i < m_Size; i++)
                newBlock[i] = m_data[i];

            //delete the old data
            delete[] m_data;
            m_data = newBlock;
            m_capacity = newCapacity; 

        }

    private:
        T* m_data = nullptr;

        size_t m_Size = 0; //size of of our vector as in elements
        size_t m_capacity = 0; //how much we could store without allocating memory


};