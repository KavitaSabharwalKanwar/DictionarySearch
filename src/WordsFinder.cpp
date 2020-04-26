#include "WordsFinder.h"

std::mutex ThreadManagement::_mtx;

ThreadManagement::ThreadManagement()
{
}

ThreadManagement::~ThreadManagement()
{
    // set up thread barrier before this object is destroyed
    std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
        t.join();
    });
}

WordsFinder::WordsFinder()
{
}

//Function to search the word in the dictionary and return back an appropriate message
void WordsFinder::isValidWord(promise<string>&& prms, string str)
{
    if (_trie->search(str))
        prms.set_value(str + " is a valid word");
    else
        prms.set_value(str + " is not a valid word");
        
}

//Function to spawn one thread for each word. Thread will search Trie and figure out if the word is present in the dictionary or not.
void WordsFinder::spawnThreads(unique_ptr<Trie>& trie, vector<string>& listOfWords)
{
    _trie = move(trie);
    for (auto str : listOfWords) {
        promise<string> prms;
        ftrVec.push_back(prms.get_future());    
        //Thread will return back this string after appending " is a valid word" or " is not a valid word" after this
        threads.emplace_back(thread(&WordsFinder::isValidWord, this, move(prms), str));
    }

    for (int i = 0; i < ftrVec.size(); i++)
    {
        string str = ftrVec[i].get();
        std::unique_lock<std::mutex> lck(_mtx);
        std::cout << str << std::endl;
        lck.unlock();
    }
}

