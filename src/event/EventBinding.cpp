#include "pch.h"

#include "event/EventBinding.h"

namespace pt = boost::property_tree;

std::map<SDL_KeyCode, Action> EventBinding::actionBinding = {};

EventBinding::EventBinding()
{
	pt::ptree root;
	pt::read_json(bindingFile, root);
	for(pt::ptree::value_type& pair : root.get_child("key")) {
		for(pt::ptree::value_type& keycode : pair.second) {
			actionBinding.emplace(static_cast<SDL_KeyCode>(keycode.first[0]), static_cast<Action>(root.get<int>(std::string("action.") + keycode.second.data())));
		}
	}
	root.clear();
}
