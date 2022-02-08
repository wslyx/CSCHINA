#pragma once
/*
   Demo Name:  Game Project 1
      Author:  Allen Sherrod
     Chapter:  Chapter 2
*/
#include"RealEngine/engine.h"

#pragma comment(lib, "RealEngine.lib")

#ifndef _MAIN_H_
#define _MAIN_H_

#define WINDOW_CLASS    L"CS::CHINA"
#define WINDOW_NAME     L"CS::CHINA"
#define WIN_WIDTH       640
#define WIN_HEIGHT      320
#define FULLSCREEN      0

bool InitializeEngine();
void ShutdownEngine();
bool GameInitialize();
void GameLoop();
void GameShutdown();

#endif