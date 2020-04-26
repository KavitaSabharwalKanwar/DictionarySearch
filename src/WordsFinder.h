#ifndef TRAFFICOBJECT_H
#define TRAFFICOBJECT_H

#include <vector>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <future>
#include <thread>
#include <algorithm>
#include <iostream>
#include <chrono>
#include "Trie.h"

using namespace::std;

class ThreadManagement
{
public:
    // constructor / desctructor
    ThreadManagement();
    ~ThreadManagement();

    // typical behaviour methods
    virtual void simulate(){};

protected:
    std::vector<std::thread> threads; // holds all threads that have been launched within this object
    static std::mutex _mtx;           

};

class WordsFinder : public ThreadManagement
{
public:
    WordsFinder();
    void spawnThreads(unique_ptr<Trie>& trie, vector<string>& listOfWords);

private:
    unique_ptr<Trie> _trie;
    vector<future<string>> ftrVec;
    //Function to find the word in the dictionary. Returns the approproiate message
    void isValidWord(promise<string>&& prms, string word);
};

#endif