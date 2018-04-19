#pragma once

enum GameTag
{
	Default,
	Player,
	Block,
	LifeText,
	TimerText,
	StartButton,
	RestartButton,
	MainMenuButton,
	ExitButton,
};


enum GameScreenRep {
	MainMenuScreen = 0,
	InGameScreen,
	DeadScreen,
};


enum GameState {
	Uninitialized, Initialized, Paused,
	Running, Exiting
};