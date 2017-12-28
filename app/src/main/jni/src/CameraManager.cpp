#include <stdio.h>
#include <jni.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include "Common.h"
#include "CameraManager.h"
template<> CameraManager* Singleton<CameraManager>::msSingleton = nullptr;
CameraManager::CameraManager()
{
}

CameraManager::~CameraManager()
{
}

void CameraManager::onCreate()
{
}

void CameraManager::onResume()
{
}

void CameraManager::onPause()
{
}

void CameraManager::onStop()
{
}

void CameraManager::onDestroy()
{
}

void CameraManager::initGL(float width, float height)
{
}
void CameraManager::deInitGL()
{
}
void CameraManager::drawFrame()
{
}

GLint CameraManager::getCameraTextureId()
{
    return _textureId;
}