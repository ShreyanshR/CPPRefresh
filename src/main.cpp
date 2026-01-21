#include <iostream>
#include "utils.h"
#include <ostream>
#include <string>
#include <vector>

#define LOG(x) std::cout << x << std::endl;

void Increment(int& value){
    value++;
}

class Player{


    int x, y;
    int speed;

    Player(){
        x = 0;
        y = 0;
        speed = 5;
    }
    void move(int newX, int newY){
        x = newX;
        y = newY;
    }
};

class Log{
    public:
};

struct Entity
{
    static int x, y;

    void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

struct Vertex
{
    float x,y,z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z)
        {

        }

    //Copy constructor
    Vertex(const Vertex& vertex)
        : x(vertex.x), y(vertex.y), z(vertex.y)
    {
        std::cout << "Copied!" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

template<typename T>
void Print(T value)
{
    std::cout<<value<<std::endl;
}

template<typename T, int N>
class Array
{
    private:
        T m_array[N];
    public:
        int getSize() const {return N;};

};

template<typename T, int N>
class Second
{
private:
    T m_array[N];

public:
    Second(const T& initialValue)
    {
        for(int i = 0; i < N; i++)
            m_array[i] = initialValue;
    }

    int getSize() const { return N; }
};

int main() {
    /*LOG("Hello World");
    int var = 8;
    char* buffer = new char[8];
    memset(buffer, 0, 8);

    char** ptr = &buffer;

    int a = 5;
    Increment(a);
    LOG(a);

    std::cout << "Welcome to CPPRefresh!" << std::endl;
    
    utils::printMessage("This is a sample C++ project");
    
    int result = utils::add(5, 3);
    std::cout << "5 + 3 = " << result << std::endl;
    */

    std::vector<Vertex> vertices;
    vertices.push_back(Vertex(1,2,3));
    vertices.push_back(Vertex(4,5,6));
    vertices.push_back(Vertex(7,8,9));

    //for(int i = 0; i < vertices.size(); i++)
    //    std::cout << vertices[i] << std::endl;


    //vertices.erase(vertices.begin()+1);

    //for (Vertex v: vertices)
    //    std::cout << v << std::endl;
    Print(5);
    Print("hello");

    Array<std::string, 10> arrayS;
    Array<int, 5> arrayI;
    std::cout<<arrayS.getSize()<<std::endl;
    std::cout<<arrayI.getSize()<<std::endl;

    Second<std::string, 10> names("hello");
    
    std::cin.get();
    
    return 0;
}
