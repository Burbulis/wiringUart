#include "config.h"

config::config()
{}

void
config::load(std::string configfile)
{
	std::cout << "++config::config()" << std::endl;
	std::cout << "++logFilePath() configfile = " << configfile << std::endl; 
	std::ifstream readedfile(configfile);
	if (readedfile.is_open())
		std::cout << "++logFilePath() readed normally" << configfile << std::endl; 
	json js = json::parse(readedfile).at("tokens");
	devicelink 	= js.at("device_link");
	fileName 	= js.at("outFileName");
	std::cout << "++logFilePath()"; 
	logFilePath = js.at("logFilePath"); 
	std::string _strbeg = js.at("begin");
	std::string _strend = js.at("end");
	std::string _strplt = js.at("PILOT");
	std::string _strfin = js.at("FINALISATOR");

	_begin = splitter(_strbeg,',');
	_end   = splitter(_strend,','); 
	_pilot = splitter(_strplt,',');
	_finaliser = splitter(_strfin,',');;
	std::cout << "--config::config()" << std::endl; 
}

std::string config::getLogPath(void) const
{
	std::string ret = logFilePath;
	std::cout << "logFilePath = " << ret << std::endl;
	return (ret);
}

std::string config::outFileName(void) const
{
	return (fileName);
}

std::string config::getDevice(void) const
{
	return (devicelink);
}

std::vector<byte> config::getBegin(void) const
{
	return (_begin);
}

std::vector<byte> config::getEnd(void) const
{
	return (_end);
}

std::vector<byte> config::getPilot(void) const
{
	return (_pilot);
}

std::vector<byte> config::getFinaliser(void) const
{
	return (_finaliser);
}

std::vector<byte> config::splitter(std::string str,char delimiter)
{
    std::istringstream split(str);
    std::vector<std::string> tokens;
    std::vector<byte> v_out;
    for (std::string each; std::getline(split, each, delimiter); tokens.push_back(each));
    std::transform(tokens.begin(), tokens.end(), std::back_inserter(v_out), [](std::string hex_) 
    {
        int num;
        sscanf(hex_.c_str(), "%x", &num);
        return (num);
    });
    return (v_out);
}