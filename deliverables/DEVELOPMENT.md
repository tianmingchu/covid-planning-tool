## Week 1 - 11/18/2020
   - This first week we met & discussed the scope of our project and brainstormed ideas. We eventually settled on turning the United States into a weighted graph with states as vertices and edges indicating the number of cases per 100k people over the last week. We intend to implement the BFS traversal as well as Landmark path so one can figure out the safest route from one state to another while hitting a third state.

## Week 2 - 11/22/2020
   - We worked on taking input from the downloaded file and organizing it neatly in a data structure. The data is in a .csv file so we decided to use ifstream to extract data from the file.

## Update for week 2 - 11/25/2020
   - After successfully implementing a way to get the data we want from the file we started working on the Graph class and Edge class. After doing so we then took our covid data and turned it into a graph that we can hopfully use the algorithms on.

## Week 3 - 11/29/2020
   - Using a .csv file with each state and its adjacent states we are able to turn the covid data into an accurate graph with edges connection their neighbors. We also worked on implementing the BFS traversal. When running the traversal on our graph we see the BFS traversal of all 50 states from one origin state which is neat to see.

## Update for week 3 - 12/04/2020
   - We finished our second algorithm, the landmark path. Now we are able to see the path one should take when traveling from one state to another while hitting a third state. Since we are basically done with our code we will start working on the write-up and short video.
