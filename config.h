#include <string>
#include <vector>
#include <sstream>
#include <nlohmann/json.hpp>
#include "_log.hpp"
using json = nlohmann::json;
typedef unsigned char byte;
class config
{
public:
config();
void load(std::string configfile);
std::string outFileName(void) const;
std::string getDevice(void) const;
std::vector<byte> getBegin(void) const;
std::vector<byte> getEnd(void) const;
std::vector<byte> getPilot(void) const;
std::vector<byte> getFinaliser(void) const;
std::string getLogPath(void) const;
private:
std::vector<byte> splitter(std::string str,char delimiter);

std::string 	devicelink;
std::string 	fileName;	
std::string 	logFilePath;
std::vector<byte> _begin;
std::vector<byte> _end;
std::vector<byte> _pilot;
std::vector<byte> _finaliser;
};