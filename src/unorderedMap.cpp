#include <cstdint>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

struct CityRecord
{
    std::string Name;
    uint64_t Population;
    double Latitude, Longitude;
};


int main(){
    std::vector<CityRecord> cities;

    /*cities.emplace_back("Delhi", 100000, [2.4, 3.4] );
    cities.emplace_back("Putian", 100000, 2.4, 3.4 );
    cities.emplace_back("Paris", 100000, 2.4, 3.4 );
    cities.emplace_back("Montrouge", 100000, 2.4, 3.4 );

    for (const auto& city: cities){
        if (city.Name == "Berlin"){
            city.Population;
            break;
        }
    }
        */

    std::map<std::string, CityRecord> cityMap;
    cityMap["Melbourne"] = CityRecord{ "Melbourne", 10000, 2.4, 5.5};
    cityMap["Paris"] = CityRecord{ "Paris", 10000, 2.4, 5.5};
    cityMap["Mumbai"] = CityRecord{ "Mumbai", 10000, 2.4, 5.5};
    cityMap["New York"] = CityRecord{ "New York", 10000, 2.4, 5.5};

    std::cout << "Ordered Map" << std::endl;
    //CityRecord& berlinData = cityMap["Berlin"];
    for(auto& [name, city]: cityMap){
        std::cout << name << "\n Population" << city.Population << std::endl; 
    }

    std::unordered_map<std::string, CityRecord> cityMap1;

    cityMap1["Mumbai"] = CityRecord{ "Mumbai", 10000, 2.4, 5.5};
    cityMap1["New York"] = CityRecord{ "New York", 10000, 2.4, 5.5};
    cityMap1["Berlin"] = CityRecord{ "Berlin", 50000, 52.5, 13.4};  // Add Berlin before accessing with .at()

    //const auto& citys = cityMap1;

    //if the hash key is cont it can't insert with [], so we have to use .at
    //if you are fine with insertign data then you can go with []

    //const CityRecord& berlinData1 = citys.at("Berlin");

    //in the below name is the key, and city is the value
    std::cout << "UnOrdered Map" << std::endl;
    for(auto& [name, city]: cityMap1){
        std::cout << name << "\n Population" << city.Population << std::endl; 
    }


    return 0;

}


