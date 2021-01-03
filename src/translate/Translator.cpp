#include "pch.h"
#include "translate/Translator.h"

Translator::Translator()
{
    Translator(Languages::en_US);
}

Translator::Translator(Languages language)
{
    LoadLanguage(language);
}

void Translator::LoadLanguage(Languages language)
{
    mTranslations.clear();
    std::string path = "assets/lang/" + GetTranslationFileName(language) + ".lang";
    if (path.empty())
    {
        std::cerr << "Unknown .lang path for language " << language << std::endl;
        return;
    }
    std::ifstream file;
    file.open(path, std::ios::binary);
    if (file) {
        file.seekg(0, std::ios::end);
        int fileSize = file.tellg();
        file.seekg(0, std::ios::beg);
        std::string line;
        int i = 0;
        while (std::getline(file, line)) {
            if (line[line.length() - 1] == '\r') {
                line = line.substr(0, line.length() - 1);
            }
            i++;
            if (line[0] == '#' || line.empty()) {
                continue;
            }
            int pos = line.find('=');
            if (pos == std::string::npos || pos == line.length() - 1) {
                std::cerr << "Syntax error : " << path << " at line " << i << std::endl;
                continue;
            }
            std::string key = line.substr(0, pos);
            std::string translation = line.substr(pos + 1, line.length());
            mTranslations.insert({key, translation});
        }
    } else {
        std::cerr << "Could not open file " << path;
    }
}

const std::string Translator::GetTranslationFileName(Languages language)
{
    switch (language)
    {
        case Languages::en_US: return "en-US";
        case Languages::fr_FR: return "fr-FR";
    }
    return "";
}

const std::string Translator::Translate(const std::string key)
{
    std::map<std::string, std::string>::iterator it = mTranslations.find(key);
    return it == mTranslations.end() ? key : it->second;
}