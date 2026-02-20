#include <iostream>
#include <fstream>

std::string ft_replace(std::string line,std::string s2, std::string s3)
{
    int index = 0;
   while (index != std::string::npos)
   {
       index = line.find(s2);
       line.erase(index, s2.length());
       line.insert(index,s3);
       index = line.find(s2, index + s3.length());
   }
    return (line);

}
int main(int argc, char **argv)
{
    std::string newline;
    std::string line;    

    if (argc != 4)
    {
        std::cout<<"invalid number of arguments";
        std::cout<<std::endl;
        return (1);
    }

    std::ifstream file(argv[1]);
    if (!file)
    {
        std::cout<<"Failed to open the file."<<std::endl;
        return (1);
    }
    
    while(std::getline(file, line))
    {
       newline +=ft_replace(line, argv[2], argv[3]) + "\n";
    }


    std::string outFile = std::string(argv[1]) + ".replace";
    std::ofstream rep_file(outFile.c_str());
    if (!rep_file) {
        std::cerr << "Failed to open output file." << std::endl;
        file.close();
        return (1);
    }

    rep_file<<newline;
    file.close();
    rep_file.close();
}