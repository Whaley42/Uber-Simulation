Team Number: 001-30
Members: Jake Whaley (whale239@umn.edu) John Reichel (reich597@umn.edu)

Project Description: This project allows the users to create a “uber like” simulation around the University of Minnesota campus. Users can schedule robots to be picked up and dropped off at certain places. There are drones located in the simulation that are responsible for picking up the robots. These drones and robots use different path strategies to get to their target location. There are also other entities that are located in the simulation that are just moving around the map.

How To Run Simulation: 
cd /path/to/repo/project
make -j
./build/bin/transit_service 8081 apps/transit_service/web/
Go to the local host port that was assigned to the simulation. 
Once in the simulation, you can change the view to any entity that is currently in the simulation to follow them around the campus. To schedule a robot to be picked up and dropped off you need to go to http://127.0.0.1:8081/schedule.html. Once here, you can use the drop down menu to change the path strategy and choose where the robot will get picked up and dropped off. Finally, there is a slider that allows you to change the speed of the simulation. 

What Does The Simulation Do: The simulation puts drones around the campus and searches for near entities. When a robot is put on campus the nearest drone will find the drone and pick them up. Then the drone will use the robot’s path strategy to get to the final destination. 

New Feature: 
What does it do: The new feature collects data on all entities that are in the simulation. This data includes the total distance that the entities have traveled during the simulation. For drones it includes the amount of robots picked up. After the simulation ends, it analyzes the data and sends it to a csv file. 

Why is it interesting: This feature is interesting because it would be useful in a real life scenario where you need to keep track of drivers (drones). The total distance is used to see how much they are traveling as well as where the most popular areas are because it collects data on which drivers are picking up the most people. It also analyzes the data so we can see what drivers are underperforming compared to the average and median drivers. 

How does it add to existing work: This extension doesn’t change anything about the current simulation. This extension just makes it useful for people who are curious about the statistics of the entities after the simulation ends. 

Which design pattern did you choose: We chose the singleton pattern for our implementation. We chose this design because it allowed us to use this class with all entities while making sure that there is always one instance of the class. This means that throughout the simulation it would always update the same data. 

Instruction to use: You will run the simulation like normal. To end the simulation and receive the data you will need to press CONTROL + C in the terminal to end the simulation. Then the csv file will appear in the outermost folder next to the readme document. 

Sprint Retrospective: Overall the whole sprint went well. We used a two week sprint to finish the whole project. We were able to plan out the parts we individually needed to complete and finish them on time. We could improve on communication when exactly different parts were to be finished. 

Presentation: https://drive.google.com/file/d/1wgwz1HPsbIlFAwNMi0_YbhEW5MnU8JFs/view
Docker: https://hub.docker.com/repository/docker/whale239/homework4
UML: https://postimg.cc/jWQqkLLJ
