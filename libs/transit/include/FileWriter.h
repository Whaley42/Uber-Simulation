#include <map>

/**
 * @brief Writes information to CSV file  
 */
class FileWriter{
 public:
        /**
         * @brief Writes available information to a CSV file
         * 
         * @param[in] objects The entities within the physical space 
         */
        void WriteToCSV(std::map<std::string, std::map<std::string,
        float>> objects);
 private:
};

