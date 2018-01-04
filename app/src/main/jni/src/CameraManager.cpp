#include "Common.h"
#include "CameraManager.h"
#include "GLUtil.h"
#include "shader/camera.frag"
#include "shader/camera.vert"
/* GL_OES_EGL_image_external */
#ifndef GL_OES_EGL_image_external
#define GL_TEXTURE_EXTERNAL_OES                                 0x8D65
#endif
template<> CameraManager* Singleton<CameraManager>::msSingleton = nullptr;
CameraManager::CameraManager()
    : _photoWidth(0)
    , _photoHeight(0)
    , _sProgramPlay(0)
    , _vaoId(0)
    , _vboBuffer(0)
    , _texture(0)
    , _positionLoc(-1)
    , _textureLoc(-1)
    , _mvpMatrixLoc(-1)
    , _mvpMatrix(glm::mat4(1.0f))
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
    glDeleteVertexArrays(1, &_vaoId);
    glDeleteBuffers(1, &_vboBuffer);
    glDeleteTextures(1, &_texture);
    glDeleteProgram(_sProgramPlay);
}

void CameraManager::initGL(float width, float height)
{
    _photoWidth     = width;
    _photoHeight    = height;
    if (CompileShaderProgram(camera_play_vert, camera_play_frag, &_sProgramPlay)) {
        _positionLoc	= glGetAttribLocation(_sProgramPlay,    "a_Position");
        _textureLoc		= glGetAttribLocation(_sProgramPlay,    "a_Textcoord");
        _mvpMatrixLoc	= glGetUniformLocation(_sProgramPlay,   "u_MvpMatrix");
        GLfloat vertices[] = {
                -1.0f, -1.0f, 0.0f, 1.0f,
                 1.0f, -1.0f, 1.0f, 1.0f,
                -1.0f,  1.0f, 0.0f, 0.0f,
                 1.0f,  1.0f, 1.0f, 0.0f,
        };
        glGenVertexArrays(1, &_vaoId);
        glBindVertexArray(_vaoId);
        glGenBuffers(1, &_vboBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, _vboBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(
                _positionLoc,
                2,
                GL_FLOAT,
                GL_FALSE,
                4 * sizeof(GL_FLOAT),
                (GLvoid*)0
        );
        glEnableVertexAttribArray(_positionLoc);
        glVertexAttribPointer(
                _textureLoc,
                2,
                GL_FLOAT,
                GL_FALSE,
                4 * sizeof(GL_FLOAT),
                (GLvoid*)(2 * sizeof(GL_FLOAT))
        );
        glEnableVertexAttribArray(_textureLoc);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        // texture
        glGenTextures(1, &_texture);
        glBindTexture(GL_TEXTURE_2D, _texture);
        glBindTexture(GL_TEXTURE_EXTERNAL_OES, _texture);
        glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glBindTexture(GL_TEXTURE_EXTERNAL_OES, 0);
    }
}

void CameraManager::drawFrame()
{
    glBindVertexArray(_vaoId);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, _photoWidth, _photoHeight);
    glUseProgram(_sProgramPlay);
    glUniformMatrix4fv(_sProgramPlay, 1, GL_FALSE, glm::value_ptr(_mvpMatrix));
    LOGE("111111111111111111111111111111111111");
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, _texture);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
    glUseProgram(0);
}

GLint CameraManager::getCameraTextureId()
{
    return _texture;
}