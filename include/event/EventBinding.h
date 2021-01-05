#pragma once

enum Action { None, PlayerUp, PlayerDown, PlayerRight, PlayerLeft, PlayerAct, PlayerInventory, OpenMenu, Quit };

class EventBinding
{
public:
	EventBinding();
	inline static Action GetAction(SDL_KeyCode keycode) { return (actionBinding.find(keycode) != actionBinding.end()) ? actionBinding[keycode] : Action::None ; }
	/** TODO: modifs */
	inline static Action GetAction(int _MouseButton) { return static_cast<Action>(_MouseButton); }
private:
	const char* bindingFile = "assets/event/binding.json";
	static std::map<SDL_KeyCode, Action> actionBinding;
private:
	static EventBinding s_Binding;
};
