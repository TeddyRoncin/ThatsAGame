#pragma once

enum Action { PlayerUp, PlayerDown, PlayerRight, PlayerLeft, PlayerAct, PlayerInventory, OpenMenu, Quit, None };

class EventBinding
{
public:
	EventBinding();
	inline static Action GetAction(SDL_KeyCode keycode) { return (actionBinding.find(keycode) != actionBinding.end()) ? actionBinding[keycode] : Action::None ; }
private:
	const char* bindingFile = "assets/event/binding.json";
	static std::map<SDL_KeyCode, Action> actionBinding;
private:
	static EventBinding s_Binding;
};
