#include <iostream>
#include <map>
#include "Schedule.h"

using namespace std;

Schedule::Schedule(string name)
{
  mName = name;
}

bool Schedule::dropCourse(std::string name)
{
  // TO DO: if the course was not already in the map, return false
  // otherwise, remove it from the map and return true!
	std::map<std::string, Course*>::iterator itr;
  itr = courseMap.find(name);
  if (itr == courseMap.end()) {
    return false;
  } else {
    courseMap.erase(itr);
    return true;
  }
}

bool Schedule::addCourse(Course* c)
{
  // TO DO: if the course was already in the map, return false
  // otherwise, add it to the map and return true!
	std::map<std::string, Course*>::iterator itr;
  for (itr = courseMap.begin(); itr != courseMap.end(); ++itr) {
    if (itr->second == c) {
      return false;
    }
  }

  courseMap.insert({c->getCourseName(), c});
  return true;
}

void Schedule::printAllAssignments()
{
	std::map<std::string, Course*>::iterator itr;
  cout << "##### Course: " << endl;
  for (itr = courseMap.begin(); itr != courseMap.end(); ++itr) {
    std::cout << "Course name: " << itr -> first << endl;
    std::set<Assignment*>::iterator itr2;
    std::set<Assignment*> assignments = itr -> second -> getAssignmentSet();

    cout << endl;
    cout << "Assignments:" << endl;
    for (itr2 = assignments.begin(); itr2 != assignments.end(); ++itr2) {
      std::cout << "Name: " << (*itr2) -> getName() << endl;
      std::cout << "Type: " << (*itr2) -> getType() << endl;
      std::cout << "Completion: " << (*itr2) -> isComplete() << endl;
    }
  }
  cout << "#### End course" << endl;
  cout << endl;
  cout << endl;
  // TO DO: print out the name of each course, followed by the set of assignments.
  // for each assignment, display its name, its type (essay vs hw vs exam), and whether or not it was completed.
  // formatting is up to you, but make sure it's easy to read!
}

std::map<std::string, Course*> Schedule::getCourses()
{
  return courseMap;
}
