
## Project Description: 
This project allows the users to create a “uber like” simulation around the University of Minnesota campus. Users can schedule robots to be picked up and dropped off at certain places. There are drones located in the simulation that are responsible for picking up the robots. These drones and robots use different path strategies to get to their target location. There are also other entities that are located in the simulation that are just moving around the map.

## How To Run Simulation: 
cd /path/to/repo/project
make -j
./build/bin/transit_service 8081 apps/transit_service/web/
Go to the local host port that was assigned to the simulation. 
Once in the simulation, you can change the view to any entity that is currently in the simulation to follow them around the campus. To schedule a robot to be picked up and dropped off you need to go to http://127.0.0.1:8081/schedule.html. Once here, you can use the drop down menu to change the path strategy and choose where the robot will get picked up and dropped off. Finally, there is a slider that allows you to change the speed of the simulation. 

## What Does The Simulation Do? 
The simulation puts drones around the campus and searches for near entities. When a robot is put on campus the nearest drone will find the drone and pick them up. Then the drone will use the robot’s path strategy to get to the final destination. 

## Sprint Retrospective: 
Overall the whole sprint went well. We used a two week sprint to finish the whole project. We were able to plan out the parts we individually needed to complete and finish them on time.

Docker: https://hub.docker.com/repository/docker/whale239/homework4
UML: https://postimg.cc/jWQqkLLJ
