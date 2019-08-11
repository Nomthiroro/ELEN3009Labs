// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"

Line::Line(const string& line)
{
	// Hint: some of string's member functions might come in handy here
	// for extracting words.
    
    istringstream buf(line);
    for(string word; buf>>word;)
    {
        auto newWord = Word{word};
        line_.push_back(newWord);
    }
}

bool Line::contains(const Word& search_word) const
{
	bool isFound = false;
    if(line_.empty() || !search_word.isQueryable())
    {
        isFound = false;
    }
    else
    {
        for(auto i =0u; i< line_.size(); i++)
        {
        if(line_.at(i)== search_word) isFound = true;
        }
    }
    
    return isFound;
}
