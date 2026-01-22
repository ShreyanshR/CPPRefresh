#include <vector>
#include <string>


class Player{
    public:
        std::string name;
        int age;
        std::string position;

        Player(std::string name, int age, std::string position)
            : name(name), age(age), position(position)

        {

        }

};



int main(){
    std::vector<Player> players;

    players.emplace_back("Lionel Messi", 35, "Middle Field");

}