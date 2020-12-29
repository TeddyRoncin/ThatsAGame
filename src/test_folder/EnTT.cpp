#include "pch.h"
#include "test_folder/EnTT.h"

Entity::Entity(const std::string& name)
	:m_ID(GenerateID(m_Name))
{}

int Entity::GetID() const
{
	return m_ID;
}

std::string Entity::GetName() const
{
	return m_Name;
}
