#include "FileWriter.h"
#include "MapMath.h"
#include <map>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <strstream>
using namespace std;

void FileWriter::WriteToCSV(std::map<std::string, std::map<std::string, float>> objects){

    fstream myFile;
    myFile.open("SimulationData.csv", ios::out);
    myFile << "Name,Distance Traveled,Robots Picked up\n";

    MapMath m;
    m.CreateVectors(objects);
    std::vector<float> disData = m.GetDistanceData();
    std::vector<float> droneData = m.GetDroneData();
    std::map<std::string, float> disAnalytics = m.GetAnalytics(disData);
    std::map<std::string, float> droneAnalytics = m.GetAnalytics(droneData);

    


    for(auto const &ent1 : objects) {
        // ent1.first is the first key
        myFile << ent1.first << ",";
        for(auto const &ent2 : ent1.second) {
            // ent2.first is the second key
            // ent2.second is the data
            myFile << ent2.second << ",";
        }
        myFile <<"\n";
    }   
    myFile << "Distance Analytics\n";
    myFile << ",Average:,Median:,Max:,Min:\n";
    myFile << "," << disAnalytics["Average"] <<","<< disAnalytics["Median"] << "," << disAnalytics["Max"] <<","<<disAnalytics["Min"]<<"\n";
    myFile << "Robots Picked Up Analytics\n";
    myFile << "," << droneAnalytics["Average"] <<","<< droneAnalytics["Median"] << "," << droneAnalytics["Max"] <<","<<droneAnalytics["Min"];


}