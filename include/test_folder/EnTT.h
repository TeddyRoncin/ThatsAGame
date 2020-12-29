#pragma once

static std::map<std::string, int> ID_manager;

static int GenerateID(const std::string& name)
{
	static int iterator = 0;
	return ID_manager[name] = iterator++;
}

class Entity
{
public:
	Entity(const std::string& name);
public:
	int GetID() const;
	std::string GetName() const;
private:
	std::string m_Name;
	int m_ID;
};

