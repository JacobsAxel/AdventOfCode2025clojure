    #include <iostream>
    #include <fstream>
    #include <string>
    #include <array>

    int solution(std::string fileName);
    std::array<int,2> rotateLeft(int start, int rotation);
    std::array<int,2> rotateRight(int start, int rotation);

    int main() 
    {
        std::cout << solution("../inputs/day1p1.txt");
    }

    int solution(std::string fileName)
    {
        int result = 0;
        int index = 50;
        std::string line;
        std::ifstream MyReadFile(fileName);
        
        while(std::getline(MyReadFile,line))
        {
            std::array lineResult = (line[0]=='L') ? rotateLeft(index,std::stoi(line.substr(1))) : rotateRight(index,stoi(line.substr(1)));
            result += lineResult[0];
            index = lineResult[1];
        }
        return result;
    }
    
    // Return {rotations,new index position}
    
    std::array<int,2> rotateLeft(int start, int rotation)
    {
        int rotations = rotation/100;
        int rest = rotation%100;

        if(rest > 0 && start <= rest && start > 0)
        {
            rotations += 1;
        }

        return {rotations,(start - rest + 100) % 100};
    }

    std::array<int,2> rotateRight(int start, int rotation)
    {
        return {(start + rotation) / 100,(start + rotation) % 100};
    }