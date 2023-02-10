#include <map>
#include <vector>

/**
 * @brief Information pertaining to the map/physical system
 */
class MapMath{
 public:
   /**
    * @brief Get the map's analytics
    */
    std::map<std::string, float> GetAnalytics(std::vector<float>);
   /**
    * @brief Creates vectors which act as guiding points for the map
    * 
    * @param[in] object The vector object to be create
    */
    void CreateVectors(std::map<std::string, std::map<std::string,
    float>> objects);
   /**
    * @brief Get the distance data pertaining to the map
    * 
    * @return The distance data 
    */
    std::vector<float> GetDistanceData() {return distanceData;}
   /**
    * @brief Get the drone data pertaining to the map
    * 
    * @return The drone data 
    */
    std::vector<float> GetDroneData() {return droneData;}

 private:
    std::vector<float> distanceData;
    std::vector<float> droneData;
    float CalculateAverage(std::vector<float> data);
    float CalculateMedian(std::vector<float> data);
    float CalculateMax(std::vector<float> data);
    float CalculateMin(std::vector<float> data);
};
