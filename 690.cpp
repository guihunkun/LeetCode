/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
/* //DFS
class Solution {
public:
    int traversal (unordered_map<int,Employee*>& myMap, int id) {
        int sum = myMap[id]->importance;
        for (int i = 0; i < myMap[id]->subordinates.size(); ++i)
            sum += traversal(myMap,myMap[id]->subordinates[i]);

        return sum;
    }

    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> myMap;
        for (int i = 0; i < employees.size(); ++i) 
            myMap[employees[i]->id] = employees[i];

        return traversal(myMap,id);
    }
};
*/
//BFS
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int size = employees.size();
        unordered_map<int,Employee*> myMap;
        for (int i = 0; i < size; ++i) 
            myMap[employees[i]->id] = employees[i];
        
        queue<int> myQueue;
        myQueue.push(id);
        int result = 0;
        while (!myQueue.empty()) {
            int tempID = myQueue.front();
            myQueue.pop();
            result += myMap[tempID]->importance;

            for (int i = 0; i < myMap[tempID]->subordinates.size(); ++i)
                myQueue.push(myMap[tempID]->subordinates[i]);
        }

        return result;
    }
};




