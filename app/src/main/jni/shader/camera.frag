const char* camera_play_frag = STRINGIFY(

\n#extension GL_OES_EGL_image_external : require\n
precision highp float;
varying vec2                v_CamTextcoord;
uniform samplerExternalOES  u_CameraTexture;

void main()
{
	gl_FragColor = texture2D(u_CameraTexture, v_CamTextcoord);
}
);