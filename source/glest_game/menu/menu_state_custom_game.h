// ==============================================================
//	This file is part of Glest (www.glest.org)
//
//	Copyright (C) 2001-2005 Marti�o Figueroa
//
//	You can redistribute this code and/or modify it under
//	the terms of the GNU General Public License as published
//	by the Free Software Foundation; either version 2 of the
//	License, or (at your option) any later version
// ==============================================================

#ifndef _GLEST_GAME_MENUSTATECUSTOMGAME_H_
#define _GLEST_GAME_MENUSTATECUSTOMGAME_H_

#include "main_menu.h"
#include "chat_manager.h"
#include "simple_threads.h"

namespace Glest{ namespace Game{
// ===============================
// 	class MenuStateCustomGame
// ===============================

class MenuStateCustomGame : public MenuState, public SimpleTaskCallbackInterface {
private:
	GraphicButton buttonReturn;
	GraphicButton buttonPlayNow;
	GraphicLabel labelControl;
	GraphicLabel labelFaction;
	GraphicLabel labelTeam;
	GraphicLabel labelMap;
	GraphicLabel labelFogOfWar;
	GraphicLabel labelTechTree;
	GraphicLabel labelTileset;
	GraphicLabel labelMapInfo;
	GraphicListBox listBoxMap;
	GraphicListBox listBoxFogOfWar;
	GraphicListBox listBoxTechTree;
	GraphicListBox listBoxTileset;
	vector<string> mapFiles;
	vector<string> techTreeFiles;
	vector<string> tilesetFiles;
	vector<string> factionFiles;
	GraphicLabel labelPlayers[GameConstants::maxPlayers];
	GraphicListBox listBoxControls[GameConstants::maxPlayers];
	GraphicListBox listBoxFactions[GameConstants::maxPlayers];
	GraphicListBox listBoxTeams[GameConstants::maxPlayers];
	GraphicLabel labelNetStatus[GameConstants::maxPlayers];
	MapInfo mapInfo;
	
	GraphicLabel labelPublishServer;
	GraphicListBox listBoxPublishServer;

	bool needToSetChangedGameSettings;
	time_t lastSetChangedGameSettings;
	time_t lastMasterserverPublishing;
	bool needToRepublishToMasterserver;
	bool needToBroadcastServerSettings;
	string publishToServerInfo;
	SimpleTaskThread *publishToMasterserverThread;
	
	bool parentMenuIsMs;
	bool soundConnectionCount;

	Console console;
	ChatManager chatManager;

public:
	MenuStateCustomGame(Program *program, MainMenu *mainMenu ,bool openNetworkSlots= false, bool parentMenuIsMasterserver=false);
	~MenuStateCustomGame();

	void mouseClick(int x, int y, MouseButton mouseButton);
	void mouseMove(int x, int y, const MouseState *mouseState);
	void render();
	void update();

    virtual void keyDown(char key);
    virtual void keyPress(char c);

    virtual void simpleTask();

private:

    bool hasNetworkGameSettings();
    void loadGameSettings(GameSettings *gameSettings);
	void loadMapInfo(string file, MapInfo *mapInfo);
	void reloadFactions();
	void updateControlers();
	void closeUnusedSlots();
	void updateNetworkSlots();
	void publishToMasterserver();
	void returnToParentMenu();
};

}}//end namespace

#endif
