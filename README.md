# CPPND: Program for Dictionary Search

This is the capstone project that I had created as part of my C++ Nanodegree from Udacity

The basic idea of this project is the usage of Trie Data Structure to
hold dictionary words. Dictionary words can be read from a file
(dictionary.txt) that is placed inside the src folder with the source
files. The words are arranged in a Trie at the start of the project and
then we ask for space separated list of words from the user and create
parallel threads to validate the words against the structure that we
have created initially.

If the word is found in Trie, we display a message saying that "X is a
valid word" else we display a message saying that "X is not a valid
word".

For demo purposes, I have added most of the words starting from 'a' and
few starting with 'b' in the dictionary. Any other words entered in the
console will be treated and displayed as invalid words in the output.

Example

Input : About Pop Tree

Output : About is a valid word
	   Pop is not a valid word
	   Tree is not a valid word

## Code Structure
Trie.h and Trie.cpp -- Files containing classes TrieNode and Trie.
Provide functionality for inserting a word into a Trie and searching the
same.

WordsFinder.h and WordsFinder.cpp -- Contain a base class
ThreadManagement and derived class WordsFinder. ThreadManagement
maintains a vector of threads that are instantiated to find words in the
dictionary in parallel. WordsFinder spawns these threads and uses search
functionality of Trie to look for these words in the structure. Promise
and Future have been used to pass data to and from the threads.

Main.cpp -- Reads words from the dictionary and invokes the insert
operation of Trie class to create the structure.

Then takes user input, parses it and calls spawnThreads function of
WordsFinder.

## Dependencies for Running Locally
* cmake >= 2.8
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* OpenCV >= 4.1
  * The OpenCV 4.1.0 source code can be found [here](https://github.com/opencv/opencv/tree/4.1.0)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./traffic_simulation`
