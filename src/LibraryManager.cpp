#include "LibraryManager.h"

#include <fstream>
#include <sstream>
#include <filesystem>

#include "Tools.h"

void LibraryManager::Init()
{

    ReadConfig();

    InitBookDir();

}

void LibraryManager::ReadConfig()
{

    std::string configPath = "conf.txt";

    std::ifstream file(configPath);

    if (file.is_open())
    {

        file >> m_dataStop;

        std::string input;
        std::getline(file, input);

        std::istringstream ss(input);

        m_name = ReadTill(ss, m_dataStop);

        m_initialBookDirName = ReadTill(ss, m_dataStop);
        m_initialBookDirPath = ReadTill(ss, m_dataStop);

    }

}

void LibraryManager::InitBookDir()
{

    m_initialBookDir = BookDir(m_initialBookDirName, std::filesystem::current_path().string() + '/' + m_initialBookDirPath, m_dataStop);

}
