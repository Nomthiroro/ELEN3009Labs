// -------------------------------------------
//					Paragraph
// -------------------------------------------

#include "Paragraph.h"

void Paragraph::addLine(const Line& line)
{
    paragraph.push_back(line);
}

tuple<bool, vector<int>> Paragraph::contains(const Word& search_word) const
{
    bool isFound = false; 
    vector<int> lineNumbers;
    
    for(auto i=0u; i< paragraph.size(); i++)
    {
        if(paragraph.at(i).contains(search_word)) isFound = true;
        lineNumbers.push_back(i+1);
    }
   
	return {isFound, lineNumbers};
}