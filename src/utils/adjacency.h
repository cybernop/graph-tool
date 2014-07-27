//
//  adjacency.h
//  utils
//
//  Created by Alexander Schulze on 27.07.14.
//
//

#ifndef __utils__adjacency__
#define __utils__adjacency__

#include <vector>
#include <string>

namespace Adjacency
{
    void splitIntoLines(std::vector <std::vector<std::string> >& result, const std::string& s);

    std::vector <std::string> splitIntoRows(std::string& s);
    
    std::string vectorsToString(std::vector <std::vector<std::string> >& vectors);
}

#endif /* defined(__utils__adjacency__) */