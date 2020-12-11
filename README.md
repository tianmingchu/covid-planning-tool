# CS225 Final Project: COVID-19 Travel Planning Tool
## Team Members: Nayonika Roy, Tianming Chu
## Mentor: Vlas Zyrianov

### Project description:
The COVID-19 pandemic has created many complications for travelers. The close quarters of airports and planes makes air travel a challenge, so road trips provide an alternative solution. This tool aims to assist anyone planning a road trip within the United States by helping them find  a safe route that least exposes them to COVID-19. 

### Project components:
To accomplish our goal, we found a dataset containing the number of cases per 100k inhabitants of each state. This number represented the safety level of each state. We also found data that mapped each state to its surrounding states, helping us figure out which states could form connected paths. By entering this information into a graph data structure, we were then able to run breadth-first traversals and Dijkstra's algorithm on our data. Finally, we developed a landmark path algorithm that can take in any two states as well as a "landmark" state in order to produce a formatted path that travels between the two states while also crossing through the landmark.

### What comes next: 
We believe our project is already capable of providing people with useful information. With the right dataset, it could be even more effective. Our current dataset provides state-by-state data, but a dataset that uses town-by-town or county-by-county data would be even more accurate and allow people to make the most informed decisions while planning a trip. Additionally, this project would greatly benefit from a well-designed UI, which would make it much more accessible to the typical consumer.

### How to run the program:
1. Clone the repository.
2. In the terminal, cd into the project directory. 
3. To run the main program:
    1. Type 'make' in the terminal (single quotes not included).
    2. Type './finalproj' in the terminal.
    3. To run the landmark path with different values, open main.cpp and modify line 9 to replace the example values. Use graph.h to view the function definition.
4. To run the tests:
    1. Type 'make test' in the terminal.
    2. Run './test'

