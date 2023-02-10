#include "IEntity.h"
#include <map>
#include "util/json.h"
#include "math/vector3.h"

/**
 * @brief Information pertaining to active entities and in-service routes
 */
class DataCollector{
 public:
        // DataCollector(const DataCollector&) = delete;

       /**
        * @brief Retrieve all available information
        */
        static DataCollector& Get();

       /**
        * @brief Add object to the data collector
        * 
        * @param[in] entity The object to be added
        */
        void AddObject(IEntity* entity);

       /**
        * @brief Set distance to the data collector
        * 
        * @param[in] pos1 Reference point
        * @param[in] pos2 Reference point
        * @param[in] name Identifier of this distance
        */
        void SetDistance(Vector3 pos1, Vector3 pos2, std::string name);

       /**
        * @brief Add robot to the data collector
        * 
        * @param[in] name Name of the robot being added
        */
        void AddRobot(std::string name);
       
       /**
        * @brief Get the map being used as the physical space
        * 
        * @param[in] objects The objects pertaining to the map
        */
        std::map<std::string, std::map<std::string, float>> GetMap()
        {return objects;}

 private:
        DataCollector() {}
        std::map<std::string, std::map<std::string, float>> objects;
};
