//
//  adjacency.cpp
//  utils
//
//  Created by Alexander Schulze on 27.07.14.
//
//

#include <sstream>

#include "adjacency.h"

namespace Adjacency
{
    
    const std::string DELIMITER   = ", ";
    const std::string LINE_ENDING = "\\";
    
    void splitIntoLines(std::vector <std::vector<std::string> >& result, const std::string& s)
    {
        std::istringstream ss(s);
        std::string line;
        while (std::getline(ss, line))
        {
            result.push_back(splitIntoRows(line));
        }
    }
    
    std::vector <std::string> splitIntoRows(std::string& rowString)
    {
        std::vector<std::string> row;
        
        size_t pos = 0;
        std::string token;
        while ((pos = rowString.find(DELIMITER)) != std::string::npos)
        {
            token = rowString.substr(0, pos);
            row.push_back(token);
            rowString.erase(0, pos + DELIMITER.length());
        }
        
        if (rowString.compare("") != 0 && rowString.compare("\\") != 0)
        {
            row.push_back(rowString);
        }
        
        return row;
    }
    
    std::string vectorsToString(std::vector <std::vector<std::string> >& vectors)
    {
        std::string result;
        
        for (std::vector<std::string>& rowVector : vectors)
        {
            for (std::string& entry : rowVector)
            {
                result += entry + DELIMITER;
            }
            result += LINE_ENDING + "\n";
        }
        
        return result.substr(0, result.length() - 4);
    }
    
}
