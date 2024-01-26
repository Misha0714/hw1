#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite



// int main(int argc, char* argv[]) {
//   // Item addValuetoEmpty()
//   // Item addValuetoOne()
//   // Item addValuetoMany(1,2,3,4,5)
//   // Item removeValuefromEmpty()
//   // Item removeValuefrom


bool testPushAndPop() {
    ULListStr list;
    list.push_front("Test1");
    //std::cout << list.front() << std::endl; 
    list.push_back("Test2");
    list.pop_front();
    list.pop_back();
  
    // Add some conditions to check if the test passed
    // For now, just returning true as a placeholder
    return true;
}

bool testGetSet() {
    ULListStr list;
    list.push_back("Test1");
    list.push_back("Test2");
    list.set(0, "NewTest1");

    // Test invalid location
    try {
        list.get(2);
    } catch (const std::invalid_argument& e) {
        // Expected exception
        return true;
    }

    // Add additional checks as necessary
    return false; // Return false if the test didn't pass as expected
}

int main() {
    if(testPushAndPop()) {
        std::cout << "testPushAndPop passed" << std::endl;
    } else {
        std::cout << "testPushAndPop failed" << std::endl;
    }

    if(testGetSet()) {
        std::cout << "testGetSet passed" << std::endl;
    } else {
        std::cout << "testGetSet failed" << std::endl;
    }

    std::cout << "All tests completed" << std::endl;
    return 0;
}























  //Test Case ListInsertBack.OneItemAdd
  // first we create a vector to hold our data
	// std::vector<std::string> contents{"768", "1024", "1536", "a", "b", "c", "d", "e", "f", "g", "h"};

	// // then we create a new list with that data
  
	// ULListStr * populatedList = new ULListStr();
  
  // for(std::string n : contents)
  // {
  //   populatedList->push_back(n);
	// 	std::cout << populatedList->back() << " ";
  //   std::cout << populatedList->size() << std::endl;
  // }
  // std::cout << populatedList->get(10) <<std::endl; 

	// // then we assert that the list contains that data
	// // EXPECT_TRUE(checkListContent(populatedList, contents));

	// delete populatedList;

  // std::vector<std::string> contents{"768", "1024", "1536", "a", "b", "c", "d", "e", "f", "g", "h"};

	// then we create a new list with that data
  
	// ULListStr * populatedList = new ULListStr();
  // populatedList->push_front("a"); 

  // std::cout << populatedList->get(0) <<std::endl; 

	

	// delete populatedList;

  // std::vector<std::string> contents{"foo", "BAR", "baz"};
	// ULListStr * populatedList = new ULListStr();

  // for(std::string n : contents)
  // {
  //   populatedList->push_back(n);
	// 	// std::cout << populatedList->back() << " ";
  //   // std::cout << populatedList->size() << std::endl;
  // }





