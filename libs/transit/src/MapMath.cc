#include "MapMath.h"
#include <iostream>
#include <bits/stdc++.h>

float MapMath::CalculateAverage(std::vector<float> data){
    float sum = 0;
    for(int i =0; i < data.size(); i++){
        sum += data[i];
    }
    return sum/data.size();
}

float MapMath::CalculateMedian(std::vector<float> data){
    sort(data.begin(), data.end());
    int middle = data.size()/2;
    if(data.size() % 2 == 0){
        float mid1 = data[middle];
        float mid2 = data[middle-1];
        return (mid1+mid2)/2;
    }
    else{
        return data[middle];
    }
}

float MapMath::CalculateMax(std::vector<float> data){
    float max = data[0];
    for(int i = 0; i < data.size(); i++){
        if(data[i] > max){
            max = data[i];
        }
    }
    return max;
}

float MapMath::CalculateMin(std::vector<float> data){
    float min = data[0];
    for(int i = 0; i < data.size(); i++){
        if(data[i]<min){
            min = data[i];
        }
    }
    return min;
}

void MapMath::CreateVectors(std::map<std::string, std::map<std::string, float>> objects){
    for(auto const &ent1 : objects) {
        // ent1.first is the first key
       
        for(auto const &ent2 : ent1.second) {
            // ent2.first is the second key
            // ent2.second is the data
            if(ent2.first == "Distance"){
                distanceData.push_back(ent2.second);
            }
            else if(ent2.first == "Robots"){
                droneData.push_back(ent2.second);
            }
  }
}
}

std::map<std::string, float> MapMath::GetAnalytics(std::vector<float> data){
    std::map<std::string, float> returnMap;
    std::string avg = "Average";
    std::string med = "Median";
    std::string max = "Max";
    std::string min = "Min";
    returnMap.insert(std::make_pair(avg, CalculateAverage(data)));
    returnMap.insert(std::make_pair(med, CalculateMedian(data)));
    returnMap.insert(std::make_pair(max, CalculateMax(data)));
    returnMap.insert(std::make_pair(min, CalculateMin(data)));

    

    return returnMap;
    
}

