#pragma once

#include "translate/Languages.h"

class Translator
{
public:
    Translator();
    Translator(Languages language);
    void LoadLanguage(Languages language);
    const std::string Translate(const std::string key);
private:
    std::map<std::string, std::string> mTranslations;
    const std::string GetTranslationFileName(Languages language);
};