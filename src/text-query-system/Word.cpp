// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"

string ignorePunctuation(const string& word)
{
    auto tempString = ""s;
    auto isPunctuation = false;
    for(auto i =0u; i<word.length(); i++)
    {
        isPunctuation = ispunct(word.at(i));
        if(!isPunctuation)
        {
            tempString.push_back(word.at(i));
        }
    }
    return tempString;
}
bool isOnlyPunctuation(const string& word)
{
    auto isOnlyPunct = false;
    auto testWord = ignorePunctuation(word);
    if(testWord.empty()) isOnlyPunct = true;
   
    return isOnlyPunct;
}

bool containsASpace(const string& word)
{
    auto hasASpace = false;
    auto tempIter = find(word.begin(), word.end(), ' ');
    if(tempIter!= word.end())
    {
        hasASpace = true;
    }
    return hasASpace;
}
Word::Word(const string& word): word_{word}
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	if (word_.empty()) throw WordContainsNoLetters{};
    word_ = ignorePunctuation(word_);
    if(isOnlyPunctuation(word_)) throw WordContainsNoLetters{};
    if(containsASpace(word_)) throw WordContainsSpace{};
    transform(word_.begin(), word_.end(), word_.begin(), ::toupper);
    

	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
	if (word_ == rhs.word_)
		return true;
	else
		return false;
}

bool Word::isQueryable() const
{
    auto queryable = false;
    if(word_.length()>=3) queryable = true;
    return queryable;
}
